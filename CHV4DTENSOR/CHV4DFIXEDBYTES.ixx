module;

#include <vector>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DFIXEDBYTES;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template<size_t n>
	class CHV4DFIXEDBYTES
	{
	public:
		CHV4DFIXEDBYTES() {}

		CHV4DFIXEDBYTES(char const (&x)[n])
		{
			size_t sz = std::size(x);

			if (sz != n) throw std::runtime_error{ "Array overrun." };

			std::memcpy((void*)Data, (const void*)x, n);
		}

		CHV4DFIXEDBYTES(int8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(int16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(int32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(int64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		CHV4DFIXEDBYTES(uint8_t const& x)  { if (n != 1) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(uint16_t const& x) { if (n != 2) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(uint32_t const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(uint64_t const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

		CHV4DFIXEDBYTES(float  const& x) { if (n != 4) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }
		CHV4DFIXEDBYTES(double const& x) { if (n != 8) throw std::runtime_error{ "Array overrun." }; std::memcpy((void*)Data, (const void*)&x, n); }

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

	public:
		unsigned char* operator()() const { return Data; }

	public:
		unsigned char& operator[](size_t const& i) { return Data[i]; }

	private:
		CHV4DFIXEDBYTES operator++() { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator--() { return CHV4DFIXEDBYTES{}; }

	private:
		CHV4DFIXEDBYTES operator+() { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator-() { return CHV4DFIXEDBYTES{}; }

	private:
		CHV4DFIXEDBYTES operator+(CHV4DFIXEDBYTES const& x) const { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator-(CHV4DFIXEDBYTES const& x) const { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator/(CHV4DFIXEDBYTES const& x) const { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator*(CHV4DFIXEDBYTES const& x) const { return CHV4DFIXEDBYTES{}; }
		CHV4DFIXEDBYTES operator%(CHV4DFIXEDBYTES const& x) const { return CHV4DFIXEDBYTES{}; }

	public:
		CHV4DFIXEDBYTES<n> operator~() const
		{
			CHV4DFIXEDBYTES<n> A;

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i; i < n; ++i) A.Data[i] = ~Data[i];

			return A;
		}
		CHV4DFIXEDBYTES<n> operator&(CHV4DFIXEDBYTES<n> const& x) const
		{
			CHV4DFIXEDBYTES<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] & B.Data[i];

			return A;
		}
		CHV4DFIXEDBYTES<n> operator|(CHV4DFIXEDBYTES<n> const& x) const
		{
			CHV4DFIXEDBYTES<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] | B.Data[i];

			return A;
		}
		CHV4DFIXEDBYTES<n> operator^(CHV4DFIXEDBYTES<n> const& x) const
		{
			CHV4DFIXEDBYTES<n> A{ *this }, B{ x };

			for (size_t i; i < n; ++i) A.Data[i] = Data[i] ^ B.Data[i];

			return A;
		}
		CHV4DFIXEDBYTES<n> operator>>(size_t const& shift) const
		{
			CHV4DFIXEDBYTES<n> A{ *this };

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
		CHV4DFIXEDBYTES<n> operator<<(size_t const& shift) const
		{
			CHV4DFIXEDBYTES<n> A{ *this };

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
		bool operator&&(CHV4DFIXEDBYTES<n> const& x) {}
		bool operator||(CHV4DFIXEDBYTES<n> const& x) {}

	public:
		bool operator!() const
		{
			CHV4DFIXEDBYTES<n> A;

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i = 0; i < n; ++i) if (Data[i] != 0) return false;

			return true;
		}
		bool operator==(CHV4DFIXEDBYTES<n> const& x) const
		{
			CHV4DFIXEDBYTES<n> A, B{ x };

			std::memcpy((void*)A.Data, (const void*)Data, n);

			for (size_t i = 0; i < n; ++i) if (A.Data[i] != B.Data[i]) return false;

			return true;
		}
		bool operator!=(CHV4DFIXEDBYTES<n> const& x) const
		{
			CHV4DFIXEDBYTES<n> A{ x };

			if (this->operator==(A)) return false;

			return true;
		}

	private:
		bool operator<(CHV4DFIXEDBYTES<n> const& x) const {}
		bool operator>(CHV4DFIXEDBYTES<n> const& x) const {}

	private:
		bool operator<=(CHV4DFIXEDBYTES<n> const& x) {}
		bool operator>=(CHV4DFIXEDBYTES<n> const& x) {}
		bool operator<=>(CHV4DFIXEDBYTES<n> const& x){}

	private:
		void operator+=(CHV4DFIXEDBYTES<n> const& x) {}
		void operator-=(CHV4DFIXEDBYTES<n> const& x) {}
		void operator*=(CHV4DFIXEDBYTES<n> const& x) {}
		void operator/=(CHV4DFIXEDBYTES<n> const& x) {}
		void operator%=(CHV4DFIXEDBYTES<n> const& x) {}

	public:
		void operator&=(CHV4DFIXEDBYTES<n> const& x)
		{
			CHV4DFIXEDBYTES<n> A{ x };

			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] & A.Data[i];
		}
		void operator|=(CHV4DFIXEDBYTES<n> const& x)
		{
			CHV4DFIXEDBYTES<n> A{ x };

			for (size_t i = 0; i < n; ++i) Data[i] = Data[i] | A.Data[i];
		}
		void operator^=(CHV4DFIXEDBYTES<n> const& x)
		{
			CHV4DFIXEDBYTES<n> A{ x };

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