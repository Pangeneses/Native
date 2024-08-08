module;

#include <type_traits>

#include <compare>

#include <stdexcept>

module CHV4DTENSOR:CHV4DZNONNEG;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DZNONNEG < uint32_t > ::CHV4DZNONNEG() { Data = 0i32; }

	CHV4DZNONNEG < uint32_t > ::CHV4DZNONNEG(CHV4DZNONNEG < uint32_t > const& x) { Data = x(); }

	CHV4DZNONNEG < uint32_t > ::CHV4DZNONNEG(uint32_t const& x) { Data = x; }

	void CHV4DZNONNEG < uint32_t > ::operator=(CHV4DZNONNEG < uint32_t > const& x) { Data = x(); }

	void CHV4DZNONNEG < uint32_t > ::operator=(uint32_t  const& x) { Data = x; }

	uint32_t CHV4DZNONNEG < uint32_t > ::operator()() const { return Data; }

	unsigned char& CHV4DZNONNEG < uint32_t > ::operator[](size_t const& i)
	{
		if (i > 3i8) throw std::runtime_error{ "Index Out of Range." };

		return reinterpret_cast<unsigned char*>(&Data)[3i8 - i];
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator++()
	{
		if (Data == std::numeric_limits<uint32_t>::max()) throw std::overflow_error{ "ZNonNeg Increment Overflow." };

		Data += 1i32;

		return Data;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator++(int)
	{
		if (Data == std::numeric_limits<uint32_t>::max()) throw std::overflow_error{ "ZNonNeg Increment Overflow." };

		uint32_t Q = Data;

		Data += 1;

		return Q;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator--()
	{
		if (Data == std::numeric_limits<uint32_t>::min()) throw std::overflow_error{ "ZNonNeg Decrement Overflow." };

		Data -= 1;

		return Data;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator--(int)
	{
		if (Data == std::numeric_limits<uint32_t>::min()) throw std::overflow_error{ "ZNonNeg Decrement Overflow." };

		uint32_t Q = Data;

		Data -= 1;

		return Q;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator+() const
	{
		return uint32_t{ Data };
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator-() const
	{
		return uint32_t{ -1 * Data };
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator+(CHV4DZNONNEG < uint32_t > const& x) const
	{
		uint32_t A{ Data }, B{ x() };

		A += B;

		if (A < std::numeric_limits<uint32_t>::min() || A > std::numeric_limits<uint32_t>::max()) throw std::overflow_error{ "ZNonNeg Addition Overflow." };

		return A;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator-(CHV4DZNONNEG < uint32_t > const& x) const
	{
		uint32_t A{ Data }, B{ x() };

		A -= B;

		if (A < std::numeric_limits<uint32_t>::min() || A > std::numeric_limits<uint32_t>::max()) throw std::overflow_error{ "ZNonNeg Subtraction Overflow." };

		return A;
	}

	CHV4DMANTISSA < double > CHV4DZNONNEG < uint32_t > ::operator/(CHV4DMANTISSA < double > const& x) const
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

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator*(CHV4DZNONNEG < uint32_t > const& x) const
	{
		int64_t A{ Data }, B{ x() };

		A *= B;

		if (A < std::numeric_limits<uint32_t>::min() || A > std::numeric_limits<uint32_t>::max()) throw std::overflow_error{ "ZNonNeg Multiplication Overflow." };

		return static_cast<uint32_t>(A);
	}

	size_t CHV4DZNONNEG < uint32_t > ::operator%(CHV4DZNONNEG < uint32_t > const& x) const
	{
		if (x() == 0i8) throw std::runtime_error{ "Division by Zero." };

		if (Data == 0i8) return 0i8;

		uint64_t A{ -Data }, B{ -x() };

		size_t bitWidth{ 63i8 };

		while ((B & 0x3000000000000000ui64) != 0x3000000000000000ui64)
		{
			B <<= 1i8;

			--bitWidth;

			if (bitWidth == 0) throw std::runtime_error{ "Division by Zero." };
		}

		B <<= 63i8 - bitWidth;

		for (size_t i = 63i8; i > bitWidth; --i)
		{
			if (A > B) { A -= B; }

			B >>= 1i8;
		}

		return A;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator&(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data & x();
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator|(CHV4DZNONNEG const x) const
	{
		return Data | x();
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator^(CHV4DZNONNEG const x) const
	{
		return Data ^ x();
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator>>(CHV4DZNONNEG < uint32_t > const x) const
	{
		return Data >> x();
	}

	CHV4DZNONNEG < uint32_t > CHV4DZNONNEG < uint32_t > ::operator<<(CHV4DZNONNEG const x) const
	{
		return Data << x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator!() const
	{
		return !Data;
	}

	bool CHV4DZNONNEG < uint32_t > ::operator&&(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data && x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator||(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data || x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator==(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data == x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator!=(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data != x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator<(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data < x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator>(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data > x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator<=(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data <= x();
	}

	bool CHV4DZNONNEG < uint32_t > ::operator>=(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data >= x();
	}

	std::strong_ordering CHV4DZNONNEG < uint32_t > ::operator<=>(CHV4DZNONNEG < uint32_t > const& x) const
	{
		return Data <=> x();
	}

	void CHV4DZNONNEG < uint32_t > ::operator+=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator-=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator*=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator&=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator|=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator^=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator>>=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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

	void CHV4DZNONNEG < uint32_t > ::operator<<=(CHV4DZNONNEG < uint32_t > const& x)
	{
		CHV4DZNONNEG A{ *this }, B{ x };

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