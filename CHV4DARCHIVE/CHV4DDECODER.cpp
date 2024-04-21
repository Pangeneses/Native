module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;
import :CHV4DENCLZSS;
import :CHV4DENCLL;
import :CHV4DENCDIST;
import :CHV4DENCCL;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DDEFLATE::SetWindowSz(int16_t sz)
	{
		if (sz < 256 || sz > 32768) return ARCHIVE_ERROR::ARCHIVE_ERROR_OUT_OF_RANGE;

		WindowSz = sz;

		return ARCHIVE_ERROR::ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DDEFLATE::DeflateStreamMemory(
		std::function<ARCHIVE_ERROR(std::shared_ptr<std::vector<unsigned char>>)> bsink = nullptr,
		std::vector<unsigned char>& dstream)
	{
		ARCHIVE_ERROR ret = ARCHIVE_ERROR::ARCHIVE_ERROR_SUCCEEDED;

		if (!bsink) throw std::invalid_argument{ "Missing sink." };

		while (ret != ARCHIVE_ERROR::ARCHIVE_ERROR_EMPTY_STREAM)
		{
			Block = nullptr;

			ret = bsink(Block);

			LZSS.AppendBlockToStream(Block, BitStream, WindowSz);

		}

		LL;

		DIST;

		CL;


		return ret;

	}

	ARCHIVE_ERROR CHV4DDEFLATE::InflateStreamMemory(
		std::vector<unsigned char>& dstream,
		std::function<ARCHIVE_ERROR(std::shared_ptr<std::vector<unsigned char>>)> bsink)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

}