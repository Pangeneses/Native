module;

#include <string>

#include <functional>
#include <memory>

#include <deque>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DSTREAM::DeflateStream(BlockSink bsink = nullptr)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->ClearStream();

		Stream.clear();

		std::shared_ptr<std::deque<unsigned char>> Block;

		do
		{
			Block->clear();

			FinalBlock = false;

			error = bsink(Block, FinalBlock);

			if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

			Stream.insert(Stream.end(), 
				std::make_move_iterator(Block->begin()), 
				std::make_move_iterator(Block->end()));

			BlockSentinel = std::next(Stream.begin(), Stream.size() - Block->size());

			LiteralSentinel = std::next(BlockSentinel, 1);

			Index.clear();

			if (FinalBlock && Block->size() < 256) return AppendNoCompression();

			if (Method == DEFLATE_COMPRESSION_NO)
			{
				error = AppendNoCompression();

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				error = SlideWindow(Block->size());

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

			}
			else if (Method == DEFLATE_COMPRESSION_FIXED)
			{
				for (; BlockSentinel != Stream.end(); ++BlockSentinel)
				{
					error = IndexWindow();

					if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

					if (Index.size() == 0)
					{
						BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

						*BitStream << CHV4DBITSTREAM::BIT_ZERO;

						BitStream->InsertBits(BitStream->BitStreamSize(), BlockSentinel, 16);

						error = SlideWindow(2);

						if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

					}
					else
					{
						error = CodePair();

						if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

						error = SlideWindow(std::distance(BlockSentinel, LiteralSentinel));

						if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

					}

				}

			}
			else if (Method == DEFLATE_COMPRESSION_DYNAMIC)
			{
				error = IndexWindow();

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				if (Index.size() == 0)
				{
					BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

					*BitStream << CHV4DBITSTREAM::BIT_ZERO;

					BitStream->InsertBits(BitStream->BitStreamSize(), BlockSentinel, 16);

					error = SlideWindow(2);

					if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				}
				else
				{
					error = CodePair();

					if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

					error = SlideWindow(std::distance(BlockSentinel, LiteralSentinel));

					if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				}

			}
			else
			{

				throw std::invalid_argument{ "Reserved." };

			}

		}
		while(!FinalBlock);

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::SetDeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO)
	{
		Method = method;

		if (Method == DEFLATE_COMPRESSION_RESERVED) throw std::invalid_argument{ "Reserved." };

		else return ARCHIVE_ERROR_SUCCEEDED;

	}

	DEFLATE_COMPRESSION CHV4DSTREAM::GetDeflateCompression()
	{

		return Method;

	}

	ARCHIVE_ERROR CHV4DSTREAM::SetSizeWindow(size_t sz = 32768)
	{
		WindowSize = sz;

		if (WindowSize < 256 || WindowSize > 32768) throw std::invalid_argument{ "Out of Range." };

		else return ARCHIVE_ERROR_SUCCEEDED;

	}

	size_t CHV4DSTREAM::GetSizeWindow()
	{

		return WindowSize;

	}

	ARCHIVE_ERROR CHV4DSTREAM::AppendNoCompression()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

		if(!FinalBlock) *BitStream << CHV4DBITSTREAM::BIT_ZERO;

		else *BitStream << CHV4DBITSTREAM::BIT_ONE;

		*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		std::deque<unsigned char>::const_iterator end = Stream.end();

		BitStream->InsertBits(
			BitStream->BitStreamSize(), 
			BlockSentinel, 
			std::distance(BlockSentinel, end) * 8);

		error = SlideWindow(std::distance(BlockSentinel, end));

		if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::IndexWindow()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		std::deque<unsigned char>::iterator WindowSentinel;

		for (WindowSentinel = Stream.begin(); WindowSentinel != BlockSentinel; ++WindowSentinel)
		{
			if (*WindowSentinel == *BlockSentinel && *std::next(WindowSentinel, 1) == *LiteralSentinel)
			{
				Index.push_back(WindowSentinel);

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::CodePair()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;





		return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::SlideWindow(size_t const& shift)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		return error;

	}

}