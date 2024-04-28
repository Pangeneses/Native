module;

#include <string>

#include <deque>

#include <stdexcept>

module CHV4DARCHIVE:CHV4DBITSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import CHV4DTENSOR;

namespace CHV4DARCHIVE
{
	CHV4DBITSTREAM::CHV4DBITSTREAM()
	{
		Data.clear();

		Data.push_back({});

		Sentinel.first = Data.begin();

		Sentinel.second = 0;

		ReverseSentinel.first = Data.rbegin();

		ReverseSentinel.second = 0;

		BitPosition = 0;

		BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

		ByteConsume = BYTE_CONSUMPTION_LEFT_RIGHT;

	}

	CHV4DBITSTREAM::CHV4DBITSTREAM(std::deque<unsigned char>::iterator begin, std::deque<unsigned char>::iterator end)
	{
		Data.clear();

		std::move(begin, end, Data.begin());

		Sentinel.first = Data.begin();

		Sentinel.second = 0;

		ReverseSentinel.first = Data.rbegin();

		ReverseSentinel.second = 0;

		BitPosition = 0;

		BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

		ByteConsume = BYTE_CONSUMPTION_LEFT_RIGHT;

	}

	CHV4DBITSTREAM::BIT CHV4DBITSTREAM::operator ()()
	{
		if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

		switch (Sentinel.second)
		{

		case 0: return (*Sentinel.first & 0b10000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 1: return (*Sentinel.first & 0b01000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 2: return (*Sentinel.first & 0b00100000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 3: return (*Sentinel.first & 0b00010000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 4: return (*Sentinel.first & 0b00001000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 5: return (*Sentinel.first & 0b00000100) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 6: return (*Sentinel.first & 0b00000010) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 7: return (*Sentinel.first & 0b00000001) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		
		default: throw std::out_of_range{ "BitStream overrun." };
		
		}

	}

	CHV4DBITSTREAM::BIT CHV4DBITSTREAM::operator ++()
	{
		if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

		int64_t Distance = std::distance(Sentinel.first, Data.end());

		size_t AbsoluteDistance{ 0 };

		if (Distance > 0) AbsoluteDistance = static_cast<size_t>(std::distance(Sentinel.first, Data.end()));

		else throw std::out_of_range{ "BitStream overrun error." };

		if (AbsoluteDistance == 1 && Sentinel.second == 7) std::out_of_range{ "End of bitstream." };

		else ++Sentinel.second;

		if (Sentinel.second == 8) { Sentinel.second = 0; std::next(Sentinel.first, 1); }

		switch (Sentinel.second)
		{

		case 0: return (*Sentinel.first & 0b10000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 1: return (*Sentinel.first & 0b01000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 2: return (*Sentinel.first & 0b00100000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 3: return (*Sentinel.first & 0b00010000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 4: return (*Sentinel.first & 0b00001000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 5: return (*Sentinel.first & 0b00000100) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 6: return (*Sentinel.first & 0b00000010) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 7: return (*Sentinel.first & 0b00000001) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;

		default: throw std::out_of_range{ "BitStream overrun." };

		}

	}

	CHV4DBITSTREAM::BIT CHV4DBITSTREAM::operator --()
	{
		if (Sentinel.first == Data.begin() && Sentinel.second == 0) std::out_of_range{ "End of bitstream." };

		if (Sentinel.second == 0) { Sentinel.second = 7; std::next(Sentinel.first, -1); }

		else --Sentinel.second;

		switch (Sentinel.second)
		{

		case 0: return (*Sentinel.first & 0b10000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 1: return (*Sentinel.first & 0b01000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 2: return (*Sentinel.first & 0b00100000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 3: return (*Sentinel.first & 0b00010000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 4: return (*Sentinel.first & 0b00001000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 5: return (*Sentinel.first & 0b00000100) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 6: return (*Sentinel.first & 0b00000010) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
		case 7: return (*Sentinel.first & 0b00000001) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;

		default: throw std::out_of_range{ "BitStream overrun." };

		}

	}

	void CHV4DBITSTREAM::operator =(CHV4DBITSTREAM const& in)
	{
		Data.clear();

		Data.insert(Data.begin(), std::move_iterator(in.Data.begin()), std::move_iterator(in.Data.end()));

	}

	void CHV4DBITSTREAM::operator <<(BIT in)
	{
		if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

		else ++BitPosition;

		switch (BitPosition)
		{

		case 0: if(in == BIT_ONE) Data.back() | 0b10000000; break;
		case 1: if(in == BIT_ONE) Data.back() | 0b01000000; break;
		case 2: if(in == BIT_ONE) Data.back() | 0b00100000; break;
		case 3: if(in == BIT_ONE) Data.back() | 0b00010000; break;
		case 4: if(in == BIT_ONE) Data.back() | 0b00001000; break;
		case 5: if(in == BIT_ONE) Data.back() | 0b00000100; break;
		case 6: if(in == BIT_ONE) Data.back() | 0b00000010; break;
		case 7: if(in == BIT_ONE) Data.back() | 0b00000001; break;

		default: throw std::runtime_error{ "BitStream overrun." }; break;

		}

	}

	void CHV4DBITSTREAM::PushBits(unsigned char const& data, size_t const& bits)
	{
		CHV4DBITSTREAM::BIT bitset[8];

		if (bits < 1 || bits > 8) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

		(0b10000000 & data) == 0b10000000 ? bitset[0] = BIT_ONE : bitset[0] = BIT_ZERO;
		(0b01000000 & data) == 0b01000000 ? bitset[1] = BIT_ONE : bitset[1] = BIT_ZERO;
		(0b00100000 & data) == 0b00100000 ? bitset[2] = BIT_ONE : bitset[2] = BIT_ZERO;
		(0b00010000 & data) == 0b00010000 ? bitset[3] = BIT_ONE : bitset[3] = BIT_ZERO;
		(0b00001000 & data) == 0b00001000 ? bitset[4] = BIT_ONE : bitset[4] = BIT_ZERO;
		(0b00000100 & data) == 0b00000100 ? bitset[5] = BIT_ONE : bitset[5] = BIT_ZERO;
		(0b00000010 & data) == 0b00000010 ? bitset[6] = BIT_ONE : bitset[6] = BIT_ZERO;
		(0b00000001 & data) == 0b00000001 ? bitset[7] = BIT_ONE : bitset[7] = BIT_ZERO;

		if (BitConsume == BIT_CONSUMPTION_LEFT_RIGHT)
		{
			for (size_t i = 0; i < bits; ++i)
			{
				if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

				*this << (bitset[i]);

			}

		}
		else
		{
			for (size_t i = 7; i >= 0; --i)
			{
				if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

				*this << (bitset[i]);

			}

		}

	}

	void CHV4DBITSTREAM::PushBits(uint16_t const& data, size_t const& bits)
	{
		if (bits < 1 || bits > 16) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

		uint16_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			bits < 8 ? PushBits(buffer[0], bits) : PushBits(buffer[0], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[1], 8 - (16 - bits)) : PushBits(buffer[1], 8);

		}
		else
		{
			bits < 8 ? PushBits(buffer[1], bits) : PushBits(buffer[1], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[0], 8 - (16 - bits)) : PushBits(buffer[0], 8);

		}

		return;

	}

	void CHV4DBITSTREAM::PushBits(uint32_t const& data, size_t const& bits)
	{
		if (bits < 1 || bits > 32) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

		uint16_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			bits < 8 ? PushBits(buffer[0], bits) : PushBits(buffer[0], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[1], 8 - (16 - bits)) : PushBits(buffer[1], 8);
			bits > 16 && bits < 24 ? PushBits(buffer[2], 8 - (24 - bits)) : PushBits(buffer[2], 8);
			bits > 24 && bits < 32 ? PushBits(buffer[3], 8 - (32 - bits)) : PushBits(buffer[3], 8);

		}
		else
		{
			bits < 8 ? PushBits(buffer[3], bits) : PushBits(buffer[3], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[2], 8 - (16 - bits)) : PushBits(buffer[2], 8);
			bits > 16 && bits < 24 ? PushBits(buffer[1], 8 - (24 - bits)) : PushBits(buffer[1], 8);
			bits > 24 && bits < 32 ? PushBits(buffer[0], 8 - (32 - bits)) : PushBits(buffer[0], 8);

		}

		return;

	}

	void CHV4DBITSTREAM::PushBits(uint64_t const& data, size_t const& bits)
	{
		if (bits < 1 || bits > 64) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

		uint16_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			bits < 8 ? PushBits(buffer[0], bits) : PushBits(buffer[0], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[1], 8 - (16 - bits)) : PushBits(buffer[1], 8);
			bits > 16 && bits < 24 ? PushBits(buffer[2], 8 - (24 - bits)) : PushBits(buffer[2], 8);
			bits > 24 && bits < 32 ? PushBits(buffer[3], 8 - (32 - bits)) : PushBits(buffer[3], 8);
			bits > 32 && bits < 40 ? PushBits(buffer[4], 8 - (40 - bits)) : PushBits(buffer[4], 8);
			bits > 40 && bits < 48 ? PushBits(buffer[5], 8 - (48 - bits)) : PushBits(buffer[5], 8);
			bits > 48 && bits < 56 ? PushBits(buffer[6], 8 - (56 - bits)) : PushBits(buffer[6], 8);
			bits > 56 && bits < 64 ? PushBits(buffer[7], 8 - (64 - bits)) : PushBits(buffer[7], 8);

		}
		else
		{
			bits < 8 ? PushBits(buffer[7], bits) : PushBits(buffer[7], 8);
			bits > 8 && bits < 16 ? PushBits(buffer[6], 8 - (16 - bits)) : PushBits(buffer[6], 8);
			bits > 16 && bits < 24 ? PushBits(buffer[5], 8 - (24 - bits)) : PushBits(buffer[5], 8);
			bits > 24 && bits < 32 ? PushBits(buffer[4], 8 - (32 - bits)) : PushBits(buffer[4], 8);
			bits > 32 && bits < 40 ? PushBits(buffer[3], 8 - (40 - bits)) : PushBits(buffer[3], 8);
			bits > 40 && bits < 48 ? PushBits(buffer[2], 8 - (48 - bits)) : PushBits(buffer[2], 8);
			bits > 48 && bits < 56 ? PushBits(buffer[1], 8 - (56 - bits)) : PushBits(buffer[1], 8);
			bits > 56 && bits < 64 ? PushBits(buffer[0], 8 - (64 - bits)) : PushBits(buffer[0], 8);

		}

		return;

	}

	void CHV4DBITSTREAM::PushBytes(uint16_t const& data)
	{
		uint64_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			PushBits(buffer[0], 8);
			PushBits(buffer[1], 8);

		}
		else
		{
			PushBits(buffer[1], 8);
			PushBits(buffer[0], 8);

		}

	}

	void CHV4DBITSTREAM::PushBytes(uint32_t const& data)
	{
		uint64_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			PushBits(buffer[0], 8);
			PushBits(buffer[1], 8);
			PushBits(buffer[2], 8);
			PushBits(buffer[3], 8);

		}
		else
		{
			PushBits(buffer[3], 8);
			PushBits(buffer[2], 8);
			PushBits(buffer[1], 8);
			PushBits(buffer[0], 8);

		}

	}

	void CHV4DBITSTREAM::PushBytes(uint64_t const& data)
	{
		uint64_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (ByteConsume == BYTE_CONSUMPTION_LEFT_RIGHT)
		{
			PushBits(buffer[0], 8);
			PushBits(buffer[1], 8);
			PushBits(buffer[2], 8);
			PushBits(buffer[3], 8);
			PushBits(buffer[4], 8);
			PushBits(buffer[5], 8);
			PushBits(buffer[6], 8);
			PushBits(buffer[7], 8);

		}
		else
		{
			PushBits(buffer[7], 8);
			PushBits(buffer[6], 8);
			PushBits(buffer[5], 8);
			PushBits(buffer[4], 8);
			PushBits(buffer[3], 8);
			PushBits(buffer[2], 8);
			PushBits(buffer[1], 8);
			PushBits(buffer[0], 8);

		}

	}

	void CHV4DBITSTREAM::PopFrontBits(size_t const& num)
	{
		if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (num > this->BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		CHV4DBITSTREAM Buffer;

		BitPosition = num % 8;

		if ((num - BitPosition) / 8 > 0) Data.erase(Data.begin(), std::next(Data.begin(), (num - BitPosition) / 8));

		EndOfStream(); ReverseSentinelPosition();

		while (!(Sentinel.first == Data.end() && Sentinel.second == 7)) Buffer << operator++();

		this->operator=(Buffer);

	}

	void CHV4DBITSTREAM::PopFrontBytes(size_t const& num)
	{
		if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (num > Data.size()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		Data.erase(Data.begin(), std::next(Data.begin(), num));

	}

	void CHV4DBITSTREAM::PopBackBits(size_t const& num)
	{
		if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (num > this->BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		BitPosition = 8 - (num % 8);

		Data.erase(std::next(Data.end(), -(num - (num % 8)) / 8), Data.end());

	}

	void CHV4DBITSTREAM::PopBackBytes(size_t const& num)
	{
		if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (num > Data.size()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		Data.erase(std::prev(Data.end(), num), Data.end());

	}

	void CHV4DBITSTREAM::BitErase(size_t const& beg, size_t const& end)
	{
		if (beg < 0 || beg >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (end < 0 || end >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (beg >= end) throw std::out_of_range{ "Invalid range." };

		CHV4DBITSTREAM Buffer;

		this->BeginningOfStream();

		while ((std::distance(Data.begin(), Sentinel.first) + Sentinel.second) != beg) Buffer << (operator++());

		Sentinel.first = std::next(Data.begin(), (end - (end % 8)) / 8);

		Sentinel.second = end % 8;

		ReverseSentinelPosition();

		while (!(Sentinel.first == std::next(Data.end(), -1) && Sentinel.second == 7)) Buffer << (operator++());

		this->operator=(Buffer);

		return;

	}

	void CHV4DBITSTREAM::InsertBits(size_t const& pos, std::deque<unsigned char>::const_iterator citt, size_t const& nbits)
	{
		if (pos < 0 || pos >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		CHV4DBITSTREAM Front;

		if (pos > BitStreamSize())
		{
			size_t FrontBytes = ((pos - (pos % 8)) / 8);

		}

		


		
		{ Data.begin(), std::next(Data.begin(), FrontBytes) };



		return;

	}

	void CHV4DBITSTREAM::ClearStream()
	{
		BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

		Data.clear();

		BitPosition = 0;

		Sentinel = { Data.begin(), 0 };

		ReverseSentinel = { Data.rbegin(), 0 };

	}

	size_t CHV4DBITSTREAM::BitStreamSize()
	{

		return (Data.size() * 8) + (BitPosition + 1);

	}

	void CHV4DBITSTREAM::BeginningOfStream()
	{
		Sentinel.first = Data.begin();

		Sentinel.second = 0;

	}

	int CHV4DBITSTREAM::FindNextOf(std::deque<BIT> const& find)
	{
		if (find.size() > (Data.size() * 8 + BitPosition)) return -1;

		bool Match{ true };

		std::deque<BIT>::const_iterator citt;

		while (Sentinel.first != Data.end())
		{
			size_t ByteIndex = std::distance(Data.begin(), Sentinel.first);
			
			size_t BitIndex = Sentinel.second;

			for (citt = find.begin(); citt != find.end(); ++citt)
			{
				if (*citt != this->operator++()) { Match = false; break; }

				++Sentinel.second;

				if (Sentinel.second == 8)
				{
					Sentinel.second = 0;

					++Sentinel.first;

				}

			}

			if (!Match)
			{
				++Sentinel.second;

				if (Sentinel.second == 8)
				{
					Sentinel.second = 0;

					++Sentinel.first;

				}

			}
			else
			{
				return static_cast<int>(ByteIndex * 8 + BitIndex);

			}

		}

		return -1;

	}

	int CHV4DBITSTREAM::ReverseFindNextOf(std::deque<BIT> const& find)
	{
		if (find.size() > (Data.size() * 8 + BitPosition)) return -1;

		if (std::distance(Data.rbegin(), ReverseSentinel.first) >= 0)
		{
			while (static_cast<size_t>(std::distance(Data.rbegin(), ReverseSentinel.first)) < (find.size() / 8) - 1) ++ReverseSentinel.first;

		}
		else
		{
			throw std::out_of_range{ "BitStream overrun." };

		}

		bool Match{ true };

		std::deque<BIT>::const_iterator citt;

		while (ReverseSentinel.first != Data.rend())
		{
			size_t ByteIndex = std::distance(Data.rbegin(), ReverseSentinel.first);

			size_t BitIndex = Sentinel.second;

			for (citt = find.begin(); citt != find.end(); ++citt)
			{
				if (*citt != this->operator++()) { Match = false; break; }

				if (ReverseSentinel.second == 0)
				{
					ReverseSentinel.second = 7;

					++ReverseSentinel.first;

				}
				else
				{
					++Sentinel.second;

				}

			}

			if (!Match)
			{
				if (ReverseSentinel.second == 0)
				{
					ReverseSentinel.second = 7;

					++ReverseSentinel.first;

				}
				else
				{
					++Sentinel.second;

				}

			}
			else
			{
				return static_cast<int>(ByteIndex * 8 + BitIndex);

			}

		}

		return -1;

	}

	int CHV4DBITSTREAM::ForwardSentinelPosition()
	{ 
		
		return static_cast<int>(((std::distance(Data.begin(), Sentinel.first) - 1) * 8) + Sentinel.second); 
	
	}

	int CHV4DBITSTREAM::ReverseSentinelPosition()
	{ 
		
		return static_cast<int>(((std::distance(Data.rbegin(), ReverseSentinel.first) - 1) * 8) + ReverseSentinel.second);
	
	}

	void CHV4DBITSTREAM::ByteAlignNext()
	{
		BitPosition = 7;

	}

	std::deque<unsigned char>& CHV4DBITSTREAM::GetData()
	{

		return Data;

	}

	std::deque<unsigned char> CHV4DBITSTREAM::GetDataView()
	{

		return std::deque<unsigned char>{ Data.begin(), Data.end() };

	}

	void CHV4DBITSTREAM::EndOfStream()
	{
		Sentinel.first = --Data.end();

		Sentinel.second = 7;

	}

}