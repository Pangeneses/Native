module;

#include <string>

#include <functional>
#include <memory>

#include <unordered_map>
#include <vector>
#include <deque>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	typedef std::function<ARCHIVE_ERROR(std::shared_ptr<CHV4DBITSTREAM> BitStream)> BlockSink;

	class CHV4DDECODER
	{
	public:
		CHV4DDECODER();

	public:
		ARCHIVE_ERROR InflateStream(BlockSink bsink = nullptr);

		std::shared_ptr<std::deque<unsigned char>> GetByteStream() { return ByteStream; }

	private:
		std::shared_ptr<CHV4DBITSTREAM> BitStream;

	private:
		ARCHIVE_ERROR NoCompress();

		ARCHIVE_ERROR DecodeLLC();

	private:
		BlockSink Sink = nullptr;

		bool EOS = false;

		std::pair<CHV4DBITSTREAM::BIT, CHV4DBITSTREAM::BIT> BlockType{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		uint16_t LLC = 0;

		std::shared_ptr<std::deque<unsigned char>> ByteStream;

	};

}