module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	typedef std::function<ARCHIVE_ERROR(std::shared_ptr<std::vector<unsigned char>>, bool)> BlockSink;

	class CHV4DSTREAM
	{
	public:
		CHV4DSTREAM() = default;

	public:
		ARCHIVE_ERROR DeflateStream(BlockSink bsink = nullptr);

		ARCHIVE_ERROR SetDeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO);

		DEFLATE_COMPRESSION GetDeflateCompression();

		ARCHIVE_ERROR SetSizeWindow(size_t sz = 32768);

		size_t GetSizeWindow();

	private:
		DEFLATE_COMPRESSION Method = DEFLATE_COMPRESSION_NO;

		size_t WindowSize{ 32768 };

		std::shared_ptr<std::vector<unsigned char>> Block = nullptr;

		bool FinalBlock{ false };

		//CHV4DENCLL LL;
		//
		//CHV4DENCDIST DIST;
		//
		//CHV4DENCCL CL;

	private:
		ARCHIVE_ERROR AppendNoCompression();

		ARCHIVE_ERROR IndexWindow();

		ARCHIVE_ERROR CodePair();

		ARCHIVE_ERROR SlideWindow(size_t const& shift);

	private:
		std::vector<unsigned char>::const_iterator BlockSentinel{};

		std::vector<unsigned char>::const_iterator LiteralSentinel{};

		std::list<std::list<unsigned char>::iterator> Index{};

		std::shared_ptr<CHV4DBITSTREAM> BitStream = nullptr;

		std::list<unsigned char> Window{};

	};

}