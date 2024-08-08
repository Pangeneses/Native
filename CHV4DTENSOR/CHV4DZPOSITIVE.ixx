module;

#include <type_traits>

#include <compare>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DZPOSITIVE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;

export namespace CHV4DTENSOR
{
	template <assert_unsigned_int T>
	class CHV4DZPOSITIVE
	{
	public:
		CHV4DZPOSITIVE() = default;

	};

	template <> class CHV4DZPOSITIVE < uint8_t >
	{
	public:
		CHV4DZPOSITIVE();

		CHV4DZPOSITIVE(CHV4DZPOSITIVE < uint8_t > const& x);

		CHV4DZPOSITIVE(uint8_t const& x);

	public:
		void operator=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator=(uint8_t const& x);

		uint8_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZPOSITIVE < uint8_t > operator++();

		CHV4DZPOSITIVE < uint8_t > operator++(int);

		CHV4DZPOSITIVE < uint8_t > operator--();

		CHV4DZPOSITIVE < uint8_t > operator--(int);

		CHV4DZPOSITIVE < uint8_t > operator+() const;

		CHV4DZPOSITIVE < uint8_t > operator-() const;

		CHV4DZPOSITIVE < uint8_t > operator+(CHV4DZPOSITIVE < uint8_t > const& x) const;

		CHV4DZPOSITIVE < uint8_t > operator-(CHV4DZPOSITIVE < uint8_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZPOSITIVE < uint8_t > operator*(CHV4DZPOSITIVE < uint8_t > const& x) const;

		size_t operator%(CHV4DZPOSITIVE < uint8_t > const& x) const;

		CHV4DZPOSITIVE < uint8_t > operator~() const;

		CHV4DZPOSITIVE < uint8_t > operator&(CHV4DZPOSITIVE < uint8_t > const& x) const;

		CHV4DZPOSITIVE < uint8_t > operator|(CHV4DZPOSITIVE < uint8_t > const x) const;

		CHV4DZPOSITIVE < uint8_t > operator^(CHV4DZPOSITIVE < uint8_t > const x) const;

		CHV4DZPOSITIVE < uint8_t > operator>>(CHV4DZPOSITIVE < uint8_t > const x) const;

		CHV4DZPOSITIVE < uint8_t > operator<<(CHV4DZPOSITIVE < uint8_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator||(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator==(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator!=(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator<(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator>(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator<=(CHV4DZPOSITIVE < uint8_t > const& x) const;

		bool operator>=(CHV4DZPOSITIVE < uint8_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZPOSITIVE < uint8_t > const& x) const;

		void operator+=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator-=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator*=(CHV4DZPOSITIVE < uint8_t > const& x);

	private:
		void operator/=(CHV4DZPOSITIVE < uint8_t > const&) {}

		void operator%=(CHV4DZPOSITIVE < uint8_t > const&) {}

	public:
		void operator&=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator|=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator^=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator>>=(CHV4DZPOSITIVE < uint8_t > const& x);

		void operator<<=(CHV4DZPOSITIVE < uint8_t > const& x);

	private:
		uint8_t Data{ 0 };
	};

	typedef CHV4DZPOSITIVE < uint8_t > CHV4DINTEGER8;

	template <> class CHV4DZPOSITIVE < uint16_t >
	{
	public:
		CHV4DZPOSITIVE();

		CHV4DZPOSITIVE(CHV4DZPOSITIVE < uint16_t > const& x);

		CHV4DZPOSITIVE(uint16_t const& x);

	public:
		void operator=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator=(uint16_t const& x);

		uint16_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZPOSITIVE < uint16_t > operator++();

		CHV4DZPOSITIVE < uint16_t > operator++(int);

		CHV4DZPOSITIVE < uint16_t > operator--();

		CHV4DZPOSITIVE < uint16_t > operator--(int);

		CHV4DZPOSITIVE < uint16_t > operator+() const;

		CHV4DZPOSITIVE < uint16_t > operator-() const;

		CHV4DZPOSITIVE < uint16_t > operator+(CHV4DZPOSITIVE < uint16_t > const& x) const;

		CHV4DZPOSITIVE < uint16_t > operator-(CHV4DZPOSITIVE < uint16_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZPOSITIVE < uint16_t > operator*(CHV4DZPOSITIVE < uint16_t > const& x) const;

		size_t operator%(CHV4DZPOSITIVE < uint16_t > const& x) const;

		CHV4DZPOSITIVE < uint16_t > operator~() const;

		CHV4DZPOSITIVE < uint16_t > operator&(CHV4DZPOSITIVE < uint16_t > const& x) const;

		CHV4DZPOSITIVE < uint16_t > operator|(CHV4DZPOSITIVE < uint16_t > const x) const;

		CHV4DZPOSITIVE < uint16_t > operator^(CHV4DZPOSITIVE < uint16_t > const x) const;

		CHV4DZPOSITIVE < uint16_t > operator>>(CHV4DZPOSITIVE < uint16_t > const x) const;

		CHV4DZPOSITIVE < uint16_t > operator<<(CHV4DZPOSITIVE < uint16_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator||(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator==(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator!=(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator<(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator>(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator<=(CHV4DZPOSITIVE < uint16_t > const& x) const;

		bool operator>=(CHV4DZPOSITIVE < uint16_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZPOSITIVE < uint16_t > const& x) const;

		void operator+=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator-=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator*=(CHV4DZPOSITIVE < uint16_t > const& x);

	private:
		void operator/=(CHV4DZPOSITIVE < uint16_t > const&) {}

		void operator%=(CHV4DZPOSITIVE < uint16_t > const&) {}

	public:
		void operator&=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator|=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator^=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator>>=(CHV4DZPOSITIVE < uint16_t > const& x);

		void operator<<=(CHV4DZPOSITIVE < uint16_t > const& x);

	private:
		uint16_t Data{ 0 };
	};

	typedef CHV4DZPOSITIVE < uint16_t > CHV4DINTEGER16;

	template <> class CHV4DZPOSITIVE < uint32_t >
	{
	public:
		CHV4DZPOSITIVE();

		CHV4DZPOSITIVE(CHV4DZPOSITIVE < uint32_t > const& x);

		CHV4DZPOSITIVE(uint32_t const& x);

	public:
		void operator=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator=(uint32_t const& x);

		uint32_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZPOSITIVE < uint32_t > operator++();

		CHV4DZPOSITIVE < uint32_t > operator++(int);

		CHV4DZPOSITIVE < uint32_t > operator--();

		CHV4DZPOSITIVE < uint32_t > operator--(int);

		CHV4DZPOSITIVE < uint32_t > operator+() const;

		CHV4DZPOSITIVE < uint32_t > operator-() const;

		CHV4DZPOSITIVE < uint32_t > operator+(CHV4DZPOSITIVE < uint32_t > const& x) const;

		CHV4DZPOSITIVE < uint32_t > operator-(CHV4DZPOSITIVE < uint32_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZPOSITIVE < uint32_t > operator*(CHV4DZPOSITIVE < uint32_t > const& x) const;

		size_t operator%(CHV4DZPOSITIVE < uint32_t > const& x) const;

		CHV4DZPOSITIVE < uint32_t > operator~() const;

		CHV4DZPOSITIVE < uint32_t > operator&(CHV4DZPOSITIVE < uint32_t > const& x) const;

		CHV4DZPOSITIVE < uint32_t > operator|(CHV4DZPOSITIVE < uint32_t > const x) const;

		CHV4DZPOSITIVE < uint32_t > operator^(CHV4DZPOSITIVE < uint32_t > const x) const;

		CHV4DZPOSITIVE < uint32_t > operator>>(CHV4DZPOSITIVE < uint32_t > const x) const;

		CHV4DZPOSITIVE < uint32_t > operator<<(CHV4DZPOSITIVE < uint32_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator||(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator==(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator!=(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator<(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator>(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator<=(CHV4DZPOSITIVE < uint32_t > const& x) const;

		bool operator>=(CHV4DZPOSITIVE < uint32_t > const& x) const;

		std::strong_ordering operator<=>(CHV4DZPOSITIVE < uint32_t > const& x) const;

		void operator+=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator-=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator*=(CHV4DZPOSITIVE < uint32_t > const& x);

	private:
		void operator/=(CHV4DZPOSITIVE < uint32_t > const&) {}

		void operator%=(CHV4DZPOSITIVE < uint32_t > const&) {}

	public:
		void operator&=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator|=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator^=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator>>=(CHV4DZPOSITIVE < uint32_t > const& x);

		void operator<<=(CHV4DZPOSITIVE < uint32_t > const& x);

	private:
		uint32_t Data{ 0 };
	};

	typedef CHV4DZPOSITIVE < uint32_t > CHV4DINTEGER32;

	template <> class CHV4DZPOSITIVE < uint64_t >
	{
	public:
		CHV4DZPOSITIVE();

		CHV4DZPOSITIVE(CHV4DZPOSITIVE < uint64_t > const& x);

		CHV4DZPOSITIVE(uint64_t const& x);

	public:
		void operator=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator=(uint64_t const& x);

		uint64_t operator()() const;

		unsigned char& operator[](size_t const& i);

		CHV4DZPOSITIVE < uint64_t > operator++();

		CHV4DZPOSITIVE < uint64_t > operator++(int);

		CHV4DZPOSITIVE < uint64_t > operator--();

		CHV4DZPOSITIVE < uint64_t > operator--(int);

		CHV4DZPOSITIVE < uint64_t > operator+() const;

		CHV4DZPOSITIVE < uint64_t > operator-() const;

		CHV4DZPOSITIVE < uint64_t > operator+(CHV4DZPOSITIVE < uint64_t > const& x) const;

		CHV4DZPOSITIVE < uint64_t > operator-(CHV4DZPOSITIVE < uint64_t > const& x) const;

		CHV4DMANTISSA < double > operator/(CHV4DMANTISSA < double > const& x) const;

		CHV4DZPOSITIVE < uint64_t > operator*(CHV4DZPOSITIVE < uint64_t > const& x) const;

		size_t operator%(CHV4DZPOSITIVE < uint64_t > const& x) const;

		CHV4DZPOSITIVE < uint64_t > operator~() const;

		CHV4DZPOSITIVE < uint64_t > operator&(CHV4DZPOSITIVE < uint64_t > const& x) const;

		CHV4DZPOSITIVE < uint64_t > operator|(CHV4DZPOSITIVE < uint64_t > const x) const;

		CHV4DZPOSITIVE < uint64_t > operator^(CHV4DZPOSITIVE < uint64_t > const x) const;

		CHV4DZPOSITIVE < uint64_t > operator>>(CHV4DZPOSITIVE < uint64_t > const x) const;

		CHV4DZPOSITIVE < uint64_t > operator<<(CHV4DZPOSITIVE < uint64_t > const x) const;

		bool operator!() const;

		bool operator&&(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator||(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator==(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator!=(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator<(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator>(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator<=(CHV4DZPOSITIVE < uint64_t > const& x) const;

		bool operator>=(CHV4DZPOSITIVE < uint64_t > const& x) const;

		std::weak_ordering operator<=>(CHV4DZPOSITIVE < uint64_t > const& x) const;

		void operator+=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator-=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator*=(CHV4DZPOSITIVE < uint64_t > const& x);

	private:
		void operator/=(CHV4DZPOSITIVE < uint64_t > const&) {}

		void operator%=(CHV4DZPOSITIVE < uint64_t > const&) {}

	public:
		void operator&=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator|=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator^=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator>>=(CHV4DZPOSITIVE < uint64_t > const& x);

		void operator<<=(CHV4DZPOSITIVE < uint64_t > const& x);

	private:
		uint64_t Data{ 0 };
	};

	typedef CHV4DZPOSITIVE < uint64_t > CHV4DINTEGER64;

	template<typename T>
	concept ASSERT_CHV4DZPOSITIVE =
		std::is_same<T, CHV4DZPOSITIVE < uint8_t >>::value ||
		std::is_same<T, CHV4DZPOSITIVE < uint16_t >>::value ||
		std::is_same<T, CHV4DZPOSITIVE < uint32_t >>::value ||
		std::is_same<T, CHV4DZPOSITIVE < uint64_t >>::value;

}