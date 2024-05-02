module;

#include <string>

#include <functional>
#include <memory>

#include <unordered_map>
#include <vector>
#include <deque>

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

		std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;

		PrefixCodeBits.insert({ 257, {  3, 0} });
		PrefixCodeBits.insert({ 258, {  4, 0} });
		PrefixCodeBits.insert({ 259, {  5, 0} });
		PrefixCodeBits.insert({ 260, {  6, 0} });
		PrefixCodeBits.insert({ 261, {  7, 0} });
		PrefixCodeBits.insert({ 262, {  8, 0} });
		PrefixCodeBits.insert({ 263, {  9, 0} });
		PrefixCodeBits.insert({ 264, { 10, 0} });
		PrefixCodeBits.insert({ 265, { 11, 1} });
		PrefixCodeBits.insert({ 266, { 13, 1} });
		PrefixCodeBits.insert({ 267, { 15, 1} });
		PrefixCodeBits.insert({ 268, { 17, 1} });
		PrefixCodeBits.insert({ 269, { 19, 2} });
		PrefixCodeBits.insert({ 270, { 23, 2} });
		PrefixCodeBits.insert({ 271, { 27, 2} });
		PrefixCodeBits.insert({ 272, { 31, 2} });
		PrefixCodeBits.insert({ 273, { 35, 3} });
		PrefixCodeBits.insert({ 274, { 43, 3} });
		PrefixCodeBits.insert({ 275, { 51, 3} });
		PrefixCodeBits.insert({ 276, { 59, 3} });
		PrefixCodeBits.insert({ 277, { 67, 4} });
		PrefixCodeBits.insert({ 278, { 83, 4} });
		PrefixCodeBits.insert({ 279, { 99, 4} });
		PrefixCodeBits.insert({ 280, {115, 4} });
		PrefixCodeBits.insert({ 281, {131, 5} });
		PrefixCodeBits.insert({ 282, {163, 5} });
		PrefixCodeBits.insert({ 283, {195, 5} });
		PrefixCodeBits.insert({ 284, {227, 5} });
		PrefixCodeBits.insert({ 285, {258, 0} });

		DistanceCodeBits.insert({ 0 ,{    1,  0} }); 
		DistanceCodeBits.insert({ 1 ,{    2,  0} });
		DistanceCodeBits.insert({ 2 ,{    3,  0} });
		DistanceCodeBits.insert({ 3 ,{    4,  0} });
		DistanceCodeBits.insert({ 4 ,{    5,  1} });
		DistanceCodeBits.insert({ 5 ,{    7,  1} });
		DistanceCodeBits.insert({ 6 ,{    9,  2} });
		DistanceCodeBits.insert({ 7 ,{   13,  2} });
		DistanceCodeBits.insert({ 8 ,{   17,  3} });
		DistanceCodeBits.insert({ 9 ,{   25,  3} });
		DistanceCodeBits.insert({10 ,{   33,  4} });
		DistanceCodeBits.insert({11 ,{   49,  4} });
		DistanceCodeBits.insert({12 ,{   65,  5} });
		DistanceCodeBits.insert({13 ,{   97,  5} });
		DistanceCodeBits.insert({14 ,{  129,  6} });
		DistanceCodeBits.insert({15 ,{  193,  6} });
		DistanceCodeBits.insert({16 ,{  257,  7} });
		DistanceCodeBits.insert({17 ,{  385,  7} });
		DistanceCodeBits.insert({18 ,{  513,  8} });
		DistanceCodeBits.insert({19 ,{  769,  8} });
		DistanceCodeBits.insert({20 ,{ 1025,  9} });
		DistanceCodeBits.insert({21 ,{ 1537,  9} });
		DistanceCodeBits.insert({22 ,{ 2049, 10} });
		DistanceCodeBits.insert({23 ,{ 3073, 10} });
		DistanceCodeBits.insert({24 ,{ 4097, 11} });
		DistanceCodeBits.insert({25 ,{ 6145, 11} });
		DistanceCodeBits.insert({26 ,{ 8193, 12} });
		DistanceCodeBits.insert({27 ,{12289, 12} });
		DistanceCodeBits.insert({28 ,{16385, 13} });
		DistanceCodeBits.insert({29 ,{24577, 13} });

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
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

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

		if (ZeroZeroBlock.second != 4)
		{
			for (; ZeroZeroBlock.second < 4; ++ZeroZeroBlock.second)
			{
				for (size_t i = 0; i < 4; ++i)
				{
					Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
						ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 0 :
						ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 32768;

				}

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

			}

		}
		else if (NotZeroZeroBlock.second != 4)
		{
			for (; NotZeroZeroBlock.second < 4; ++NotZeroZeroBlock.second)
			{
				for (size_t i = 0; i < 4; ++i)
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
			for (;  ZeroZeroBlock.first != 0; --ZeroZeroBlock.first)
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

		if (BackRef.LPrefixCode.second == 7)
		{
			if (BackRef.LPrefixCode.first >= 24 && BackRef.LPrefixCode.first >= 95)
			{
				Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

				uint16_t Literal = BackRef.LPrefixCode.first - 48;

				ByteStream->push_back(reinterpret_cast<unsigned char*>(&Literal)[4]);

				std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

				return ARCHIVE_ERROR_CONSUME_STREAM;

			}
			else if (BackRef.LPrefixCode.first >= 100 && BackRef.LPrefixCode.first >= 127)
			{
				Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

				BackRef.LPrefixCode.second = 8;

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

				if (BackRef.LPrefixCode.second == 8)
				{
					Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
						BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
						BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

					uint16_t Literal = BackRef.LPrefixCode.first - 400;

					ByteStream->push_back(reinterpret_cast<unsigned char*>(&Literal)[4]);

					std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

				}

				return ARCHIVE_ERROR_CONSUME_STREAM;

			}
			else if (BackRef.LPrefixCode.first >= 0 && BackRef.LPrefixCode.first >= 23)
			{
				if (BackRef.LPrefixCode.first == 0)
				{
					BlockType = std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

					ReadHeader = true;

					std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

					if (EOS) return ARCHIVE_ERROR_EMPTY_STREAM;

				}

				if (DecodeLiteralLength() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Decoder failure." };

				return;

			}
			else if (BackRef.LPrefixCode.first >= 96 && BackRef.LPrefixCode.first >= 99)
			{
				Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | 0 :
					BackRef.LPrefixCode.first = (BackRef.LPrefixCode.first << 1) | static_cast<uint8_t>(32768);

				if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

				if (DecodeLiteralLength() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Decoder failure." };

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodeLiteralLength()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		uint16_t Prefix{ 0 };

		if (BackRef.LPrefixCode.first >= 192 && BackRef.LPrefixCode.first <= 199)
		{
			Prefix = BackRef.LPrefixCode.first - 192 + 280;

		}
		else
		{
			Prefix = BackRef.LPrefixCode.first + 257;

		}

		BackRef.Length = PrefixCodeBits.at(Prefix);

		uint8_t Offset{ 0 };

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

	ARCHIVE_ERROR CHV4DDECODER::DecodeLiteralLength()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		for (BackRef.DPrefixCode.second = 0; BackRef.DPrefixCode.second < 5; ++BackRef.DPrefixCode.second)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				BackRef.DPrefixCode.first = (BackRef.DPrefixCode.first << 1) | 0 :
				BackRef.DPrefixCode.first = (BackRef.DPrefixCode.first << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		}

		BackRef.Distance = DistanceCodeBits.at(BackRef.DPrefixCode.first);

		uint8_t Offset{ 0 };

		for (; BackRef.Distance.second > 0; --BackRef.Distance.second)
		{
			Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
				Offset = (Offset << 1) | 0 :
				Offset = (Offset << 1) | static_cast<uint8_t>(32768);

			if (FetchStream() != ARCHIVE_ERROR_CONSUME_STREAM) throw std::runtime_error{ "Stream overrun." };

		}

		BackRef.Distance.first = BackRef.Distance.first + Offset;

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::PushFromDictionary()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;




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

		std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;

	}

}