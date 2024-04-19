module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DSTREAM;

import :CHV4DENCLZSS;
import :CHV4DENCLL;
import :CHV4DENCDIST;
import :CHV4DENCCL;

export namespace CHV4DARCHIVE
{
	class CHV4DENCODER
	{
	public:
		CHV4DENCODER() = default;

	public:
		ARCHIVE_ERROR DeflateStream(
			std::shared_ptr<CHV4DARCHIVE::CHV4DSTREAM> stream = nullptr,
			std::function<ARCHIVE_ERROR()> bsink = nullptr);

	private:
		DEFLATE_COMPRESSION CompressionMethodTest();

	private:
		std::shared_ptr<CHV4DARCHIVE::CHV4DSTREAM> Stream;

		CHV4DARCHIVE::CHV4DENCLZSS LZSS;

		CHV4DARCHIVE::CHV4DENCLL LL;

		CHV4DARCHIVE::CHV4DENCDIST DIST;

		CHV4DARCHIVE::CHV4DENCCL CL;

	};

}