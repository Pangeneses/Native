module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

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

		Window.clear();

		while (bsink(Block, FinalBlock) != ARCHIVE_ERROR_EMPTY_STREAM)
		{
			BlockSentinel = Block->begin();

			LiteralSentinel = std::next(Block->begin(), 1);

			Index.clear();

			if (FinalBlock && Block->size() <= 256)
			{
				error = AppendNoCompression();

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

			}

			if (Method == DEFLATE_COMPRESSION_NO)
			{
				error = AppendNoCompression();

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

			}
			else if (Method == DEFLATE_COMPRESSION_FIXED)
			{
				error = IndexWindow();

				if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				if (Index.size() == 0)
				{
					BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

					*BitStream << CHV4DBITSTREAM::BIT_ZERO;

					BitStream->InsertBits(BitStream->BitStreamSize(), BlockSentinel, 16);

				}
				else
				{
					error = CodePair();

					if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

				}

			}
			else if (Method == DEFLATE_COMPRESSION_DYNAMIC)
			{


			}
			else
			{

				throw std::invalid_argument{ "Reserved." };

			}

		}

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
		BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_RIGHT_LEFT);

		if(!FinalBlock) *BitStream << CHV4DBITSTREAM::BIT_ZERO;

		else *BitStream << CHV4DBITSTREAM::BIT_ONE;

		*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		BitStream->InsertBits(BitStream->BitStreamSize(), Block->begin(), Block->size() * 8);

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::IndexWindow()
	{

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::CodePair()
	{

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::SlideWindow(size_t const& shift)
	{

		return ARCHIVE_ERROR_SUCCEEDED;

	}

}