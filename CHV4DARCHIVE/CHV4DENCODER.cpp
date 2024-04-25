module;

#include <string>

#include <functional>
#include <memory>

#include <deque>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

namespace CHV4DARCHIVE
{
	CHV4DENCODER::CHV4DENCODER()
	{
		LengthPrefixBucket.insert({ 0, {0, 0} });
		LengthPrefixBucket.insert({ 2, {1, 0} });
		LengthPrefixBucket.insert({ 3, {257, 0} });
		LengthPrefixBucket.insert({ 4, {258, 0} });
		LengthPrefixBucket.insert({ 5, {259, 0} });
		LengthPrefixBucket.insert({ 6, {260, 0} });
		LengthPrefixBucket.insert({ 7, {261, 0} });
		LengthPrefixBucket.insert({ 8, {262, 0} });
		LengthPrefixBucket.insert({ 9, {263, 0} });
		LengthPrefixBucket.insert({ 10, {264, 0} });
		LengthPrefixBucket.insert({ 12, {265, 1} });
		LengthPrefixBucket.insert({ 14, {266, 1} });
		LengthPrefixBucket.insert({ 16, {267, 1} });
		LengthPrefixBucket.insert({ 18, {268, 1} });
		LengthPrefixBucket.insert({ 22, {269, 2} });
		LengthPrefixBucket.insert({ 26, {270, 2} });
		LengthPrefixBucket.insert({ 30, {271, 2} });
		LengthPrefixBucket.insert({ 34, {272, 2} });
		LengthPrefixBucket.insert({ 42, {273, 3} });
		LengthPrefixBucket.insert({ 50, {274, 3} });
		LengthPrefixBucket.insert({ 58, {275, 3} });
		LengthPrefixBucket.insert({ 66, {276, 3} });
		LengthPrefixBucket.insert({ 82, {277, 4} });
		LengthPrefixBucket.insert({ 98, {278, 4} });
		LengthPrefixBucket.insert({ 114, {279, 4} });
		LengthPrefixBucket.insert({ 130, {280, 4} });
		LengthPrefixBucket.insert({ 162, {281, 5} });
		LengthPrefixBucket.insert({ 194, {282, 5} });
		LengthPrefixBucket.insert({ 226, {283, 5} });
		LengthPrefixBucket.insert({ 257, {284, 5} });
		LengthPrefixBucket.insert({ 258, {285, 0} });

		DistancePrefixBucket.insert({ 1, {0, 0} });
		DistancePrefixBucket.insert({ 2, {1, 0} });
		DistancePrefixBucket.insert({ 3, {2, 0} });
		DistancePrefixBucket.insert({ 4, {3, 0} });
		DistancePrefixBucket.insert({ 6, {4, 1} });
		DistancePrefixBucket.insert({ 8, {5, 1} });
		DistancePrefixBucket.insert({ 12, {6, 2} });
		DistancePrefixBucket.insert({ 16, {7, 2} });
		DistancePrefixBucket.insert({ 24, {8, 3} });
		DistancePrefixBucket.insert({ 32, {9, 3} });
		DistancePrefixBucket.insert({ 48, {10, 4} });
		DistancePrefixBucket.insert({ 64, {11, 4} });
		DistancePrefixBucket.insert({ 96, {12, 5} });
		DistancePrefixBucket.insert({ 128, {13, 5} });
		DistancePrefixBucket.insert({ 192, {14, 6} });
		DistancePrefixBucket.insert({ 256, {15, 6} });
		DistancePrefixBucket.insert({ 384, {16, 7} });
		DistancePrefixBucket.insert({ 512, {17, 7} });
		DistancePrefixBucket.insert({ 768, {18, 8} });
		DistancePrefixBucket.insert({ 1024, {19, 8} });
		DistancePrefixBucket.insert({ 1536, {20, 9} });
		DistancePrefixBucket.insert({ 2048, {21, 9} });
		DistancePrefixBucket.insert({ 3072, {22, 10} });
		DistancePrefixBucket.insert({ 4096, {23, 10} });
		DistancePrefixBucket.insert({ 6144, {24, 11} });
		DistancePrefixBucket.insert({ 8192, {25, 11} });
		DistancePrefixBucket.insert({ 12288, {26, 12} });
		DistancePrefixBucket.insert({ 16384, {27, 12} });
		DistancePrefixBucket.insert({ 24576, {28, 13} });
		DistancePrefixBucket.insert({ 32768, {29, 13} });

	}

	ARCHIVE_ERROR CHV4DENCODER::DeflateStream(BlockSink bsink, size_t const& powWindow)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (powWindow < 8 || powWindow > 15) throw std::out_of_range{ "Window size out of range." };

		if (bsink == nullptr) throw std::invalid_argument{ "No Sink specified." };

		BitStream->ClearStream();

		Stream->clear();

		Sink = bsink;

		do
		{
			error = NewBlock();

			if (error != ARCHIVE_ERROR_END_OF_STREAM)
			{
				do
				{
					if (IndexWindow() != ARCHIVE_ERROR_SUCCEEDED) return error;

					if (LiteralLength() != ARCHIVE_ERROR_SUCCEEDED) return error;

					if (Encode() != ARCHIVE_ERROR_SUCCEEDED) return error;

					if (SlideWindow(std::distance(BlockSentinel, LiteralSentinel)) != ARCHIVE_ERROR_SUCCEEDED) return error;

				} while (BlockSentinel != Block->end());

				uint8_t end = 0;

				BitStream->PushBits(end, 7);

			}

		} while (!FinalBlock);

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DENCODER::NewBlock()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		Block->clear();

		FinalBlock = false;

		if (Sink(Block, FinalBlock) != ARCHIVE_ERROR_SUCCEEDED) return error;

		if (Block->size() == 0) throw std::out_of_range{ "Empty Block." };

		Stream->insert(Stream->end(),
			std::make_move_iterator(Block->begin()),
			std::make_move_iterator(Block->end()));

		BlockSentinel = std::next(Stream->begin(), Stream->size() - Block->size());

		LiteralSentinel = std::next(BlockSentinel, 1);

		Index.clear();

		if (!FinalBlock) *BitStream << CHV4DBITSTREAM::BIT_ZERO;

		else *BitStream << CHV4DBITSTREAM::BIT_ONE;

		if (Method == DEFLATE_COMPRESSION_NO || Block->size() < 258)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			BitStream->ByteAlignNext();

			size_t sz = Block->size();

			unsigned char* ptr = reinterpret_cast<unsigned char*>(&sz);

			BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

			BitStream->PushBits(ptr[7], 8);
			BitStream->PushBits(ptr[6], 8);
			BitStream->PushBits(ptr[5], 8);
			BitStream->PushBits(ptr[4], 8);

			sz = ~sz;

			BitStream->PushBits(ptr[7], 8);
			BitStream->PushBits(ptr[6], 8);
			BitStream->PushBits(ptr[5], 8);
			BitStream->PushBits(ptr[4], 8);

			if (AppendNoCompression() != ARCHIVE_ERROR_SUCCEEDED) return error;

			if (FinalBlock) return ARCHIVE_ERROR_EMPTY_STREAM;

		}
		else if (Method == DEFLATE_COMPRESSION_FIXED)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ONE;

			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		}
		if (Method == DEFLATE_COMPRESSION_DYNAMIC)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			*BitStream << CHV4DBITSTREAM::BIT_ONE;

			throw std::invalid_argument{ "Not supported." };

		}
		else
		{

			throw std::invalid_argument{ "Reserved." };

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::AppendNoCompression()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

		BitStream->InsertBits(BitStream->BitStreamSize(), BlockSentinel, std::distance(BlockSentinel, Stream->cend()) * 8);

		SlideWindow(std::distance(BlockSentinel, Stream->cend()));

		return ARCHIVE_ERROR_END_OF_STREAM;

	}

	ARCHIVE_ERROR CHV4DENCODER::IndexWindow()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		std::deque<unsigned char>::iterator WindowSentinel;

		for (WindowSentinel = Stream->begin(); WindowSentinel != BlockSentinel; ++WindowSentinel)
		{
			if (std::equal(WindowSentinel, std::next(WindowSentinel, 3), BlockSentinel, std::next(BlockSentinel, 3)))
			{
				Index.push_back(WindowSentinel);

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::LiteralLength()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (Index.empty()) return error;

		std::deque<unsigned char> LongestLiteral;

		std::deque<std::deque<unsigned char>::const_iterator>::const_reverse_iterator Literal;

		LongestLiteral.insert(LongestLiteral.end(), *Index.crbegin(), std::next(*Index.crbegin(), 3));

		for (Literal = Index.crbegin(); Index.size() > 1; ++Literal)
		{
			std::deque<unsigned char>::const_iterator citt = *Literal;

			citt = std::next(citt, 3);

			while (*citt == *std::next(BlockSentinel, std::distance(*Literal, citt)) && std::distance(*Literal, citt) <= 258)
			{
				if (std::distance(*Literal, citt) > LongestLiteral.size())
				{
					LongestLiteral.push_back(*citt);

					++citt;

				}

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::Encode()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (Index.size() == 0)
		{
			error = PushLiteral();

			return error;

		}

		error = PushLength(std::distance(BlockSentinel, LiteralSentinel));

		if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

		error = PushDistance(std::distance(Index.front(), BlockSentinel));

		if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::PushLiteral()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		std::deque<unsigned char>::const_iterator Chew;

		for (Chew = BlockSentinel; Chew != Block->end(); ++Chew)
		{
			if (static_cast<uint8_t>(*Chew) < 144)
			{
				BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

				uint8_t PrefixCode;

				PrefixCode = 0b00110000 + *BlockSentinel;

				BitStream->PushBits(PrefixCode, 8);

			}
			else
			{
				BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

				uint16_t PrefixCode;

				PrefixCode = 0b110010000 + *BlockSentinel;

				PrefixCode = PrefixCode << 7;

				BitStream->PushBits(PrefixCode, 9);

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::PushLength(size_t const& len)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (len < 280)
		{
			BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

			uint8_t PrefixCode;

			PrefixCode = 0b00000000 + len;

			PrefixCode = PrefixCode << 1;

			BitStream->PushBits(PrefixCode, 7);

		}
		else
		{
			BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

			uint8_t PrefixCode;

			PrefixCode = 0b11000000 + len;

			BitStream->PushBits(PrefixCode, 8);

		}

		{
			BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

			std::unordered_map<size_t, std::pair<size_t, size_t>>::const_iterator PrefixPoolItt = std::next(LengthPrefixBucket.begin(), 2);

			for (; len >= PrefixPoolItt->first && len < std::next(PrefixPoolItt, 1)->first; ++PrefixPoolItt);

			uint8_t ExtraBits = std::next(PrefixPoolItt, 1)->first - PrefixPoolItt->first;

			BitStream->PushBits(ExtraBits, PrefixPoolItt->second.second);

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::PushDistance(size_t const& dist)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

		std::unordered_map<size_t, std::pair<size_t, size_t>>::const_iterator PrefixPoolItt = DistancePrefixBucket.begin();

		for (; dist >= PrefixPoolItt->first && dist < std::next(PrefixPoolItt, 1)->first; ++PrefixPoolItt);

		uint8_t DistancePrefixCode = std::next(PrefixPoolItt, 1)->first - PrefixPoolItt->first;

		DistancePrefixCode << 3;

		BitStream->PushBits(DistancePrefixCode, 5);

		BitStream->SetBitConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

		uint16_t ExtraBits = static_cast<uint16_t>(dist - PrefixPoolItt->first);

		BitStream->PushBits(ExtraBits, PrefixPoolItt->second.second);

		return error;

	}

	ARCHIVE_ERROR CHV4DENCODER::SlideWindow(size_t const& shift)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (std::distance(BlockSentinel, Block->cend()) < shift) return ARCHIVE_ERROR_OUT_OF_RANGE;

		BlockSentinel = std::next(BlockSentinel, shift);

		LiteralSentinel = std::next(BlockSentinel, 1);

		return error;

	}

}