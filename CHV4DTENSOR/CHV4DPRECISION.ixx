module;

#include <compare>

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


		float operator()() const;

	private:
		CHV4DPRECISION < float > operator[](int) const {};


	public:
		CHV4DPRECISION < float > operator++();

		CHV4DPRECISION < float > operator++(int);

		CHV4DPRECISION < float > operator--();

		CHV4DPRECISION < float > operator--(int);


	public:
		CHV4DPRECISION < float > operator+() const;

		CHV4DPRECISION < float > operator-() const;

		CHV4DPRECISION < float > operator+(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator-(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator/(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator*(CHV4DPRECISION < float > const& x) const;

		CHV4DPRECISION < float > operator%(CHV4DPRECISION < float > const& x) const;


	private:
		CHV4DPRECISION < float > operator~() const { return {}; }

		CHV4DPRECISION < float > operator&(CHV4DPRECISION < float > const& x) const { return {}; }

		CHV4DPRECISION < float > operator|(CHV4DPRECISION < float > const x) const { return {}; }

		CHV4DPRECISION < float > operator^(CHV4DPRECISION < float > const x) const { return {}; }

		CHV4DPRECISION < float > operator>>(CHV4DPRECISION < float > const x) const { return {}; }

		CHV4DPRECISION < float > operator<<(CHV4DPRECISION < float > const x) const { return {}; }

		
	private:
		bool operator!() const { return {}; }

		bool operator&&(CHV4DPRECISION < float > const& x) const { return {}; }

		bool operator||(CHV4DPRECISION < float > const& x) const { return {}; }


	public:
		bool operator==(CHV4DPRECISION < float > const& x) const;

		bool operator!=(CHV4DPRECISION < float > const& x) const;

		bool operator<(CHV4DPRECISION < float > const& x) const;

		bool operator>(CHV4DPRECISION < float > const& x) const;

		bool operator<=(CHV4DPRECISION < float > const& x) const;

		bool operator>=(CHV4DPRECISION < float > const& x) const;

		std::partial_ordering operator<=>(CHV4DPRECISION < float > const& x) const;


	public:
		void operator+=(CHV4DPRECISION < float > const& x);

		void operator-=(CHV4DPRECISION < float > const& x);

		void operator*=(CHV4DPRECISION < float > const& x);

		void operator/=(CHV4DPRECISION < float > const&) {}

		void operator%=(CHV4DPRECISION < float > const& x);


	private:
		void operator&=(CHV4DPRECISION < float > const& x) { }

		void operator|=(CHV4DPRECISION < float > const& x) { }

		void operator^=(CHV4DPRECISION < float > const& x) { }

		void operator>>=(CHV4DPRECISION < float > const& x) { }

		void operator<<=(CHV4DPRECISION < float > const& x) { }

	public:
		CHV4DMANTISSA < float > const& Radix() const { return Data; }


	private:
		CHV4DMANTISSA < float > Data;

	};

	template<> class CHV4DPRECISION < double >
	{
	public:
		CHV4DPRECISION();

		CHV4DPRECISION(CHV4DPRECISION < double > const& x);

		CHV4DPRECISION(double const& x);

	public:
		void operator=(CHV4DPRECISION < double > const& x);

		void operator=(double const& x);


		double operator()() const;

	private:
		CHV4DPRECISION < double > operator[](int) const {};


	public:
		CHV4DPRECISION < double > operator++();

		CHV4DPRECISION < double > operator++(int);

		CHV4DPRECISION < double > operator--();

		CHV4DPRECISION < double > operator--(int);


	public:
		CHV4DPRECISION < double > operator+() const;

		CHV4DPRECISION < double > operator-() const;

		CHV4DPRECISION < double > operator+(CHV4DPRECISION < double > const& x) const;

		CHV4DPRECISION < double > operator-(CHV4DPRECISION < double > const& x) const;

		CHV4DPRECISION < double > operator/(CHV4DPRECISION < double > const& x) const;

		CHV4DPRECISION < double > operator*(CHV4DPRECISION < double > const& x) const;

		CHV4DPRECISION < double > operator%(CHV4DPRECISION < double > const& x) const;


	private:
		CHV4DPRECISION < double > operator~() const { return {}; }

		CHV4DPRECISION < double > operator&(CHV4DPRECISION < double > const& x) const { return {}; }

		CHV4DPRECISION < double > operator|(CHV4DPRECISION < double > const x) const { return {}; }

		CHV4DPRECISION < double > operator^(CHV4DPRECISION < double > const x) const { return {}; }

		CHV4DPRECISION < double > operator>>(CHV4DPRECISION < double > const x) const { return {}; }

		CHV4DPRECISION < double > operator<<(CHV4DPRECISION < double > const x) const { return {}; }


	private:
		bool operator!() const { return {}; }

		bool operator&&(CHV4DPRECISION < double > const& x) const { return {}; }

		bool operator||(CHV4DPRECISION < double > const& x) const { return {}; }


	public:
		bool operator==(CHV4DPRECISION < double > const& x) const;

		bool operator!=(CHV4DPRECISION < double > const& x) const;

		bool operator<(CHV4DPRECISION < double > const& x) const;

		bool operator>(CHV4DPRECISION < double > const& x) const;

		bool operator<=(CHV4DPRECISION < double > const& x) const;

		bool operator>=(CHV4DPRECISION < double > const& x) const;

		std::partial_ordering operator<=>(CHV4DPRECISION < double > const& x) const;


	public:
		void operator+=(CHV4DPRECISION < double > const& x);

		void operator-=(CHV4DPRECISION < double > const& x);

		void operator*=(CHV4DPRECISION < double > const& x);

		void operator/=(CHV4DPRECISION < double > const&) {}

		void operator%=(CHV4DPRECISION < double > const& x);


	private:
		void operator&=(CHV4DPRECISION < double > const& x) { }

		void operator|=(CHV4DPRECISION < double > const& x) { }

		void operator^=(CHV4DPRECISION < double > const& x) { }

		void operator>>=(CHV4DPRECISION < double > const& x) { }

		void operator<<=(CHV4DPRECISION < double > const& x) { }

	public:
		CHV4DMANTISSA < double > const& Radix() const { return Data; }


	private:
		CHV4DMANTISSA < double > Data;

	};

	template<typename T>
	concept ASSERT_CHV4DPRECISION =
		std::is_same<T, CHV4DPRECISION < float >>::value ||
		std::is_same<T, CHV4DPRECISION < double >>::value;

}