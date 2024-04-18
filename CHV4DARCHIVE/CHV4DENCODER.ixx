module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;
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
		ZIP_ERROR SetWindowSz(int16_t sz);

		ZIP_ERROR DeflateStream(
			std::function<ZIP_ERROR(std::shared_ptr<std::vector<unsigned char>>, size_t)> bsink,
			std::shared_ptr<std::vector<unsigned char>> dstream);

	private:
		DEFLATE_COMPRESSION CompressionMethodTest();

	private:
		DEFLATE_COMPRESSION Method = DEFLATE_COMPRESSION_NO;

		size_t WindowSz{ 32768 };

		std::shared_ptr<std::vector<unsigned char>> Block;

		std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> BitStream;

		CHV4DARCHIVE::CHV4DENCLZSS LZSS;

		CHV4DARCHIVE::CHV4DENCLL LL;

		CHV4DARCHIVE::CHV4DENCDIST DIST;

		CHV4DARCHIVE::CHV4DENCCL CL;

	};

}