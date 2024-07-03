module;

#include <stdfloat>

#include <type_traits>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DMANTISSA;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	template <typename T>
	class CHV4DMANTISSA
	{
	public:
		CHV4DMANTISSA() = default;

	};

	template<>
	class CHV4DMANTISSA < float >
	{
	public:
		CHV4DMANTISSA() = default;

		CHV4DMANTISSA(float const& x)
		{
			float A{ x };

			unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

			Sign = ((Data[3] & 0b10000000) == 0b10000000) ? true : false;

			Exponent = (Data[3] << 1) | (Data[2] >> 7);

			Mantissa = 0xFFFF8F00 & *reinterpret_cast <uint32_t*>(Data);
		}

		CHV4DMANTISSA(bool Sign, const uint32_t& Mantissa, const uint8_t& Exponent)
			: Sign(Sign), Mantissa(Mantissa), Exponent(Exponent) { }

	public:
		void operator=(CHV4DMANTISSA const& x) { *this = x; }

		float operator()() const
		{
			float expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			*reinterpret_cast<uint32_t*>(data) = Mantissa;

			data[3] |= Exponent >> 1;

			data[2] |= Exponent << 7;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}

		float Absolute() const { return Sign ? -1 * (this->operator()()) : this->operator()(); }

		float Floor() const
		{
			if (IsZero()) return 0.0f;

			if (Mantissa < 1.0f) return 0.0f;

			uint32_t mantissa = Mantissa;

			if (Exponent >= 127)
			{
				mantissa <<= 23 - (Exponent - 127);

				mantissa <<= 23 - (Exponent - 127);
			}

			//CHV4DMANTISSA < float > ret;

			//ret = this;

			return static_cast< float >(mantissa);
		}

		bool IsPositive() const { return !Sign ? true : false; }

		bool IsNegative() const { return Sign ? true : false; }

		bool IsZero() const { return Mantissa == 0 && Exponent == 0 ? true : false; }

		bool IsNonNegative() const { return Mantissa == 0 && Exponent == 0 || !Sign ? true : false; }

		bool IsNonPositive() const { return Mantissa == 0 && Exponent == 0 || Sign ? true : false; }

		bool IsInteger() const
		{
			uint32_t mantissa = Mantissa;

			if (IsZero()) return true;

			if (Exponent >= 127)
			{
				mantissa <<= 9 + Exponent - 127;

				return mantissa > 0 ? false : true;
			}

			return false;
		}

		bool IsReal() const { return IsInteger() ? false : true; }

		bool IsInfinite() const { return Exponent == 0xFF && Mantissa == 0 ? true : false; }

		uint32_t Significand() const { return Mantissa; }

		uint8_t Shift() const { return Exponent; }

	private:
		bool Sign{ false };

		uint32_t Mantissa;

		uint8_t Exponent;
	};

	template<>
	class CHV4DMANTISSA < double >
	{
	public:
		CHV4DMANTISSA(double const& x)
		{
			double A{ x };

			unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

			Sign = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

			Exponent = (Data[7] << 1) | (Data[6] >> 5);

			Mantissa = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
		}

		CHV4DMANTISSA(bool Sign, const uint64_t& Mantissa, const uint16_t& Exponent)
			: Sign(Sign), Mantissa(Mantissa), Exponent(Exponent) { }

	public:
		void operator=(CHV4DMANTISSA const& x) { *this = x; }

		double operator()() const
		{
			double expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			*reinterpret_cast<uint64_t*>(data) = Mantissa;

			data[7] |= Exponent >> 1;

			data[6] |= Exponent << 5;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}

		double Absolute() const { return Sign ? -1 * (this->operator()()) : this->operator()(); }

		double Floor() const
		{
			if (IsZero()) return 0.0;

			if (Mantissa < 1.0) return 0.0;

			uint64_t mantissa = Mantissa;

			if (Exponent >= 127)
			{
				mantissa <<= 23 - (Exponent - 127);

				mantissa <<= 23 - (Exponent - 127);
			}

			return static_cast<double>(mantissa);
		}

		bool IsPositive() const { return !Sign ? true : false; }

		bool IsNegative() const { return Sign ? true : false; }

		bool IsZero() const { return Mantissa == 0 && Exponent == 0 ? true : false; }

		bool IsNonNegative() const { return Mantissa == 0 && Exponent == 0 || !Sign ? true : false; }

		bool IsNonPositive() const { return Mantissa == 0 && Exponent == 0 || Sign ? true : false; }

		bool IsInteger() const
		{
			uint64_t mantissa = Mantissa;

			if (IsZero()) return true;

			if (Exponent >= 1023)
			{
				mantissa <<= 12 + Exponent - 1023;

				return mantissa > 0 ? false : true;
			}

			return false;
		}

		bool IsReal() const { return IsInteger() ? false : true; }

		bool IsInfinite() const { return Exponent == 0x08FF && Mantissa == 0 ? true : false; }

		uint64_t Significand() const { return Mantissa; }

		uint16_t Shift() const { return Exponent; }

	private:
		bool Sign{ false };

		uint64_t Mantissa;

		uint16_t Exponent;
	};

	template<>
	class CHV4DMANTISSA < long double >
	{
	public:
		CHV4DMANTISSA(long double const& x)
		{
			long double A{ x };

			unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

			Sign = ((Data[7] & 0b10000000) == 0b10000000) ? true : false;

			Exponent = (Data[7] << 1) | (Data[6] >> 5);

			Mantissa = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
		}

		CHV4DMANTISSA(bool Sign, const uint64_t& Mantissa, const uint16_t& Exponent)
			: Sign(Sign), Mantissa(Mantissa), Exponent(Exponent) { }

	public:
		void operator=(CHV4DMANTISSA const& x) { *this = x; }

		long double operator()() const
		{
			long double expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			*reinterpret_cast<uint64_t*>(data) = Mantissa;

			data[7] |= Exponent >> 1;

			data[6] |= Exponent << 5;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}

		long double Absolute() const { return Sign ? -1 * (this->operator()()) : this->operator()(); }

		long double Floor() const
		{
			if (IsZero()) return 0.0;

			if (Mantissa < 1.0) return 0.0;

			uint64_t mantissa = Mantissa;

			if (Exponent >= 127)
			{
				mantissa <<= 23 - (Exponent - 127);

				mantissa <<= 23 - (Exponent - 127);
			}

			return static_cast<long double>(mantissa);
		}

		bool IsPositive() const { return !Sign ? true : false; }

		bool IsNegative() const { return Sign ? true : false; }

		bool IsZero() const { return Mantissa == 0 && Exponent == 0 ? true : false; }

		bool IsNonNegative() const { return Mantissa == 0 && Exponent == 0 || !Sign ? true : false; }

		bool IsNonPositive() const { return Mantissa == 0 && Exponent == 0 || Sign ? true : false; }

		bool IsInteger() const
		{
			uint64_t mantissa = Mantissa;

			if (IsZero()) return true;

			if (Exponent >= 1023)
			{
				mantissa <<= 12 + Exponent - 1023;

				return mantissa > 0 ? false : true;
			}

			return false;
		}

		bool IsReal() const { return IsInteger() ? false : true; }

		bool IsInfinite() const { return Exponent == 0x08FF && Mantissa == 0 ? true : false; }

		uint64_t Significand() const { return Mantissa; }

		uint16_t Shift() const { return Exponent; }

	private:
		bool Sign{ false };

		uint64_t Mantissa;

		uint16_t Exponent;
	};
}