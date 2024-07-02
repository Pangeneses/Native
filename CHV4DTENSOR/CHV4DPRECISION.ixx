module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	/*
	class CHV4DF32
	{
	public:
		CHV4DF32(CHV4DF32 const& x)
		{
			sign = x.sign;

			mantissa = x.mantissa;

			exponent = x.exponent;
		}
		CHV4DF32(float const& x)
		{
			float temp{ x };

			unsigned char* Data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((Data[3] & 0b10000000) == true) ? true : false;

			unsigned char exp = (Data[3] << 1) | (Data[2] >> 7);

			exponent = static_cast<uint16_t>(exp + (2047ui16 - 127ui16));

			uint32_t sig = 0xFFFF8F00 & *reinterpret_cast<uint32_t*>(Data);

			mantissa = static_cast<uint64_t>(sig);

			mantissa = mantissa << 44;
		}

	public:
		void operator=(CHV4DF32 const& x)
		{
			sign = x.sign;

			mantissa = x.mantissa;

			exponent = x.exponent;
		}
		void operator=(float const& x)
		{
			float temp{ x };

			unsigned char* Data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((Data[3] & 0b10000000) == true) ? true : false;

			unsigned char exp = (Data[3] << 1) | (Data[2] >> 7);

			exponent = static_cast<uint16_t>(exp + (2047ui16 - 127ui16));

			uint32_t sig = 0xFFFF8F00 & *reinterpret_cast<uint32_t*>(Data);

			mantissa = static_cast<uint64_t>(sig);

			mantissa = mantissa << 44;
		}

		template<typename T>
		T operator()() const
		{
			static_assert(false, "Non Precision type.");
		}
		template<>
		CHV4DF32 operator() < CHV4DF32 > () const
		{
			return *this;
		}
		template<>
		float operator() < float > () const
		{
			unsigned char Data[4]{ 0 };

			{
				sign ? Data[3] | 0b10000000 : Data[3] | 0;
			}

			{
				if (exponent > 2047ui16) throw std::runtime_error{ "Exponent error." };

				if (exponent < (1023ui16 - 127ui16)) throw std::overflow_error{ "Precision overrun" };

				uint16_t exp = (exponent + 127ui16) - 1023ui16;

				if (exp > 255ui16) throw std::overflow_error{ "Precision overrun" };

				Data[3] = Data[3] | ((*reinterpret_cast<unsigned char*>(&exp)) >> 1);

				Data[2] = (*reinterpret_cast<unsigned char*>(&exp)) << 7;
			}

			{
				uint64_t fraction = mantissa;

				Data[2] |= (reinterpret_cast<unsigned char*>(&fraction)[2] & 0b01111111);
				Data[1] = reinterpret_cast<unsigned char*>(&fraction)[1];
				Data[0] = reinterpret_cast<unsigned char*>(&fraction)[0];
			}

			return *reinterpret_cast<float*>(Data);
		}

		CHV4DF32 operator+(CHV4DF32 const& x) const
		{
			CHV4DF32 A{ *this }, B{ x };

			if (A.exponent > B.exponent)
			{
				B.mantissa = B.mantissa >> (A.exponent - B.exponent);

				B.exponent = A.exponent;

				if (A.mantissa > (0xFFFFFFFFFFFFF000 - B.mantissa) && A.exponent == 2047)
				{
					throw std::overflow_error{ "Addition overflow." };
				}

				if (!A.sign && !B.sign) A.mantissa += B.mantissa;
				else if (!A.sign && B.sign) A.mantissa -= B.mantissa;
				else if (A.sign && !B.sign) A.mantissa -= B.mantissa;
				else if (A.sign && B.sign) A.mantissa += B.mantissa;

				return A;
			}
			else if (A.exponent < B.exponent)
			{
				A.mantissa = A.mantissa >> (B.exponent - A.exponent);

				if (B.mantissa > (0xFFFFFFFFFFFFF000 - A.mantissa) && B.exponent == 2047)
				{
					throw std::overflow_error{ "Addition overflow." };
				}

				if (!A.sign && !B.sign) B.mantissa += A.mantissa;
				else if (!A.sign && B.sign) B.mantissa -= A.mantissa;
				else if (A.sign && !B.sign) B.mantissa -= A.mantissa;
				else if (A.sign && B.sign) B.mantissa += A.mantissa;

				return B;
			}
			else
			{
				if (B.mantissa > (0xFFFFFFFFFFFFF000 - A.mantissa) && B.exponent == 2047)
				{
					throw std::overflow_error{ "Addition overflow." };
				}

				if (!A.sign && !B.sign) B.mantissa += A.mantissa;
				else if (!A.sign && B.sign) B.mantissa -= A.mantissa;
				else if (A.sign && !B.sign) B.mantissa -= A.mantissa;
				else if (A.sign && B.sign) B.mantissa += A.mantissa;

				return B;
			}
		}

		CHV4DF32 operator-(CHV4DF32 const& x) const
		{
			CHV4DF32 A{ x };

			if (A.sign) A.sign = false; else A.sign = true;

			try
			{
				A = this->operator+(A);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return A;
		}

		CHV4DF32 operator/(CHV4DF32 const& x) const
		{
			if (x.mantissa == 0 && x.exponent == 1023ui16) throw std::runtime_error{ "Division by zero." };

			if (mantissa == 0 && exponent == 1023ui16) return CHV4DF32{ 0.0 };

			CHV4DF32 A{ *this }, B{ x };

			B.sign = (!A.sign != !B.sign) ? true : false;

			if (A.exponent > 2047ui16 || B.exponent > 2047ui16) throw std::runtime_error{ "Exponent overrun." };

			if ((A.exponent - 1023ui16) - (B.exponent - 1023ui16) < 0)
			{
				std::swap(A.exponent, B.exponent);

				std::swap(A.mantissa, B.mantissa);
			}

			B.exponent = A.exponent - B.exponent;

			if (A.mantissa == 0ui16)
			{
				B.mantissa = 0;
			}
			else if (B.mantissa == 0)
			{
				throw std::runtime_error{ "Division by zero." };
			}
			else
			{
				A.mantissa |= ((A.mantissa >> 1) | 0x8000000000000000);
				B.mantissa |= ((B.mantissa >> 1) | 0x8000000000000000);

				uint64_t Q{ 0 };

				for (size_t i = 0; i < 16; ++i)
				{
					if (A.mantissa - B.mantissa >= 0)
					{
						A.mantissa -= B.mantissa;

						Q |= 0x0000000000000001;
					}

					A.mantissa << 1;

					Q = Q << 1;
				}

				B.mantissa = Q;
			}
		}

		void operator*(CHV4DF32 const& x) const
		{

		}

		void operator^(CHV4DF32 const& x) const
		{

		}

		void operator==(CHV4DF32 const& x) const
		{

		}

		void operator>(CHV4DF32 const& x) const
		{

		}

		void operator<(CHV4DF32 const& x) const
		{

		}

		void operator>=(CHV4DF32 const& x) const
		{

		}

		void operator<=(CHV4DF32 const& x) const
		{

		}

	public:
	bool Sign() const { return sign ? true : false; }

	bool Infinity() const { return (exponent == 65535ui16) && (mantissa != 0ui64) ? true : false; }

	size_t Exponent() const { return exponent; }

	size_t Mantissa() const { return mantissa; }

	template<typename T>
	T Value() const
	{
		static_assert(false, "Non Precision type.");
	}
	template<>
	CHV4DF32 Value<CHV4DF32>() const
	{
		return *this;
	}
	template<>
	float Value<float>() const
	{
		float fpvalue{ 0 };

		try
		{
			fpvalue = this->operator() < float > ();
		}
		catch (std::overflow_error error)
		{
			throw error;
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		return fpvalue;
	}

		template<typename T>
		T Trunc(size_t sigBits) const
		{
			static_assert(false, "Non Integer type.");
		}
		template<>
		CHV4DF32 Trunc<CHV4DF32>(size_t sigBits) const
		{
			if (!(sigBits < 53 && sigBits >= 0)) std::runtime_error{ "Sig Bit Error." };

			CHV4DF32 trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				trunced.mantissa = trunced.mantissa << trunced.exponent - 1023;
			}
			else if (trunced.exponent < 1023ui16)
			{
				trunced.mantissa = trunced.mantissa >> 1023 - trunced.exponent;
			}

			switch (sigBits)
			{
			case 0:	trunced.mantissa = trunced.mantissa & 0x00000000000000; break;
			case 1:	trunced.mantissa = trunced.mantissa & 0x70000000000000; break;
			case 2:	trunced.mantissa = trunced.mantissa & 0xB0000000000000; break;
			case 3:	trunced.mantissa = trunced.mantissa & 0xE0000000000000; break;
			case 4:	trunced.mantissa = trunced.mantissa & 0xF0000000000000; break;
			case 5:	trunced.mantissa = trunced.mantissa & 0xF7000000000000; break;
			case 6:	trunced.mantissa = trunced.mantissa & 0xFB000000000000; break;
			case 7:	trunced.mantissa = trunced.mantissa & 0xFE000000000000; break;
			case 8:	trunced.mantissa = trunced.mantissa & 0xFF000000000000; break;
			case 9:	trunced.mantissa = trunced.mantissa & 0xFF700000000000; break;
			case 10: trunced.mantissa = trunced.mantissa & 0xFFB00000000000; break;
			case 11: trunced.mantissa = trunced.mantissa & 0xFFE00000000000; break;
			case 12: trunced.mantissa = trunced.mantissa & 0xFFF00000000000; break;
			case 13: trunced.mantissa = trunced.mantissa & 0xFFF70000000000; break;
			case 14: trunced.mantissa = trunced.mantissa & 0xFFFB0000000000; break;
			case 15: trunced.mantissa = trunced.mantissa & 0xFFFE0000000000; break;
			case 16: trunced.mantissa = trunced.mantissa & 0xFFFF0000000000; break;
			case 17: trunced.mantissa = trunced.mantissa & 0xFFFF7000000000; break;
			case 18: trunced.mantissa = trunced.mantissa & 0xFFFFB000000000; break;
			case 19: trunced.mantissa = trunced.mantissa & 0xFFFFE000000000; break;
			case 20: trunced.mantissa = trunced.mantissa & 0xFFFFF000000000; break;
			case 21: trunced.mantissa = trunced.mantissa & 0xFFFFF700000000; break;
			case 22: trunced.mantissa = trunced.mantissa & 0xFFFFFB00000000; break;
			case 23: trunced.mantissa = trunced.mantissa & 0xFFFFFE00000000; break;
			case 24: trunced.mantissa = trunced.mantissa & 0xFFFFFF0000000000; break;
			case 25: trunced.mantissa = trunced.mantissa & 0xFFFFFF7000000000; break;
			case 26: trunced.mantissa = trunced.mantissa & 0xFFFFFFB000000000; break;
			case 27: trunced.mantissa = trunced.mantissa & 0xFFFFFFE000000000; break;
			case 28: trunced.mantissa = trunced.mantissa & 0xFFFFFFF000000000; break;
			case 29: trunced.mantissa = trunced.mantissa & 0xFFFFFFF700000000; break;
			case 30: trunced.mantissa = trunced.mantissa & 0xFFFFFFFB00000000; break;
			case 31: trunced.mantissa = trunced.mantissa & 0xFFFFFFFE00000000; break;
			case 32: trunced.mantissa = trunced.mantissa & 0xFFFFFFFF00000000; break;
			case 33: trunced.mantissa = trunced.mantissa & 0xFFFFFFFF70000000; break;
			case 34: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFB0000000; break;
			case 35: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFE0000000; break;
			case 36: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFF0000000; break;
			case 37: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFF7000000; break;
			case 38: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFB000000; break;
			case 39: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFE000000; break;
			case 40: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFF000000; break;
			case 41: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFF700000; break;
			case 42: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFB00000; break;
			case 43: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFE00000; break;
			case 44: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFF00000; break;
			case 45: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFF70000; break;
			case 46: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFB0000; break;
			case 47: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFE0000; break;
			case 48: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFF0000; break;
			case 49: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFF7000; break;
			case 50: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFFB000; break;
			case 51: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFFE000; break;
			case 52: trunced.mantissa = trunced.mantissa & 0xFFFFFFFFFFFFF000; break;
			default: break;
			}

			if (trunced.exponent > 1023ui16)
			{
				trunced.mantissa = trunced.mantissa >> trunced.exponent - 1023ui16;

				switch (trunced.exponent)
				{
				case 1023: trunced.mantissa = trunced.mantissa | (mantissa & 0x0000000000000000); break;
				case 1024: trunced.mantissa = trunced.mantissa | (mantissa & 0x7000000000000000); break;
				case 1025: trunced.mantissa = trunced.mantissa | (mantissa & 0xB000000000000000); break;
				case 1026: trunced.mantissa = trunced.mantissa | (mantissa & 0xE000000000000000); break;
				case 1027: trunced.mantissa = trunced.mantissa | (mantissa & 0xF000000000000000); break;
				case 1028: trunced.mantissa = trunced.mantissa | (mantissa & 0xF700000000000000); break;
				case 1029: trunced.mantissa = trunced.mantissa | (mantissa & 0xFB00000000000000); break;
				case 1030: trunced.mantissa = trunced.mantissa | (mantissa & 0xFE00000000000000); break;
				case 1031: trunced.mantissa = trunced.mantissa | (mantissa & 0xFF00000000000000); break;
				case 1032: trunced.mantissa = trunced.mantissa | (mantissa & 0xFF70000000000000); break;
				case 1033: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFB0000000000000); break;
				case 1034: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFE0000000000000); break;
				case 1035: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFF0000000000000); break;
				case 1036: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFF7000000000000); break;
				case 1037: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFB000000000000); break;
				case 1038: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFE000000000000); break;
				case 1039: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFF000000000000); break;
				case 1040: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFF700000000000); break;
				case 1041: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFB00000000000); break;
				case 1042: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFE00000000000); break;
				case 1043: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFF00000000000); break;
				case 1044: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFF70000000000); break;
				case 1045: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFB0000000000); break;
				case 1046: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFE0000000000); break;
				case 1047: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFF0000000000); break;
				case 1048: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFF7000000000); break;
				case 1049: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFB000000000); break;
				case 1050: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFE000000000); break;
				case 1051: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFF000000000); break;
				case 1052: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFF700000000); break;
				case 1053: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFB00000000); break;
				case 1054: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFE00000000); break;
				case 1055: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFF00000000); break;
				case 1056: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFF70000000); break;
				case 1057: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFB0000000); break;
				case 1058: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFE0000000); break;
				case 1059: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFF0000000); break;
				case 1060: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFF7000000); break;
				case 1061: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFB000000); break;
				case 1062: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFE000000); break;
				case 1063: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFF000000); break;
				case 1064: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFF700000); break;
				case 1065: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFB00000); break;
				case 1066: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFE00000); break;
				case 1067: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFF00000); break;
				case 1068: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFF70000); break;
				case 1069: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFB0000); break;
				case 1070: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFE0000); break;
				case 1071: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFF0000); break;
				case 1072: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFF7000); break;
				case 1073: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFFB000); break;
				case 1074: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFFE000); break;
				case 1075: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFFFFFFFFF000); break;
				default: trunced.mantissa = 0; break;
				}
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.mantissa = trunced.mantissa << 127ui16 - trunced.exponent;
			}

			return trunced;
		}
		template<>
		float Trunc<float>(size_t sigBits) const
		{
			if (!(sigBits < 24 && sigBits >= 0)) std::runtime_error{ "Sig Bit Error." };

			CHV4DF32 trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				trunced.mantissa = trunced.mantissa << trunced.exponent - 127ui16;
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.mantissa = trunced.mantissa >> 127ui16 - trunced.exponent;
			}

			switch (sigBits)
			{
			case 0:	trunced.mantissa = trunced.mantissa & 0x0000000000000000; break;
			case 1:	trunced.mantissa = trunced.mantissa & 0x7000000000000000; break;
			case 2:	trunced.mantissa = trunced.mantissa & 0xB000000000000000; break;
			case 3:	trunced.mantissa = trunced.mantissa & 0xE000000000000000; break;
			case 4:	trunced.mantissa = trunced.mantissa & 0xF000000000000000; break;
			case 5:	trunced.mantissa = trunced.mantissa & 0xF700000000000000; break;
			case 6:	trunced.mantissa = trunced.mantissa & 0xFB00000000000000; break;
			case 7:	trunced.mantissa = trunced.mantissa & 0xFE00000000000000; break;
			case 8:	trunced.mantissa = trunced.mantissa & 0xFF00000000000000; break;
			case 9:	trunced.mantissa = trunced.mantissa & 0xFF70000000000000; break;
			case 10: trunced.mantissa = trunced.mantissa & 0xFFB0000000000000; break;
			case 11: trunced.mantissa = trunced.mantissa & 0xFFE0000000000000; break;
			case 12: trunced.mantissa = trunced.mantissa & 0xFFF0000000000000; break;
			case 13: trunced.mantissa = trunced.mantissa & 0xFFF7000000000000; break;
			case 14: trunced.mantissa = trunced.mantissa & 0xFFFB000000000000; break;
			case 15: trunced.mantissa = trunced.mantissa & 0xFFFE000000000000; break;
			case 16: trunced.mantissa = trunced.mantissa & 0xFFFF000000000000; break;
			case 17: trunced.mantissa = trunced.mantissa & 0xFFFF700000000000; break;
			case 18: trunced.mantissa = trunced.mantissa & 0xFFFFB00000000000; break;
			case 19: trunced.mantissa = trunced.mantissa & 0xFFFFE00000000000; break;
			case 20: trunced.mantissa = trunced.mantissa & 0xFFFFF00000000000; break;
			case 21: trunced.mantissa = trunced.mantissa & 0xFFFFF70000000000; break;
			case 22: trunced.mantissa = trunced.mantissa & 0xFFFFFB0000000000; break;
			case 23: trunced.mantissa = trunced.mantissa & 0xFFFFFE0000000000; break;
			default: break;
			}

			if (trunced.exponent > 127ui16)
			{
				trunced.mantissa = trunced.mantissa >> trunced.exponent - 127ui16;

				switch (trunced.exponent)
				{
				case 127: trunced.mantissa = trunced.mantissa | (mantissa & 0x0000000000000000); break;
				case 128: trunced.mantissa = trunced.mantissa | (mantissa & 0x7000000000000000); break;
				case 129: trunced.mantissa = trunced.mantissa | (mantissa & 0xB000000000000000); break;
				case 130: trunced.mantissa = trunced.mantissa | (mantissa & 0xE000000000000000); break;
				case 131: trunced.mantissa = trunced.mantissa | (mantissa & 0xF000000000000000); break;
				case 132: trunced.mantissa = trunced.mantissa | (mantissa & 0xF700000000000000); break;
				case 133: trunced.mantissa = trunced.mantissa | (mantissa & 0xFB00000000000000); break;
				case 134: trunced.mantissa = trunced.mantissa | (mantissa & 0xFE00000000000000); break;
				case 135: trunced.mantissa = trunced.mantissa | (mantissa & 0xFF00000000000000); break;
				case 136: trunced.mantissa = trunced.mantissa | (mantissa & 0xFF70000000000000); break;
				case 137: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFB0000000000000); break;
				case 138: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFE0000000000000); break;
				case 139: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFF0000000000000); break;
				case 140: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFF7000000000000); break;
				case 141: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFB000000000000); break;
				case 142: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFE000000000000); break;
				case 143: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFF000000000000); break;
				case 144: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFF700000000000); break;
				case 145: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFB00000000000); break;
				case 146: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFE00000000000); break;
				case 147: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFF00000000000); break;
				case 148: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFF70000000000); break;
				case 149: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFB0000000000); break;
				case 150: trunced.mantissa = trunced.mantissa | (mantissa & 0xFFFFFE0000000000); break;
				default: trunced.mantissa = 0; break;
				}
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.mantissa = trunced.mantissa << 127ui16 - trunced.exponent;
			}

			float ret{ 0.0f };

			try
			{
				ret = trunced.Value<float>();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return ret;
		}

		template<typename T>
		T Floor() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<>
		CHV4DF32 Floor<CHV4DF32>() const
		{
			CHV4DF32 trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.mantissa = mantissa & 0x0000000000000000; break;
				case 1024: trunced.mantissa = mantissa & 0x7000000000000000; break;
				case 1025: trunced.mantissa = mantissa & 0xB000000000000000; break;
				case 1026: trunced.mantissa = mantissa & 0xE000000000000000; break;
				case 1027: trunced.mantissa = mantissa & 0xF000000000000000; break;
				case 1028: trunced.mantissa = mantissa & 0xF700000000000000; break;
				case 1029: trunced.mantissa = mantissa & 0xFB00000000000000; break;
				case 1030: trunced.mantissa = mantissa & 0xFE00000000000000; break;
				case 1031: trunced.mantissa = mantissa & 0xFF00000000000000; break;
				case 1032: trunced.mantissa = mantissa & 0xFF70000000000000; break;
				case 1033: trunced.mantissa = mantissa & 0xFFB0000000000000; break;
				case 1034: trunced.mantissa = mantissa & 0xFFE0000000000000; break;
				case 1035: trunced.mantissa = mantissa & 0xFFF0000000000000; break;
				case 1036: trunced.mantissa = mantissa & 0xFFF7000000000000; break;
				case 1037: trunced.mantissa = mantissa & 0xFFFB000000000000; break;
				case 1038: trunced.mantissa = mantissa & 0xFFFE000000000000; break;
				case 1039: trunced.mantissa = mantissa & 0xFFFF000000000000; break;
				case 1040: trunced.mantissa = mantissa & 0xFFFF700000000000; break;
				case 1041: trunced.mantissa = mantissa & 0xFFFFB00000000000; break;
				case 1042: trunced.mantissa = mantissa & 0xFFFFE00000000000; break;
				case 1043: trunced.mantissa = mantissa & 0xFFFFF00000000000; break;
				case 1044: trunced.mantissa = mantissa & 0xFFFFF70000000000; break;
				case 1045: trunced.mantissa = mantissa & 0xFFFFFB0000000000; break;
				case 1046: trunced.mantissa = mantissa & 0xFFFFFE0000000000; break;
				case 1047: trunced.mantissa = mantissa & 0xFFFFFF0000000000; break;
				case 1048: trunced.mantissa = mantissa & 0xFFFFFF7000000000; break;
				case 1049: trunced.mantissa = mantissa & 0xFFFFFFB000000000; break;
				case 1050: trunced.mantissa = mantissa & 0xFFFFFFE000000000; break;
				case 1051: trunced.mantissa = mantissa & 0xFFFFFFF000000000; break;
				case 1052: trunced.mantissa = mantissa & 0xFFFFFFF700000000; break;
				case 1053: trunced.mantissa = mantissa & 0xFFFFFFFB00000000; break;
				case 1054: trunced.mantissa = mantissa & 0xFFFFFFFE00000000; break;
				case 1055: trunced.mantissa = mantissa & 0xFFFFFFFF00000000; break;
				case 1056: trunced.mantissa = mantissa & 0xFFFFFFFF70000000; break;
				case 1057: trunced.mantissa = mantissa & 0xFFFFFFFFB0000000; break;
				case 1058: trunced.mantissa = mantissa & 0xFFFFFFFFE0000000; break;
				case 1059: trunced.mantissa = mantissa & 0xFFFFFFFFF0000000; break;
				case 1060: trunced.mantissa = mantissa & 0xFFFFFFFFF7000000; break;
				case 1061: trunced.mantissa = mantissa & 0xFFFFFFFFFB000000; break;
				case 1062: trunced.mantissa = mantissa & 0xFFFFFFFFFE000000; break;
				case 1063: trunced.mantissa = mantissa & 0xFFFFFFFFFF000000; break;
				case 1064: trunced.mantissa = mantissa & 0xFFFFFFFFFF700000; break;
				case 1065: trunced.mantissa = mantissa & 0xFFFFFFFFFFB00000; break;
				case 1066: trunced.mantissa = mantissa & 0xFFFFFFFFFFE00000; break;
				case 1067: trunced.mantissa = mantissa & 0xFFFFFFFFFFF00000; break;
				case 1068: trunced.mantissa = mantissa & 0xFFFFFFFFFFF70000; break;
				case 1069: trunced.mantissa = mantissa & 0xFFFFFFFFFFFB0000; break;
				case 1070: trunced.mantissa = mantissa & 0xFFFFFFFFFFFE0000; break;
				case 1071: trunced.mantissa = mantissa & 0xFFFFFFFFFFFF0000; break;
				case 1072: trunced.mantissa = mantissa & 0xFFFFFFFFFFFF7000; break;
				case 1073: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFB000; break;
				case 1074: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFE000; break;
				case 1075: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFF000; break;
				default: trunced.mantissa = 0; break;
				}
			}

			return trunced;
		}
		template<>
		float Floor<float>() const
		{
			CHV4DF32 trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				switch (trunced.exponent)
				{
				case 127: trunced.mantissa = mantissa & 0x0000000000000000; break;
				case 128: trunced.mantissa = mantissa & 0x7000000000000000; break;
				case 129: trunced.mantissa = mantissa & 0xB000000000000000; break;
				case 130: trunced.mantissa = mantissa & 0xE000000000000000; break;
				case 131: trunced.mantissa = mantissa & 0xF000000000000000; break;
				case 132: trunced.mantissa = mantissa & 0xF700000000000000; break;
				case 133: trunced.mantissa = mantissa & 0xFB00000000000000; break;
				case 134: trunced.mantissa = mantissa & 0xFE00000000000000; break;
				case 135: trunced.mantissa = mantissa & 0xFF00000000000000; break;
				case 136: trunced.mantissa = mantissa & 0xFF70000000000000; break;
				case 137: trunced.mantissa = mantissa & 0xFFB0000000000000; break;
				case 138: trunced.mantissa = mantissa & 0xFFE0000000000000; break;
				case 139: trunced.mantissa = mantissa & 0xFFF0000000000000; break;
				case 140: trunced.mantissa = mantissa & 0xFFF7000000000000; break;
				case 141: trunced.mantissa = mantissa & 0xFFFB000000000000; break;
				case 142: trunced.mantissa = mantissa & 0xFFFE000000000000; break;
				case 143: trunced.mantissa = mantissa & 0xFFFF000000000000; break;
				case 144: trunced.mantissa = mantissa & 0xFFFF700000000000; break;
				case 145: trunced.mantissa = mantissa & 0xFFFFB00000000000; break;
				case 146: trunced.mantissa = mantissa & 0xFFFFE00000000000; break;
				case 147: trunced.mantissa = mantissa & 0xFFFFF00000000000; break;
				case 148: trunced.mantissa = mantissa & 0xFFFFF70000000000; break;
				case 149: trunced.mantissa = mantissa & 0xFFFFFB0000000000; break;
				case 150: trunced.mantissa = mantissa & 0xFFFFFE0000000000; break;
				default: trunced.mantissa = 0; break;
				}
			}

			float ret{ 0 };

			try
			{
				ret = trunced.Value<float>();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return ret;
		}

		template<typename T>
		T Ceiling() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<>
		CHV4DF32 Ceiling<CHV4DF32>() const
		{
			CHV4DF32 trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.mantissa = mantissa & 0x0000000000000000; break;
				case 1024: trunced.mantissa = mantissa & 0x7000000000000000; break;
				case 1025: trunced.mantissa = mantissa & 0xB000000000000000; break;
				case 1026: trunced.mantissa = mantissa & 0xE000000000000000; break;
				case 1027: trunced.mantissa = mantissa & 0xF000000000000000; break;
				case 1028: trunced.mantissa = mantissa & 0xF700000000000000; break;
				case 1029: trunced.mantissa = mantissa & 0xFB00000000000000; break;
				case 1030: trunced.mantissa = mantissa & 0xFE00000000000000; break;
				case 1031: trunced.mantissa = mantissa & 0xFF00000000000000; break;
				case 1032: trunced.mantissa = mantissa & 0xFF70000000000000; break;
				case 1033: trunced.mantissa = mantissa & 0xFFB0000000000000; break;
				case 1034: trunced.mantissa = mantissa & 0xFFE0000000000000; break;
				case 1035: trunced.mantissa = mantissa & 0xFFF0000000000000; break;
				case 1036: trunced.mantissa = mantissa & 0xFFF7000000000000; break;
				case 1037: trunced.mantissa = mantissa & 0xFFFB000000000000; break;
				case 1038: trunced.mantissa = mantissa & 0xFFFE000000000000; break;
				case 1039: trunced.mantissa = mantissa & 0xFFFF000000000000; break;
				case 1040: trunced.mantissa = mantissa & 0xFFFF700000000000; break;
				case 1041: trunced.mantissa = mantissa & 0xFFFFB00000000000; break;
				case 1042: trunced.mantissa = mantissa & 0xFFFFE00000000000; break;
				case 1043: trunced.mantissa = mantissa & 0xFFFFF00000000000; break;
				case 1044: trunced.mantissa = mantissa & 0xFFFFF70000000000; break;
				case 1045: trunced.mantissa = mantissa & 0xFFFFFB0000000000; break;
				case 1046: trunced.mantissa = mantissa & 0xFFFFFE0000000000; break;
				case 1047: trunced.mantissa = mantissa & 0xFFFFFF0000000000; break;
				case 1048: trunced.mantissa = mantissa & 0xFFFFFF7000000000; break;
				case 1049: trunced.mantissa = mantissa & 0xFFFFFFB000000000; break;
				case 1050: trunced.mantissa = mantissa & 0xFFFFFFE000000000; break;
				case 1051: trunced.mantissa = mantissa & 0xFFFFFFF000000000; break;
				case 1052: trunced.mantissa = mantissa & 0xFFFFFFF700000000; break;
				case 1053: trunced.mantissa = mantissa & 0xFFFFFFFB00000000; break;
				case 1054: trunced.mantissa = mantissa & 0xFFFFFFFE00000000; break;
				case 1055: trunced.mantissa = mantissa & 0xFFFFFFFF00000000; break;
				case 1056: trunced.mantissa = mantissa & 0xFFFFFFFF70000000; break;
				case 1057: trunced.mantissa = mantissa & 0xFFFFFFFFB0000000; break;
				case 1058: trunced.mantissa = mantissa & 0xFFFFFFFFE0000000; break;
				case 1059: trunced.mantissa = mantissa & 0xFFFFFFFFF0000000; break;
				case 1060: trunced.mantissa = mantissa & 0xFFFFFFFFF7000000; break;
				case 1061: trunced.mantissa = mantissa & 0xFFFFFFFFFB000000; break;
				case 1062: trunced.mantissa = mantissa & 0xFFFFFFFFFE000000; break;
				case 1063: trunced.mantissa = mantissa & 0xFFFFFFFFFF000000; break;
				case 1064: trunced.mantissa = mantissa & 0xFFFFFFFFFF700000; break;
				case 1065: trunced.mantissa = mantissa & 0xFFFFFFFFFFB00000; break;
				case 1066: trunced.mantissa = mantissa & 0xFFFFFFFFFFE00000; break;
				case 1067: trunced.mantissa = mantissa & 0xFFFFFFFFFFF00000; break;
				case 1068: trunced.mantissa = mantissa & 0xFFFFFFFFFFF70000; break;
				case 1069: trunced.mantissa = mantissa & 0xFFFFFFFFFFFB0000; break;
				case 1070: trunced.mantissa = mantissa & 0xFFFFFFFFFFFE0000; break;
				case 1071: trunced.mantissa = mantissa & 0xFFFFFFFFFFFF0000; break;
				case 1072: trunced.mantissa = mantissa & 0xFFFFFFFFFFFF7000; break;
				case 1073: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFB000; break;
				case 1074: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFE000; break;
				case 1075: trunced.mantissa = mantissa & 0xFFFFFFFFFFFFF000; break;
				default: trunced.mantissa = 0; break;
				}

				//trunced.mantissa = trunced.mantissa >> ;


			}



			return trunced;
		}
		template<>
		float Floor<float>() const
		{
			CHV4DF32 trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				switch (trunced.exponent)
				{
				case 127: trunced.mantissa = mantissa & 0x0000000000000000; break;
				case 128: trunced.mantissa = mantissa & 0x7000000000000000; break;
				case 129: trunced.mantissa = mantissa & 0xB000000000000000; break;
				case 130: trunced.mantissa = mantissa & 0xE000000000000000; break;
				case 131: trunced.mantissa = mantissa & 0xF000000000000000; break;
				case 132: trunced.mantissa = mantissa & 0xF700000000000000; break;
				case 133: trunced.mantissa = mantissa & 0xFB00000000000000; break;
				case 134: trunced.mantissa = mantissa & 0xFE00000000000000; break;
				case 135: trunced.mantissa = mantissa & 0xFF00000000000000; break;
				case 136: trunced.mantissa = mantissa & 0xFF70000000000000; break;
				case 137: trunced.mantissa = mantissa & 0xFFB0000000000000; break;
				case 138: trunced.mantissa = mantissa & 0xFFE0000000000000; break;
				case 139: trunced.mantissa = mantissa & 0xFFF0000000000000; break;
				case 140: trunced.mantissa = mantissa & 0xFFF7000000000000; break;
				case 141: trunced.mantissa = mantissa & 0xFFFB000000000000; break;
				case 142: trunced.mantissa = mantissa & 0xFFFE000000000000; break;
				case 143: trunced.mantissa = mantissa & 0xFFFF000000000000; break;
				case 144: trunced.mantissa = mantissa & 0xFFFF700000000000; break;
				case 145: trunced.mantissa = mantissa & 0xFFFFB00000000000; break;
				case 146: trunced.mantissa = mantissa & 0xFFFFE00000000000; break;
				case 147: trunced.mantissa = mantissa & 0xFFFFF00000000000; break;
				case 148: trunced.mantissa = mantissa & 0xFFFFF70000000000; break;
				case 149: trunced.mantissa = mantissa & 0xFFFFFB0000000000; break;
				case 150: trunced.mantissa = mantissa & 0xFFFFFE0000000000; break;
				default: trunced.mantissa = 0; break;
				}
			}

			float ret{ 0 };

			try
			{
				ret = trunced.Value<float>();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return ret;
		}

	private:
		bool sign{ false };

		int64_t mantissa{ 0 };

		int16_t exponent{ 0 };

	};






	class CHV4DF32F32
	{
	public:
		CHV4DF32F32() = default;

		CHV4DF32F32(CHV4DF32 x, CHV4DF32 y) { Data[0] = x; Data[1] = y; };

		CHV4DF32F32(CHV4DF32F32 const& e) { *this = e; }

	public:
		inline void operator =(CHV4DF32F32 const& e) { memcpy(this, &e, sizeof(CHV4DF32F32)); }

		inline bool operator ==(CHV4DF32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32)) == 0; }

		inline bool operator !=(CHV4DF32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32)) != 0; }

		inline CHV4DF32F32 const operator ()() const { return *this; }

	public:
		CHV4DF32 const operator ~() { return static_cast<float>(cLength(Data[0](), Data[1]())); }

		CHV4DLDOUBLE const operator !() { return cLength(Data[0](), Data[1]()); }

		inline CHV4DF32& operator [](size_t const& i) { return Data[i]; }

		inline CHV4DF32 const A() { return Data[0]; }

		inline CHV4DF32 const B() { return Data[1]; }

	private:
		CHV4DF32 Data[2];

	};

	class CHV4DF32F32F32
	{
	public:
		CHV4DF32F32F32() = default;

		CHV4DF32F32F32(CHV4DF32 x, CHV4DF32 y, CHV4DF32 z)
		{
			Data[0] = x; Data[1] = y; Data[2] = z;

		}

		CHV4DF32F32F32(CHV4DF32F32F32 const& e)
		{
			*this = e;

		}

	public:
		inline void operator =(CHV4DF32F32F32 const& e) { memcpy(this, &e, sizeof(CHV4DF32F32F32)); }

		inline bool operator ==(CHV4DF32F32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32F32)) != 0; }

		inline bool operator !=(CHV4DF32F32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32F32)) == 0; }

		inline CHV4DF32F32F32 operator ()() const { return CHV4DF32F32F32{ Data[0], Data[1], Data[2] }; }

	public:
		CHV4DF32 const operator ~() { return static_cast<float>(cLength(Data[0](), Data[1](), Data[3]())); }

		CHV4DDOUBLE const operator !() { return cLength(Data[0](), Data[1](), Data[3]()); }

		inline CHV4DF32& operator [](size_t const& i) { return Data[i]; }

		inline CHV4DF32 const A() const { return Data[0]; }

		inline CHV4DF32 const B() const { return Data[1]; }

		inline CHV4DF32 const C() const { return Data[2]; }

	private:
		CHV4DF32 Data[3];

	};

	class CHV4DF32F32F32F32
	{
	public:
		CHV4DF32F32F32F32() = default;

		CHV4DF32F32F32F32(CHV4DF32 x, CHV4DF32 y, CHV4DF32 z, CHV4DF32 w)
		{
			Data[0] = x; Data[1] = y; Data[2] = z; Data[3] = w;

		}

		CHV4DF32F32F32F32(CHV4DF32F32F32F32 const& e)
		{
			*this = e;

		}

	public:
		inline void operator =(CHV4DF32F32F32F32 const& e) { memcpy(this, &e, sizeof(CHV4DF32F32F32F32)); }

		inline bool operator ==(CHV4DF32F32F32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32F32F32)) != 0; }

		inline bool operator !=(CHV4DF32F32F32F32 const& e) const { return memcmp(Data, e.Data, sizeof(CHV4DF32F32F32F32)) == 0; }

		inline CHV4DF32F32F32F32 operator ()() const { return CHV4DF32F32F32F32{ Data[0], Data[1], Data[2], Data[4] }; }

	public:
		CHV4DF32 const operator ~() { return static_cast<float>(cLength(Data[0](), Data[1](), Data[3](), Data[4]())); }

		CHV4DDOUBLE const operator !() { return cLength(Data[0](), Data[1](), Data[3](), Data[4]()); }

		inline CHV4DF32& operator [](size_t const& i) { return Data[i]; }

		inline CHV4DF32 const A() const { return Data[0]; }

		inline CHV4DF32 const B() const { return Data[1]; }

		inline CHV4DF32 const C() const { return Data[2]; }

		inline CHV4DF32 const D() const { return Data[3]; }

	private:
		CHV4DF32 Data[4];

	};
	*/
}