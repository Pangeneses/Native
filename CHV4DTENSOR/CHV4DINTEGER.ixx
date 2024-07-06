module;

#include <type_traits>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template <assert_signed_int T>
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() = default;

	};

	template <> class CHV4DINTEGER < int8_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER const& x);

		CHV4DINTEGER(int8_t const& x);

	public:
		void operator=(CHV4DINTEGER const& x);

		void operator=(int8_t const& x);

		int8_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER operator++();

		CHV4DINTEGER operator++(int);

		CHV4DINTEGER operator--();

		CHV4DINTEGER operator--(int);


		CHV4DINTEGER operator+() const;

		CHV4DINTEGER operator-() const;


		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator-(CHV4DINTEGER const& x) const;


		double operator/(double const& x) const;


		CHV4DINTEGER operator*(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator%(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator~() const;

		CHV4DINTEGER operator&(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator|(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator^(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator>>(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator<<(CHV4DINTEGER const x) const;

		bool operator!() const;

		bool operator&&(CHV4DINTEGER const& x) const;

		bool operator||(CHV4DINTEGER const& x) const;

		bool operator==(CHV4DINTEGER const& x) const;

		bool operator!=(CHV4DINTEGER const& x) const;

		bool operator<(CHV4DINTEGER const& x) const;

		bool operator>(CHV4DINTEGER const& x) const;

		bool operator<=(CHV4DINTEGER const& x) const;

		bool operator>=(CHV4DINTEGER const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER const& x) const;


		void operator+=(CHV4DINTEGER const& x);

		void operator-=(CHV4DINTEGER const& x);

		void operator*=(CHV4DINTEGER const& x);

	private:
		void operator/=(CHV4DINTEGER const&) {}

	public:
		void operator%=(CHV4DINTEGER const& x);

		void operator&=(CHV4DINTEGER const& x);

		void operator|=(CHV4DINTEGER const& x);

		void operator^=(CHV4DINTEGER const& x);

		void operator>>=(CHV4DINTEGER const& x);

		void operator<<=(CHV4DINTEGER const& x);

	private:
		int8_t Data{ 0 };
	};

	template <> class CHV4DINTEGER < int16_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER const& x);

		CHV4DINTEGER(int16_t const& x);

	public:
		void operator=(CHV4DINTEGER const& x);

		void operator=(int16_t const& x);

		int16_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER operator++();

		CHV4DINTEGER operator++(int);

		CHV4DINTEGER operator--();

		CHV4DINTEGER operator--(int);


		CHV4DINTEGER operator+() const;

		CHV4DINTEGER operator-() const;


		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator-(CHV4DINTEGER const& x) const;


		double operator/(double const& x) const;


		CHV4DINTEGER operator*(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator%(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator~() const;

		CHV4DINTEGER operator&(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator|(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator^(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator>>(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator<<(CHV4DINTEGER const x) const;

		bool operator!() const;

		bool operator&&(CHV4DINTEGER const& x) const;

		bool operator||(CHV4DINTEGER const& x) const;

		bool operator==(CHV4DINTEGER const& x) const;

		bool operator!=(CHV4DINTEGER const& x) const;

		bool operator<(CHV4DINTEGER const& x) const;

		bool operator>(CHV4DINTEGER const& x) const;

		bool operator<=(CHV4DINTEGER const& x) const;

		bool operator>=(CHV4DINTEGER const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER const& x) const;


		void operator+=(CHV4DINTEGER const& x);

		void operator-=(CHV4DINTEGER const& x);

		void operator*=(CHV4DINTEGER const& x);

	private:
		void operator/=(CHV4DINTEGER const&) {}

	public:
		void operator%=(CHV4DINTEGER const& x);

		void operator&=(CHV4DINTEGER const& x);

		void operator|=(CHV4DINTEGER const& x);

		void operator^=(CHV4DINTEGER const& x);

		void operator>>=(CHV4DINTEGER const& x);

		void operator<<=(CHV4DINTEGER const& x);

	private:
		int16_t Data{ 0 };
	};

	template <> class CHV4DINTEGER < int32_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER const& x);

		CHV4DINTEGER(int32_t const& x);

	public:
		void operator=(CHV4DINTEGER const& x);

		void operator=(int32_t const& x);

		int32_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER operator++();

		CHV4DINTEGER operator++(int);

		CHV4DINTEGER operator--();

		CHV4DINTEGER operator--(int);


		CHV4DINTEGER operator+() const;

		CHV4DINTEGER operator-() const;


		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator-(CHV4DINTEGER const& x) const;


		double operator/(double const& x) const;


		CHV4DINTEGER operator*(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator%(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator~() const;

		CHV4DINTEGER operator&(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator|(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator^(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator>>(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator<<(CHV4DINTEGER const x) const;

		bool operator!() const;

		bool operator&&(CHV4DINTEGER const& x) const;

		bool operator||(CHV4DINTEGER const& x) const;

		bool operator==(CHV4DINTEGER const& x) const;

		bool operator!=(CHV4DINTEGER const& x) const;

		bool operator<(CHV4DINTEGER const& x) const;

		bool operator>(CHV4DINTEGER const& x) const;

		bool operator<=(CHV4DINTEGER const& x) const;

		bool operator>=(CHV4DINTEGER const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER const& x) const;


		void operator+=(CHV4DINTEGER const& x);

		void operator-=(CHV4DINTEGER const& x);

		void operator*=(CHV4DINTEGER const& x);

	private:
		void operator/=(CHV4DINTEGER const&) {}

	public:
		void operator%=(CHV4DINTEGER const& x);

		void operator&=(CHV4DINTEGER const& x);

		void operator|=(CHV4DINTEGER const& x);

		void operator^=(CHV4DINTEGER const& x);

		void operator>>=(CHV4DINTEGER const& x);

		void operator<<=(CHV4DINTEGER const& x);

	private:
		int32_t Data{ 0 };
	};

	template <> class CHV4DINTEGER < int64_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER const& x);

		CHV4DINTEGER(int64_t const& x);

	public:
		void operator=(CHV4DINTEGER const& x);

		void operator=(int64_t const& x);

		int64_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER operator++();

		CHV4DINTEGER operator++(int);

		CHV4DINTEGER operator--();

		CHV4DINTEGER operator--(int);


		CHV4DINTEGER operator+() const;

		CHV4DINTEGER operator-() const;


		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator-(CHV4DINTEGER const& x) const;


		double operator/(double const& x) const;


		CHV4DINTEGER operator*(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator%(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator~() const;

		CHV4DINTEGER operator&(CHV4DINTEGER const& x) const;

		CHV4DINTEGER operator|(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator^(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator>>(CHV4DINTEGER const x) const;

		CHV4DINTEGER operator<<(CHV4DINTEGER const x) const;

		bool operator!() const;

		bool operator&&(CHV4DINTEGER const& x) const;

		bool operator||(CHV4DINTEGER const& x) const;

		bool operator==(CHV4DINTEGER const& x) const;

		bool operator!=(CHV4DINTEGER const& x) const;

		bool operator<(CHV4DINTEGER const& x) const;

		bool operator>(CHV4DINTEGER const& x) const;

		bool operator<=(CHV4DINTEGER const& x) const;

		bool operator>=(CHV4DINTEGER const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER const& x) const;


		void operator+=(CHV4DINTEGER const& x);

		void operator-=(CHV4DINTEGER const& x);

		void operator*=(CHV4DINTEGER const& x);

	private:
		void operator/=(CHV4DINTEGER const&) {}

	public:
		void operator%=(CHV4DINTEGER const& x);

		void operator&=(CHV4DINTEGER const& x);

		void operator|=(CHV4DINTEGER const& x);

		void operator^=(CHV4DINTEGER const& x);

		void operator>>=(CHV4DINTEGER const& x);

		void operator<<=(CHV4DINTEGER const& x);

	private:
		int64_t Data{ 0 };
	};

}