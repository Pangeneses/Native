module;

#include <type_traits>

#include <compare>

#include <stdexcept>

module CHV4DTENSOR:CHV4DZPOSITIVE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DZPOSITIVE < uint16_t > ::CHV4DZPOSITIVE() { Data = 0i16; }

	CHV4DZPOSITIVE < uint16_t > ::CHV4DZPOSITIVE(CHV4DZPOSITIVE < uint16_t > const& x) { Data = x(); }

	CHV4DZPOSITIVE < uint16_t > ::CHV4DZPOSITIVE(uint16_t const& x) { Data = x; }

	void CHV4DZPOSITIVE < uint16_t > ::operator=(CHV4DZPOSITIVE < uint16_t > const& x) { Data = x(); }

	void CHV4DZPOSITIVE < uint16_t > ::operator=(uint16_t  const& x) { Data = x; }

	uint16_t CHV4DZPOSITIVE < uint16_t > ::operator()() const { return Data; }

	unsigned char& CHV4DZPOSITIVE < uint16_t > ::operator[](size_t const& i)
	{
		if (i > 1i8) throw std::overflow_error{ "Index Out of Range." };

		return reinterpret_cast<unsigned char*>(&Data)[1i8 - i];
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator++()
	{
		if (Data == std::numeric_limits<uint16_t>::max()) throw std::overflow_error{ "ZPositive Increment Overflow." };

		Data += 1;

		return Data;
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator++(int)
	{
		if (Data == std::numeric_limits<uint16_t>::max()) throw std::overflow_error{ "ZPositive Increment Overflow." };

		uint16_t Q = Data;

		Data += 1;

		return Q;
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator--()
	{
		if (Data == std::numeric_limits<uint16_t>::min()) throw std::overflow_error{ "ZPositive Decrement Overflow." };

		Data -= 1;

		return Data;
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator--(int)
	{
		if (Data == std::numeric_limits<uint16_t>::min()) throw std::overflow_error{ "ZPositive Decrement Overflow." };

		uint16_t Q = Data;

		Data -= 1;

		return Q;
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator+() const
	{
		return uint16_t{ Data };
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator-() const
	{
		return uint16_t{ -1 * Data };
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator+(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		int32_t A{ Data }, B{ x() };

		A += B;

		if (A < std::numeric_limits<uint16_t>::min() || A > std::numeric_limits<uint16_t>::max()) throw std::overflow_error{ "ZPositive Addition Overflow." };

		return static_cast<uint16_t>(A);
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator-(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		int32_t A{ Data }, B{ x() };

		A -= B;

		if (A < std::numeric_limits<uint16_t>::min() || A > std::numeric_limits<uint16_t>::max()) throw std::overflow_error{ "ZPositive Subtraction Overflow." };

		return static_cast<uint16_t>(A);
	}

	CHV4DMANTISSA < double > CHV4DZPOSITIVE < uint16_t > ::operator/(CHV4DMANTISSA < double > const& x) const
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

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator*(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		int32_t A{ Data }, B{ x() };

		A *= B;

		if (A < std::numeric_limits<uint16_t>::min() || A > std::numeric_limits<uint16_t>::max()) throw std::overflow_error{ "ZPositive Multiplication Overflow." };

		return static_cast<uint16_t>(A);
	}

	size_t CHV4DZPOSITIVE < uint16_t > ::operator%(CHV4DZPOSITIVE < uint16_t > const& x) const
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

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator&(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data & x();
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator|(CHV4DZPOSITIVE const x) const
	{
		return Data | x();
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator^(CHV4DZPOSITIVE const x) const
	{
		return Data ^ x();
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator>>(CHV4DZPOSITIVE < uint16_t > const x) const
	{
		return Data >> x();
	}

	CHV4DZPOSITIVE < uint16_t > CHV4DZPOSITIVE < uint16_t > ::operator<<(CHV4DZPOSITIVE const x) const
	{
		return Data << x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator!() const
	{
		return !Data;
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator&&(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data && x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator||(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data || x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator==(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data == x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator!=(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data != x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator<(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data < x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator>(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data > x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator<=(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data <= x();
	}

	bool CHV4DZPOSITIVE < uint16_t > ::operator>=(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data >= x();
	}

	std::strong_ordering CHV4DZPOSITIVE < uint16_t > ::operator<=>(CHV4DZPOSITIVE < uint16_t > const& x) const
	{
		return Data <=> x();
	}

	void CHV4DZPOSITIVE < uint16_t > ::operator+=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator-=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator*=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator&=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator|=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator^=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator>>=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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

	void CHV4DZPOSITIVE < uint16_t > ::operator<<=(CHV4DZPOSITIVE < uint16_t > const& x)
	{
		CHV4DZPOSITIVE A{ *this }, B{ x };

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