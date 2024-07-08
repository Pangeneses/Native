module;

#include <type_traits>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template <assert_opt_signed T>
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() = default;

	};

	template <> class CHV4DINTEGER < int8_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER < int8_t > const& x);

		CHV4DINTEGER(int8_t const& x);

	public:
		void operator=(CHV4DINTEGER < int8_t > const& x);

		void operator=(int8_t const& x);

		int8_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER < int8_t > operator++();

		CHV4DINTEGER < int8_t > operator++(int);

		CHV4DINTEGER < int8_t > operator--();

		CHV4DINTEGER < int8_t > operator--(int);


		CHV4DINTEGER < int8_t > operator+() const;

		CHV4DINTEGER < int8_t > operator-() const;


		CHV4DINTEGER < int8_t > operator+(CHV4DINTEGER < int8_t > const& x) const;

		CHV4DINTEGER < int8_t > operator-(CHV4DINTEGER < int8_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DINTEGER < int8_t > operator*(CHV4DINTEGER < int8_t > const& x) const;

		CHV4DINTEGER < int8_t > operator%(CHV4DINTEGER < int8_t > const& x) const;


		CHV4DINTEGER < int8_t > operator~() const;

		CHV4DINTEGER < int8_t > operator&(CHV4DINTEGER < int8_t > const& x) const;

		CHV4DINTEGER < int8_t > operator|(CHV4DINTEGER < int8_t > const x) const;

		CHV4DINTEGER < int8_t > operator^(CHV4DINTEGER < int8_t > const x) const;

		CHV4DINTEGER < int8_t > operator>>(CHV4DINTEGER < int8_t > const x) const;

		CHV4DINTEGER < int8_t > operator<<(CHV4DINTEGER < int8_t > const x) const;


		bool operator!() const;

		bool operator&&(CHV4DINTEGER < int8_t > const& x) const;

		bool operator||(CHV4DINTEGER < int8_t > const& x) const;

		bool operator==(CHV4DINTEGER < int8_t > const& x) const;

		bool operator!=(CHV4DINTEGER < int8_t > const& x) const;

		bool operator<(CHV4DINTEGER < int8_t > const& x) const;

		bool operator>(CHV4DINTEGER < int8_t > const& x) const;

		bool operator<=(CHV4DINTEGER < int8_t > const& x) const;

		bool operator>=(CHV4DINTEGER < int8_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DINTEGER < int8_t > const& x) const;


		void operator+=(CHV4DINTEGER < int8_t > const& x);

		void operator-=(CHV4DINTEGER < int8_t > const& x);

		void operator*=(CHV4DINTEGER < int8_t > const& x);

	private:
		void operator/=(CHV4DINTEGER < int8_t > const&) {}

		void operator%=(CHV4DINTEGER < int8_t > const& x);

	public:
		void operator&=(CHV4DINTEGER < int8_t > const& x);

		void operator|=(CHV4DINTEGER < int8_t > const& x);

		void operator^=(CHV4DINTEGER < int8_t > const& x);

		void operator>>=(CHV4DINTEGER < int8_t > const& x);

		void operator<<=(CHV4DINTEGER < int8_t > const& x);

	private:
		int8_t Data{ 0 };
	};

	typedef CHV4DINTEGER < int8_t > CHV4DINTEGER8;

	template <> class CHV4DINTEGER < int16_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER < int16_t > const& x);

		CHV4DINTEGER(int16_t const& x);

	public:
		void operator=(CHV4DINTEGER < int16_t > const& x);

		void operator=(int16_t const& x);

		int16_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER < int16_t > operator++();

		CHV4DINTEGER < int16_t > operator++(int);

		CHV4DINTEGER < int16_t > operator--();

		CHV4DINTEGER < int16_t > operator--(int);


		CHV4DINTEGER < int16_t > operator+() const;

		CHV4DINTEGER < int16_t > operator-() const;


		CHV4DINTEGER < int16_t > operator+(CHV4DINTEGER < int16_t > const& x) const;

		CHV4DINTEGER < int16_t > operator-(CHV4DINTEGER < int16_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DINTEGER < int16_t > operator*(CHV4DINTEGER < int16_t > const& x) const;

		CHV4DINTEGER < int16_t > operator%(CHV4DINTEGER < int16_t > const& x) const;

		CHV4DINTEGER < int16_t > operator~() const;

		CHV4DINTEGER < int16_t > operator&(CHV4DINTEGER < int16_t > const& x) const;

		CHV4DINTEGER < int16_t > operator|(CHV4DINTEGER < int16_t > const x) const;

		CHV4DINTEGER < int16_t > operator^(CHV4DINTEGER < int16_t > const x) const;

		CHV4DINTEGER < int16_t > operator>>(CHV4DINTEGER < int16_t > const x) const;

		CHV4DINTEGER < int16_t > operator<<(CHV4DINTEGER < int16_t > const x) const;


		bool operator!() const;

		bool operator&&(CHV4DINTEGER < int16_t > const& x) const;

		bool operator||(CHV4DINTEGER < int16_t > const& x) const;

		bool operator==(CHV4DINTEGER < int16_t > const& x) const;

		bool operator!=(CHV4DINTEGER < int16_t > const& x) const;

		bool operator<(CHV4DINTEGER < int16_t > const& x) const;

		bool operator>(CHV4DINTEGER < int16_t > const& x) const;

		bool operator<=(CHV4DINTEGER < int16_t > const& x) const;

		bool operator>=(CHV4DINTEGER < int16_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DINTEGER < int16_t > const& x) const;


		void operator+=(CHV4DINTEGER < int16_t > const& x);

		void operator-=(CHV4DINTEGER < int16_t > const& x);

		void operator*=(CHV4DINTEGER < int16_t > const& x);

	private:
		void operator/=(CHV4DINTEGER < int16_t > const&) {}

		void operator%=(CHV4DINTEGER < int16_t > const& x);

	public:
		void operator&=(CHV4DINTEGER < int16_t > const& x);

		void operator|=(CHV4DINTEGER < int16_t > const& x);

		void operator^=(CHV4DINTEGER < int16_t > const& x);

		void operator>>=(CHV4DINTEGER < int16_t > const& x);

		void operator<<=(CHV4DINTEGER < int16_t > const& x);

	private:
		int16_t Data{ 0 };
	};

	typedef CHV4DINTEGER < int16_t > CHV4DINTEGER16;

	template <> class CHV4DINTEGER < int32_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER < int32_t > const& x);

		CHV4DINTEGER(int32_t const& x);

	public:
		void operator=(CHV4DINTEGER < int32_t > const& x);

		void operator=(int32_t const& x);

		int32_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER < int32_t > operator++();

		CHV4DINTEGER < int32_t > operator++(int);

		CHV4DINTEGER < int32_t > operator--();

		CHV4DINTEGER < int32_t > operator--(int);


		CHV4DINTEGER < int32_t > operator+() const;

		CHV4DINTEGER < int32_t > operator-() const;


		CHV4DINTEGER < int32_t > operator+(CHV4DINTEGER < int32_t > const& x) const;

		CHV4DINTEGER < int32_t > operator-(CHV4DINTEGER < int32_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DINTEGER < int32_t > operator*(CHV4DINTEGER < int32_t > const& x) const;

		CHV4DINTEGER < int32_t > operator%(CHV4DINTEGER < int32_t > const& x) const;

		CHV4DINTEGER < int32_t > operator~() const;

		CHV4DINTEGER < int32_t > operator&(CHV4DINTEGER < int32_t > const& x) const;

		CHV4DINTEGER < int32_t > operator|(CHV4DINTEGER < int32_t > const x) const;

		CHV4DINTEGER < int32_t > operator^(CHV4DINTEGER < int32_t > const x) const;

		CHV4DINTEGER < int32_t > operator>>(CHV4DINTEGER < int32_t > const x) const;

		CHV4DINTEGER < int32_t > operator<<(CHV4DINTEGER < int32_t > const x) const;


		bool operator!() const;

		bool operator&&(CHV4DINTEGER < int32_t > const& x) const;

		bool operator||(CHV4DINTEGER < int32_t > const& x) const;

		bool operator==(CHV4DINTEGER < int32_t > const& x) const;

		bool operator!=(CHV4DINTEGER < int32_t > const& x) const;

		bool operator<(CHV4DINTEGER < int32_t > const& x) const;

		bool operator>(CHV4DINTEGER < int32_t > const& x) const;

		bool operator<=(CHV4DINTEGER < int32_t > const& x) const;

		bool operator>=(CHV4DINTEGER < int32_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DINTEGER < int32_t > const& x) const;


		void operator+=(CHV4DINTEGER < int32_t > const& x);

		void operator-=(CHV4DINTEGER < int32_t > const& x);

		void operator*=(CHV4DINTEGER < int32_t > const& x);

	private:
		void operator/=(CHV4DINTEGER < int32_t > const&) {}

		void operator%=(CHV4DINTEGER < int32_t > const& x);

	public:
		void operator&=(CHV4DINTEGER < int32_t > const& x);

		void operator|=(CHV4DINTEGER < int32_t > const& x);

		void operator^=(CHV4DINTEGER < int32_t > const& x);

		void operator>>=(CHV4DINTEGER < int32_t > const& x);

		void operator<<=(CHV4DINTEGER < int32_t > const& x);

	private:
		int32_t Data{ 0 };
	};

	typedef CHV4DINTEGER < int32_t > CHV4DINTEGER32;

	template <> class CHV4DINTEGER < int64_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER < int64_t > const& x);

		CHV4DINTEGER(int64_t const& x);

	public:
		void operator=(CHV4DINTEGER < int64_t > const& x);

		void operator=(int64_t const& x);

		int64_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER < int64_t > operator++();

		CHV4DINTEGER < int64_t > operator++(int);

		CHV4DINTEGER < int64_t > operator--();

		CHV4DINTEGER < int64_t > operator--(int);


		CHV4DINTEGER < int64_t > operator+() const;

		CHV4DINTEGER < int64_t > operator-() const;


		CHV4DINTEGER < int64_t > operator+(CHV4DINTEGER < int64_t > const& x) const;

		CHV4DINTEGER < int64_t > operator-(CHV4DINTEGER < int64_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DINTEGER < int64_t > operator*(CHV4DINTEGER < int64_t > const& x) const;

		CHV4DINTEGER < int64_t > operator%(CHV4DINTEGER < int64_t > const& x) const;

		CHV4DINTEGER < int64_t > operator~() const;

		CHV4DINTEGER < int64_t > operator&(CHV4DINTEGER < int64_t > const& x) const;

		CHV4DINTEGER < int64_t > operator|(CHV4DINTEGER < int64_t > const x) const;

		CHV4DINTEGER < int64_t > operator^(CHV4DINTEGER < int64_t > const x) const;

		CHV4DINTEGER < int64_t > operator>>(CHV4DINTEGER < int64_t > const x) const;

		CHV4DINTEGER < int64_t > operator<<(CHV4DINTEGER < int64_t > const x) const;


		bool operator!() const;

		bool operator&&(CHV4DINTEGER < int64_t > const& x) const;

		bool operator||(CHV4DINTEGER < int64_t > const& x) const;

		bool operator==(CHV4DINTEGER < int64_t > const& x) const;

		bool operator!=(CHV4DINTEGER < int64_t > const& x) const;

		bool operator<(CHV4DINTEGER < int64_t > const& x) const;

		bool operator>(CHV4DINTEGER < int64_t > const& x) const;

		bool operator<=(CHV4DINTEGER < int64_t > const& x) const;

		bool operator>=(CHV4DINTEGER < int64_t > const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER < int64_t > const& x) const;


		void operator+=(CHV4DINTEGER < int64_t > const& x);

		void operator-=(CHV4DINTEGER < int64_t > const& x);

		void operator*=(CHV4DINTEGER < int64_t > const& x);

	private:
		void operator/=(CHV4DINTEGER < int64_t > const&) {}

		void operator%=(CHV4DINTEGER < int64_t > const& x);

	public:
		void operator&=(CHV4DINTEGER < int64_t > const& x);

		void operator|=(CHV4DINTEGER < int64_t > const& x);

		void operator^=(CHV4DINTEGER < int64_t > const& x);

		void operator>>=(CHV4DINTEGER < int64_t > const& x);

		void operator<<=(CHV4DINTEGER < int64_t > const& x);

	private:
		int64_t Data{ 0 };
	};

	typedef CHV4DINTEGER < int64_t > CHV4DINTEGER64;

	template<typename T>
	concept ASSERT_CHV4DINTEGER =
		std::is_same<T, CHV4DINTEGER < int8_t >>::value ||
		std::is_same<T, CHV4DINTEGER < int16_t >>::value ||
		std::is_same<T, CHV4DINTEGER < int32_t >>::value ||
		std::is_same<T, CHV4DINTEGER < int64_t >>::value;

	template <> class CHV4DINTEGER < size_t >
	{
	public:
		CHV4DINTEGER();

		CHV4DINTEGER(CHV4DINTEGER < size_t > const& x);

		CHV4DINTEGER(size_t const& x);

	public:
		void operator=(CHV4DINTEGER < size_t > const& x);

		void operator=(size_t const& x);

		size_t operator()() const;

		unsigned char& operator[](size_t const& i);


		CHV4DINTEGER < size_t > operator++();

		CHV4DINTEGER < size_t > operator++(int);

		CHV4DINTEGER < size_t > operator--();

		CHV4DINTEGER < size_t > operator--(int);


		CHV4DINTEGER < size_t > operator+() const;

		CHV4DINTEGER < size_t > operator-() const;


		CHV4DINTEGER < size_t > operator+(CHV4DINTEGER < size_t > const& x) const;

		CHV4DINTEGER < size_t > operator-(CHV4DINTEGER < size_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DINTEGER < size_t > operator*(CHV4DINTEGER < size_t > const& x) const;

		CHV4DINTEGER < size_t > operator%(CHV4DINTEGER < size_t > const& x) const;

		CHV4DINTEGER < size_t > operator~() const;

		CHV4DINTEGER < size_t > operator&(CHV4DINTEGER < size_t > const& x) const;

		CHV4DINTEGER < size_t > operator|(CHV4DINTEGER < size_t > const x) const;

		CHV4DINTEGER < size_t > operator^(CHV4DINTEGER < size_t > const x) const;

		CHV4DINTEGER < size_t > operator>>(CHV4DINTEGER < size_t > const x) const;

		CHV4DINTEGER < size_t > operator<<(CHV4DINTEGER < size_t > const x) const;


		bool operator!() const;

		bool operator&&(CHV4DINTEGER < size_t > const& x) const;

		bool operator||(CHV4DINTEGER < size_t > const& x) const;

		bool operator==(CHV4DINTEGER < size_t > const& x) const;

		bool operator!=(CHV4DINTEGER < size_t > const& x) const;

		bool operator<(CHV4DINTEGER < size_t > const& x) const;

		bool operator>(CHV4DINTEGER < size_t > const& x) const;

		bool operator<=(CHV4DINTEGER < size_t > const& x) const;

		bool operator>=(CHV4DINTEGER < size_t > const& x) const;

		std::weak_ordering operator<=>(CHV4DINTEGER < size_t > const& x) const;


		void operator+=(CHV4DINTEGER < size_t > const& x);

		void operator-=(CHV4DINTEGER < size_t > const& x);

		void operator*=(CHV4DINTEGER < size_t > const& x);

	private:
		void operator/=(CHV4DINTEGER < size_t > const&) {}

		void operator%=(CHV4DINTEGER < size_t > const& x);

	public:
		void operator&=(CHV4DINTEGER < size_t > const& x);

		void operator|=(CHV4DINTEGER < size_t > const& x);

		void operator^=(CHV4DINTEGER < size_t > const& x);

		void operator>>=(CHV4DINTEGER < size_t > const& x);

		void operator<<=(CHV4DINTEGER < size_t > const& x);

	private:
		size_t Data{ 0 };
	};

	typedef CHV4DINTEGER < size_t > CHV4DSCALAR;

}