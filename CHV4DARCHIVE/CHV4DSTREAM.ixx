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
	class CHV4DSTREAM
	{
	public:
		CHV4DSTREAM() = default;

	public:
		ARCHIVE_ERROR DeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO);

		DEFLATE_COMPRESSION DeflateCompression();

		ARCHIVE_ERROR szWindow(size_t sz = 32768);

		size_t szWindow();

		ARCHIVE_ERROR SharedBlock(std::shared_ptr<std::vector<unsigned char>> block = nullptr);

		std::shared_ptr<std::vector<unsigned char>> SharedBlock();

	private:
		DEFLATE_COMPRESSION Method = DEFLATE_COMPRESSION_NO;

		size_t WindowSize{ 32768 };

		std::shared_ptr<std::vector<unsigned char>> Block = nullptr;

	public:
		ARCHIVE_ERROR EmptyStream();

		std::vector<unsigned char>::const_iterator RefBlockSentinel();

		std::vector<unsigned char>::const_iterator RefLiteralSentinel();

		std::list<std::vector<unsigned char>::const_iterator> RefIndex();

		std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> RefBitStream();

	private:
		std::vector<unsigned char>::const_iterator BlockSentinel{};

		std::vector<unsigned char>::const_iterator LiteralSentinel{};

		std::list<std::vector<unsigned char>::const_iterator> Index{};

		std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> BitStream = nullptr;

		std::list<unsigned char> Window{};

	};

}