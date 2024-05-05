module;

#include <string>

#include <functional>
#include <memory>

#include <unordered_map>
#include <vector>
#include <deque>

#include <stdint.h>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	CHV4DDECODER::CHV4DDECODER()
	{		
		Segment->ClearStream();

		ByteStream->clear();

		ReadHeader = true;

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

		std::memset((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;

		InitPrefixCodeBits();

		InitDistanceCodeBits();
		
	}

	ARCHIVE_ERROR CHV4DDECODER::InflateStream(BlockSink bsink)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;
		
		NewStream(bsink);

		while (error == ARCHIVE_ERROR_CONSUME_STREAM)
		{
			if (ReadHeader)
			{
				error = Header();

			}
			else if (!ReadHeader)
			{
				if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ZERO })
				{
					do
					{
						error = NoCompress();

					} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

				}
				else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ZERO })
				{
					do
					{
						error = DecodePrefix();

					} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

				}

			}

		}
		
		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DDECODER::FetchStream()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		if (Segment->Remain() == 0)
		{
			error = Sink(Segment);

			if (Segment->Remain() == 0) return ARCHIVE_ERROR_EMPTY_STREAM;

			if (error != ARCHIVE_ERROR_CONSUME_STREAM && error != ARCHIVE_ERROR_END_OF_STREAM)
			{
				throw std::runtime_error{ "Invalid return." };

			}

			if (error == ARCHIVE_ERROR_END_OF_STREAM)
			{
				EOS = true;

				error = ARCHIVE_ERROR_CONSUME_STREAM;

			}

			Segment->BeginningOfStream();

		}
		
		return ARCHIVE_ERROR_CONSUME_STREAM;

	}

	ARCHIVE_ERROR CHV4DDECODER::Header()
	{
		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		if (Segment->operator++() == CHV4DBITSTREAM::BIT_ONE) EOS = true;

		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		BlockType.first = Segment->operator++();

		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		BlockType.second = Segment->operator++();

		if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ZERO })
		{
			if (Segment->BitStreamSize() % 8 != 0) throw std::invalid_argument{ "Uncompressed segment should be mod 8." };

			Segment->ByteAlignNext();

		}
		else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ONE })
		{
			throw std::invalid_argument{ "Dynamic trees not supported." };

		}
		else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
		{
			throw std::invalid_argument{ "Reserved." };

		}

		ReadHeader = false;
		
		return ARCHIVE_ERROR_CONSUME_STREAM;

	}

	ARCHIVE_ERROR CHV4DDECODER::NoCompress()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;
		
		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		if (Segment->BitStreamSize() % 8 != 0) throw std::invalid_argument{ "All segments should be mod 8 except last." };

		if (ZeroZeroBlock.second != 2)
		{
			for (; ZeroZeroBlock.second < 2; ++ZeroZeroBlock.second)
			{
				for (size_t i = 0; i < 8; ++i)
				{
					Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
						ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 0 :
						ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 32768;

				}

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

			}

		}
		else if (NotZeroZeroBlock.second != 2)
		{
			for (; NotZeroZeroBlock.second < 2; ++NotZeroZeroBlock.second)
			{
				for (size_t i = 0; i < 8; ++i)
				{
					Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
						NotZeroZeroBlock.first = (NotZeroZeroBlock.first >> 1) | 0 :
						NotZeroZeroBlock.first = (NotZeroZeroBlock.first >> 1) | 32768;

				}

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

			}

		}
		else if (ZeroZeroBlock.first != 0)
		{
			for (; ZeroZeroBlock.first != 0; --ZeroZeroBlock.first)
			{
				uint8_t Literal = 0;

				for (size_t i = 0; i < 8; ++i)
				{
					Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
						Literal = (Literal << 1) | 0 :
						Literal = (Literal << 1) | static_cast<uint8_t>(32768);

				}

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

				ByteStream->push_back(static_cast<unsigned char>(Literal));

			}

		}

		if (ZeroZeroBlock.first == 0)
		{
			BlockType = std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

			ReadHeader = true;

			ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

			if (EOS) return ARCHIVE_ERROR_END_OF_STREAM;

		}
		
		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodePrefix()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };
		
		for (; BackRef.LPrefixCode.second != 7; ++BackRef.LPrefixCode.second)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };
			
		}
		
		if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };
		
		if (BackRef.LPrefixCode.first >= 24 && BackRef.LPrefixCode.first >= 95)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			ByteStream->push_back(reinterpret_cast<unsigned char*>(&BackRef.LPrefixCode.first)[1]); 
		
			std::memset((void*)&BackRef, '\0', sizeof(BackRef));

			return ARCHIVE_ERROR_CONSUME_STREAM;
			
		}
		else if (BackRef.LPrefixCode.first >= 100 && BackRef.LPrefixCode.first >= 127)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			ByteStream->push_back(reinterpret_cast<unsigned char*>(&BackRef.LPrefixCode.first)[1]);

			std::memset((void*)&BackRef, '\0', sizeof(BackRef));

			return ARCHIVE_ERROR_CONSUME_STREAM;
			
		}
		else if (BackRef.LPrefixCode.first >= 0 && BackRef.LPrefixCode.first >= 23)
		{
			if (BackRef.LPrefixCode.first == 0)
			{
				BlockType = std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

				ReadHeader = true;

				std::memset((void*)&BackRef, '\0', sizeof(BackRef));

				if (EOS) return ARCHIVE_ERROR_EMPTY_STREAM;

			}

			if (DecodeLiteralLength() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Decoder failure." };

			return ARCHIVE_ERROR_CONSUME_STREAM;
		
		}
		else if (BackRef.LPrefixCode.first >= 96 && BackRef.LPrefixCode.first >= 99)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
				BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

			if (DecodeLiteralLength() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Decoder failure." };
			
			return ARCHIVE_ERROR_CONSUME_STREAM;
			
		}
		
		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodeLiteralLength()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;
		
		uint16_t Prefix{ 0 };

		if (BackRef.LPrefixCode.first >= 1 && BackRef.LPrefixCode.first <= 23)
		{
			Prefix = BackRef.LPrefixCode.first + 256ui16;

		}
		else
		{
			Prefix = BackRef.LPrefixCode.first - 192ui16 + 280ui16;

		}

		BackRef.Length = PrefixCodeBits.at(Prefix);

		uint16_t Offset{ 0 };

		for (; BackRef.Length.second > 0; --BackRef.Length.second)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				Offset = (Offset << 1) | 0 :
				Offset = (Offset << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		}

		BackRef.Length.first = BackRef.Length.first + Offset;
		
		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::PushFromDictionary()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;
		
		ByteStream->insert(
			ByteStream->end(),
			std::prev(ByteStream->end(), BackRef.Length.first),
			std::next(std::prev(ByteStream->end(), BackRef.Length.first), BackRef.Distance.first));
			
		return error;

	}

	void CHV4DDECODER::NewStream(BlockSink bsink)
	{
		if (bsink == nullptr) throw std::invalid_argument{ "No Sink specified." };

		Sink = bsink;

		Segment->ClearStream();

		ByteStream->clear();

		ReadHeader = true;

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

		std::memset((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;
		
	}

	void CHV4DDECODER::InitPrefixCodeBits()
	{
		PrefixCodeBits.insert({257ui16, {  3ui16, 0}});
		PrefixCodeBits.insert({258ui16, {  4ui16, 0}});
		PrefixCodeBits.insert({259ui16, {  5ui16, 0}});
		PrefixCodeBits.insert({260ui16, {  6ui16, 0}});
		PrefixCodeBits.insert({261ui16, {  7ui16, 0}});
		PrefixCodeBits.insert({262ui16, {  8ui16, 0}});
		PrefixCodeBits.insert({263ui16, {  9ui16, 0}});
		PrefixCodeBits.insert({264ui16, { 10ui16, 0}});
		PrefixCodeBits.insert({265ui16, { 11ui16, 1}});
		PrefixCodeBits.insert({266ui16, { 13ui16, 1}});
		PrefixCodeBits.insert({267ui16, { 15ui16, 1}});
		PrefixCodeBits.insert({268ui16, { 17ui16, 1}});
		PrefixCodeBits.insert({269ui16, { 19ui16, 2}});
		PrefixCodeBits.insert({270ui16, { 23ui16, 2}});
		PrefixCodeBits.insert({271ui16, { 27ui16, 2}});
		PrefixCodeBits.insert({272ui16, { 31ui16, 2}});
		PrefixCodeBits.insert({273ui16, { 35ui16, 3}});
		PrefixCodeBits.insert({274ui16, { 43ui16, 3}});
		PrefixCodeBits.insert({275ui16, { 51ui16, 3}});
		PrefixCodeBits.insert({276ui16, { 59ui16, 3}});
		PrefixCodeBits.insert({277ui16, { 67ui16, 4}});
		PrefixCodeBits.insert({278ui16, { 83ui16, 4}});
		PrefixCodeBits.insert({279ui16, { 99ui16, 4}});
		PrefixCodeBits.insert({280ui16, {115ui16, 4}});
		PrefixCodeBits.insert({281ui16, {131ui16, 5}});
		PrefixCodeBits.insert({282ui16, {163ui16, 5}});
		PrefixCodeBits.insert({283ui16, {195ui16, 5}});
		PrefixCodeBits.insert({284ui16, {227ui16, 5}});
		PrefixCodeBits.insert({285ui16, {258ui16, 0}});
		
	}

	void CHV4DDECODER::InitDistanceCodeBits()
	{
		DistanceCodeBits.insert({  0ui16, {    1ui16,  0} });
		DistanceCodeBits.insert({  1ui16, {    2ui16,  0} });
		DistanceCodeBits.insert({  2ui16, {    3ui16,  0} });
		DistanceCodeBits.insert({  3ui16, {    4ui16,  0} });
		DistanceCodeBits.insert({  4ui16, {    5ui16,  1} });
		DistanceCodeBits.insert({  5ui16, {    7ui16,  1} });
		DistanceCodeBits.insert({  6ui16, {    9ui16,  2} });
		DistanceCodeBits.insert({  7ui16, {   13ui16,  2} });
		DistanceCodeBits.insert({  8ui16, {   17ui16,  3} });
		DistanceCodeBits.insert({  9ui16, {   25ui16,  3} });
		DistanceCodeBits.insert({ 10ui16, {   33ui16,  4} });
		DistanceCodeBits.insert({ 11ui16, {   49ui16,  4} });
		DistanceCodeBits.insert({ 12ui16, {   65ui16,  5} });
		DistanceCodeBits.insert({ 13ui16, {   97ui16,  5} });
		DistanceCodeBits.insert({ 14ui16, {  129ui16,  6} });
		DistanceCodeBits.insert({ 15ui16, {  193ui16,  6} });
		DistanceCodeBits.insert({ 16ui16, {  257ui16,  7} });
		DistanceCodeBits.insert({ 17ui16, {  385ui16,  7} });
		DistanceCodeBits.insert({ 18ui16, {  513ui16,  8} });
		DistanceCodeBits.insert({ 19ui16, {  769ui16,  8} });
		DistanceCodeBits.insert({ 20ui16, { 1025ui16,  9} });
		DistanceCodeBits.insert({ 21ui16, { 1537ui16,  9} });
		DistanceCodeBits.insert({ 22ui16, { 2049ui16, 10} });
		DistanceCodeBits.insert({ 23ui16, { 3073ui16, 10} });
		DistanceCodeBits.insert({ 24ui16, { 4097ui16, 11} });
		DistanceCodeBits.insert({ 25ui16, { 6145ui16, 11} });
		DistanceCodeBits.insert({ 26ui16, { 8193ui16, 12} });
		DistanceCodeBits.insert({ 27ui16, {12289ui16, 12} });
		DistanceCodeBits.insert({ 28ui16, {16385ui16, 13} });
		DistanceCodeBits.insert({ 29ui16, {24577ui16, 13} });
		
	}

}