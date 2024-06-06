module;

#include <string>

#include <functional>
#include <memory>

#include <deque>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DBITSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	class CHV4DBITSTREAM
	{
	public:
		CHV4DBITSTREAM()
		{
			BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

			ByteConsume = BYTE_CONSUMPTION_LEFT_RIGHT;

			Data.clear();

			Sentinel.first = Data.begin();

			Sentinel.second = 0;

			isValidSentinel = false;

			ReverseSentinel.first = Data.rbegin();

			ReverseSentinel.second = 0;

			isValidReverseSentinel = false;

			BitPosition = 0;

		}

		CHV4DBITSTREAM(std::deque<unsigned char>::iterator begin, std::deque<unsigned char>::iterator end)
		{
			BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

			ByteConsume = BYTE_CONSUMPTION_LEFT_RIGHT;

			Data.clear();

			std::move(std::move_iterator(begin), std::move_iterator(end), Data.begin());

			Sentinel.first = Data.begin();

			Sentinel.second = 0;

			isValidSentinel = true;

			ReverseSentinel.first = Data.rbegin();

			ReverseSentinel.second = 0;

			isValidReverseSentinel = true;

			BitPosition = 0;

		}

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

		bool InRange(size_t const& n) { return (((n + 8) / 8) - 1) < Data.size() ? true : false; }

	public:
		void operator =(CHV4DBITSTREAM const& in)
		{
			CHV4DBITSTREAM A{ in };

			Data.clear();

			Data.insert(Data.begin(), std::move_iterator(A.Data.begin()), std::move_iterator(A.Data.end()));

			isValidSentinel = false;

			isValidReverseSentinel = false;

		}

		BIT operator ()()
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

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

		void operator ()(size_t const& i, BIT const& set)
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (!InRange(i)) throw std::runtime_error{ "Out of range." };

			size_t bits = i % 8;

			size_t bytes = ((i - bits) / 8);

			switch (bits)
			{

			case 0: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b10000000 : Data[bytes] & 0b00000000; break;
			case 1: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b01000000 : Data[bytes] & 0b00000000; break;
			case 2: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00100000 : Data[bytes] & 0b00000000; break;
			case 3: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00010000 : Data[bytes] & 0b00000000; break;
			case 4: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00001000 : Data[bytes] & 0b00000000; break;
			case 5: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00000100 : Data[bytes] & 0b00000000; break;
			case 6: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00000010 : Data[bytes] & 0b00000000; break;
			case 7: Data[bytes] = (set == BIT::BIT_ONE) ? Data[bytes] | 0b00000001 : Data[bytes] & 0b00000000; break;

			default: throw std::out_of_range{ "BitStream overrun." };

			}
		}

		BIT operator[](size_t const& i) 
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (!InRange(i)) throw std::runtime_error{ "Out of range." };

			size_t bits = i % 8;

			size_t bytes = ((i - bits) / 8);

			switch (bits)
			{

			case 0: return (Data[bytes] & 0b10000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 1: return (Data[bytes] & 0b01000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 2: return (Data[bytes] & 0b00100000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 3: return (Data[bytes] & 0b00010000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 4: return (Data[bytes] & 0b00001000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 5: return (Data[bytes] & 0b00000100) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 6: return (Data[bytes] & 0b00000010) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 7: return (Data[bytes] & 0b00000001) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;

			default: throw std::out_of_range{ "BitStream overrun." };

			}
		}

	public:
		BIT operator ++()
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

			++Sentinel.second;

			if (Sentinel.second == 8) { Sentinel.second = 0; Sentinel.first = std::next(Sentinel.first, 1); }

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

		BIT operator ++(int)
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

			BIT A{ BIT::BIT_ZERO };

			switch (Sentinel.second)
			{

			case 0: A = (*Sentinel.first & 0b10000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 1: A = (*Sentinel.first & 0b01000000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 2: A = (*Sentinel.first & 0b00100000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 3: A = (*Sentinel.first & 0b00010000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 4: A = (*Sentinel.first & 0b00001000) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 5: A = (*Sentinel.first & 0b00000100) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 6: A = (*Sentinel.first & 0b00000010) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;
			case 7: A = (*Sentinel.first & 0b00000001) == 0 ? BIT::BIT_ZERO : BIT::BIT_ONE; break;

			default: throw std::out_of_range{ "BitStream overrun." };

			}

			++Sentinel.second;

			if (Sentinel.second == 8) { Sentinel.second = 0; Sentinel.first = std::next(Sentinel.first, 1); }

			return A;

		}

		BIT operator --()
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (Sentinel.first < Data.begin()) std::out_of_range{ "End of bitstream." };

			--Sentinel.second;

			if (Sentinel.second == -1) { Sentinel.second = 0; Sentinel.first = std::prev(Sentinel.first, 1); }

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

		BIT operator --()
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			if (Sentinel.first < Data.begin()) std::out_of_range{ "End of bitstream." };

			BIT A{ BIT::BIT_ZERO };

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

			--Sentinel.second;

			if (Sentinel.second == -1) { Sentinel.second = 0; Sentinel.first = std::prev(Sentinel.first, 1); }

			return A;
		}

	private:
		CHV4DBITSTREAM operator+() { return CHV4DBITSTREAM{}; }
		CHV4DBITSTREAM operator-() { return CHV4DBITSTREAM{}; }

	private:
		CHV4DBITSTREAM operator+(CHV4DBITSTREAM const& x) const { return CHV4DBITSTREAM{}; }
		CHV4DBITSTREAM operator-(CHV4DBITSTREAM const& x) const { return CHV4DBITSTREAM{}; }
		CHV4DBITSTREAM operator/(CHV4DBITSTREAM const& x) const { return CHV4DBITSTREAM{}; }
		CHV4DBITSTREAM operator*(CHV4DBITSTREAM const& x) const { return CHV4DBITSTREAM{}; }
		CHV4DBITSTREAM operator%(CHV4DBITSTREAM const& x) const { return CHV4DBITSTREAM{}; }

	public:
		CHV4DBITSTREAM operator~() const
		{
			CHV4DBITSTREAM A;

			for (size_t i; i < A.Data.size(); ++i) A.Data[i] = ~A.Data[i];

			return A;
		}
		CHV4DBITSTREAM operator&(CHV4DBITSTREAM const& x) const
		{
			CHV4DBITSTREAM A{ *this }, B{ x };

			for (size_t i; i < A.Data.size(); ++i) A.Data[i] = A.Data[i] & B.Data[i];

			return A;
		}
		CHV4DBITSTREAM operator|(CHV4DBITSTREAM const& x) const
		{
			CHV4DBITSTREAM A{ *this }, B{ x };

			for (size_t i; i < A.Data.size(); ++i) A.Data[i] = A.Data[i] | B.Data[i];

			return A;
		}
		CHV4DBITSTREAM operator^(CHV4DBITSTREAM const& x) const
		{
			CHV4DBITSTREAM A{ *this }, B{ x };

			for (size_t i; i < A.Data.size(); ++i) A.Data[i] = A.Data[i] ^ B.Data[i];

			return A;
		}

	private:
		CHV4DBITSTREAM operator>>(size_t const& shift) { return {}; }
		CHV4DBITSTREAM operator<<(size_t const& shift) { return {}; }

	private:
		bool operator&&(CHV4DBITSTREAM const& x) {}
		bool operator||(CHV4DBITSTREAM const& x) {}

	public:
		bool operator!() const
		{
			for (size_t i = 0; i < Data.size(); ++i) if (Data[i] != 0) return false;

			return true;
		}
		bool operator==(CHV4DBITSTREAM const& x) const
		{
			for (size_t i = 0; i < Data.size(); ++i) if (Data[i] != Data[i]) return false;

			return true;
		}
		bool operator!=(CHV4DBITSTREAM const& x) const
		{
			CHV4DBITSTREAM A{ x };

			if (this->operator==(A)) return false;

			return true;
		}

	private:
		bool operator<(CHV4DBITSTREAM const& x) const {}
		bool operator>(CHV4DBITSTREAM const& x) const {}
		bool operator<=(CHV4DBITSTREAM const& x) {}
		bool operator>=(CHV4DBITSTREAM const& x) {}
		bool operator<=>(CHV4DBITSTREAM const& x) {}

	private:
		void operator+=(BIT const& bit)
		{
			if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

			else ++BitPosition;

			switch (BitPosition)
			{

			case 0: bit == BIT_ONE ? Data.back() = Data.back() | 0b10000000 : Data.back() = Data.back() & 0b00000000; break;
			case 1: bit == BIT_ONE ? Data.back() = Data.back() | 0b01000000 : Data.back() = Data.back() & 0b00000000; break;
			case 2: bit == BIT_ONE ? Data.back() = Data.back() | 0b00100000 : Data.back() = Data.back() & 0b00000000; break;
			case 3: bit == BIT_ONE ? Data.back() = Data.back() | 0b00010000 : Data.back() = Data.back() & 0b00000000; break;
			case 4: bit == BIT_ONE ? Data.back() = Data.back() | 0b00001000 : Data.back() = Data.back() & 0b00000000; break;
			case 5: bit == BIT_ONE ? Data.back() = Data.back() | 0b00000100 : Data.back() = Data.back() & 0b00000000; break;
			case 6: bit == BIT_ONE ? Data.back() = Data.back() | 0b00000010 : Data.back() = Data.back() & 0b00000000; break;
			case 7: bit == BIT_ONE ? Data.back() = Data.back() | 0b00000001 : Data.back() = Data.back() & 0b00000000; break;

			default: throw std::runtime_error{ "BitStream overrun." }; break;

			}

		}
		void operator-=(int)
		{
			if (BitPosition == 0) 
			{ 
				BitPosition = 0; 
				
				Data.pop_back();

				return;
			}

			else --BitPosition;

			switch (BitPosition)
			{

			case 0: Data.back() = Data.back() & 0b00000000; break;
			case 1: Data.back() = Data.back() & 0b10000000; break;
			case 2: Data.back() = Data.back() & 0b11000000; break;
			case 3: Data.back() = Data.back() & 0b11100000; break;
			case 4: Data.back() = Data.back() & 0b11110000; break;
			case 5: Data.back() = Data.back() & 0b11111000; break;
			case 6: Data.back() = Data.back() & 0b11111100; break;
			case 7: Data.back() = Data.back() & 0b11111110; break;

			default: throw std::runtime_error{ "BitStream overrun." }; break;

			}
		}

	private:
		void operator*=(CHV4DBITSTREAM const& x) {}
		void operator/=(CHV4DBITSTREAM const& x) {}
		void operator%=(CHV4DBITSTREAM const& x) {}

	public:
		void operator&=(CHV4DBITSTREAM const& x)
		{
			CHV4DBITSTREAM A{ x };

			for (size_t i; i < A.Data.size(); ++i) Data[i] = Data[i] & A.Data[i];
		}
		void operator|=(CHV4DBITSTREAM const& x)
		{
			CHV4DBITSTREAM A{ x };

			for (size_t i; i < A.Data.size(); ++i) Data[i] = Data[i] | A.Data[i];
		}
		void operator^=(CHV4DBITSTREAM const& x)
		{
			CHV4DBITSTREAM A{ x };

			for (size_t i; i < A.Data.size(); ++i) Data[i] = Data[i] ^ A.Data[i];
		}
		void operator>>=(size_t const& shift)
		{
			size_t bits = shift % 8;

			size_t bytes = ((shift - bits) / 8);

			Data.erase(std::prev(Data.end(), bytes), Data.end());

			for (size_t i = Data.size(); i != 1; --i) Data[i] = Data[i - 1] << (8 - bits) | Data[i] >> bits;

			Data[0] = Data[0] >> bits;

			for (size_t i = 0; i < bytes; ++i) Data.push_front(0b00000000);
		}
		void operator<<=(size_t const& shift)
		{
			size_t bits = shift % 8;

			size_t bytes = ((shift - bits) / 8);

			Data.erase(Data.begin(), std::next(Data.begin(), bytes));

			Data[0] = Data[0] << bits;

			for (size_t i = 0; i != Data.size(); --i)
			{
				Data[i] = Data[i] | Data[i + 1] >> (8 - bits);

				Data[i + 1] = Data[i + 1] << bits;
			}

			for (size_t i = 0; i < bytes; ++i) Data.push_back(0b00000000);
		}

	public:
		void PushBits(unsigned char const& data, size_t const& bits = 8)
		{
			CHV4DBITSTREAM::BIT bitset[8];

			if (bits < 1 || bits > 8) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

			bitset[0] = (0b10000000 & data) == 0b10000000 ? BIT_ONE : BIT_ZERO;
			bitset[1] = (0b01000000 & data) == 0b01000000 ? BIT_ONE : BIT_ZERO;
			bitset[2] = (0b00100000 & data) == 0b00100000 ? BIT_ONE : BIT_ZERO;
			bitset[3] = (0b00010000 & data) == 0b00010000 ? BIT_ONE : BIT_ZERO;
			bitset[4] = (0b00001000 & data) == 0b00001000 ? BIT_ONE : BIT_ZERO;
			bitset[5] = (0b00000100 & data) == 0b00000100 ? BIT_ONE : BIT_ZERO;
			bitset[6] = (0b00000010 & data) == 0b00000010 ? BIT_ONE : BIT_ZERO;
			bitset[7] = (0b00000001 & data) == 0b00000001 ? BIT_ONE : BIT_ZERO;

			if (BitConsume == BIT_CONSUMPTION_LEFT_RIGHT)
			{
				for (size_t i = 0; i < bits; ++i)
				{
					if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

					this->operator+=(bitset[i]);
				}

				isValidSentinel = false;

				isValidReverseSentinel = false;
			}
			else
			{
				for (size_t i = 7; i >= 0; --i)
				{
					if (BitPosition == 7) { BitPosition = 0; Data.push_back({}); }

					this->operator+=(bitset[i]);
				}

				isValidSentinel = false;

				isValidReverseSentinel = false;
			}
		}

		void PushBits(uint16_t const& Data, size_t const& bits)
		{
			if (bits < 1 || bits > 16) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

			uint16_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PushBits(uint32_t const& Data, size_t const& bits)
		{
			if (bits < 1 || bits > 32) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

			uint32_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PushBits(uint64_t const& Data, size_t const& bits)
		{
			if (bits < 1 || bits > 64) throw std::invalid_argument{ "Invalid bit insertion in PushBits." };

			uint64_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PushBytes(uint16_t const& Data)
		{
			uint64_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PushBytes(uint32_t const& Data)
		{
			uint64_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PushBytes(uint64_t const& Data)
		{
			uint64_t InPlace = Data;

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

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PopFrontBits(size_t const& num)
		{
			if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (num > this->BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };
			
			size_t bits = num % 8;

			size_t bytes = ((num - bits) / 8);

			Data.erase(Data.begin(), std::next(Data.begin(), bytes));

			Data[0] = Data[0] << bits;

			for (size_t i = 0; i != Data.size(); --i)
			{
				Data[i] = Data[i] | Data[i + 1] >> (8 - bits);

				Data[i + 1] = Data[i + 1] << bits;
			}

			for (size_t i = 0; i < bytes; ++i) Data.push_back(0b00000000);

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PopFrontBytes(size_t const& num)
		{
			if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

			if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (num > Data.size()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			Data.erase(Data.begin(), std::next(Data.begin(), num));

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PopBackBits(size_t const& num)
		{
			if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

			if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (num > this->BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			size_t bits = num % 8;

			size_t bytes = ((num - bits) / 8);

			Data.erase(std::prev(Data.end(), bytes), Data.end());

			for (size_t i = Data.size(); i != 1; --i) Data[i] = Data[i - 1] << (8 - bits) | Data[i] >> bits;

			Data[0] = Data[0] >> bits;

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void PopBackBytes(size_t const& num)
		{
			if (this->BitStreamSize() == 0) throw std::out_of_range{ "BitStream is empty." };

			if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (num > Data.size()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			Data.erase(std::prev(Data.end(), num), Data.end());

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void BitErase(size_t const& beg, size_t const& end)
		{
			if (beg < 0 || beg >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (end < 0 || end >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (beg >= end) throw std::out_of_range{ "Invalid range." };

			size_t bBits{ beg % 8 }, bBytes{ (beg - bBits) / 8 };

			size_t eBits = end % 8, eBytes{ (end - eBits) / 8 };

			size_t szStream = BitStreamSize() - (end - beg);

			std::deque<unsigned char> front{ std::move_iterator(Data.begin()), std::move_iterator(std::next(Data.begin(), bBytes)) };

			std::deque<unsigned char> back{ std::move_iterator(std::next(Data.begin(), eBytes)), std::move_iterator(Data.end()) };

			Data.insert(Data.begin(), std::move_iterator(back.begin()), std::move_iterator(back.end()));

			this->operator<<=(8 - eBits); //shift back to front

			size_t szFront = front.size();

			Data.insert(Data.begin(), std::move_iterator(front.begin()), std::move_iterator(std::prev(front.end(), 1)));

			Data[szFront] |= front[0];

			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

		void InsertBits(size_t const& pos, std::deque<unsigned char>& insert, size_t const& nbits)
		{
			if (pos < -1 || pos > BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (nbits < 0 || nbits > insert.size() * 8) throw std::out_of_range{ "Invalid number of bits for removal specified." };

			if (insert.empty()) throw std::invalid_argument{ "Empty Data." };

			CHV4DBITSTREAM Buffer;


			isValidSentinel = false;

			isValidReverseSentinel = false;
		}

	public:
		void ClearStream()
		{
			Data.clear();

			Sentinel.first = Data.begin();

			Sentinel.second = 0;

			isValidSentinel = false;

			ReverseSentinel.first = Data.rbegin();

			ReverseSentinel.second = 0;

			isValidReverseSentinel = false;

			BitPosition = 0;

			BitConsume = BIT_CONSUMPTION_LEFT_RIGHT;

			ByteConsume = BYTE_CONSUMPTION_LEFT_RIGHT;

		}

		size_t BitStreamSize()
		{
			if (Data.empty()) return 0;

			else return ((Data.size() * 8) - 8) + (BitPosition + 1);

		}

		void BeginningOfStream()
		{
			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			Sentinel.first = Data.begin();

			Sentinel.second = 0;

			isValidSentinel = true;

			ReverseSentinel.first = Data.rbegin();

			ReverseSentinel.second = 0;

			isValidReverseSentinel = true;

			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

		}

		bool FindNextOf(std::deque<BIT> const& find)
		{
			if (find.empty()) throw std::invalid_argument{ "No search deque." };

			if (find.size() > this->BitStreamSize()) return false;

			this->BeginningOfStream();

			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			std::deque<BIT>::const_iterator citt;

			std::pair<std::deque<unsigned char>::iterator, size_t> poke;

			while (static_cast<size_t>((std::distance(std::next(Sentinel.first, 1), Data.end()) * 8) + (8 - Sentinel.second)) >= find.size())
			{
				citt = find.begin();

				poke = Sentinel;

				while (this->operator()((std::distance(Data.begin(), poke.first) * 8) + poke.second) == *citt && citt != find.end())
				{
					if (poke.second < 7)
					{
						++poke.second;

					}
					else
					{
						poke.first = std::next(poke.first, 1);

						poke.second = 0;

					}

				}

				if (citt == find.end()) return true;

				if (Sentinel.first != std::prev(Data.end(), 1) && Sentinel.second == 7)
				{
					Sentinel.first = std::next(Sentinel.first, 1);

					++Sentinel.second;

				}
				else if (Sentinel.second < 7)
				{
					++Sentinel.second;

				}
				else if (Sentinel.first == std::prev(Data.end(), 1) && Sentinel.second == 7)
				{
					return false;

				}


			}

			return false;

		}

		bool ReverseFindNextOf(std::deque<BIT> const& find)
		{
			if (find.empty()) throw std::invalid_argument{ "No search deque." };

			if (find.size() > this->BitStreamSize()) return false;

			this->BeginningOfStream();

			if (!isValidReverseSentinel) throw std::runtime_error{ "Invalid Sentinel." };

			std::deque<BIT>::const_iterator citt;

			std::pair<std::deque<unsigned char>::reverse_iterator, size_t> poke;

			while (static_cast<size_t>((std::distance(std::next(ReverseSentinel.first, 1), Data.rend()) * 8) + (8 - ReverseSentinel.second)) >= find.size())
			{
				citt = find.begin();

				poke = ReverseSentinel;

				while (this->operator()((std::distance(Data.rbegin(), poke.first) * 8, false) + poke.second) == *citt && citt != find.end())
				{
					if (poke.second < 7)
					{
						++poke.second;

					}
					else
					{
						poke.first = std::next(poke.first, 1);

						poke.second = 0;

					}

				}

				if (citt == find.end()) return true;

				if (ReverseSentinel.first != std::prev(Data.rend(), 1) && ReverseSentinel.second == 7)
				{
					ReverseSentinel.first = std::next(ReverseSentinel.first, 1);

					++ReverseSentinel.second;

				}
				else if (ReverseSentinel.second < 7)
				{
					++ReverseSentinel.second;

				}
				else if (ReverseSentinel.first == std::prev(Data.rend(), 1) && ReverseSentinel.second == 7)
				{
					return false;

				}


			}

			return false;

		}

		size_t ForwardSentinelPosition()
		{
			if (!ValidSentinel()) throw std::runtime_error{ "Invalid Sentinel." };

			return (std::distance(Data.begin(), Sentinel.first) * 8) + Sentinel.second;

		}

		size_t ReverseSentinelPosition()
		{
			if (!ValidReverseSentinel()) throw std::runtime_error{ "Invalid Sentinel." };

			return (std::distance(Data.rbegin(), ReverseSentinel.first) * 8) + ReverseSentinel.second;

		}

		size_t Remain()
		{
			if (ForwardSentinelPosition() > BitStreamSize()) throw std::runtime_error{ "BitStream overrun." };

			return BitStreamSize() - ForwardSentinelPosition();

		}

		void ByteAlignNext()
		{
			if (!ValidSentinel()) throw std::runtime_error{ "Invalid Sentinel." };

			if (Sentinel.first == Data.end()) Sentinel.second = BitPosition;

			else Sentinel.second = 7;

		}

		std::deque<unsigned char>& GetData()
		{

			return Data;

		}

		std::deque<unsigned char> GetDataView()
		{
			isValidSentinel = false;

			isValidReverseSentinel = false;

			return std::deque<unsigned char>{ std::move_iterator(Data.begin()), std::move_iterator(Data.end()) };

		}

		void EndOfStream()
		{
			if (Data.empty()) throw std::runtime_error{ "Empty stream." };

			Sentinel.first = --Data.end();

			Sentinel.second = 7;

			isValidSentinel = true;

			ReverseSentinel.first = Data.rend();

			ReverseSentinel.second = 7;

			isValidReverseSentinel = true;

			if (!isValidSentinel) throw std::runtime_error{ "Invalid Sentinel." };

		}

	private:
		bool ValidSentinel()
		{
			if (!isValidSentinel) return false;

			if (Data.empty())
			{
				isValidSentinel = false;

				return false;

			}

			if (Sentinel.first < Data.begin() || Sentinel.first >= Data.end())
			{
				isValidSentinel = false;

				return false;

			}

			return true;

		}

		bool ValidReverseSentinel()
		{
			if (!isValidSentinel) return false;

			if (Data.empty())
			{
				isValidReverseSentinel = false;

				return false;

			}

			if (ReverseSentinel.first < Data.rbegin() || ReverseSentinel.first >= Data.rend())
			{
				isValidReverseSentinel = false;

				return false;

			}

			return true;

		}

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