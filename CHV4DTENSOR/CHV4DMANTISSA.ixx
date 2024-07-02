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
		CHV4DMANTISSA(float const& x)
		{
			static_assert(std::is_same<T, float>::value, "Non Float Container.");

			float A{ x };

			unsigned char* Data = reinterpret_cast < unsigned char* >(&A);

			Sign = ((Data[3] & 0b10000000) == true) ? true : false;

			Exponent32 = (Data[3] << 1) | (Data[2] >> 7);

			Mantissa32 = 0xFFFF8F00 & *reinterpret_cast < uint32_t* >(Data);
		}
		CHV4DMANTISSA(double const& x)
		{
			static_assert(std::is_same<T, double>::value, "Non Double Container.");

			float A{ x };

			unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

			Sign = ((Data[7] & 0b10000000) == true) ? true : false;

			Exponent64 = (Data[7] << 1) | (Data[6] >> 5);

			Mantissa64 = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast < uint64_t* >(Data);
		}
		CHV4DMANTISSA(long double const& x)
		{
			static_assert(std::is_same<T, long double>::value, "Non Long Double Container.");

			float A{ x };

			unsigned char* Data = reinterpret_cast <unsigned char*>(&A);

			Sign = ((Data[7] & 0b10000000) == true) ? true : false;

			Exponent64 = (Data[7] << 1) | (Data[6] >> 5);

			Mantissa64 = 0xFFFFFFFFFFFF8F00 & *reinterpret_cast <uint64_t*>(Data);
		}

	public:
		template<typename ret>
		ret operator()() const
		{
			assert_precision < ret >();
		}
		template<> float operator() < float > ()
		{
			static_assert(std::is_same<float, T>::value, "Precision Container does not match Precision P32.");

			float expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			static_cast<uint32_t>(data) = Mentissa32;

			data[3] |= Exponent32 >> 1;

			data[2] |= Exponent32 << 7;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}
		template<> double operator() < double > ()
		{
			static_assert(std::is_same<double, T>::value, "Precision Container does not match Precision P64.");

			double expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			static_cast<uint64_t>(data) = Mentissa64;

			data[7] |= Exponent64 >> 1;

			data[6] |= Exponent64 << 5;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}
		template<> long double operator() < long double > ()
		{
			static_assert(std::is_same<long double, T>::value, "Precision Container does not match Precision LP64.");

			long double expose{ 0 };

			unsigned char* data = reinterpret_cast<unsigned char*>(&expose);

			static_cast<uint64_t>(data) = Mentissa64;

			data[7] |= Exponent64 >> 1;

			data[6] |= Exponent64 << 5;

			expose = Sign ? -1 * expose : expose;

			return expose;
		}

		bool IsPositive() 
		{
			if (std::is_same<T, float>::value) return !Sign ? true : false;
						
			else if (std::is_same<T, double>::value) return !Sign ? true : false;

			else if (std::is_same<T, long double>::value) return !Sign ? true : false;
		}

		bool IsNegative() 
		{
			if (std::is_same<T, float>::value) return Sign ? true : false;

			else if (std::is_same<T, double>::value) return Sign ? true : false;

			else if (std::is_same<T, long double>::value) return Sign ? true : false;
		}

		bool IsZero() 
		{
			if (std::is_same<T, float>::value) return Mantissa32 == 0 && Exponent32 == 0 ? true : false;

			else if (std::is_same<T, double>::value) return Mantissa64 == 0 && Exponent64 == 0 ? true : false;

			else if (std::is_same<T, long double>::value) return Mantissa64 == 0 && Exponent64 == 0 ? true : false;
		}

		bool IsNonNegative() 
		{
			if (std::is_same<T, float>::value) return Mantissa32 == 0 && Exponent32 == 0 || !Sign ? true : false;

			else if (std::is_same<T, double>::value) return Mantissa64 == 0 && Exponent64 == 0 || !Sign ? true : false;

			else if (std::is_same<T, long double>::value) return Mantissa64 == 0 && Exponent64 == 0 || !Sign ? true : false;
		}

		bool IsNonPositive() 
		{
			if (std::is_same<T, float>::value) return Mantissa32 == 0 && Exponent32 == 0 || Sign ? true : false;

			else if (std::is_same<T, double>::value) return Mantissa64 == 0 && Exponent64 == 0 || Sign ? true : false;

			else if (std::is_same<T, long double>::value) return Mantissa64 == 0 && Exponent64 == 0 || Sign ? true : false;
		}

		bool IsInteger() 
		{
			if (std::is_same<T, float>::value)
			{
				uint32_t mantissa = Mantissa32;

				if (IsZero()) return true;

				if (Exponent32 >= 127)
				{
					mantissa <<= 9 + Exponent32 - 127;

					return mantissa > 0 ? false : true;
				}

				return false;
			}
			else if (std::is_same<T, double>::value)
			{
				uint64_t mantissa = Mantissa64;

				if (IsZero()) return true;

				if (Exponent64 >= 1023)
				{
					mantissa <<= 12 + Exponent64 - 1023;

					return mantissa > 0 ? false : true;
				}

				return false;
			}
			else if (std::is_same<T, long double>::value)
			{
				uint64_t mantissa = Mantissa64;

				if (IsZero()) return true;

				if (Exponent64 >= 1023)
				{
					mantissa <<= 12 + Exponent64 - 1023;

					return mantissa > 0 ? false : true;
				}

				return false;
			}
		}

		bool IsReal() {}

		bool IsInfinite()
		{
			if (std::is_same<T, float>::value) return Exponent32 == 0xFF && Mantissa32 == 0 ? true : false;

			else if (std::is_same<T, double>::value) return Exponent64 == 0x08FF && Mantissa64 == 0 ? true : false;

			else if (std::is_same<T, long double>::value) return Exponent64 == 0x08FF && Mantissa64 == 0 ? true : false;
		}

	private:
		bool Sign{ false };

		uint32_t Mantissa32{ 0 };

		uint8_t Exponent32{ 127ui16 };

		uint64_t Mantissa64{ 0 };

		uint16_t Exponent64{ 1023ui16 };
	};
}