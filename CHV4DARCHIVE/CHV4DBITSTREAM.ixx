module;

#include <string>

#include <deque>

export module CHV4DARCHIVE:CHV4DBITSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import CHV4DTENSOR;

export namespace CHV4DARCHIVE
{
	class CHV4DBITSTREAM
	{
	public:
		CHV4DBITSTREAM();

		CHV4DBITSTREAM(std::deque<unsigned char>::iterator begin, std::deque<unsigned char>::iterator end);

	public:
		typedef enum BIT {
			BIT_ZERO = 0,
			BIT_ONE = 1
		} BIT;

		typedef enum BIT_CONSUMPTION {
			BIT_CONSUMPTION_LEFT_RIGHT = 0,
			BIT_CONSUMPTION_RIGHT_LEFT = 1
		} BIT_CONSUMPTION;

		void SetBitConsumption(BIT_CONSUMPTION const& set) { BitConsume = set; }

		typedef enum BYTE_CONSUMPTION {
			BYTE_CONSUMPTION_LEFT_RIGHT = 0,
			BYTE_CONSUMPTION_RIGHT_LEFT = 1
		} BYTE_CONSUMPTION;

		void SetByteConsumption(BYTE_CONSUMPTION const& set) { ByteConsume = set; }

	public:
		BIT operator ()();

		BIT operator ++();

		BIT operator --();

		void operator =(CHV4DBITSTREAM const& in);

		void operator <<(BIT in);

	public:
		void PushBits(unsigned char const& data, size_t const& bits);

		void PushBits(uint16_t const& data, size_t const& bits);

		void PushBits(uint32_t const& data, size_t const& bits);

		void PushBits(uint64_t const& data, size_t const& bits);

		void PushBytes(uint16_t const& data);

		void PushBytes(uint32_t const& data);

		void PushBytes(uint64_t const& data);

		void PopFrontBits(size_t const& num);

		void PopFrontBytes(size_t const& num);

		void PopBackBits(size_t const& num);

		void PopBackBytes(size_t const& num);

		void BitErase(size_t const& beg, size_t const& end);

		void InsertBits(size_t const& pos, std::deque<unsigned char>::const_iterator citt, size_t const& nbytes);

	public:
		void ClearStream();

		void BeginningOfStream();

		size_t FindNextOf(std::deque<BIT> const& find);

		size_t ReverseFindNextOf(std::deque<BIT> const& find);

		void EndOfStream();

		std::deque<unsigned char>& GetData() { return Data; }

		std::deque<unsigned char> GetDataView() { return std::deque<unsigned char>{ Data.begin(), Data.end() }; }

		size_t BitStreamSize() { return (Data.size() * 8) + (BitPosition + 1); }

		void ByteAlignNext();

		size_t ForwardSentinelPosition() { return ((std::distance(Data.begin(), Sentinel.first) - 1) * 8) + Sentinel.second; }

		size_t ReverseSentinelPosition() { return ((std::distance(Data.rbegin(), ReverseSentinel.first) - 1) * 8) + ReverseSentinel.second; }

	private:
		BIT_CONSUMPTION BitConsume{ BIT_CONSUMPTION_LEFT_RIGHT };

		BYTE_CONSUMPTION ByteConsume{ BYTE_CONSUMPTION_LEFT_RIGHT };

		std::deque<unsigned char> Data;

		size_t BitPosition{ 0 };

		std::pair<std::deque<unsigned char>::iterator, size_t> Sentinel;

		std::pair<std::deque<unsigned char>::reverse_iterator, size_t> ReverseSentinel;

	};

}