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
		BIT operator ()(bool forward = true);

		BIT operator ()(size_t const& pos, bool forward = true);

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

		void InsertBits(size_t const& pos, std::deque<unsigned char>& insert, size_t const& nbits);

	public:
		void ClearStream();

		size_t BitStreamSize();

		void BeginningOfStream();

		bool FindNextOf(std::deque<BIT> const& find);

		bool ReverseFindNextOf(std::deque<BIT> const& find);

		size_t ForwardSentinelPosition();

		size_t ReverseSentinelPosition();

		void ByteAlignNext();

		std::deque<unsigned char>& GetData();

		std::deque<unsigned char> GetDataView();

		void EndOfStream();

	private:
		bool ValidSentinel();

		bool ValidReverseSentinel();

	private:
		BIT_CONSUMPTION BitConsume{ BIT_CONSUMPTION_LEFT_RIGHT };

		BYTE_CONSUMPTION ByteConsume{ BYTE_CONSUMPTION_LEFT_RIGHT };

		std::deque<unsigned char> Data;

		size_t BitPosition{ 0 };

		std::pair<std::deque<unsigned char>::iterator, size_t> Sentinel;

		bool isValidSentinel;

		std::pair<std::deque<unsigned char>::reverse_iterator, size_t> ReverseSentinel;

		bool isValidReverseSentinel;

	};

}