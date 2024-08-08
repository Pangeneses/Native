module;

#include <type_traits>

#include <compare>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DZNONPOS;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template <assert_signed_int T>
	class CHV4DZNONPOS
	{
	public:
		CHV4DZNONPOS() = default;

	};

	template <> class CHV4DZNONPOS < int8_t >
	{
	public:
		CHV4DZNONPOS();

		CHV4DZNONPOS(CHV4DZNONPOS < int8_t > const& x);

		CHV4DZNONPOS(int8_t const& x);

	public:
		void operator=(CHV4DZNONPOS < int8_t > const& x);

		void operator=(int8_t const& x);

		int8_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNONPOS < int8_t > operator++();

		CHV4DZNONPOS < int8_t > operator++(int);

		CHV4DZNONPOS < int8_t > operator--();

		CHV4DZNONPOS < int8_t > operator--(int);

		CHV4DZNONPOS < int8_t > operator+() const;

		CHV4DZNONPOS < int8_t > operator-() const;

		CHV4DZNONPOS < int8_t > operator+(CHV4DZNONPOS < int8_t > const& x) const;

		CHV4DZNONPOS < int8_t > operator-(CHV4DZNONPOS < int8_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNONPOS < int8_t > operator*(CHV4DZNONPOS < int8_t > const& x) const;

		size_t operator%(CHV4DZNONPOS < int8_t > const& x) const;

		CHV4DZNONPOS < int8_t > operator~() const;

		CHV4DZNONPOS < int8_t > operator&(CHV4DZNONPOS < int8_t > const& x) const;

		CHV4DZNONPOS < int8_t > operator|(CHV4DZNONPOS < int8_t > const x) const;

		CHV4DZNONPOS < int8_t > operator^(CHV4DZNONPOS < int8_t > const x) const;

		CHV4DZNONPOS < int8_t > operator>>(CHV4DZNONPOS < int8_t > const x) const;

		CHV4DZNONPOS < int8_t > operator<<(CHV4DZNONPOS < int8_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator||(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator==(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator!=(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator<(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator>(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator<=(CHV4DZNONPOS < int8_t > const& x) const;

		bool operator>=(CHV4DZNONPOS < int8_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNONPOS < int8_t > const& x) const;

		void operator+=(CHV4DZNONPOS < int8_t > const& x);

		void operator-=(CHV4DZNONPOS < int8_t > const& x);

		void operator*=(CHV4DZNONPOS < int8_t > const& x);

	private:
		void operator/=(CHV4DZNONPOS < int8_t > const&) {}

		void operator%=(CHV4DZNONPOS < int8_t > const&) {}

	public:
		void operator&=(CHV4DZNONPOS < int8_t > const& x);

		void operator|=(CHV4DZNONPOS < int8_t > const& x);

		void operator^=(CHV4DZNONPOS < int8_t > const& x);

		void operator>>=(CHV4DZNONPOS < int8_t > const& x);

		void operator<<=(CHV4DZNONPOS < int8_t > const& x);

	public:
		bool Sign() { return (Data & 0x80) == 0x80 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x80 : Data &= 0x7F; }

	private:
		int8_t Data{ 0 };
	};

	typedef CHV4DZNONPOS < int8_t > CHV4DINTEGER8;

	template <> class CHV4DZNONPOS < int16_t >
	{
	public:
		CHV4DZNONPOS();

		CHV4DZNONPOS(CHV4DZNONPOS < int16_t > const& x);

		CHV4DZNONPOS(int16_t const& x);

	public:
		void operator=(CHV4DZNONPOS < int16_t > const& x);

		void operator=(int16_t const& x);

		int16_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNONPOS < int16_t > operator++();

		CHV4DZNONPOS < int16_t > operator++(int);

		CHV4DZNONPOS < int16_t > operator--();

		CHV4DZNONPOS < int16_t > operator--(int);

		CHV4DZNONPOS < int16_t > operator+() const;

		CHV4DZNONPOS < int16_t > operator-() const;

		CHV4DZNONPOS < int16_t > operator+(CHV4DZNONPOS < int16_t > const& x) const;

		CHV4DZNONPOS < int16_t > operator-(CHV4DZNONPOS < int16_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNONPOS < int16_t > operator*(CHV4DZNONPOS < int16_t > const& x) const;

		size_t operator%(CHV4DZNONPOS < int16_t > const& x) const;

		CHV4DZNONPOS < int16_t > operator~() const;

		CHV4DZNONPOS < int16_t > operator&(CHV4DZNONPOS < int16_t > const& x) const;

		CHV4DZNONPOS < int16_t > operator|(CHV4DZNONPOS < int16_t > const x) const;

		CHV4DZNONPOS < int16_t > operator^(CHV4DZNONPOS < int16_t > const x) const;

		CHV4DZNONPOS < int16_t > operator>>(CHV4DZNONPOS < int16_t > const x) const;

		CHV4DZNONPOS < int16_t > operator<<(CHV4DZNONPOS < int16_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator||(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator==(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator!=(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator<(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator>(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator<=(CHV4DZNONPOS < int16_t > const& x) const;

		bool operator>=(CHV4DZNONPOS < int16_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNONPOS < int16_t > const& x) const;

		void operator+=(CHV4DZNONPOS < int16_t > const& x);

		void operator-=(CHV4DZNONPOS < int16_t > const& x);

		void operator*=(CHV4DZNONPOS < int16_t > const& x);

	private:
		void operator/=(CHV4DZNONPOS < int16_t > const&) {}

		void operator%=(CHV4DZNONPOS < int16_t > const&) {}

	public:
		void operator&=(CHV4DZNONPOS < int16_t > const& x);

		void operator|=(CHV4DZNONPOS < int16_t > const& x);

		void operator^=(CHV4DZNONPOS < int16_t > const& x);

		void operator>>=(CHV4DZNONPOS < int16_t > const& x);

		void operator<<=(CHV4DZNONPOS < int16_t > const& x);

	public:
		bool Sign() { return (Data & 0x8000) == 0x8000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x8000 : Data &= 0x7FFF; }

	private:
		int16_t Data{ 0 };
	};

	typedef CHV4DZNONPOS < int16_t > CHV4DINTEGER16;

	template <> class CHV4DZNONPOS < int32_t >
	{
	public:
		CHV4DZNONPOS();

		CHV4DZNONPOS(CHV4DZNONPOS < int32_t > const& x);

		CHV4DZNONPOS(int32_t const& x);

	public:
		void operator=(CHV4DZNONPOS < int32_t > const& x);

		void operator=(int32_t const& x);

		int32_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNONPOS < int32_t > operator++();

		CHV4DZNONPOS < int32_t > operator++(int);

		CHV4DZNONPOS < int32_t > operator--();

		CHV4DZNONPOS < int32_t > operator--(int);

		CHV4DZNONPOS < int32_t > operator+() const;

		CHV4DZNONPOS < int32_t > operator-() const;

		CHV4DZNONPOS < int32_t > operator+(CHV4DZNONPOS < int32_t > const& x) const;

		CHV4DZNONPOS < int32_t > operator-(CHV4DZNONPOS < int32_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNONPOS < int32_t > operator*(CHV4DZNONPOS < int32_t > const& x) const;

		size_t operator%(CHV4DZNONPOS < int32_t > const& x) const;

		CHV4DZNONPOS < int32_t > operator~() const;

		CHV4DZNONPOS < int32_t > operator&(CHV4DZNONPOS < int32_t > const& x) const;

		CHV4DZNONPOS < int32_t > operator|(CHV4DZNONPOS < int32_t > const x) const;

		CHV4DZNONPOS < int32_t > operator^(CHV4DZNONPOS < int32_t > const x) const;

		CHV4DZNONPOS < int32_t > operator>>(CHV4DZNONPOS < int32_t > const x) const;

		CHV4DZNONPOS < int32_t > operator<<(CHV4DZNONPOS < int32_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator||(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator==(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator!=(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator<(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator>(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator<=(CHV4DZNONPOS < int32_t > const& x) const;

		bool operator>=(CHV4DZNONPOS < int32_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZNONPOS < int32_t > const& x) const;

		void operator+=(CHV4DZNONPOS < int32_t > const& x);

		void operator-=(CHV4DZNONPOS < int32_t > const& x);

		void operator*=(CHV4DZNONPOS < int32_t > const& x);

	private:
		void operator/=(CHV4DZNONPOS < int32_t > const&) {}

		void operator%=(CHV4DZNONPOS < int32_t > const&) {}

	public:
		void operator&=(CHV4DZNONPOS < int32_t > const& x);

		void operator|=(CHV4DZNONPOS < int32_t > const& x);

		void operator^=(CHV4DZNONPOS < int32_t > const& x);

		void operator>>=(CHV4DZNONPOS < int32_t > const& x);

		void operator<<=(CHV4DZNONPOS < int32_t > const& x);

	public:
		bool Sign() { return (Data & 0x80000000) == 0x80000000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x80000000 : Data &= 0x7FFFFFFF; }

	private:
		int32_t Data{ 0 };
	};

	typedef CHV4DZNONPOS < int32_t > CHV4DINTEGER32;

	template <> class CHV4DZNONPOS < int64_t >
	{
	public:
		CHV4DZNONPOS();

		CHV4DZNONPOS(CHV4DZNONPOS < int64_t > const& x);

		CHV4DZNONPOS(int64_t const& x);

	public:
		void operator=(CHV4DZNONPOS < int64_t > const& x);

		void operator=(int64_t const& x);

		int64_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZNONPOS < int64_t > operator++();

		CHV4DZNONPOS < int64_t > operator++(int);

		CHV4DZNONPOS < int64_t > operator--();

		CHV4DZNONPOS < int64_t > operator--(int);

		CHV4DZNONPOS < int64_t > operator+() const;

		CHV4DZNONPOS < int64_t > operator-() const;

		CHV4DZNONPOS < int64_t > operator+(CHV4DZNONPOS < int64_t > const& x) const;

		CHV4DZNONPOS < int64_t > operator-(CHV4DZNONPOS < int64_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZNONPOS < int64_t > operator*(CHV4DZNONPOS < int64_t > const& x) const;

		size_t operator%(CHV4DZNONPOS < int64_t > const& x) const;

		CHV4DZNONPOS < int64_t > operator~() const;

		CHV4DZNONPOS < int64_t > operator&(CHV4DZNONPOS < int64_t > const& x) const;

		CHV4DZNONPOS < int64_t > operator|(CHV4DZNONPOS < int64_t > const x) const;

		CHV4DZNONPOS < int64_t > operator^(CHV4DZNONPOS < int64_t > const x) const;

		CHV4DZNONPOS < int64_t > operator>>(CHV4DZNONPOS < int64_t > const x) const;

		CHV4DZNONPOS < int64_t > operator<<(CHV4DZNONPOS < int64_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator||(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator==(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator!=(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator<(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator>(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator<=(CHV4DZNONPOS < int64_t > const& x) const;

		bool operator>=(CHV4DZNONPOS < int64_t > const& x) const;

		std::weak_ordering operator<=>(CHV4DZNONPOS < int64_t > const& x) const;

		void operator+=(CHV4DZNONPOS < int64_t > const& x);

		void operator-=(CHV4DZNONPOS < int64_t > const& x);

		void operator*=(CHV4DZNONPOS < int64_t > const& x);

	private:
		void operator/=(CHV4DZNONPOS < int64_t > const&) {}

		void operator%=(CHV4DZNONPOS < int64_t > const&) {}

	public:
		void operator&=(CHV4DZNONPOS < int64_t > const& x);

		void operator|=(CHV4DZNONPOS < int64_t > const& x);

		void operator^=(CHV4DZNONPOS < int64_t > const& x);

		void operator>>=(CHV4DZNONPOS < int64_t > const& x);

		void operator<<=(CHV4DZNONPOS < int64_t > const& x);

	public:
		bool Sign() { return (Data & 0x8000000000000000) == 0x8000000000000000 ? true : false; }

		void Sign(bool const& set) { set ? Data |= 0x8000000000000000 : Data &= 0x7FFFFFFFFFFFFFFF; }

	private:
		int64_t Data{ 0 };
	};

	typedef CHV4DZNONPOS < int64_t > CHV4DINTEGER64;

	template<typename T>
	concept ASSERT_CHV4DZNONPOS =
		std::is_same<T, CHV4DZNONPOS < int8_t >>::value ||
		std::is_same<T, CHV4DZNONPOS < int16_t >>::value ||
		std::is_same<T, CHV4DZNONPOS < int32_t >>::value ||
		std::is_same<T, CHV4DZNONPOS < int64_t >>::value;

}