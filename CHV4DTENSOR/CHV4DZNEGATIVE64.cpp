module;

#include <type_traits>

#include <compare>

#include <stdexcept>

module CHV4DTENSOR:CHV4DZNEGATIVE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DZNEGATIVE < int64_t > ::CHV4DZNEGATIVE() { Data = -1i64; }

	CHV4DZNEGATIVE < int64_t > ::CHV4DZNEGATIVE(CHV4DZNEGATIVE < int64_t > const& x) { Data = x(); }

	CHV4DZNEGATIVE < int64_t > ::CHV4DZNEGATIVE(int64_t const& x) { Data = x; }

	void CHV4DZNEGATIVE < int64_t > ::operator=(CHV4DZNEGATIVE < int64_t > const& x) { Data = x(); }

	void CHV4DZNEGATIVE < int64_t > ::operator=(int64_t  const& x) { Data = x; }

	int64_t CHV4DZNEGATIVE < int64_t > ::operator()() const { return Data; }

	unsigned char& CHV4DZNEGATIVE < int64_t > ::operator[](size_t const& i)
	{
		if (i > 7i8) throw std::runtime_error{ "Index Out of Range." };

		return reinterpret_cast<unsigned char*>(&Data)[7i8 - i];
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator++()
	{
		if (Data == -1i64) throw std::overflow_error{ "ZNegative Increment Overflow." };

		Data += 1;

		return Data;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator++(int)
	{
		if (Data == -1i64) throw std::overflow_error{ "ZNegative Increment Overflow." };

		int64_t Q = Data;

		Data += 1;

		return Q;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator--()
	{
		if (Data == std::numeric_limits<int64_t>::min()) throw std::overflow_error{ "ZNegative Decrement Overflow." };

		Data -= 1;

		return Data;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator--(int)
	{
		if (Data == std::numeric_limits<int64_t>::min()) throw std::overflow_error{ "ZNegative Decrement Overflow." };

		int64_t Q = Data;

		Data -= 1;

		return Q;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator+() const
	{
		return int64_t{ Data };
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator-() const
	{
		return int64_t{ -1 * Data };
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator+(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() };

		if (A <= (std::numeric_limits<int64_t>::min() - B)) throw std::overflow_error{ "ZNegative Addition Overflow." };

		A += B;

		return A;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator-(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() };

		A -= B;

		if (A < std::numeric_limits<int64_t>::min() || A > -1i64) throw std::overflow_error{ "ZNegative Addition Overflow." };

		return A;
	}

	CHV4DMANTISSA < double > CHV4DZNEGATIVE < int64_t > ::operator/(CHV4DMANTISSA < double > const& x) const
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

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator*(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() }, Q{ 0 };

		bool sign = !(A < 0) != !(B < 0) ? true : false;

		for (size_t i = 63; i > 0; --i)
		{
			if (B & 0x0000000000000001ui64) { Q += A; }

			B >>= 1;

			if (B != 0 && A >= 0x8000000000000000ui64)
			{
				throw std::overflow_error{ "ZNegative Multiplication Overflow." };
			}

			A <<= 1;
		}

		Q = sign ? (-1 * Q) : Q;

		if (Q > -1i64) throw std::overflow_error{ "ZNegative Multiplication Overflow." };

		return Q;
	}

	size_t CHV4DZNEGATIVE < int64_t > ::operator%(CHV4DZNEGATIVE < int64_t > const& x) const
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

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator&(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data & x();
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator|(CHV4DZNEGATIVE const x) const
	{
		return Data | x();
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator^(CHV4DZNEGATIVE const x) const
	{
		return Data ^ x();
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator>>(CHV4DZNEGATIVE < int64_t > const x) const
	{
		return Data >> x();
	}

	CHV4DZNEGATIVE < int64_t > CHV4DZNEGATIVE < int64_t > ::operator<<(CHV4DZNEGATIVE const x) const
	{
		return Data << x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator!() const
	{
		return !Data;
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator&&(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data && x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator||(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data || x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator==(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data == x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator!=(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data != x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator<(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data < x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator>(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data > x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator<=(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data <= x();
	}

	bool CHV4DZNEGATIVE < int64_t > ::operator>=(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data >= x();
	}

	std::weak_ordering CHV4DZNEGATIVE < int64_t > ::operator<=>(CHV4DZNEGATIVE < int64_t > const& x) const
	{
		return Data <=> x();
	}

	void CHV4DZNEGATIVE < int64_t > ::operator+=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator-=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator*=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator&=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator|=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator^=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator>>=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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

	void CHV4DZNEGATIVE < int64_t > ::operator<<=(CHV4DZNEGATIVE < int64_t > const& x)
	{
		CHV4DZNEGATIVE A{ *this }, B{ x };

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