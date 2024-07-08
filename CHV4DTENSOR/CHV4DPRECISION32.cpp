module;

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DPRECISION < float > ::CHV4DPRECISION() { Data = 0.0f; }

	CHV4DPRECISION < float > ::CHV4DPRECISION(CHV4DPRECISION < float > const& x) { Data = x.Data; }

	CHV4DPRECISION < float > ::CHV4DPRECISION(float const& x) { Data = x; }

	void CHV4DPRECISION < float > ::operator=(CHV4DPRECISION < float > const& x) { Data = x.Data; }

	void CHV4DPRECISION < float > ::operator=(float const& x) { Data = x; }

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator()() const { return *this; }

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator++()
	{
		if (Data.IsMaximum()) throw std::overflow_error{ "Precision32 Overflow." };
	
		if (Data.Exponent() > 150ui8) 
		{ 
			return *this; 
		}
		else if (Data.Exponent() <= 150ui8 && Data.Exponent() >= 127ui8)
		{
			if (Data.Exponent() == 150ui8 && Data.Mantissa() == 8388608ui32)
			{
				throw std::overflow_error{ "Precision32 Overflow." };
			}
			
			uint32_t Q = Data.Mantissa() + (1ui8 << (150ui8 - 127ui8));

			if (Q > 8388608ui32) 
			{ 
				Q >>= 1;  

				try
				{
					Data.Exponent(Data.Exponent() + 1);
				}
				catch (std::overflow_error error)
				{
					throw error;
				}
			}

			try
			{
				Data.Mantissa(Q);
			}
			catch(std::overflow_error error)
			{
				throw error;
			}
		}
		else if (Data.Exponent() < 127 && Data.Exponent() >= 104)
		{
			try
			{
				Data.Mantissa(Data.Mantissa() >> (127ui8 - Data.Exponent()));
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
		}
		else
		{
			Data.Exponent(127);

			Data.Mantissa(0ui32);
		}

		try
		{
			Data.Mantissa(Data.Mantissa() + 1);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		return Data();
	}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator++(int) 
	{
		CHV4DMANTISSA < float > ret{ Data };
		
		try
		{
			Data = this->operator++().Data;
		}
		catch (std::overflow_error error)
		{
			throw error;
		}

		return ret();
	}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator--() 
	{
	
	
	}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator--(int) {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator+() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator-() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator+(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator-(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator/(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator*(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator%(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator~() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator&(CHV4DPRECISION < float > const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator|(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator^(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator>>(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator<<(CHV4DPRECISION const x) const {}

	bool CHV4DPRECISION < float > ::operator!() const {}

	bool CHV4DPRECISION < float > ::operator&&(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator||(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator==(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator!=(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator<(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator>(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator<=(CHV4DPRECISION < float > const& x) const {}

	bool CHV4DPRECISION < float > ::operator>=(CHV4DPRECISION < float > const& x) const {}

	std::strong_ordering CHV4DPRECISION < float > ::operator<=>(CHV4DPRECISION < float > const& x) const {}

	void CHV4DPRECISION < float > ::operator+=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator-=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator*=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator/=(CHV4DPRECISION < float > const&) {}

	void CHV4DPRECISION < float > ::operator%=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator&=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator|=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator^=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator>>=(CHV4DPRECISION < float > const& x) {}

	void CHV4DPRECISION < float > ::operator<<=(CHV4DPRECISION < float > const& x) {}

}