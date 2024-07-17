module;

#include <type_traits>

#include <compare>

#include <stdexcept>

module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DINTEGER < int64_t > ::CHV4DINTEGER() { Data = 0; }

	CHV4DINTEGER < int64_t > ::CHV4DINTEGER(CHV4DINTEGER < int64_t > const& x) { Data = x(); }

	CHV4DINTEGER < int64_t > ::CHV4DINTEGER(int64_t const& x) { Data = x; }


	void CHV4DINTEGER < int64_t > ::operator=(CHV4DINTEGER < int64_t > const& x) { Data = x(); }

	void CHV4DINTEGER < int64_t > ::operator=(int64_t  const& x) { Data = x; }


	int64_t CHV4DINTEGER < int64_t > ::operator()() const { return Data; }

	unsigned char& CHV4DINTEGER < int64_t > ::operator[](size_t const& i)
	{
		if (i > 7) throw std::runtime_error{ "Index Out of Range." };

		return reinterpret_cast<unsigned char*>(&Data)[7 - i];
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator++()
	{
		if (Data == 9223372036854775807i64) throw std::overflow_error{ "Integer Increment Overflow." };

		Data = Data + 1;

		return Data;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator++(int)
	{
		if (Data == 9223372036854775807i64) throw std::overflow_error{ "Integer Increment Overflow." };

		int64_t Q = Data;

		Data = Data + 1;

		return Q;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator--()
	{
		if (Data == -9223372036854775807i64) throw std::overflow_error{ "Integer Decrement Overflow." };

		Data = Data - 1;

		return Data;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator--(int)
	{
		if (Data == -9223372036854775807i64) throw std::overflow_error{ "Integer Decrement Overflow." };

		int64_t Q = Data;

		Data = Data - 1;

		return Q;
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator+() const
	{
		return int64_t{ Data };
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator-() const
	{
		return int64_t{ -1 * Data };
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator+(CHV4DINTEGER < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() };

		if (A >= 0 && B >= 0)
		{
			if (A > (9223372036854775807 - B)) throw std::overflow_error{ "Integer Addition Overflow." };

			A = A + B;
		}
		else if (A < 0 && B < 0)
		{
			if ((-A) > (9223372036854775807 - (-B))) throw std::overflow_error{ "Integer Addition Overflow." };

			A = A + B;
		}
		else
		{
			A = A + B;
		}

		if (A < -9223372036854775807i64 || A > 9223372036854775807i64) throw std::overflow_error{ "Integer Addition Overflow." };

		return A;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator-(CHV4DINTEGER < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() };

		if(A >= 0 && B < 0)
		{
			if(A > (9223372036854775807 + B))

			A = A - B;
		}
		else if (A < 0 && B >= 0)
		{
			if (A < (-9223372036854775807 - B))

			A = A - B;
		}
		else
		{
			A = A - B;
		}

		if (A < -9223372036854775807i64 || A > 9223372036854775807i64) throw std::overflow_error{ "Integer Addition Overflow." };

		return A;
	}

	CHV4DMANTISSA < double > CHV4DINTEGER< int64_t > ::operator/(CHV4DMANTISSA < double > const& x) const
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

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator*(CHV4DINTEGER < int64_t > const& x) const
	{
		int64_t A{ Data }, B{ x() }, Q{ 0 };

		bool sign = !(A < 0) != !(B < 0) ? true : false;

		for (size_t i = 63; i > 0; --i)
		{
			if (B & 0x0000000000000001ui64) { Q += A; }

			B >>= 1;

			if (B != 0 && A >= 0x8000000000000000ui64)
			{
				throw std::overflow_error{ "Integer Multiplication Overflow." };
			}

			A <<= 1;
		}

		if (Q > 9223372036854775807i64) throw std::overflow_error{ "Integer Multiplication Overflow." };

		Q = sign ? (-1 * Q) : Q; 

		return Q;
	}

	CHV4DINTEGER < int64_t > CHV4DINTEGER< int64_t > ::operator%(CHV4DINTEGER < int64_t > const& x) const
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
		
		return sign ? static_cast<int64_t>(-1 * A) : static_cast<int64_t>(A);
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator&(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data & x();
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator|(CHV4DINTEGER const x) const
	{
		return Data | x();
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator^(CHV4DINTEGER const x) const
	{
		return Data ^ x();
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator>>(CHV4DINTEGER< int64_t > const x) const
	{
		return Data >> x();
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator<<(CHV4DINTEGER const x) const
	{
		return Data << x();
	}


	bool CHV4DINTEGER< int64_t > ::operator!() const
	{
		return !Data;
	}

	bool CHV4DINTEGER< int64_t > ::operator&&(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data && x();
	}

	bool CHV4DINTEGER< int64_t > ::operator||(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data || x();
	}

	bool CHV4DINTEGER< int64_t > ::operator==(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data == x();
	}

	bool CHV4DINTEGER< int64_t > ::operator!=(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data != x();
	}

	bool CHV4DINTEGER< int64_t > ::operator<(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data < x();
	}

	bool CHV4DINTEGER< int64_t > ::operator>(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data > x();
	}

	bool CHV4DINTEGER< int64_t > ::operator<=(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data <= x();
	}

	bool CHV4DINTEGER< int64_t > ::operator>=(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data >= x();
	}

	std::weak_ordering CHV4DINTEGER< int64_t > ::operator<=>(CHV4DINTEGER < int64_t > const& x) const
	{
		return Data <=> x();
	}


	void CHV4DINTEGER< int64_t > ::operator+=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator-=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator*=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator&=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator|=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator^=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator>>=(CHV4DINTEGER < int64_t > const& x)
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

	void CHV4DINTEGER< int64_t > ::operator<<=(CHV4DINTEGER < int64_t > const& x)
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