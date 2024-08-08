module;

#include <stdfloat>

#include <type_traits>

#include <optional>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DMANTISSA;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template <assert_precision T>
	class CHV4DMANTISSA	
	{ 
	public:
		CHV4DMANTISSA(T const&) {}
	
	};

	template <> class CHV4DMANTISSA < float >
	{
	public:
		CHV4DMANTISSA() = default;

		CHV4DMANTISSA(float const& x);

		CHV4DMANTISSA(bool sign, const uint32_t& mantissa, const uint8_t& exponent);

	public:
		void operator=(float const& x);

		float operator()() const;

		float Absolute() const;

		std::optional<size_t> Integer() const;

		float Floor() const;

		float Decimal() const;

		bool IsPositive() const;

		bool IsNegative() const;

		bool IsZero() const;

		bool IsNonNegative() const;

		bool IsNonPositive() const;

		bool IsInteger() const;

		bool IsReal() const;

		bool IsInfinite() const;

		bool IsMaximum() const;

		bool IsMinimum() const;

		bool& Sign();

		void Mantissa(uint32_t const& x);

		uint32_t Mantissa() const;

		void Exponent(uint8_t const& x);

		uint8_t Exponent() const;

	private:
		bool SignBit{ false };

		uint32_t Significand;

		uint8_t Shift;
	};

	template <> class CHV4DMANTISSA < double >
	{
	public:
		CHV4DMANTISSA() = default;

		CHV4DMANTISSA(double const& x);

		CHV4DMANTISSA(bool sign, const uint64_t& mantissa, const uint16_t& exponent);

	public:
		void operator=(double const& x);

		double operator()() const;

		double Absolute() const;

		std::optional<size_t> Integer() const;

		double Floor() const;

		double Decimal() const;

		bool IsPositive() const;

		bool IsNegative() const;

		bool IsZero() const;

		bool IsNonNegative() const;

		bool IsNonPositive() const;

		bool IsInteger() const;

		bool IsReal() const;

		bool IsInfinite() const;

		bool IsMaximum() const;

		bool IsMinimum() const;

		bool& Sign();

		void Mantissa(uint64_t const& x);

		uint64_t Mantissa() const;

		void Exponent(uint16_t const& x);

		uint16_t Exponent() const;

	private:
		bool SignBit{ false };

		uint64_t Significand;

		uint16_t Shift;
	};

	template <> class CHV4DMANTISSA < long double >
	{
	public:
		CHV4DMANTISSA() = default;

		CHV4DMANTISSA(long double const& x);

		CHV4DMANTISSA(bool sign, const uint64_t& mantissa, const uint16_t& exponent);

	public:
		void operator=(long double const& x);

		long double operator()() const;

		long double Absolute() const;

		std::optional<size_t> Integer() const;

		long double Floor() const;

		long double Decimal() const;

		bool IsPositive() const;

		bool IsNegative() const;

		bool IsZero() const;

		bool IsNonNegative() const;

		bool IsNonPositive() const;

		bool IsInteger() const;

		bool IsReal() const;

		bool IsInfinite() const;

		bool IsMaximum() const;

		bool IsMinimum() const;

		bool& Sign();

		void Mantissa(uint64_t const& x);

		uint64_t Mantissa() const;

		void Exponent(uint16_t const& x);

		uint16_t Exponent() const;

	private:
		bool SignBit{ false };

		uint64_t Significand;

		uint16_t Shift;
	};
}