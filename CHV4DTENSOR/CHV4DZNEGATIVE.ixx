module;

#include <type_traits>

#include <compare>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DZNEGATIVE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template <assert_signed_int T>
	class CHV4DZNEGATIVE
	{
	public:
		CHV4DZNEGATIVE() = default;

	};

	template <> class CHV4DZNEGATIVE < int8_t >
	{
	public:
		CHV4DZNEGATIVE();

		CHV4DZNEGATIVE(CHV4DZNEGATIVE < int8_t > const& x);

		CHV4DZNEGATIVE(int8_t const& x);

	public:
		void operator=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator=(int8_t const& x);

		int8_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNEGATIVE < int8_t > operator++();

		CHV4DZNEGATIVE < int8_t > operator++(int);

		CHV4DZNEGATIVE < int8_t > operator--();

		CHV4DZNEGATIVE < int8_t > operator--(int);

		CHV4DZNEGATIVE < int8_t > operator+() const;

		CHV4DZNEGATIVE < int8_t > operator-() const;

		CHV4DZNEGATIVE < int8_t > operator+(CHV4DZNEGATIVE < int8_t > const& x) const;

		CHV4DZNEGATIVE < int8_t > operator-(CHV4DZNEGATIVE < int8_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNEGATIVE < int8_t > operator*(CHV4DZNEGATIVE < int8_t > const& x) const;

		size_t operator%(CHV4DZNEGATIVE < int8_t > const& x) const;

		CHV4DZNEGATIVE < int8_t > operator~() const;

		CHV4DZNEGATIVE < int8_t > operator&(CHV4DZNEGATIVE < int8_t > const& x) const;

		CHV4DZNEGATIVE < int8_t > operator|(CHV4DZNEGATIVE < int8_t > const x) const;

		CHV4DZNEGATIVE < int8_t > operator^(CHV4DZNEGATIVE < int8_t > const x) const;

		CHV4DZNEGATIVE < int8_t > operator>>(CHV4DZNEGATIVE < int8_t > const x) const;

		CHV4DZNEGATIVE < int8_t > operator<<(CHV4DZNEGATIVE < int8_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator||(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator==(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator!=(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator<(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator>(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator<=(CHV4DZNEGATIVE < int8_t > const& x) const;

		bool operator>=(CHV4DZNEGATIVE < int8_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNEGATIVE < int8_t > const& x) const;

		void operator+=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator-=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator*=(CHV4DZNEGATIVE < int8_t > const& x);

	private:
		void operator/=(CHV4DZNEGATIVE < int8_t > const&) {}

		void operator%=(CHV4DZNEGATIVE < int8_t > const&) {}

	public:
		void operator&=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator|=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator^=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator>>=(CHV4DZNEGATIVE < int8_t > const& x);

		void operator<<=(CHV4DZNEGATIVE < int8_t > const& x);

	public:
		bool Sign() { return (Data & 0x80) == 0x80 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x80 : Data &= 0x7F; }

	private:
		int8_t Data{ 0 };
	};

	typedef CHV4DZNEGATIVE < int8_t > ZNeg8;

	template <> class CHV4DZNEGATIVE < int16_t >
	{
	public:
		CHV4DZNEGATIVE();

		CHV4DZNEGATIVE(CHV4DZNEGATIVE < int16_t > const& x);

		CHV4DZNEGATIVE(int16_t const& x);

	public:
		void operator=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator=(int16_t const& x);

		int16_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNEGATIVE < int16_t > operator++();

		CHV4DZNEGATIVE < int16_t > operator++(int);

		CHV4DZNEGATIVE < int16_t > operator--();

		CHV4DZNEGATIVE < int16_t > operator--(int);

		CHV4DZNEGATIVE < int16_t > operator+() const;

		CHV4DZNEGATIVE < int16_t > operator-() const;

		CHV4DZNEGATIVE < int16_t > operator+(CHV4DZNEGATIVE < int16_t > const& x) const;

		CHV4DZNEGATIVE < int16_t > operator-(CHV4DZNEGATIVE < int16_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNEGATIVE < int16_t > operator*(CHV4DZNEGATIVE < int16_t > const& x) const;

		size_t operator%(CHV4DZNEGATIVE < int16_t > const& x) const;

		CHV4DZNEGATIVE < int16_t > operator~() const;

		CHV4DZNEGATIVE < int16_t > operator&(CHV4DZNEGATIVE < int16_t > const& x) const;

		CHV4DZNEGATIVE < int16_t > operator|(CHV4DZNEGATIVE < int16_t > const x) const;

		CHV4DZNEGATIVE < int16_t > operator^(CHV4DZNEGATIVE < int16_t > const x) const;

		CHV4DZNEGATIVE < int16_t > operator>>(CHV4DZNEGATIVE < int16_t > const x) const;

		CHV4DZNEGATIVE < int16_t > operator<<(CHV4DZNEGATIVE < int16_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator||(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator==(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator!=(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator<(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator>(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator<=(CHV4DZNEGATIVE < int16_t > const& x) const;

		bool operator>=(CHV4DZNEGATIVE < int16_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNEGATIVE < int16_t > const& x) const;

		void operator+=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator-=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator*=(CHV4DZNEGATIVE < int16_t > const& x);

	private:
		void operator/=(CHV4DZNEGATIVE < int16_t > const&) {}

		void operator%=(CHV4DZNEGATIVE < int16_t > const&) {}

	public:
		void operator&=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator|=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator^=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator>>=(CHV4DZNEGATIVE < int16_t > const& x);

		void operator<<=(CHV4DZNEGATIVE < int16_t > const& x);

	public:
		bool Sign() { return (Data & 0x8000) == 0x8000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x8000 : Data &= 0x7FFF; }

	private:
		int16_t Data{ 0 };
	};

	typedef CHV4DZNEGATIVE < int16_t > ZNeg16;

	template <> class CHV4DZNEGATIVE < int32_t >
	{
	public:
		CHV4DZNEGATIVE();

		CHV4DZNEGATIVE(CHV4DZNEGATIVE < int32_t > const& x);

		CHV4DZNEGATIVE(int32_t const& x);

	public:
		void operator=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator=(int32_t const& x);

		int32_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNEGATIVE < int32_t > operator++();

		CHV4DZNEGATIVE < int32_t > operator++(int);

		CHV4DZNEGATIVE < int32_t > operator--();

		CHV4DZNEGATIVE < int32_t > operator--(int);

		CHV4DZNEGATIVE < int32_t > operator+() const;

		CHV4DZNEGATIVE < int32_t > operator-() const;

		CHV4DZNEGATIVE < int32_t > operator+(CHV4DZNEGATIVE < int32_t > const& x) const;

		CHV4DZNEGATIVE < int32_t > operator-(CHV4DZNEGATIVE < int32_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNEGATIVE < int32_t > operator*(CHV4DZNEGATIVE < int32_t > const& x) const;

		size_t operator%(CHV4DZNEGATIVE < int32_t > const& x) const;

		CHV4DZNEGATIVE < int32_t > operator~() const;

		CHV4DZNEGATIVE < int32_t > operator&(CHV4DZNEGATIVE < int32_t > const& x) const;

		CHV4DZNEGATIVE < int32_t > operator|(CHV4DZNEGATIVE < int32_t > const x) const;

		CHV4DZNEGATIVE < int32_t > operator^(CHV4DZNEGATIVE < int32_t > const x) const;

		CHV4DZNEGATIVE < int32_t > operator>>(CHV4DZNEGATIVE < int32_t > const x) const;

		CHV4DZNEGATIVE < int32_t > operator<<(CHV4DZNEGATIVE < int32_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator||(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator==(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator!=(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator<(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator>(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator<=(CHV4DZNEGATIVE < int32_t > const& x) const;

		bool operator>=(CHV4DZNEGATIVE < int32_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNEGATIVE < int32_t > const& x) const;

		void operator+=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator-=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator*=(CHV4DZNEGATIVE < int32_t > const& x);

	private:
		void operator/=(CHV4DZNEGATIVE < int32_t > const&) {}

		void operator%=(CHV4DZNEGATIVE < int32_t > const&) {}

	public:
		void operator&=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator|=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator^=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator>>=(CHV4DZNEGATIVE < int32_t > const& x);

		void operator<<=(CHV4DZNEGATIVE < int32_t > const& x);

	public:
		bool Sign() { return (Data & 0x80000000) == 0x80000000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x80000000 : Data &= 0x7FFFFFFF; }

	private:
		int32_t Data{ 0 };
	};

	typedef CHV4DZNEGATIVE < int32_t > ZNeg32;

	template <> class CHV4DZNEGATIVE < int64_t >
	{
	public:
		CHV4DZNEGATIVE();

		CHV4DZNEGATIVE(CHV4DZNEGATIVE < int64_t > const& x);

		CHV4DZNEGATIVE(int64_t const& x);

	public:
		void operator=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator=(int64_t const& x);

		int64_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNEGATIVE < int64_t > operator++();

		CHV4DZNEGATIVE < int64_t > operator++(int);

		CHV4DZNEGATIVE < int64_t > operator--();

		CHV4DZNEGATIVE < int64_t > operator--(int);

		CHV4DZNEGATIVE < int64_t > operator+() const;

		CHV4DZNEGATIVE < int64_t > operator-() const;

		CHV4DZNEGATIVE < int64_t > operator+(CHV4DZNEGATIVE < int64_t > const& x) const;

		CHV4DZNEGATIVE < int64_t > operator-(CHV4DZNEGATIVE < int64_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNEGATIVE < int64_t > operator*(CHV4DZNEGATIVE < int64_t > const& x) const;

		size_t operator%(CHV4DZNEGATIVE < int64_t > const& x) const;

		CHV4DZNEGATIVE < int64_t > operator~() const;

		CHV4DZNEGATIVE < int64_t > operator&(CHV4DZNEGATIVE < int64_t > const& x) const;

		CHV4DZNEGATIVE < int64_t > operator|(CHV4DZNEGATIVE < int64_t > const x) const;

		CHV4DZNEGATIVE < int64_t > operator^(CHV4DZNEGATIVE < int64_t > const x) const;

		CHV4DZNEGATIVE < int64_t > operator>>(CHV4DZNEGATIVE < int64_t > const x) const;

		CHV4DZNEGATIVE < int64_t > operator<<(CHV4DZNEGATIVE < int64_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator||(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator==(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator!=(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator<(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator>(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator<=(CHV4DZNEGATIVE < int64_t > const& x) const;

		bool operator>=(CHV4DZNEGATIVE < int64_t > const& x) const;

		std::weak_ordering operator<=>(CHV4DZNEGATIVE < int64_t > const& x) const;

		void operator+=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator-=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator*=(CHV4DZNEGATIVE < int64_t > const& x);

	private:
		void operator/=(CHV4DZNEGATIVE < int64_t > const&) {}

		void operator%=(CHV4DZNEGATIVE < int64_t > const&) {}

	public:
		void operator&=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator|=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator^=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator>>=(CHV4DZNEGATIVE < int64_t > const& x);

		void operator<<=(CHV4DZNEGATIVE < int64_t > const& x);

	public:
		bool Sign() { return (Data & 0x8000000000000000) == 0x8000000000000000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x8000000000000000 : Data &= 0x7FFFFFFFFFFFFFFF; }

	private:
		int64_t Data{ 0 };
	};

	typedef CHV4DZNEGATIVE < int64_t > ZNeg64;

	template<typename T>
	concept ASSERT_CHV4DZNEGATIVE =
		std::is_same<T, CHV4DZNEGATIVE < int8_t >>::value ||
		std::is_same<T, CHV4DZNEGATIVE < int16_t >>::value ||
		std::is_same<T, CHV4DZNEGATIVE < int32_t >>::value ||
		std::is_same<T, CHV4DZNEGATIVE < int64_t >>::value;

}