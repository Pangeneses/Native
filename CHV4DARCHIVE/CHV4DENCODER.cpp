module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;
import :CHV4DENCLZSS;
import :CHV4DENCLL;
import :CHV4DENCDIST;
import :CHV4DENCCL;

namespace CHV4DARCHIVE
{
	ZIP_ERROR CHV4DENCODER::SetWindowSz(int16_t sz)
	{
		if (sz < 256 || sz > 32768) return ZIP_ERROR::ZIP_ERROR_OUT_OF_RANGE;

		if (sz % 2 != 0) return ZIP_ERROR::ZIP_ERROR_OUT_OF_RANGE;

		WindowSz = sz;

		return ZIP_ERROR::ZIP_ERROR_SUCCEEDED;

	}

	ZIP_ERROR CHV4DENCODER::DeflateStream(
		std::function<ZIP_ERROR(std::shared_ptr<std::vector<unsigned char>>, size_t)> bsink = nullptr,
		std::shared_ptr<std::vector<unsigned char>> dstream)
	{
		ZIP_ERROR error = ZIP_ERROR::ZIP_ERROR_SUCCEEDED;

		if (!bsink) throw std::invalid_argument{ "Missing sink." };

		while (error != ZIP_ERROR::ZIP_ERROR_EMPTY_STREAM)
		{
			Block = nullptr;

			error = bsink(Block, WindowSz);

			if (Block->size() < WindowSz)
			{
				WindowSz = 256;

			}
			else if (Block->size() < 32768)
			{
				WindowSz = 0;

			}

			Method = CompressionMethodTest();

			if (Method == 0)
			{
				LZSS.AppendBlockToStream(Block, BitStream, 65535, DEFLATE_COMPRESSION_NO);

			}
			else if (Method == 1)
			{
				LZSS.AppendBlockToStream(Block, BitStream, WindowSz, DEFLATE_COMPRESSION_FIXED);

				LL;

				DIST;

				CL;

			}
			else if (Method == 2)
			{
				LZSS.AppendBlockToStream(Block, BitStream, WindowSz, DEFLATE_COMPRESSION_DYNAMIC);

				LL;

				DIST;

				CL;

			}
			else if (Method == 3)
			{
				throw std::invalid_argument{ "Reserved." };

			}

		}

		return error;

	}

	DEFLATE_COMPRESSION CHV4DENCODER::CompressionMethodTest()
	{
		DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO;

		if (Block->size() < 256)
		{
			return method;

		}

		if (Block->size() >= 65535)
		{


		}


		return method;

	}

}