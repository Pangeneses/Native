module;

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DINTEGER < int64_t > ::CHV4DINTEGER() { Data = 0; }

	CHV4DINTEGER < int64_t > ::CHV4DINTEGER(CHV4DINTEGER const& x) { Data = x(); }

	CHV4DINTEGER < int64_t > ::CHV4DINTEGER(int64_t const& x) { Data = x; }


	void CHV4DINTEGER < int64_t > ::operator=(CHV4DINTEGER const& x) { Data = x(); }

	void CHV4DINTEGER < int64_t > ::operator=(int64_t  const& x) { Data = x; }


	int64_t CHV4DINTEGER < int64_t > ::operator()() const { return Data; }

	unsigned char& CHV4DINTEGER < int64_t > ::operator[](size_t const& i)
	{
		if (i > 0) throw std::runtime_error{ "Index out of range." };

		return reinterpret_cast<unsigned char*>(Data)[0];
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator++()
	{
		if (Data == 127i64) throw std::overflow_error{ "Integer overflow" };

		Data = Data + 1;

		return Data;
	}
	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator++(int)
	{
		if (Data == 127i64) throw std::overflow_error{ "Integer overflow" };

		int64_t Q = Data;

		Data = Data + 1;

		return Q;
	}
	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator--()
	{
		if (Data == -127i64) throw std::overflow_error{ "Integer overflow" };

		Data = Data - 1;

		return Data;
	}
	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator--(int)
	{
		if (Data == -127i64) throw std::overflow_error{ "Integer overflow" };

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


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator+(CHV4DINTEGER const& x) const
	{
		int16_t A{ Data }, B{ x() };

		A = A + B;

		if (A < -127i16 || A > 127i16) throw std::overflow_error{ "Integer overflow." };

		return A;
	}
	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator-(CHV4DINTEGER const& x) const
	{
		int16_t A{ Data }, B{ x() };

		A = A - B;

		if (A < -127i16 || A > 127i16) throw std::overflow_error{ "Integer overflow." };

		return A;
	}


	double CHV4DINTEGER< int64_t > ::operator/(double const& x) const
	{
		if (x == 0) throw std::runtime_error{ "Division by zero." };

		if (Data == 0) return 0.0;

		CHV4DMANTISSA < double > A{ Data }, B{ x }, Result{}; uint64_t Q{ 0 };

		try { A.Mantissa(A.Mantissa() | ((A.Mantissa() >> 1) | 0x8000000000000000ui64)); }

		catch (std::runtime_error error) { throw error; }

		try { B.Mantissa(B.Mantissa() | ((B.Mantissa() >> 1) | 0x8000000000000000ui64)); }

		catch (std::runtime_error error) { throw error; }

		for (size_t i = 0; i < 16; ++i)
		{
			if (A.Mantissa() - B.Mantissa() >= 0)
			{
				try
				{
					A.Mantissa(A.Mantissa() - B.Mantissa());
				}
				catch (std::runtime_error error)
				{
					throw error;
				}

				Q |= 0x0000000000000001ui64;
			}

			A.Mantissa(A.Mantissa() << 1);

			Q = Q << 1;
		}

		Result.Sign() = (!A.Sign() != !B.Sign()) ? true : false;

		int16_t exponent = (A.Exponent() - 127ui8) - (B.Exponent() - 127ui8) + 127ui16;

		while (Q > 16777216i16) { Q >>= 1; ++exponent; }

		while (Q < 16777216i16) { Q <<= 1; --exponent; }

		if (exponent > 127i16 || exponent < -127i16) throw std::overflow_error{ "Precision32 Division Overflow." };

		try
		{
			Result.Mantissa(Q |= 0x8000000000000000ui64);
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		try
		{
			Result.Exponent(exponent);
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		return Result();
	}


	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator*(CHV4DINTEGER const& x) const
	{
		int64_t A{ Data }, B{ x() };

		int16_t Q = A * B;

		if (Q > 127i16 || Q < -127i16) throw std::overflow_error{ "Integer overflow." };

		return static_cast<int64_t>(Q);
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator%(CHV4DINTEGER const& x) const
	{
		int64_t A{ Data }, B{ x() };

		uint64_t Q{ 0 };

		if (A == 0) return A;

		A = A < 0 ? -1 * A : A;
		B = B < 0 ? -1 * B : B;

		for (size_t i = 0; i < 64; ++i)
		{
			if (A - B >= 0)
			{
				A = A - B;

				Q |= 0x0000000000000001;
			}

			A = A << 1;

			Q = Q << 1;
		}

		A = A - (Q * B);

		return A;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator~() const
	{
		return ~Data;
	}

	CHV4DINTEGER< int64_t > CHV4DINTEGER< int64_t > ::operator&(CHV4DINTEGER const& x) const
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
	bool CHV4DINTEGER< int64_t > ::operator&&(CHV4DINTEGER const& x) const
	{
		return Data && x();
	}
	bool CHV4DINTEGER< int64_t > ::operator||(CHV4DINTEGER const& x) const
	{
		return Data || x();
	}
	bool CHV4DINTEGER< int64_t > ::operator==(CHV4DINTEGER const& x) const
	{
		return Data == x();
	}
	bool CHV4DINTEGER< int64_t > ::operator!=(CHV4DINTEGER const& x) const
	{
		return Data != x();
	}
	bool CHV4DINTEGER< int64_t > ::operator<(CHV4DINTEGER const& x) const
	{
		return Data < x();
	}
	bool CHV4DINTEGER< int64_t > ::operator>(CHV4DINTEGER const& x) const
	{
		return Data > x();
	}
	bool CHV4DINTEGER< int64_t > ::operator<=(CHV4DINTEGER const& x) const
	{
		return Data <= x();
	}
	bool CHV4DINTEGER< int64_t > ::operator>=(CHV4DINTEGER const& x) const
	{
		return Data >= x();
	}
	std::weak_ordering CHV4DINTEGER< int64_t > ::operator<=>(CHV4DINTEGER const& x) const
	{
		return Data <=> x();
	}

	void CHV4DINTEGER< int64_t > ::operator+=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator-=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator*=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator/=(CHV4DINTEGER const&) {}

	void CHV4DINTEGER< int64_t > ::operator%=(CHV4DINTEGER const& x)
	{
		CHV4DINTEGER A{ *this }, B{ x };

		try
		{
			A = A.operator%(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		*this = A;
	}

	void CHV4DINTEGER< int64_t > ::operator&=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator|=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator^=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator>>=(CHV4DINTEGER const& x)
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

	void CHV4DINTEGER< int64_t > ::operator<<=(CHV4DINTEGER const& x)
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