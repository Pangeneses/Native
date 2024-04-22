module;

#include <string>

#include <functional>
#include <memory>

#include <vector>
#include <deque>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	typedef std::function<ARCHIVE_ERROR(std::shared_ptr<std::deque<unsigned char>>, bool)> BlockSink;

	class CHV4DSTREAM
	{
	public:
		CHV4DSTREAM() = default;

	public:
		ARCHIVE_ERROR DeflateStream(BlockSink bsink = nullptr, size_t const& powWindow = 15);

		ARCHIVE_ERROR SetDeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO);

		DEFLATE_COMPRESSION GetDeflateCompression();

		ARCHIVE_ERROR NewBlock();

	private:
		DEFLATE_COMPRESSION Method = DEFLATE_COMPRESSION_NO;

		size_t WindowSize{ 32768 };

		bool FinalBlock{ false };

	private:
		ARCHIVE_ERROR AppendNoCompression();

		ARCHIVE_ERROR IndexWindow();

		ARCHIVE_ERROR PushLiteral();

		ARCHIVE_ERROR Encode();

		ARCHIVE_ERROR PushLength(size_t const& len);

		ARCHIVE_ERROR PushDistance(size_t const& dist);

		ARCHIVE_ERROR SlideWindow(size_t const& shift);

	private:
		BlockSink Sink;

		std::shared_ptr<std::deque<unsigned char>> Block;

		std::deque<unsigned char> Stream{};

		std::deque<unsigned char>::const_iterator BlockSentinel{};

		std::deque<unsigned char>::const_iterator LiteralSentinel{};

		std::deque<std::deque<unsigned char>::const_iterator> Index{};

		std::shared_ptr<CHV4DBITSTREAM> BitStream = nullptr;

	};

}