module;

#include <string>

#include <vector>
#include <list>

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

		Sentinel.first = Data.begin();

		Sentinel.second = 0;

	}

	CHV4DBITSTREAM::CHV4DBITSTREAM(std::list<unsigned char>::iterator begin, std::list<unsigned char>::iterator end)
	{
		Data.clear();

		std::move(begin, end, Data.begin());

		Sentinel.first = Data.begin();

		Sentinel.second = 0;

	}

	CHV4DBITSTREAM::BIT CHV4DBITSTREAM::operator ++()
	{
		if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

		++Sentinel.second;

		if (Sentinel.second == 8) { Sentinel.second = 0; ++Sentinel.first; }

		if (Sentinel.first == Data.end()) std::out_of_range{ "End of bitstream." };

		if (Sentinel.second == 0) {
			if ((*Sentinel.first & 0b10000000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 1) {
			if ((*Sentinel.first & 0b01000000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 2) {
			if ((*Sentinel.first & 0b00100000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 3) {
			if ((*Sentinel.first & 0b00010000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 4) {
			if ((*Sentinel.first & 0b00001000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 5) {
			if ((*Sentinel.first & 0b00000100) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 6) {
			if ((*Sentinel.first & 0b00000010) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 7) {
			if ((*Sentinel.first & 0b00000001) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}

	}

	CHV4DBITSTREAM::BIT CHV4DBITSTREAM::operator --()
	{
		if (Sentinel.first == Data.begin() && Sentinel.second == 0) std::out_of_range{ "End of bitstream." };

		if (Sentinel.second == 0) { Sentinel.second = 7; --Sentinel.first; }

		if (Sentinel.second == 0) {
			if ((*Sentinel.first & 0b10000000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 1) {
			if ((*Sentinel.first & 0b01000000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 2) {
			if ((*Sentinel.first & 0b00100000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 3) {
			if ((*Sentinel.first & 0b00010000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 4) {
			if ((*Sentinel.first & 0b00001000) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 5) {
			if ((*Sentinel.first & 0b00000100) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 6) {
			if ((*Sentinel.first & 0b00000010) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}
		if (Sentinel.second == 7) {
			if ((*Sentinel.first & 0b00000001) == 0) return BIT::BIT_ZERO; else return BIT::BIT_ONE;
		}

	}

	void CHV4DBITSTREAM::operator =(CHV4DBITSTREAM const& in)
	{
		Data.clear();

		Data.insert(Data.begin(), in.Data.begin(), in.Data.end());

	}

	void CHV4DBITSTREAM::operator <<(BIT in)
	{
		if (in == BIT_ZERO) Data.back() = (Data.back() >> (8 - BitPosition)) << (8 - BitPosition);

		if (in == BIT_ONE) Data.back() = ((Data.back() >> (7 - BitPosition)) | 0b00000001) << (7 - BitPosition);

		if (BitPosition == 7) { Data.push_back({}); BitPosition = 0; }

	}

	void CHV4DBITSTREAM::PushBits(unsigned char const& data, size_t const& bits)
	{
		CHV4DBITSTREAM::BIT bitset[8];

		if ((0b10000000 | data) == 0b10000000) bitset[0] = BIT_ONE; else bitset[0] = BIT_ZERO;
		if ((0b01000000 | data) == 0b01000000) bitset[1] = BIT_ONE; else bitset[1] = BIT_ZERO;
		if ((0b00100000 | data) == 0b00100000) bitset[2] = BIT_ONE; else bitset[2] = BIT_ZERO;
		if ((0b00010000 | data) == 0b00010000) bitset[3] = BIT_ONE; else bitset[3] = BIT_ZERO;
		if ((0b00001000 | data) == 0b00001000) bitset[4] = BIT_ONE; else bitset[4] = BIT_ZERO;
		if ((0b00000100 | data) == 0b00000100) bitset[5] = BIT_ONE; else bitset[5] = BIT_ZERO;
		if ((0b00000010 | data) == 0b00000010) bitset[6] = BIT_ONE; else bitset[6] = BIT_ZERO;
		if ((0b00000001 | data) == 0b00000001) bitset[7] = BIT_ONE; else bitset[7] = BIT_ZERO;

		if (Consume == BIT_CONSUMPTION_LEFT_RIGHT)
		{
			for (size_t i = 0; i < bits; ++i)
			{
				unsigned char mask = 0b00000001 << (7 - BitPosition);

				Data.back() = Data.back() | (mask & bitset[i]);

				++BitPosition;

				if (BitPosition == 8)
				{
					BitPosition = 0;

					Data.push_back({});

				}

			}

		}
		else
		{
			for (size_t i = 0; i < bits; ++i)
			{
				unsigned char mask = 0b00000001 << (7 - BitPosition);

				Data.back() = Data.back() | (mask & bitset[7 - i]);

				++BitPosition;

				if (BitPosition == 8)
				{
					BitPosition = 0;

					Data.push_back({});

				}

			}

		}

	}

	void CHV4DBITSTREAM::PushBits(uint16_t const& data, size_t const& bits)
	{
		uint16_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (bits >= 8) { PushBits(buffer[1], 8); }
		else { PushBits(buffer[1], 8 - (8 - bits)); return; }

		PushBits(buffer[0], 8 - (16 - bits));

		return;

	}

	void CHV4DBITSTREAM::PushBits(uint32_t const& data, size_t const& bits)
	{
		uint32_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (bits >= 8) { PushBits(buffer[3], 8); }
		else { PushBits(buffer[3], 8 - (8 - bits)); return; }

		if (bits >= 16) { PushBits(buffer[2], 8); }
		else { PushBits(buffer[2], 8 - (16 - bits)); return; }

		if (bits >= 24) { PushBits(buffer[1], 8); }
		else { PushBits(buffer[1], 8 - (24 - bits)); return; }

		PushBits(buffer[0], 8 - (32 - bits));

	}

	void CHV4DBITSTREAM::PushBits(uint64_t const& data, size_t const& bits)
	{
		uint64_t InPlace = data;

		unsigned char* buffer = reinterpret_cast<unsigned char*>(&InPlace);

		if (bits >= 8) { PushBits(buffer[7], 8); }
		else { PushBits(buffer[7], 8 - (8 - bits)); return; }

		if (bits >= 16) { PushBits(buffer[6], 8); }
		else { PushBits(buffer[6], 8 - (16 - bits)); return; }

		if (bits >= 24) { PushBits(buffer[5], 8); }
		else { PushBits(buffer[5], 8 - (24 - bits)); return; }

		if (bits >= 32) { PushBits(buffer[4], 8); }
		else { PushBits(buffer[4], 8 - (32 - bits)); return; }

		if (bits >= 40) { PushBits(buffer[3], 8); }
		else { PushBits(buffer[3], 8 - (40 - bits)); return; }

		if (bits >= 48) { PushBits(buffer[2], 8); }
		else { PushBits(buffer[2], 8 - (48 - bits)); return; }

		if (bits >= 56) { PushBits(buffer[1], 8); }
		else { PushBits(buffer[1], 8 - (56 - bits)); return; }

		PushBits(buffer[0], 8 - (64 - bits));

	}

	void CHV4DBITSTREAM::PopFrontBits(size_t const& num)
	{
		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (Data.size() == 0) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		size_t Bytes = num - (num % 8);

		size_t bits = num % 8;

		size_t BitStreamSz = (Data.size() * 8) + (BitPosition + 1);

		if (BitStreamSz < num) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		size_t remove = num;

		while (remove >= 8)
		{
			Data.pop_front();

			remove -= 8;

		}

		if (remove == 0) return;

		Data.front() = (Data.front() << remove) >> remove;

		BIT_CONSUMPTION StoreConsumption = Consume;

		std::list<unsigned char> Move{ std::move(Data) };

		Data.clear();

		std::list<unsigned char>::iterator itt;

		for (itt = Move.begin(); itt != Move.end();)
		{
			Consume = BIT_CONSUMPTION_RIGHT_LEFT;

			PushBits(Move.front(), 8 - remove);

			if (Move.size() != 1)
			{
				Consume = BIT_CONSUMPTION_LEFT_RIGHT;

				Move.pop_front();

				PushBits(Move.front(), remove);

			}

		}

		Move.clear();

		Consume = StoreConsumption;

	}

	void CHV4DBITSTREAM::PopBackBits(size_t const& num)
	{
		if (num < 1) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (Data.size() == 0) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		size_t Bytes = num - (num % 8);

		size_t bits = num % 8;

		size_t BitStreamSz = (Data.size() * 8) + (BitPosition + 1);

		if (BitStreamSz < num) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		size_t remove = num;

		while (remove >= 8)
		{
			Data.pop_back();

			remove -= 8;

		}

		if (remove == 0) return;

		if ((BitPosition + 1) <= remove)
		{
			BitPosition = 7;

			Data.pop_back();

			remove = remove - (BitPosition + 1);

		}

		if (remove == 0) return;

		Data.back() = (Data.back() >> remove) << remove;

		BitPosition -= remove;

	}

	void CHV4DBITSTREAM::BitErase(size_t const& beg, size_t const& end)
	{
		if (beg < 0 || beg >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (end < 0 || end >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		if (beg >= end) throw std::out_of_range{ "Invalid range." };

		if (beg == 0) { PopFrontBits(end + 1); return; }

		if ((end + 1) == BitStreamSize()) { PopBackBits((end - beg) + 1); return; }

		size_t ProcessedBitPosition = (BitStreamSize() - ((end + 1) - beg)) % 8;

		size_t FrontBits = beg % 8;

		size_t KeptFrontBytes = (beg - FrontBits) / 8;

		CHV4DBITSTREAM Front{ Data.begin(), std::next(Data.begin(), KeptFrontBytes) };

		size_t BackBits = 8 - ((end + 1) % 8);

		size_t RemoveFrontBytes = (end - (8 - BackBits)) / 8;

		CHV4DBITSTREAM Back{ Data.begin(), Data.end() };

		if (RemoveFrontBytes > 0) Back.Data.erase(Data.begin(), std::next(Data.begin(), RemoveFrontBytes - 1));

		Data.clear();

		std::move(Front.Data.begin(), Front.Data.end(), Data.begin());

		Front.Data.clear();

		Data.back() = (Data.back() >> (8 - FrontBits)) << (8 - FrontBits);

		Back.Data.front() = (Back.Data.front() << BackBits) >> BackBits;

		BIT_CONSUMPTION StoreConsumption = Consume;

		BitPosition = FrontBits;

		Consume = BIT_CONSUMPTION_RIGHT_LEFT;

		PushBits(Back.Data.front(), BackBits);

		Back.Data.pop_front();

		std::list<unsigned char>::iterator itt;

		for (itt = Back.Data.begin(); itt != Back.Data.end(); Back.Data.pop_front())
		{
			PushBits(Back.Data.front(), 8);

		}

		Back.Data.clear();

		Consume = StoreConsumption;

		BitPosition = ProcessedBitPosition;

		return;

	}

	void CHV4DBITSTREAM::InsertBits(size_t const& pos, std::vector<unsigned char>::const_iterator citt, size_t const& nbits)
	{
		if (pos < 0 || pos >= BitStreamSize()) throw std::out_of_range{ "Invalid number of bits for removal specified." };

		size_t ProcessedBitPosition = (BitStreamSize() + nbits) % 8;

		size_t FrontBits = pos % 8;

		size_t KeptFrontBytes = (pos - FrontBits) / 8;

		CHV4DBITSTREAM Front{ Data.begin(), std::next(Data.begin(), KeptFrontBytes) };

		size_t BackBits = 8 - ((pos + 1) % 8);

		size_t RemoveFrontBytes = (pos - (8 - BackBits)) / 8;

		CHV4DBITSTREAM Back{ Data.begin(), Data.end() };

		if (RemoveFrontBytes > 0) Back.Data.erase(Data.begin(), std::next(Data.begin(), RemoveFrontBytes - 1));

		Data.clear();

		std::move(Front.Data.begin(), Front.Data.end(), Data.begin());

		Front.Data.clear();

		Data.back() = (Data.back() >> (8 - FrontBits)) << (8 - FrontBits);

		Back.Data.front() = (Back.Data.front() << BackBits) >> BackBits;

		BIT_CONSUMPTION StoreConsumption = Consume;

		BitPosition = FrontBits;

		Consume = BIT_CONSUMPTION_RIGHT_LEFT;

		std::list<unsigned char> Insert{ citt, std::next(citt, Calc::Ceiling((float)nbits/8))};

		std::list<unsigned char>::iterator itt;

		for (itt = Insert.begin(); itt != Insert.end(); Insert.pop_front())
		{
			PushBits(Insert.front(), 8);

		}

		PushBits(Back.Data.front(), BackBits);

		Back.Data.pop_front();

		std::list<unsigned char>::iterator itt;

		for (itt = Back.Data.begin(); itt != Back.Data.end(); Back.Data.pop_back())
		{
			PushBits(Back.Data.front(), 8);

		}

		Back.Data.clear();

		Consume = StoreConsumption;

		BitPosition = ProcessedBitPosition;

		return;

	}

	void CHV4DBITSTREAM::BeginningOfStream()
	{
		Sentinel.first = Data.begin();

		Sentinel.second = 0;

	}

	size_t CHV4DBITSTREAM::FindNextOf(std::vector<BIT> const& find)
	{
		if (find.size() > (Data.size() * 8 + BitPosition)) return -1;

		bool Match{ true };

		std::vector<BIT>::const_iterator citt;

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
				return ByteIndex * 8 + BitIndex;

			}

		}

		return -1;

	}

	size_t CHV4DBITSTREAM::ReverseFindNextOf(std::vector<BIT> const& find)
	{
		if (find.size() > (Data.size() * 8 + BitPosition)) return -1;

		while (std::distance(Data.rbegin(), ReverseSentinel.first) < (find.size() / 8) - 1) ++ReverseSentinel.first;

		bool Match{ true };

		std::vector<BIT>::const_iterator citt;

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
				return ByteIndex * 8 + BitIndex;

			}

		}

		return -1;

	}

	void CHV4DBITSTREAM::EndOfStream()
	{
		Sentinel.first = --Data.end();

		Sentinel.second = 7;

	}

}