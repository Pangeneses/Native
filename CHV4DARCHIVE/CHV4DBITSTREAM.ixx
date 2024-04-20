module;

#include <string>

#include <vector>
#include <list>

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

		CHV4DBITSTREAM(std::list<unsigned char>::iterator begin, std::list<unsigned char>::iterator end);

	public:
		typedef enum BIT {
			BIT_ZERO = 0,
			BIT_ONE = 1
		} BIT;

		typedef enum BIT_CONSUMPTION {
			BIT_CONSUMPTION_LEFT_RIGHT = 0,
			BIT_CONSUMPTION_RIGHT_LEFT = 1
		} BIT_CONSUMPTION;

		void SetConsumption(BIT_CONSUMPTION const& set) { Consume = set; }

	public:
		BIT operator ++();

		BIT operator --();

		void operator =(CHV4DBITSTREAM const& in);

		void operator <<(BIT in);

	public:
		void PushBits(unsigned char const& data, size_t const& bits);

		void PushBits(uint16_t const& data, size_t const& bits);

		void PushBits(uint32_t const& data, size_t const& bits);

		void PushBits(uint64_t const& data, size_t const& bits);

		void PopFrontBits(size_t const& num);

		void PopBackBits(size_t const& num);

		void BitErase(size_t const& beg, size_t const& end);

		void InsertBits(size_t const& pos, std::vector<unsigned char>::const_iterator citt, size_t const& nbytes);

	public:
		void ClearStream();

		void BeginningOfStream();

		size_t FindNextOf(std::vector<BIT> const& find);

		size_t ReverseFindNextOf(std::vector<BIT> const& find);

		void EndOfStream();

		std::list<unsigned char>& GetData() { return Data; }

		std::vector<unsigned char> GetDataView() { return std::vector<unsigned char>{ Data.begin(), Data.end() }; }

		size_t BitStreamSize() { return (Data.size() * 8) + (BitPosition + 1); }

	private:
		BIT_CONSUMPTION Consume{ BIT_CONSUMPTION_LEFT_RIGHT };

		std::list<unsigned char> Data;

		size_t BitPosition{ 0 };

		std::pair<std::list<unsigned char>::iterator, size_t> Sentinel;

		std::pair<std::list<unsigned char>::reverse_iterator, size_t> ReverseSentinel;

	};

}