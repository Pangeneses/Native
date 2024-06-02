module;

#include <vector>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DBYTE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template<size_t n>
	class CHV4DBYTE
	{
	public:
		CHV4DBYTE() {}

		CHV4DBYTE(char const (&x)[n])
		{
			size_t sz = std::size(x);

			if (sz != n) throw std::runtime_error{ "Array overrun." };

			std::memcpy((void*)data, (const void*)x, n);
		}

		CHV4DBYTE(int8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(int16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(int32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(int64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

		CHV4DBYTE(uint8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(uint16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(uint32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(uint64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

		CHV4DBYTE(float  const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		CHV4DBYTE(double const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

	public:
		void operator=(char const (&x)[n])
		{
			size_t sz = std::size(x);

			if (sz != n) throw std::runtime_error{ "Array overrun." };

			std::memcpy((void*)data, (const void*)x, n);
		}

		void operator=(int8_t const& x) { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(int16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(int32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(int64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

		void operator=(uint8_t const& x) { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(uint16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(uint32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(uint64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

		void operator=(float  const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }
		void operator=(double const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)data, (const void*)&x, n); }

	private:
		unsigned char* operator()() const {}

	public:
		unsigned char& operator[](size_t const& i) { return data[i]; }

	private:
		CHV4DBYTE operator++() { return CHV4DBYTE{}; }
		CHV4DBYTE operator--() { return CHV4DBYTE{}; }

	private:
		CHV4DBYTE operator+() { return CHV4DBYTE{}; }
		CHV4DBYTE operator-() { return CHV4DBYTE{}; }

	private:
		CHV4DBYTE operator+(CHV4DBYTE const& x) const { return CHV4DBYTE{}; }
		CHV4DBYTE operator-(CHV4DBYTE const& x) const { return CHV4DBYTE{}; }
		CHV4DBYTE operator/(CHV4DBYTE const& x) const { return CHV4DBYTE{}; }
		CHV4DBYTE operator*(CHV4DBYTE const& x) const { return CHV4DBYTE{}; }
		CHV4DBYTE operator%(CHV4DBYTE const& x) const { return CHV4DBYTE{}; }

	public:
		CHV4DBYTE<n> operator~() const
		{
			CHV4DBYTE<n> A;

			std::memcpy((void*)A.data, (const void*)data, n);

			for (size_t i; i < n; ++i) A.data[i] = ~data[i];

			return A;
		}
		CHV4DBYTE<n> operator&(CHV4DBYTE<n> const& x) const
		{
			CHV4DBYTE<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.data[i] = data[i] & B.data[i];

			return A;
		}
		CHV4DBYTE<n> operator|(CHV4DBYTE<n> const& x) const
		{
			CHV4DBYTE<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.data[i] = data[i] | B.data[i];

			return A;
		}
		CHV4DBYTE<n> operator^(CHV4DBYTE<n> const& x) const
		{
			CHV4DBYTE<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.data[i] = data[i] ^ B.data[i];

			return A;
		}
		CHV4DBYTE<n> operator>>(size_t const& shift) const
		{
			CHV4DBYTE<n> A{ *this };

			unsigned char bit{ 0 };

			for (size_t i; i < shift; ++i)
			{
				bit = data[i] & 0b00000001;

				bit = bit << 8;

				if(i + 1 != shift) A.data[i + 1] = A.data[i + 1] & 0b10000000;

				A.data[i] = data[i] >> shift;

			}

			return A;
		}
		CHV4DBYTE<n> operator<<(size_t const& shift) const
		{
			CHV4DBYTE<n> A{ *this };

			unsigned char bit{ 0 };

			for (size_t i = shift; i != 0; --i)
			{
				bit = data[i] & 0b100000000;

				bit = bit >> 8;

				if (i - 1 != 0) A.data[i - 1] = A.data[i - 1] & 0b00000001;

				A.data[i] = data[i] << shift;

			}

			return A;
		}

	private:
		bool operator&&(CHV4DBYTE<n> const& x) {}
		bool operator||(CHV4DBYTE<n> const& x) {}

	public:
		bool operator!() const
		{
			CHV4DBYTE<n> A;

			std::memcpy((void*)A.data, (const void*)data, n);

			for (size_t i = 0; i < n; ++i) if (data[i] != 0) return false;

			return true;
		}
		bool operator==(CHV4DBYTE<n> const& x) const
		{
			CHV4DBYTE<n> A, B{ x };

			std::memcpy((void*)A.data, (const void*)data, n);

			for (size_t i = 0; i < n; ++i) if (A.data[i] != B.data[i]) return false;

			return true;
		}
		bool operator!=(CHV4DBYTE<n> const& x) const
		{
			CHV4DBYTE<n> A{ x };

			if (this->operator==(A)) return false;

			return true;
		}

	private:
		bool operator<(CHV4DBYTE<n> const& x) const {}
		bool operator>(CHV4DBYTE<n> const& x) const {}

	private:
		bool operator<=(CHV4DBYTE<n> const& x) {}
		bool operator>=(CHV4DBYTE<n> const& x) {}
		bool operator<=>(CHV4DBYTE<n> const& x){}

	private:
		void operator+=(CHV4DBYTE<n> const& x) {}
		void operator-=(CHV4DBYTE<n> const& x) {}
		void operator*=(CHV4DBYTE<n> const& x) {}
		void operator/=(CHV4DBYTE<n> const& x) {}
		void operator%=(CHV4DBYTE<n> const& x) {}

	public:
		void operator&=(CHV4DBYTE<n> const& x)
		{
			CHV4DBYTE<n> A{ x };

			for (size_t i = 0; i < n; ++i) data[i] = data[i] & A.data[i];
		}
		void operator|=(CHV4DBYTE<n> const& x)
		{
			CHV4DBYTE<n> A{ x };

			for (size_t i = 0; i < n; ++i) data[i] = data[i] | A.data[i];
		}
		void operator^=(CHV4DBYTE<n> const& x)
		{
			CHV4DBYTE<n> A{ x };

			for (size_t i = 0; i < n; ++i) data[i] = data[i] ^ A.data[i];
		}
		void operator>>=(size_t const& shift)
		{
			for (size_t i = 0; i < n; ++i) data[i] = data[i] >> shift;
		}
		void operator<<=(size_t const& shift)
		{
			for (size_t i = 0; i < n; ++i) data[i] = data[i] << shift;
		}

	public:
		unsigned char data[n];
		
	};

}