module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;
import :CHV4DENCLZSS;

export namespace CHV4DARCHIVE
{
	class CHV4DDEFLATE
	{
	public:
		CHV4DDEFLATE() = default;

	public:
		ARCHIVE_ERROR SetWindowSz(int16_t sz);

		ARCHIVE_ERROR DeflateStreamMemory(
			std::function<ARCHIVE_ERROR(std::shared_ptr<std::vector<unsigned char>>)> bsink,
			std::vector<unsigned char>& dstream);

		ARCHIVE_ERROR InflateStreamMemory(
			std::vector<unsigned char>& dstream,
			std::function<ARCHIVE_ERROR(std::shared_ptr<std::vector<unsigned char>>)> bsink);

	private:
		size_t WindowSz{ 32768 };

		std::shared_ptr<std::vector<unsigned char>> Block;

		CHV4DARCHIVE::CHV4DBITSTREAM BitStream;

		CHV4DARCHIVE::CHV4DENCLZSS LZSS;

	};

}