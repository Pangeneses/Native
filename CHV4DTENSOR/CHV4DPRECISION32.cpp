module;

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DPRECISION < float > ::CHV4DPRECISION() { Data = 0.0f; }

	CHV4DPRECISION < float > ::CHV4DPRECISION(CHV4DPRECISION const& x) { Data = x.Data; }

	CHV4DPRECISION < float > ::CHV4DPRECISION(float const& x) { Data = x; }

	void CHV4DPRECISION < float > ::operator=(CHV4DPRECISION const& x) { Data = x.Data; }

	void CHV4DPRECISION < float > ::operator=(float const& x) { Data = x; }

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator()() const { return *this; }

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator++()
	{
		if (Data.IsMaximum()) throw std::overflow_error{ "Precision32 Overflow." };
	
		uint32_t 


		Data.Mantissa(Data.Mantissa() + 1);

		return Data;
	}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator++(int) {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator--() {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator--(int) {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator+() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator-() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator+(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator-(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator/(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator*(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator%(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator~() const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator&(CHV4DPRECISION const& x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator|(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator^(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator>>(CHV4DPRECISION const x) const {}

	CHV4DPRECISION < float > CHV4DPRECISION < float > ::operator<<(CHV4DPRECISION const x) const {}

	bool CHV4DPRECISION < float > ::operator!() const {}

	bool CHV4DPRECISION < float > ::operator&&(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator||(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator==(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator!=(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator<(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator>(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator<=(CHV4DPRECISION const& x) const {}

	bool CHV4DPRECISION < float > ::operator>=(CHV4DPRECISION const& x) const {}

	std::weak_ordering CHV4DPRECISION < float > ::operator<=>(CHV4DPRECISION const& x) const {}

	void CHV4DPRECISION < float > ::operator+=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator-=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator*=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator/=(CHV4DPRECISION const&) {}

	void CHV4DPRECISION < float > ::operator%=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator&=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator|=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator^=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator>>=(CHV4DPRECISION const& x) {}

	void CHV4DPRECISION < float > ::operator<<=(CHV4DPRECISION const& x) {}

}