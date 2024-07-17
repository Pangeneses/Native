module;

#include <type_traits>

#include <compare>

#include <stdexcept>

module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DINTEGER < int16_t > ::CHV4DINTEGER() { Data = 0; }

	CHV4DINTEGER < int16_t > ::CHV4DINTEGER(CHV4DINTEGER < int16_t > const& x) { Data = x(); }

	CHV4DINTEGER < int16_t > ::CHV4DINTEGER(int16_t const& x) { Data = x; }


	void CHV4DINTEGER < int16_t > ::operator=(CHV4DINTEGER < int16_t > const& x) { Data = x(); }

	void CHV4DINTEGER < int16_t > ::operator=(int16_t  const& x) { Data = x; }


	int16_t CHV4DINTEGER < int16_t > ::operator()() const { return Data; }

	unsigned char& CHV4DINTEGER < int16_t > ::operator[](size_t const& i)
	{
		if (i > 1) throw std::overflow_error{ "Index Out of Range." };

		return reinterpret_cast<unsigned char*>(&Data)[1 - i];
	}


	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator++()
	{
		if (Data == 32767i16) throw std::overflow_error{ "Integer Increment Overflow." };

		Data = Data + 1;

		return Data;
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator++(int)
	{
		if (Data == 32767i16) throw std::overflow_error{ "Integer Increment Overflow." };

		int16_t Q = Data;

		Data = Data + 1;

		return Q;
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator--()
	{
		if (Data == -32767i16) throw std::overflow_error{ "Integer Decrement Overflow." };

		Data = Data - 1;

		return Data;
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator--(int)
	{
		if (Data == -32767i16) throw std::overflow_error{ "Integer Decrement Overflow." };

		int16_t Q = Data;

		Data = Data - 1;

		return Q;
	}


	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator+() const
	{
		return int16_t{ Data };
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator-() const
	{
		return int16_t{ -1 * Data };
	}


	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator+(CHV4DINTEGER < int16_t > const& x) const
	{
		int32_t A{ Data }, B{ x() };

		A = A + B;

		if (A < -32767i32 || A > 32767i32) throw std::overflow_error{ "Integer Addition Overflow." };

		return static_cast<int16_t>(A);
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator-(CHV4DINTEGER < int16_t > const& x) const
	{
		int32_t A{ Data }, B{ x() };

		A = A - B;

		if (A < -32767i32 || A > 32767i32) throw std::overflow_error{ "Integer Subtraction Overflow." };

		return static_cast<int16_t>(A);
	}

	CHV4DMANTISSA < double > CHV4DINTEGER < int16_t > ::operator/(CHV4DMANTISSA < double > const& x) const
	{
		if (x.IsZero()) throw std::runtime_error{ "Division by Zero." };

		if (Data == 0) return 0.0;

		CHV4DMANTISSA < double > A{ static_cast<double>(Data) }, B{ x }, Q{ 0 };

		uint64_t dividend{ A.Mantissa() }, divisor{ B.Mantissa() };

		dividend |= 0x0008000000000000ui64;

		divisor |= 0x0008000000000000ui64;

		for (size_t i = 0; i < 52; ++i)
		{
			try { Q.Mantissa(Q.Mantissa() << 1); }

			catch (std::overflow_error error) { throw error; }

			if (dividend >= divisor)
			{
				dividend -= divisor;

				try { Q.Mantissa(Q.Mantissa() | 0x0000000000000001ui64); }

				catch (std::overflow_error error) { throw error; }
			}

			if (dividend < divisor) dividend <<= 1;
		}

		try { Q.Mantissa(dividend & 0x00007FFFFFFFFFFFF); }

		catch (std::overflow_error error) { throw error; }

		try { Q.Exponent(A.Exponent() - B.Exponent() + 127i8); }

		catch (std::overflow_error error) { throw error; }

		Q.Sign() = (!A.Sign() != !B.Sign()) ? true : false;

		return Q;
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator*(CHV4DINTEGER < int16_t > const& x) const
	{
		int16_t A{ Data }, B{ x() };

		int16_t Q = A * B;

		if (Q > 127i16 || Q < -127i16) throw std::overflow_error{ "Integer Multiplication Overflow." };

		return static_cast<int16_t>(Q);
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator%(CHV4DINTEGER < int16_t > const& x) const
	{
		if (x == 0) throw std::runtime_error{ "Division by Zero." };

		if (Data == 0) return 0;

		bool sign = !(Data < 0) != !(x < 0) ? true : false;

		uint64_t A{ 0 }, B{ 0 };

		A = Data < 0 ? static_cast<uint64_t>(-1 * Data) : static_cast<uint64_t>(Data);

		B = x() < 0 ? static_cast<uint64_t>(-1 * x()) : static_cast<uint64_t>(x());

		size_t bitWidth{ 63 };

		while ((B & 0x3000000000000000ui64) != 0x3000000000000000ui64)
		{
			B <<= 1;

			--bitWidth;

			if (bitWidth == 0) throw std::runtime_error{ "Division by Zero." };
		}

		B <<= 63 - bitWidth;

		for (size_t i = 63; i > bitWidth; --i)
		{
			if (A > B) { A -= B; }

			B >>= 1;
		}

		if (A > 32768) throw std::runtime_error{ "Runtime Out of Range." };

		return sign ? static_cast<int16_t>(-1 * A) : static_cast<int16_t>(A);
	}


	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator&(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data & x();
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator|(CHV4DINTEGER const x) const
	{
		return Data | x();
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator^(CHV4DINTEGER const x) const
	{
		return Data ^ x();
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator>>(CHV4DINTEGER < int16_t > const x) const
	{
		return Data >> x();
	}

	CHV4DINTEGER < int16_t > CHV4DINTEGER < int16_t > ::operator<<(CHV4DINTEGER const x) const
	{
		return Data << x();
	}


	bool CHV4DINTEGER < int16_t > ::operator!() const
	{
		return !Data;
	}

	bool CHV4DINTEGER < int16_t > ::operator&&(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data && x();
	}

	bool CHV4DINTEGER < int16_t > ::operator||(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data || x();
	}

	bool CHV4DINTEGER < int16_t > ::operator==(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data == x();
	}

	bool CHV4DINTEGER < int16_t > ::operator!=(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data != x();
	}

	bool CHV4DINTEGER < int16_t > ::operator<(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data < x();
	}

	bool CHV4DINTEGER < int16_t > ::operator>(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data > x();
	}

	bool CHV4DINTEGER < int16_t > ::operator<=(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data <= x();
	}

	bool CHV4DINTEGER < int16_t > ::operator>=(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data >= x();
	}

	std::strong_ordering CHV4DINTEGER < int16_t > ::operator<=>(CHV4DINTEGER < int16_t > const& x) const
	{
		return Data <=> x();
	}


	void CHV4DINTEGER < int16_t > ::operator+=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator+(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator-=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator-(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator*=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator*(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator&=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator&(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator|=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator|(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator^=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator^(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator>>=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator>>(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER < int16_t > ::operator<<=(CHV4DINTEGER < int16_t > const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator<<(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}
}