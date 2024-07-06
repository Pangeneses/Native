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

		CHV4DPRECISION(CHV4DPRECISION const& x);

		CHV4DPRECISION(float const& x);

	public:
		void operator=(CHV4DPRECISION const& x);

		void operator=(float const& x);

		CHV4DPRECISION operator()() const;

	private:
		CHV4DPRECISION operator[](int) const {};

	public:
		CHV4DPRECISION operator++();

		CHV4DPRECISION operator++(int);

		CHV4DPRECISION operator--();

		CHV4DPRECISION operator--(int);


		CHV4DPRECISION operator+() const;

		CHV4DPRECISION operator-() const;


		CHV4DPRECISION operator+(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator-(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator/(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator*(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator%(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator~() const;

		CHV4DPRECISION operator&(CHV4DPRECISION const& x) const;

		CHV4DPRECISION operator|(CHV4DPRECISION const x) const;

		CHV4DPRECISION operator^(CHV4DPRECISION const x) const;

		CHV4DPRECISION operator>>(CHV4DPRECISION const x) const;

		CHV4DPRECISION operator<<(CHV4DPRECISION const x) const;

		bool operator!() const;

		bool operator&&(CHV4DPRECISION const& x) const;

		bool operator||(CHV4DPRECISION const& x) const;

		bool operator==(CHV4DPRECISION const& x) const;

		bool operator!=(CHV4DPRECISION const& x) const;

		bool operator<(CHV4DPRECISION const& x) const;

		bool operator>(CHV4DPRECISION const& x) const;

		bool operator<=(CHV4DPRECISION const& x) const;

		bool operator>=(CHV4DPRECISION const& x) const;

		std::weak_ordering operator<=>(CHV4DPRECISION const& x) const;


		void operator+=(CHV4DPRECISION const& x);

		void operator-=(CHV4DPRECISION const& x);

		void operator*=(CHV4DPRECISION const& x);

	private:
		void operator/=(CHV4DPRECISION const&) {}

	public:
		void operator%=(CHV4DPRECISION const& x);

		void operator&=(CHV4DPRECISION const& x);

		void operator|=(CHV4DPRECISION const& x);

		void operator^=(CHV4DPRECISION const& x);

		void operator>>=(CHV4DPRECISION const& x);

		void operator<<=(CHV4DPRECISION const& x);

	public:
		CHV4DMANTISSA< float > const& Radix() const { return Data; }

	public:
		CHV4DMANTISSA< float > Data;

	};
}