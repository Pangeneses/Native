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

	typedef std::unordered_map<uint16_t, std::pair<uint16_t, size_t>> PrefixBucket;

	typedef struct LLC {
		std::pair<uint16_t, size_t> LPrefixCode;
		std::pair<uint16_t, size_t> Length;
		std::pair<uint16_t, size_t> DPrefixCode;
		std::pair<uint16_t, size_t> Distance;
	}LLC;

	class CHV4DDECODER
	{
	public:
		CHV4DDECODER();

	public:
		ARCHIVE_ERROR InflateStream(BlockSink bsink = nullptr);

		std::shared_ptr<std::deque<unsigned char>> GetByteStream() { return ByteStream; }

	private:
		ARCHIVE_ERROR FetchStream();

		ARCHIVE_ERROR Header();

		ARCHIVE_ERROR NoCompress();

		ARCHIVE_ERROR DecodePrefix();

		ARCHIVE_ERROR DecodeLiteralLength();

		ARCHIVE_ERROR PushFromDictionary();

	private:
		BlockSink Sink;

		std::shared_ptr<CHV4DBITSTREAM> Segment;

		bool ReadHeader = true;

		std::pair<CHV4DBITSTREAM::BIT, CHV4DBITSTREAM::BIT> BlockType{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		std::pair<uint16_t, size_t> ZeroZeroBlock;

		std::pair<uint16_t, size_t> NotZeroZeroBlock;

		LLC BackRef;

		std::shared_ptr<std::deque<unsigned char>> ByteStream;

		bool EOS{ false };

	private:
		void InitPrefixCodeBits();

		void InitDistanceCodeBits();

		void NewStream(BlockSink bsink);

	private:
		PrefixBucket PrefixCodeBits;

		PrefixBucket DistanceCodeBits;

	};

}