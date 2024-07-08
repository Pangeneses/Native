module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template<assert_precision T>
	class CHV4DPRECISION
	{
	public:
		CHV4DPRECISION() = default;

	};

	template<> class CHV4DPRECISION < float >
	{
	public:
		CHV4DPRECISION();

		CHV4DPRECISION(CHV4DPRECISION < float > const& x);

		CHV4DPRECISION(float const& x);

	public:
		void operator=(CHV4DPRECISION < float > const& x);

		void operator=(float const& x);


		CHV4DPRECISION < float > operator()() const;

	private:
		CHV4DPRECISION < float > operator[](int) const {};


	public:
		CHV4DPRECISION < float > operator++();

		CHV4DPRECISION < float > operator++(int);

		CHV4DPRECISION < float > operator--();

		CHV4DPRECISION < float > operator--(int);


		CHV4DPRECISION < float > operator+() const;

		CHV4DPRECISION < float > operator-() const;


		CHV4DPRECISION < float > operator+(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator-(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator/(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator*(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator%(CHV4DPRECISION < float > const& x) const;


		CHV4DPRECISION < float > operator~() const;

		CHV4DPRECISION < float > operator&(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator|(CHV4DPRECISION < float > const x) const;

		CHV4DPRECISION < float > operator^(CHV4DPRECISION < float > const x) const;

		CHV4DPRECISION < float > operator>>(CHV4DPRECISION < float > const x) const;

		CHV4DPRECISION < float > operator<<(CHV4DPRECISION < float > const x) const;

		
		bool operator!() const;

		bool operator&&(CHV4DPRECISION < float > const& x) const;

		bool operator||(CHV4DPRECISION < float > const& x) const;

		bool operator==(CHV4DPRECISION < float > const& x) const;

		bool operator!=(CHV4DPRECISION < float > const& x) const;

		bool operator<(CHV4DPRECISION < float > const& x) const;

		bool operator>(CHV4DPRECISION < float > const& x) const;

		bool operator<=(CHV4DPRECISION < float > const& x) const;

		bool operator>=(CHV4DPRECISION < float > const& x) const;

		std::strong_ordering operator<=>(CHV4DPRECISION < float > const& x) const;


		void operator+=(CHV4DPRECISION < float > const& x);

		void operator-=(CHV4DPRECISION < float > const& x);

		void operator*=(CHV4DPRECISION < float > const& x);

		void operator/=(CHV4DPRECISION < float > const&) {}

	public:
		void operator%=(CHV4DPRECISION < float > const& x);

		void operator&=(CHV4DPRECISION < float > const& x);

		void operator|=(CHV4DPRECISION < float > const& x);

		void operator^=(CHV4DPRECISION < float > const& x);

		void operator>>=(CHV4DPRECISION < float > const& x);

		void operator<<=(CHV4DPRECISION < float > const& x);

	public:
		CHV4DMANTISSA < float > const& Radix() const { return Data; }

	public:
		CHV4DMANTISSA < float > Data;

	};
}