module;

#include <stdfloat>

#include <type_traits>

#include <stdexcept>

module CHV4DTENSOR:CHV4DMANTISSA;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DTENSOR
{
	CHV4DMANTISSA < double > ::CHV4DMANTISSA(double const& x)
	{
		double A{ x };

		unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

		SignBit = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

		Shift = (Data[7] << 1) | (Data[6] >> 5);

		Significand = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
	}

	CHV4DMANTISSA < double > ::CHV4DMANTISSA(bool sign, const uint64_t& mantissa, const uint16_t& exponent)
	{
		SignBit = sign;

		Significand = mantissa;

		Shift = exponent;
	}

	void CHV4DMANTISSA < double > ::operator=(double const& x)
	{
		double A{ x };

		unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

		SignBit = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

		Shift = (Data[7] << 1) | (Data[6] >> 5);

		Significand = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
	}

	double CHV4DMANTISSA < double > ::operator()() const
	{
		double expose{ 0 };

		unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

		*reinterpret_cast<uint64_t*>(data) = Significand;

		data[7] |= Shift >> 1;

		data[6] |= Shift << 5;

		expose = SignBit ? -1 * expose : expose;

		return expose;
	}

	double CHV4DMANTISSA < double > ::Absolute() const 
	{ 
		return SignBit ? -1 * (this->operator()()) : this->operator()(); 
	}

	std::optional<size_t> CHV4DMANTISSA < double > ::Integer() const
	{
		if (this->Decimal() != 0) return {};

		return this->Mantissa() * (this->Exponent() - 127);
	}

	double CHV4DMANTISSA < double > ::Floor() const
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

		return static_cast<double>(expose);
	}

	double CHV4DMANTISSA < double > ::Decimal() const { return this->operator()() - this->Floor(); }

	bool CHV4DMANTISSA < double > ::IsPositive() const { return !SignBit ? true : false; }

	bool CHV4DMANTISSA < double > ::IsNegative() const { return SignBit ? true : false; }

	bool CHV4DMANTISSA < double > ::IsZero() const { return Significand == 0 && Shift == 0 ? true : false; }

	bool CHV4DMANTISSA < double > ::IsNonNegative() const { return Significand == 0 && Shift == 0 || !SignBit ? true : false; }

	bool CHV4DMANTISSA < double > ::IsNonPositive() const { return Significand == 0 && Shift == 0 || SignBit ? true : false; }

	bool CHV4DMANTISSA < double > ::IsInteger() const
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

	bool CHV4DMANTISSA < double > ::IsReal() const { return IsInteger() ? false : true; }

	bool CHV4DMANTISSA < double > ::IsInfinite() const { return Shift == 0x08FF && Significand == 0 ? true : false; }

	bool CHV4DMANTISSA < double > ::IsMaximum() const
	{
		if (!SignBit && Shift == 0x07FE && Significand == 4503599627370495ui64) return true;

		else return false;
	}

	bool CHV4DMANTISSA < double > ::IsMinimum() const
	{
		if (SignBit && Shift == 0x07FE && Significand == 4503599627370495ui64) return true;

		else return false;
	}

	bool& CHV4DMANTISSA < double > ::Sign() { return SignBit; }

	void CHV4DMANTISSA < double > ::Mantissa(uint64_t const& x)
	{
		if (x > 4503599627370496ui64) throw std::overflow_error{ "Mantissa out of range." };
	}
	uint64_t CHV4DMANTISSA < double > ::Mantissa() const
	{
		return Significand;
	}
	void CHV4DMANTISSA < double > ::Exponent(uint16_t const& x)
	{
		if (x > 2048ui16) throw std::overflow_error{ "Exponent out of range." };
	}
	uint16_t CHV4DMANTISSA < double > ::Exponent() const
	{
		return Shift;
	}

}