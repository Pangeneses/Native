module;

#include <vector>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DBYTESTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template<size_t n>
	class CHV4DBYTESTREAM
	{
	public:
		CHV4DBYTESTREAM() {}

		CHV4DBYTESTREAM(char const (&x)[n])
		{
			size_t sz = std::size(x);

			if (sz != n) throw std::runtime_error{ "Array overrun." };

			std::memcpy((void*)Data, (const void*)x, n);
		}

		CHV4DBYTESTREAM(int8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(int16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(int32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(int64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		CHV4DBYTESTREAM(uint8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(uint16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(uint32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(uint64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		CHV4DBYTESTREAM(float  const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DBYTESTREAM(double const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

	public:
		void operator=(char const (&x)[n])
		{
			size_t sz = std::size(x);

			if (sz != n) throw std::runtime_error{ "Array overrun." };

			std::memcpy((void*)Data, (const void*)x, n);
		}

		void operator=(int8_t const& x) { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(int16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(int32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(int64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		void operator=(uint8_t const& x) { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(uint16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(uint32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(uint64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		void operator=(float  const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		void operator=(double const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

	private:
		unsigned char* operator()() const {}

	public:
		unsigned char& operator[](size_t const& i) { return Data[i]; }

	private:
		CHV4DBYTESTREAM operator++() { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator--() { return CHV4DBYTESTREAM{}; }

	private:
		CHV4DBYTESTREAM operator+() { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator-() { return CHV4DBYTESTREAM{}; }

	private:
		CHV4DBYTESTREAM operator+(CHV4DBYTESTREAM const& x) const { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator-(CHV4DBYTESTREAM const& x) const { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator/(CHV4DBYTESTREAM const& x) const { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator*(CHV4DBYTESTREAM const& x) const { return CHV4DBYTESTREAM{}; }
		CHV4DBYTESTREAM operator%(CHV4DBYTESTREAM const& x) const { return CHV4DBYTESTREAM{}; }

	public:
		CHV4DBYTESTREAM<n> operator~() const
		{
			CHV4DBYTESTREAM<n> A;

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i; i < n; ++i) A.Data[i] = ~Data[i];

			return A;
		}
		CHV4DBYTESTREAM<n> operator&(CHV4DBYTESTREAM<n> const& x) const
		{
			CHV4DBYTESTREAM<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] & B.Data[i];

			return A;
		}
		CHV4DBYTESTREAM<n> operator|(CHV4DBYTESTREAM<n> const& x) const
		{
			CHV4DBYTESTREAM<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] | B.Data[i];

			return A;
		}
		CHV4DBYTESTREAM<n> operator^(CHV4DBYTESTREAM<n> const& x) const
		{
			CHV4DBYTESTREAM<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] ^ B.Data[i];

			return A;
		}
		CHV4DBYTESTREAM<n> operator>>(size_t const& shift) const
		{
			CHV4DBYTESTREAM<n> A{ *this };

			unsigned char bit{ 0 };

			for (size_t i; i < shift; ++i)
			{
				bit = Data[i] & 0b00000001;

				bit = bit << 8;

				if(i + 1 != shift) A.Data[i + 1] = A.Data[i + 1] & 0b10000000;

				A.Data[i] = Data[i] >> shift;

			}

			return A;
		}
		CHV4DBYTESTREAM<n> operator<<(size_t const& shift) const
		{
			CHV4DBYTESTREAM<n> A{ *this };

			unsigned char bit{ 0 };

			for (size_t i = shift; i != 0; --i)
			{
				bit = Data[i] & 0b100000000;

				bit = bit >> 8;

				if (i - 1 != 0) A.Data[i - 1] = A.Data[i - 1] & 0b00000001;

				A.Data[i] = Data[i] << shift;

			}

			return A;
		}

	private:
		bool operator&&(CHV4DBYTESTREAM<n> const& x) {}
		bool operator||(CHV4DBYTESTREAM<n> const& x) {}

	public:
		bool operator!() const
		{
			CHV4DBYTESTREAM<n> A;

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i = 0; i < n; ++i) if (Data[i] != 0) return false;

			return true;
		}
		bool operator==(CHV4DBYTESTREAM<n> const& x) const
		{
			CHV4DBYTESTREAM<n> A, B{ x };

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i = 0; i < n; ++i) if (A.Data[i] != B.Data[i]) return false;

			return true;
		}
		bool operator!=(CHV4DBYTESTREAM<n> const& x) const
		{
			CHV4DBYTESTREAM<n> A{ x };

			if (this->operator==(A)) return false;

			return true;
		}

	private:
		bool operator<(CHV4DBYTESTREAM<n> const& x) const {}
		bool operator>(CHV4DBYTESTREAM<n> const& x) const {}

	private:
		bool operator<=(CHV4DBYTESTREAM<n> const& x) {}
		bool operator>=(CHV4DBYTESTREAM<n> const& x) {}
		bool operator<=>(CHV4DBYTESTREAM<n> const& x){}

	private:
		void operator+=(CHV4DBYTESTREAM<n> const& x) {}
		void operator-=(CHV4DBYTESTREAM<n> const& x) {}
		void operator*=(CHV4DBYTESTREAM<n> const& x) {}
		void operator/=(CHV4DBYTESTREAM<n> const& x) {}
		void operator%=(CHV4DBYTESTREAM<n> const& x) {}

	public:
		void operator&=(CHV4DBYTESTREAM<n> const& x)
		{
			CHV4DBYTESTREAM<n> A{ x };

			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] & A.Data[i];
		}
		void operator|=(CHV4DBYTESTREAM<n> const& x)
		{
			CHV4DBYTESTREAM<n> A{ x };

			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] | A.Data[i];
		}
		void operator^=(CHV4DBYTESTREAM<n> const& x)
		{
			CHV4DBYTESTREAM<n> A{ x };

			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] ^ A.Data[i];
		}
		void operator>>=(size_t const& shift)
		{
			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] >> shift;
		}
		void operator<<=(size_t const& shift)
		{
			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] << shift;
		}

	public:
		unsigned char Data[n];
		
	};

}