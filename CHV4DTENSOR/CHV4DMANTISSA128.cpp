module;

#include <stdfloat>

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DMANTISSA;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DMANTISSA < long double > ::CHV4DMANTISSA(long double const& x)
	{
		long double A{ x };

		unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

		SignBit = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

		Shift = (Data[7] << 1) | (Data[6] >> 5);

		Significand = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
	}

	CHV4DMANTISSA < long double > ::CHV4DMANTISSA(bool sign, const uint64_t& mantissa, const uint16_t& exponent)
	{
		SignBit = sign;

		Significand = mantissa;

		Shift = exponent;
	}

	void CHV4DMANTISSA < long double > ::operator=(long double const& x)
	{
		long double A{ x };

		unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

		SignBit = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

		Shift = (Data[7] << 1) | (Data[6] >> 5);

		Significand = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
	}

	long double CHV4DMANTISSA < long double > ::operator()() const
	{
		long double expose{ 0 };

		unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

		*reinterpret_cast<uint64_t*>(data) = Significand;

		data[7] |= Shift >> 1;

		data[6] |= Shift << 5;

		expose = SignBit ? -1 * expose : expose;

		return expose;
	}

	long double CHV4DMANTISSA < long double > ::Absolute() const
	{
		return SignBit ? -1 * (this->operator()()) : this->operator()();
	}

	long double CHV4DMANTISSA < long double > ::Floor() const
	{
		if (IsZero()) return 0.0f;

		if (Shift == 1023) return 0.0f;

		if (Shift >= 1073) return this->operator()();

		uint64_t expose{ Significand };

		if (Shift >= 1073)
		{
			expose <<= 52 - (Shift - 1073);

			expose <<= 52 - (Shift - 1073);
		}

		unsigned char* expose_ptr = reinterpret_cast<unsigned char*>(&expose);

		expose_ptr[7] |= Shift >> 1;

		expose_ptr[6] |= Shift << 5;

		expose_ptr[7] = SignBit ? expose_ptr[7] | 0b10000000 : expose_ptr[7] & 0b01111111;

		return static_cast<long double>(expose);
	}

	bool CHV4DMANTISSA < long double > ::IsPositive() const { return !SignBit ? true : false; }

	bool CHV4DMANTISSA < long double > ::IsNegative() const { return SignBit ? true : false; }

	bool CHV4DMANTISSA < long double > ::IsZero() const { return Significand == 0 && Shift == 0 ? true : false; }

	bool CHV4DMANTISSA < long double > ::IsNonNegative() const { return Significand == 0 && Shift == 0 || !SignBit ? true : false; }

	bool CHV4DMANTISSA < long double > ::IsNonPositive() const { return Significand == 0 && Shift == 0 || SignBit ? true : false; }

	bool CHV4DMANTISSA < long double > ::IsInteger() const
	{
		uint64_t mantissa = Significand;

		if (IsZero()) return true;

		if (Shift >= 1023)
		{
			mantissa <<= 12 + Shift - 1023;

			return mantissa > 0 ? false : true;
		}

		return false;
	}

	bool CHV4DMANTISSA < long double > ::IsReal() const { return IsInteger() ? false : true; }

	bool CHV4DMANTISSA < long double > ::IsInfinite() const { return Shift == 0x08FF && Significand == 0 ? true : false; }

	bool& CHV4DMANTISSA < long double > ::Sign() { return SignBit; }

	void CHV4DMANTISSA < long double > ::Mantissa(uint64_t const& x)
	{
		if (x > 4503599627370496ui64) throw std::runtime_error{ "Mantissa out of range." };
	}
	uint64_t CHV4DMANTISSA < long double > ::Mantissa()
	{
		return Significand;
	}
	void CHV4DMANTISSA < long double > ::Exponent(uint16_t const& x)
	{
		if (x > 2048ui16) throw std::runtime_error{ "Exponent out of range." };
	}
	uint16_t CHV4DMANTISSA < long double > ::Exponent()
	{
		return Shift;
	}

}