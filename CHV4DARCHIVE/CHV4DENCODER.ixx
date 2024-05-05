module;

#include <string>

#include <functional>
#include <memory>

#include <unordered_map>
#include <vector>
#include <deque>

#include <stdexcept> 

export module CHV4DARCHIVE:CHV4DENCODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	typedef std::function<ARCHIVE_ERROR(std::shared_ptr<std::deque<unsigned char>>)> BlockSink;

	typedef std::unordered_map<size_t, std::pair<size_t, size_t>> PrefixBucket;

	class CHV4DENCODER
	{
	public:
		CHV4DENCODER();

	public:
		ARCHIVE_ERROR DeflateStream(BlockSink bsink = nullptr, size_t const& powWindow = 15);

		std::shared_ptr<std::deque<unsigned char>> GetStream();

		void SetDeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO);

		DEFLATE_COMPRESSION GetDeflateCompression();

	private:
		DEFLATE_COMPRESSION Method = DEFLATE_COMPRESSION_NO;

		size_t WindowSize{ 32768 };

		bool FinalBlock{ false };

	private:
		ARCHIVE_ERROR ResetEncoder();

		ARCHIVE_ERROR NewBlock();

		ARCHIVE_ERROR AppendNoCompression();

		ARCHIVE_ERROR IndexWindow();

		ARCHIVE_ERROR LiteralLength();

		ARCHIVE_ERROR PushLiteral();

		ARCHIVE_ERROR Encode();

		ARCHIVE_ERROR PushLength(uint16_t const& len);

		ARCHIVE_ERROR PushDistance(uint16_t const& dist);

		ARCHIVE_ERROR SlideWindow(uint16_t const& shift);

	private:
		BlockSink Sink;

		std::shared_ptr<std::deque<unsigned char>> Block;

		std::shared_ptr<std::deque<unsigned char>> Stream{};

		std::deque<unsigned char>::const_iterator BlockSentinel{};

		std::deque<unsigned char>::const_iterator LiteralSentinel{};

		std::deque<std::deque<unsigned char>::const_iterator> Index{};

		std::shared_ptr<CHV4DBITSTREAM> BitStream = nullptr;

	private:
		void InitLengthPrefixBucket();

		void InitDistancePrefixBucket();

	private:
		PrefixBucket LengthPrefixBucket;

		PrefixBucket DistancePrefixBucket; 


	};

}