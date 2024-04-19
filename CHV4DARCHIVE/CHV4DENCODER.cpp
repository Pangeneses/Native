module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DENCLZSS;
import :CHV4DENCLL;
import :CHV4DENCDIST;
import :CHV4DENCCL;

import :CHV4DBITSTREAM;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DENCODER::DeflateStream(
		std::shared_ptr<CHV4DARCHIVE::CHV4DSTREAM> stream = nullptr,
		std::function<ARCHIVE_ERROR()> sink = nullptr)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR::ARCHIVE_ERROR_SUCCEEDED;

		if (!stream) throw std::invalid_argument{ "Missing Stream." };

		if (!sink) throw std::invalid_argument{ "Missing sink." };

		Stream.reset(stream.get());

		while (error != ARCHIVE_ERROR::ARCHIVE_ERROR_EMPTY_STREAM)
		{
			error = sink();

			if (Stream->SharedBlock()->size() < Stream->szWindow())
			{
				Stream->szWindow(256);

			}
			else if (Stream->SharedBlock()->size() < 32768)
			{
				Stream->szWindow(0);

			}

			Stream->DeflateCompression(CompressionMethodTest());

			if (Stream->DeflateCompression() == DEFLATE_COMPRESSION_NO)
			{
				LZSS.AppendBlockToStream(Stream);

			}
			else if (Stream->DeflateCompression() == DEFLATE_COMPRESSION_FIXED)
			{
				LZSS.AppendBlockToStream(Stream);

				LL;

				DIST;

				CL;

			}
			else if (Stream->DeflateCompression() == DEFLATE_COMPRESSION_DYNAMIC)
			{
				LZSS.AppendBlockToStream(Stream);

				LL;

				DIST;

				CL;

			}
			else
			{
				throw std::invalid_argument{ "Reserved." };

			}

		}

		return error;

	}

	DEFLATE_COMPRESSION CHV4DENCODER::CompressionMethodTest()
	{
		DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO;

		if (Stream->SharedBlock()->size() < 256)
		{
			return method;

		}

		if (Stream->SharedBlock()->size() >= 65535)
		{


		}


		return method;

	}

}