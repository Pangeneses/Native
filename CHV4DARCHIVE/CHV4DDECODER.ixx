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

	typedef struct LLC {
		std::pair<uint16_t, uint8_t> LPrefixCode;
		std::pair<uint16_t, uint8_t> Length;
		std::pair<uint16_t, uint8_t> DPrefixCode;
		std::pair<uint16_t, uint8_t> Distance;
	}LLC;

	class CHV4DDECODER
	{
	public:
		CHV4DDECODER();

	public:
		ARCHIVE_ERROR InflateStream(BlockSink bsink = nullptr);

		std::shared_ptr<std::deque<unsigned char>> GetByteStream() { return ByteStream; }

	private:
		ARCHIVE_ERROR Header();

		ARCHIVE_ERROR NoCompress();

		ARCHIVE_ERROR DecodeLLC();

	private:
		std::shared_ptr<CHV4DBITSTREAM> Segment;

		bool ReadHeader = true;

		std::pair<CHV4DBITSTREAM::BIT, CHV4DBITSTREAM::BIT> BlockType{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		std::pair<uint16_t, size_t> ZeroZeroBlock;

		std::pair<uint16_t, size_t> NotZeroZeroBlock;

		LLC BackRef;

		std::shared_ptr<std::deque<unsigned char>> ByteStream;

		bool EOS{ false };

	private:
		void NewStream();

	};

}