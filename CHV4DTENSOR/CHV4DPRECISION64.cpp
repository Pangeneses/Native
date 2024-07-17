module;

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DPRECISION < double > ::CHV4DPRECISION() { Data = 0.0f; }

	CHV4DPRECISION < double > ::CHV4DPRECISION(CHV4DPRECISION < double > const& x) { Data = x.Data; }

	CHV4DPRECISION < double > ::CHV4DPRECISION(double const& x) { Data = x; }

	void CHV4DPRECISION < double > ::operator=(CHV4DPRECISION < double > const& x) { Data = x.Data; }

	void CHV4DPRECISION < double > ::operator=(double const& x) { Data = x; }

	double CHV4DPRECISION < double > ::operator()() const { return Data(); }

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator++()
	{
		try
		{
			Data = this->operator+(CHV4DPRECISION < double >{ 1.0f })();
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		return *this;
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator++(int)
	{
		CHV4DPRECISION < double > A{ *this };

		try
		{
			Data = this->operator+(CHV4DPRECISION < double >{ 1.0f })();
		}
		catch (std::overflow_error error)
		{
			throw error;
		}
		return A;
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator--()
	{
		try
		{
			Data = this->operator-(CHV4DPRECISION < double >{ 1.0f })();
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		return *this;
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator--(int)
	{
		CHV4DPRECISION < double > A{ *this };

		try
		{
			Data = this->operator-(CHV4DPRECISION < double >{ 1.0f })();
		}
		catch (std::overflow_error error)
		{
			throw error;
		}
		return A;
	}


	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator+() const
	{
		return { *this };
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator-() const
	{
		CHV4DPRECISION < double > A{ *this };

		A.Data.Sign() = A.Data.Sign() ? false : true;

		return A;
	}


	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator+(CHV4DPRECISION < double > const& x) const
	{
		if (Data.IsMaximum()) throw std::overflow_error{ "Precision32 Addition Overflow." };

		CHV4DMANTISSA < double > A{ Data }, B{ x() };

		int32_t delta = A.Exponent() - B.Exponent();

		if (delta > 24) return A(); if (delta < -24) return B();

		A.Mantissa(A.Mantissa() | 0x00400000ui32); B.Mantissa(B.Mantissa() | 0x00400000ui32);

		while (delta > 0)
		{
			A.Exponent(A.Exponent() + 1);
			A.Mantissa(A.Mantissa() >> 1);

			B.Exponent(B.Exponent() - 1);
			B.Mantissa(B.Mantissa() << 1);
		}

		while (delta < 0)
		{
			A.Exponent(A.Exponent() - 1);
			A.Mantissa(A.Mantissa() << 1);

			B.Exponent(B.Exponent() + 1);
			B.Mantissa(B.Mantissa() >> 1);
		}

		int64_t mantissa{ 0 };

		if (!A.Sign() != !B.Sign())
		{
			if (A.Sign())
			{
				mantissa = B.Mantissa() - A.Mantissa();

				A.Sign() = mantissa < 0 ? true : false;
			}
			else
			{
				mantissa = A.Mantissa() - B.Mantissa();

				A.Sign() = mantissa < 0 ? true : false;
			}
		}
		else
		{
			mantissa = A.Mantissa() + B.Mantissa();
		}

		mantissa &= 0x7FFFFFFF;

		if ((mantissa > 0x00FFFFFF) && (A.Exponent() == 0xFF))
		{
			throw std::overflow_error{ "Precision32 Addition Overflow." };
		}
		else if (mantissa > 0x00FFFFFF)
		{
			mantissa >>= 1;

			A.Mantissa(mantissa & 0x0007FFFFF);

			A.Exponent(A.Exponent() + 1);
		}

		return A();
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator-(CHV4DPRECISION < double > const& x) const
	{
		if (Data.IsMaximum()) throw std::overflow_error{ "Precision32 Addition Overflow." };

		CHV4DMANTISSA < double > A{ Data }, B{ x() };

		B.Sign() = B.Sign() ? false : true;

		int32_t delta = A.Exponent() - B.Exponent();

		if (delta > 24) return A(); if (delta < -24) return B();

		A.Mantissa(A.Mantissa() | 0x00400000ui32); B.Mantissa(B.Mantissa() | 0x00400000ui32);

		while (delta > 0)
		{
			A.Exponent(A.Exponent() + 1);
			A.Mantissa(A.Mantissa() >> 1);

			B.Exponent(B.Exponent() - 1);
			B.Mantissa(B.Mantissa() << 1);
		}

		while (delta < 0)
		{
			A.Exponent(A.Exponent() - 1);
			A.Mantissa(A.Mantissa() << 1);

			B.Exponent(B.Exponent() + 1);
			B.Mantissa(B.Mantissa() >> 1);
		}

		int64_t mantissa{ 0 };

		if (!A.Sign() != !B.Sign())
		{
			if (A.Sign())
			{
				mantissa = B.Mantissa() - A.Mantissa();

				A.Sign() = mantissa < 0 ? true : false;
			}
			else
			{
				mantissa = A.Mantissa() - B.Mantissa();

				A.Sign() = mantissa < 0 ? true : false;
			}
		}
		else
		{
			mantissa = A.Mantissa() + B.Mantissa();
		}

		mantissa &= 0x7FFFFFFF;

		if ((mantissa > 0x00FFFFFF) && (A.Exponent() == 0xFF))
		{
			throw std::overflow_error{ "Precision32 Addition Overflow." };
		}
		else if (mantissa > 0x00FFFFFF)
		{
			mantissa >>= 1;

			A.Mantissa(mantissa & 0x0007FFFFF);

			A.Exponent(A.Exponent() + 1);
		}

		return A();
	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator/(CHV4DPRECISION < double > const& x) const
	{


	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator*(CHV4DPRECISION < double > const& x) const
	{


	}

	CHV4DPRECISION < double > CHV4DPRECISION < double > ::operator%(CHV4DPRECISION < double > const& x) const
	{


	}

	bool CHV4DPRECISION < double > ::operator==(CHV4DPRECISION < double > const& x) const
	{
		return Data() == x() ? true : false;
	}

	bool CHV4DPRECISION < double > ::operator!=(CHV4DPRECISION < double > const& x) const
	{
		return Data() != x() ? true : false;
	}

	bool CHV4DPRECISION < double > ::operator<(CHV4DPRECISION < double > const& x) const
	{
		return Data() < x() ? true : false;
	}

	bool CHV4DPRECISION < double > ::operator>(CHV4DPRECISION < double > const& x) const
	{
		return Data() > x() ? true : false;
	}

	bool CHV4DPRECISION < double > ::operator<=(CHV4DPRECISION < double > const& x) const
	{
		return Data() <= x() ? true : false;
	}

	bool CHV4DPRECISION < double > ::operator>=(CHV4DPRECISION < double > const& x) const
	{
		return Data() >= x() ? true : false;
	}

	std::partial_ordering CHV4DPRECISION < double > ::operator<=>(CHV4DPRECISION < double > const& x) const
	{
		return Data() <=> x();
	}

	void CHV4DPRECISION < double > ::operator+=(CHV4DPRECISION < double > const& x)
	{
		CHV4DPRECISION < double > A{ *this }, B{ x };

		try
		{
			A = A.operator+(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		this->operator=(A);
	}

	void CHV4DPRECISION < double > ::operator-=(CHV4DPRECISION < double > const& x)
	{
		CHV4DPRECISION < double > A{ *this }, B{ x };

		try
		{
			A = A.operator-(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		this->operator=(A);
	}

	void CHV4DPRECISION < double > ::operator*=(CHV4DPRECISION < double > const& x)
	{
		CHV4DPRECISION < double > A{ *this }, B{ x };

		try
		{
			A = A.operator*(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		this->operator=(A);
	}

	void CHV4DPRECISION < double > ::operator/=(CHV4DPRECISION < double > const& x)
	{
		CHV4DPRECISION < double > A{ *this }, B{ x };

		try
		{
			A = A.operator/(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		this->operator=(A);
	}

	void CHV4DPRECISION < double > ::operator%=(CHV4DPRECISION < double > const& x)
	{
		CHV4DPRECISION < double > A{ *this }, B{ x };

		try
		{
			A = A.operator%(B);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		this->operator=(A);
	}

}