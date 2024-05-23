module;

#include <stdfloat>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DPRECISION;

import :CHV4DRESOURCE;

import :CHV4DINTEGER; 

export namespace CHV4DTENSOR
{
	class MaxPrecision
	{
	public:
		MaxPrecision(MaxPrecision const& x)	
		{
			sign = x.sign;

			significand = x.significand;

			exponent = x.exponent;
		}
		MaxPrecision(float const& x) 
		{
			float temp{ x };

			unsigned char* data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((data[0] & 0b10000000) == true) ? true : false;

			unsigned char fpexp = (data[0] << 1) | (data[1] >> 7);

			exponent = static_cast<uint16_t>(fpexp);

			uint32_t fpsignificand = 0x008FFFFF & *reinterpret_cast<uint32_t*>(data);

			data = reinterpret_cast<unsigned char*>(&fpsignificand);

			std::swap(data[0], data[3]);
			std::swap(data[1], data[2]);

			significand = static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(data));
		}
		MaxPrecision(double const& x) 
		{
			double temp{ x };

			unsigned char* data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((data[0] & 0b10000000) == true) ? true : false;

			unsigned char fpexp[2];
			
			fpexp[0] = (data[0] << 4) | (data[1] >> 4);

			fpexp[1] = (data[0] << 4) | (data[1] >> 4);

			exponent = *reinterpret_cast<uint16_t*>(fpexp);

			uint64_t fpsignificand = 0x008FFFFFFFFFFFFF & *reinterpret_cast<uint64_t*>(data);

			data = reinterpret_cast<unsigned char*>(&fpsignificand);

			std::swap(data[0], data[7]);
			std::swap(data[1], data[6]);
			std::swap(data[2], data[5]);
			std::swap(data[3], data[4]);

			significand = *reinterpret_cast<uint64_t*>(data);
		}

	public:
		void operator=(MaxPrecision const& x)
		{
			sign = x.sign;

			significand = x.significand;

			exponent = x.exponent;
		}
		void operator=(float const& x)
		{
			float temp{ x };

			unsigned char* data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((data[0] & 0b10000000) == true) ? true : false;

			unsigned char fpexp = (data[0] << 1) | (data[1] >> 7);

			exponent = static_cast<uint16_t>(fpexp);

			uint32_t fpsignificand = 0x008FFFFF & *reinterpret_cast<uint32_t*>(data);

			data = reinterpret_cast<unsigned char*>(&fpsignificand);

			std::swap(data[0], data[3]);
			std::swap(data[1], data[2]);

			significand = static_cast<uint64_t>(*reinterpret_cast<uint32_t*>(data));
		}
		void operator=(double const& x)
		{
			double temp{ x };

			unsigned char* data = reinterpret_cast<unsigned char*>(&temp);

			sign = ((data[0] & 0b10000000) == true) ? true : false;

			unsigned char fpexp[2];

			fpexp[0] = (data[0] << 4) | (data[1] >> 4);

			fpexp[1] = (data[0] << 4) | (data[1] >> 4);

			exponent = *reinterpret_cast<uint16_t*>(fpexp);

			uint64_t fpsignificand = 0x008FFFFFFFFFFFFF & *reinterpret_cast<uint64_t*>(data);

			data = reinterpret_cast<unsigned char*>(&fpsignificand);

			std::swap(data[0], data[7]);
			std::swap(data[1], data[6]);
			std::swap(data[2], data[5]);
			std::swap(data[3], data[4]);

			significand = *reinterpret_cast<uint64_t*>(data);
		}

		template<typename T>
		T operator()() const
		{
			static_assert(false, "Non Precision type.");
		}
		template<>
		MaxPrecision operator() < MaxPrecision > () const
		{
			return *this;
		}
		template<>
		float operator() < float > () const
		{
			unsigned char data[4]{ 0 };

			{
				sign ? data[0] | 0b10000000 : data[0] | 0;
			}

			{
				if (exponent > 255ui16) throw std::overflow_error{ "Precision overrun" };

				unsigned char fpexp = *reinterpret_cast<unsigned char*>(const_cast<uint16_t*>(&exponent));

				data[0] = data[0] | fpexp >> 1;

				data[1] = 0 | fpexp << 7;
			}

			{
				if (significand > 8388607ui64) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpsignificand = reinterpret_cast<unsigned char*>(const_cast<uint64_t*>(&significand));

				data[3] = fpsignificand[0];
				data[2] = fpsignificand[1];
				data[1] = data[1] | (fpsignificand[2] & 0b01111111);
			}

			return *reinterpret_cast<float*>(data);
		}
		template<>
		double operator() < double > () const
		{
			unsigned char data[8]{ 0 };

			{
				sign ? data[0] | 0b10000000 : data[0] | 0;
			}

			{
				if (exponent > 2047ui16) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpexp = reinterpret_cast<unsigned char*>(const_cast<uint16_t*>(&exponent));

				data[0] = data[0] | fpexp[1] >> 1;

				data[1] = 0 | fpexp[1] << 7;

				data[1] = data[1] | ((fpexp[0] >> 1) & 0b01110000);
			}

			{
				if (significand > 4503599627370495ui64) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpsignificand = reinterpret_cast<unsigned char*>(const_cast<uint64_t*>(&significand));

				data[7] = fpsignificand[0];
				data[6] = fpsignificand[1];
				data[5] = fpsignificand[2];
				data[4] = fpsignificand[3];
				data[3] = fpsignificand[4];
				data[2] = fpsignificand[5];
				data[1] = data[1] | (fpsignificand[6] & 0b00001111);
			}

			return *reinterpret_cast<double*>(data);
		}

		void operator+(MaxPrecision const& x) const
		{

		}
		void operator+(float const& x) const
		{

		}
		void operator+(double const& x) const
		{

		}

		void operator-(MaxPrecision const& x) const
		{

		}
		void operator-(float const& x) const
		{

		}
		void operator-(double const& x) const
		{

		}

		void operator*(MaxPrecision const& x) const
		{

		}
		void operator*(float const& x) const
		{

		}
		void operator*(double const& x) const
		{

		}

		void operator/(MaxPrecision const& x) const
		{

		}
		void operator/(float const& x) const
		{

		}
		void operator/(double const& x) const
		{

		}

		void operator^(MaxPrecision const& x) const
		{

		}
		void operator^(float const& x) const
		{

		}
		void operator^(double const& x) const
		{

		}

		void operator==(MaxPrecision const& x) const
		{

		}
		void operator==(float const& x) const
		{

		}
		void operator==(double const& x) const
		{

		}

		void operator>(MaxPrecision const& x) const
		{

		}
		void operator>(float const& x) const
		{

		}
		void operator>(double const& x) const
		{

		}

		void operator<(MaxPrecision const& x) const
		{

		}
		void operator<(float const& x) const
		{

		}
		void operator<(double const& x) const
		{

		}

		void operator>=(MaxPrecision const& x) const
		{

		}
		void operator>=(float const& x) const
		{

		}
		void operator>=(double const& x) const
		{

		}

		void operator<=(MaxPrecision const& x) const
		{

		}
		void operator<=(float const& x) const
		{

		}
		void operator<=(double const& x) const
		{

		}

	public:
		bool Sign() const { return sign ? true : false; }

		bool Infinity() const { return (exponent == 65535ui16) && (significand != 0ui64) ? true : false; }

		size_t Exponent() const { return exponent; }

		size_t Significand() const { return significand; }

		template<typename T>
		T Value() const
		{
			static_assert(false, "Non Precision type.");
		}
		template<>
		MaxPrecision Value<MaxPrecision>() const
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
			catch(std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return fpvalue;
		}
		template<>
		double Value<double>() const
		{
			double fpvalue{ 0 };

			try
			{
				fpvalue = this->operator() < double > ();
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
		T Abs() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<>
		float Abs<float>() const
		{
			unsigned char data[4]{ 0 };

			{
				if (exponent > 255ui16) throw std::overflow_error{ "Precision overrun" };

				unsigned char fpexp = *reinterpret_cast<unsigned char*>(const_cast<uint16_t*>(&exponent));

				data[0] = data[0] | fpexp >> 1;

				data[1] = 0 | fpexp << 7;
			}

			{
				if (significand > 8388607ui64) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpsignificand = reinterpret_cast<unsigned char*>(const_cast<uint64_t*>(&significand));

				data[3] = fpsignificand[0];
				data[2] = fpsignificand[1];
				data[1] = data[1] | (fpsignificand[2] & 0b01111111);
			}

			return *reinterpret_cast<float*>(data);
		}
		template<>
		double Abs<double>() const
		{
			unsigned char data[8]{ 0 };

			{
				if (exponent > 2047ui16) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpexp = reinterpret_cast<unsigned char*>(const_cast<uint16_t*>(&exponent));

				data[0] = data[0] | fpexp[1] >> 1;

				data[1] = 0 | fpexp[1] << 7;

				data[1] = data[1] | ((fpexp[0] >> 1) & 0b01110000);
			}

			{
				if (significand > 4503599627370495ui64) throw std::overflow_error{ "Precision overrun" };

				unsigned char* fpsignificand = reinterpret_cast<unsigned char*>(const_cast<uint64_t*>(&significand));

				data[7] = fpsignificand[0];
				data[6] = fpsignificand[1];
				data[5] = fpsignificand[2];
				data[4] = fpsignificand[3];
				data[3] = fpsignificand[4];
				data[2] = fpsignificand[5];
				data[1] = data[1] | (fpsignificand[6] & 0b00001111);
			}

			return *reinterpret_cast<double*>(data);
		}

		template<typename T>
		T Trunc(size_t sigBits) const
		{
			static_assert(false, "Non Integer type.");
		}
		template<>
		MaxPrecision Trunc<MaxPrecision>(size_t sigBits) const
		{
			if (!(sigBits < 53 && sigBits >= 0)) std::runtime_error{ "Sig Bit Error." };

			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				trunced.significand = trunced.significand << trunced.exponent - 1023;
			}
			else if (trunced.exponent < 1023ui16)
			{
				trunced.significand = trunced.significand >> 1023 - trunced.exponent;
			}

			switch (sigBits)
			{
			case 0:	trunced.significand = trunced.significand & 0x00000000000000; break;
			case 1:	trunced.significand = trunced.significand & 0x70000000000000; break;
			case 2:	trunced.significand = trunced.significand & 0xB0000000000000; break;
			case 3:	trunced.significand = trunced.significand & 0xE0000000000000; break;
			case 4:	trunced.significand = trunced.significand & 0xF0000000000000; break;
			case 5:	trunced.significand = trunced.significand & 0xF7000000000000; break;
			case 6:	trunced.significand = trunced.significand & 0xFB000000000000; break;
			case 7:	trunced.significand = trunced.significand & 0xFE000000000000; break;
			case 8:	trunced.significand = trunced.significand & 0xFF000000000000; break;
			case 9:	trunced.significand = trunced.significand & 0xFF700000000000; break;
			case 10: trunced.significand = trunced.significand & 0xFFB00000000000; break;
			case 11: trunced.significand = trunced.significand & 0xFFE00000000000; break;
			case 12: trunced.significand = trunced.significand & 0xFFF00000000000; break;
			case 13: trunced.significand = trunced.significand & 0xFFF70000000000; break;
			case 14: trunced.significand = trunced.significand & 0xFFFB0000000000; break;
			case 15: trunced.significand = trunced.significand & 0xFFFE0000000000; break;
			case 16: trunced.significand = trunced.significand & 0xFFFF0000000000; break;
			case 17: trunced.significand = trunced.significand & 0xFFFF7000000000; break;
			case 18: trunced.significand = trunced.significand & 0xFFFFB000000000; break;
			case 19: trunced.significand = trunced.significand & 0xFFFFE000000000; break;
			case 20: trunced.significand = trunced.significand & 0xFFFFF000000000; break;
			case 21: trunced.significand = trunced.significand & 0xFFFFF700000000; break;
			case 22: trunced.significand = trunced.significand & 0xFFFFFB00000000; break;
			case 23: trunced.significand = trunced.significand & 0xFFFFFE00000000; break;
			case 24: trunced.significand = trunced.significand & 0xFFFFFF0000000000; break;
			case 25: trunced.significand = trunced.significand & 0xFFFFFF7000000000; break;
			case 26: trunced.significand = trunced.significand & 0xFFFFFFB000000000; break;
			case 27: trunced.significand = trunced.significand & 0xFFFFFFE000000000; break;
			case 28: trunced.significand = trunced.significand & 0xFFFFFFF000000000; break;
			case 29: trunced.significand = trunced.significand & 0xFFFFFFF700000000; break;
			case 30: trunced.significand = trunced.significand & 0xFFFFFFFB00000000; break;
			case 31: trunced.significand = trunced.significand & 0xFFFFFFFE00000000; break;
			case 32: trunced.significand = trunced.significand & 0xFFFFFFFF00000000; break;
			case 33: trunced.significand = trunced.significand & 0xFFFFFFFF70000000; break;
			case 34: trunced.significand = trunced.significand & 0xFFFFFFFFB0000000; break;
			case 35: trunced.significand = trunced.significand & 0xFFFFFFFFE0000000; break;
			case 36: trunced.significand = trunced.significand & 0xFFFFFFFFF0000000; break;
			case 37: trunced.significand = trunced.significand & 0xFFFFFFFFF7000000; break;
			case 38: trunced.significand = trunced.significand & 0xFFFFFFFFFB000000; break;
			case 39: trunced.significand = trunced.significand & 0xFFFFFFFFFE000000; break;
			case 40: trunced.significand = trunced.significand & 0xFFFFFFFFFF000000; break;
			case 41: trunced.significand = trunced.significand & 0xFFFFFFFFFF700000; break;
			case 42: trunced.significand = trunced.significand & 0xFFFFFFFFFFB00000; break;
			case 43: trunced.significand = trunced.significand & 0xFFFFFFFFFFE00000; break;
			case 44: trunced.significand = trunced.significand & 0xFFFFFFFFFFF00000; break;
			case 45: trunced.significand = trunced.significand & 0xFFFFFFFFFFF70000; break;
			case 46: trunced.significand = trunced.significand & 0xFFFFFFFFFFFB0000; break;
			case 47: trunced.significand = trunced.significand & 0xFFFFFFFFFFFE0000; break;
			case 48: trunced.significand = trunced.significand & 0xFFFFFFFFFFFF0000; break;
			case 49: trunced.significand = trunced.significand & 0xFFFFFFFFFFFF7000; break;
			case 50: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFB000; break;
			case 51: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFE000; break;
			case 52: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFF000; break;
			default: break;
			}

			if (trunced.exponent > 1023ui16)
			{
				trunced.significand = trunced.significand >> trunced.exponent - 1023ui16;

				switch (trunced.exponent)
				{
				case 1023: trunced.significand = trunced.significand | (significand & 0x0000000000000000); break;
				case 1024: trunced.significand = trunced.significand | (significand & 0x7000000000000000); break;
				case 1025: trunced.significand = trunced.significand | (significand & 0xB000000000000000); break;
				case 1026: trunced.significand = trunced.significand | (significand & 0xE000000000000000); break;
				case 1027: trunced.significand = trunced.significand | (significand & 0xF000000000000000); break;
				case 1028: trunced.significand = trunced.significand | (significand & 0xF700000000000000); break;
				case 1029: trunced.significand = trunced.significand | (significand & 0xFB00000000000000); break;
				case 1030: trunced.significand = trunced.significand | (significand & 0xFE00000000000000); break;
				case 1031: trunced.significand = trunced.significand | (significand & 0xFF00000000000000); break;
				case 1032: trunced.significand = trunced.significand | (significand & 0xFF70000000000000); break;
				case 1033: trunced.significand = trunced.significand | (significand & 0xFFB0000000000000); break;
				case 1034: trunced.significand = trunced.significand | (significand & 0xFFE0000000000000); break;
				case 1035: trunced.significand = trunced.significand | (significand & 0xFFF0000000000000); break;
				case 1036: trunced.significand = trunced.significand | (significand & 0xFFF7000000000000); break;
				case 1037: trunced.significand = trunced.significand | (significand & 0xFFFB000000000000); break;
				case 1038: trunced.significand = trunced.significand | (significand & 0xFFFE000000000000); break;
				case 1039: trunced.significand = trunced.significand | (significand & 0xFFFF000000000000); break;
				case 1040: trunced.significand = trunced.significand | (significand & 0xFFFF700000000000); break;
				case 1041: trunced.significand = trunced.significand | (significand & 0xFFFFB00000000000); break;
				case 1042: trunced.significand = trunced.significand | (significand & 0xFFFFE00000000000); break;
				case 1043: trunced.significand = trunced.significand | (significand & 0xFFFFF00000000000); break;
				case 1044: trunced.significand = trunced.significand | (significand & 0xFFFFF70000000000); break;
				case 1045: trunced.significand = trunced.significand | (significand & 0xFFFFFB0000000000); break;
				case 1046: trunced.significand = trunced.significand | (significand & 0xFFFFFE0000000000); break;
				case 1047: trunced.significand = trunced.significand | (significand & 0xFFFFFF0000000000); break;
				case 1048: trunced.significand = trunced.significand | (significand & 0xFFFFFF7000000000); break;
				case 1049: trunced.significand = trunced.significand | (significand & 0xFFFFFFB000000000); break;
				case 1050: trunced.significand = trunced.significand | (significand & 0xFFFFFFE000000000); break;
				case 1051: trunced.significand = trunced.significand | (significand & 0xFFFFFFF000000000); break;
				case 1052: trunced.significand = trunced.significand | (significand & 0xFFFFFFF700000000); break;
				case 1053: trunced.significand = trunced.significand | (significand & 0xFFFFFFFB00000000); break;
				case 1054: trunced.significand = trunced.significand | (significand & 0xFFFFFFFE00000000); break;
				case 1055: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF00000000); break;
				case 1056: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF70000000); break;
				case 1057: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFB0000000); break;
				case 1058: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFE0000000); break;
				case 1059: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF0000000); break;
				case 1060: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF7000000); break;
				case 1061: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFB000000); break;
				case 1062: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFE000000); break;
				case 1063: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF000000); break;
				case 1064: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF700000); break;
				case 1065: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFB00000); break;
				case 1066: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFE00000); break;
				case 1067: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF00000); break;
				case 1068: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF70000); break;
				case 1069: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFB0000); break;
				case 1070: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFE0000); break;
				case 1071: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF0000); break;
				case 1072: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF7000); break;
				case 1073: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFB000); break;
				case 1074: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFE000); break;
				case 1075: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFF000); break;
				default: trunced.significand = 0; break;
				}
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.significand = trunced.significand << 127ui16 - trunced.exponent;
			}

			return trunced;
		}
		template<>
		float Trunc<float>(size_t sigBits) const
		{
			if (!(sigBits < 24 && sigBits >= 0)) std::runtime_error{ "Sig Bit Error." };

			MaxPrecision trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				trunced.significand = trunced.significand << trunced.exponent - 127ui16;
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.significand = trunced.significand >> 127ui16 - trunced.exponent;
			}

			switch (sigBits)
			{
			case 0:	trunced.significand = trunced.significand & 0x0000000000000000; break;
			case 1:	trunced.significand = trunced.significand & 0x7000000000000000; break;
			case 2:	trunced.significand = trunced.significand & 0xB000000000000000; break;
			case 3:	trunced.significand = trunced.significand & 0xE000000000000000; break;
			case 4:	trunced.significand = trunced.significand & 0xF000000000000000; break;
			case 5:	trunced.significand = trunced.significand & 0xF700000000000000; break;
			case 6:	trunced.significand = trunced.significand & 0xFB00000000000000; break;
			case 7:	trunced.significand = trunced.significand & 0xFE00000000000000; break;
			case 8:	trunced.significand = trunced.significand & 0xFF00000000000000; break;
			case 9:	trunced.significand = trunced.significand & 0xFF70000000000000; break;
			case 10: trunced.significand = trunced.significand & 0xFFB0000000000000; break;
			case 11: trunced.significand = trunced.significand & 0xFFE0000000000000; break;
			case 12: trunced.significand = trunced.significand & 0xFFF0000000000000; break;
			case 13: trunced.significand = trunced.significand & 0xFFF7000000000000; break;
			case 14: trunced.significand = trunced.significand & 0xFFFB000000000000; break;
			case 15: trunced.significand = trunced.significand & 0xFFFE000000000000; break;
			case 16: trunced.significand = trunced.significand & 0xFFFF000000000000; break;
			case 17: trunced.significand = trunced.significand & 0xFFFF700000000000; break;
			case 18: trunced.significand = trunced.significand & 0xFFFFB00000000000; break;
			case 19: trunced.significand = trunced.significand & 0xFFFFE00000000000; break;
			case 20: trunced.significand = trunced.significand & 0xFFFFF00000000000; break;
			case 21: trunced.significand = trunced.significand & 0xFFFFF70000000000; break;
			case 22: trunced.significand = trunced.significand & 0xFFFFFB0000000000; break;
			case 23: trunced.significand = trunced.significand & 0xFFFFFE0000000000; break;
			default: break;
			}

			if (trunced.exponent > 127ui16)
			{
				trunced.significand = trunced.significand >> trunced.exponent - 127ui16;

				switch (trunced.exponent)
				{
				case 127: trunced.significand = trunced.significand | (significand & 0x0000000000000000); break;
				case 128: trunced.significand = trunced.significand | (significand & 0x7000000000000000); break;
				case 129: trunced.significand = trunced.significand | (significand & 0xB000000000000000); break;
				case 130: trunced.significand = trunced.significand | (significand & 0xE000000000000000); break;
				case 131: trunced.significand = trunced.significand | (significand & 0xF000000000000000); break;
				case 132: trunced.significand = trunced.significand | (significand & 0xF700000000000000); break;
				case 133: trunced.significand = trunced.significand | (significand & 0xFB00000000000000); break;
				case 134: trunced.significand = trunced.significand | (significand & 0xFE00000000000000); break;
				case 135: trunced.significand = trunced.significand | (significand & 0xFF00000000000000); break;
				case 136: trunced.significand = trunced.significand | (significand & 0xFF70000000000000); break;
				case 137: trunced.significand = trunced.significand | (significand & 0xFFB0000000000000); break;
				case 138: trunced.significand = trunced.significand | (significand & 0xFFE0000000000000); break;
				case 139: trunced.significand = trunced.significand | (significand & 0xFFF0000000000000); break;
				case 140: trunced.significand = trunced.significand | (significand & 0xFFF7000000000000); break;
				case 141: trunced.significand = trunced.significand | (significand & 0xFFFB000000000000); break;
				case 142: trunced.significand = trunced.significand | (significand & 0xFFFE000000000000); break;
				case 143: trunced.significand = trunced.significand | (significand & 0xFFFF000000000000); break;
				case 144: trunced.significand = trunced.significand | (significand & 0xFFFF700000000000); break;
				case 145: trunced.significand = trunced.significand | (significand & 0xFFFFB00000000000); break;
				case 146: trunced.significand = trunced.significand | (significand & 0xFFFFE00000000000); break;
				case 147: trunced.significand = trunced.significand | (significand & 0xFFFFF00000000000); break;
				case 148: trunced.significand = trunced.significand | (significand & 0xFFFFF70000000000); break;
				case 149: trunced.significand = trunced.significand | (significand & 0xFFFFFB0000000000); break;
				case 150: trunced.significand = trunced.significand | (significand & 0xFFFFFE0000000000); break;
				default: trunced.significand = 0; break;
				}
			}
			else if (trunced.exponent < 127ui16)
			{
				trunced.significand = trunced.significand << 127ui16 - trunced.exponent;
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
		template<>
		double Trunc<double>(size_t sigBits) const
		{
			if (!(sigBits < 53 && sigBits >= 0)) std::runtime_error{ "Sig Bit Error." };

			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				trunced.significand = trunced.significand << trunced.exponent - 1023ui16;
			}
			else if (trunced.exponent < 1023ui16)
			{
				trunced.significand = trunced.significand >> 1023ui16 - trunced.exponent;
			}

			switch (sigBits)
			{
			case 0:	trunced.significand = trunced.significand & 0x00000000000000; break;
			case 1:	trunced.significand = trunced.significand & 0x70000000000000; break;
			case 2:	trunced.significand = trunced.significand & 0xB0000000000000; break;
			case 3:	trunced.significand = trunced.significand & 0xE0000000000000; break;
			case 4:	trunced.significand = trunced.significand & 0xF0000000000000; break;
			case 5:	trunced.significand = trunced.significand & 0xF7000000000000; break;
			case 6:	trunced.significand = trunced.significand & 0xFB000000000000; break;
			case 7:	trunced.significand = trunced.significand & 0xFE000000000000; break;
			case 8:	trunced.significand = trunced.significand & 0xFF000000000000; break;
			case 9:	trunced.significand = trunced.significand & 0xFF700000000000; break;
			case 10: trunced.significand = trunced.significand & 0xFFB00000000000; break;
			case 11: trunced.significand = trunced.significand & 0xFFE00000000000; break;
			case 12: trunced.significand = trunced.significand & 0xFFF00000000000; break;
			case 13: trunced.significand = trunced.significand & 0xFFF70000000000; break;
			case 14: trunced.significand = trunced.significand & 0xFFFB0000000000; break;
			case 15: trunced.significand = trunced.significand & 0xFFFE0000000000; break;
			case 16: trunced.significand = trunced.significand & 0xFFFF0000000000; break;
			case 17: trunced.significand = trunced.significand & 0xFFFF7000000000; break;
			case 18: trunced.significand = trunced.significand & 0xFFFFB000000000; break;
			case 19: trunced.significand = trunced.significand & 0xFFFFE000000000; break;
			case 20: trunced.significand = trunced.significand & 0xFFFFF000000000; break;
			case 21: trunced.significand = trunced.significand & 0xFFFFF700000000; break;
			case 22: trunced.significand = trunced.significand & 0xFFFFFB00000000; break;
			case 23: trunced.significand = trunced.significand & 0xFFFFFE00000000; break;
			case 24: trunced.significand = trunced.significand & 0xFFFFFF0000000000; break;
			case 25: trunced.significand = trunced.significand & 0xFFFFFF7000000000; break;
			case 26: trunced.significand = trunced.significand & 0xFFFFFFB000000000; break;
			case 27: trunced.significand = trunced.significand & 0xFFFFFFE000000000; break;
			case 28: trunced.significand = trunced.significand & 0xFFFFFFF000000000; break;
			case 29: trunced.significand = trunced.significand & 0xFFFFFFF700000000; break;
			case 30: trunced.significand = trunced.significand & 0xFFFFFFFB00000000; break;
			case 31: trunced.significand = trunced.significand & 0xFFFFFFFE00000000; break;
			case 32: trunced.significand = trunced.significand & 0xFFFFFFFF00000000; break;
			case 33: trunced.significand = trunced.significand & 0xFFFFFFFF70000000; break;
			case 34: trunced.significand = trunced.significand & 0xFFFFFFFFB0000000; break;
			case 35: trunced.significand = trunced.significand & 0xFFFFFFFFE0000000; break;
			case 36: trunced.significand = trunced.significand & 0xFFFFFFFFF0000000; break;
			case 37: trunced.significand = trunced.significand & 0xFFFFFFFFF7000000; break;
			case 38: trunced.significand = trunced.significand & 0xFFFFFFFFFB000000; break;
			case 39: trunced.significand = trunced.significand & 0xFFFFFFFFFE000000; break;
			case 40: trunced.significand = trunced.significand & 0xFFFFFFFFFF000000; break;
			case 41: trunced.significand = trunced.significand & 0xFFFFFFFFFF700000; break;
			case 42: trunced.significand = trunced.significand & 0xFFFFFFFFFFB00000; break;
			case 43: trunced.significand = trunced.significand & 0xFFFFFFFFFFE00000; break;
			case 44: trunced.significand = trunced.significand & 0xFFFFFFFFFFF00000; break;
			case 45: trunced.significand = trunced.significand & 0xFFFFFFFFFFF70000; break;
			case 46: trunced.significand = trunced.significand & 0xFFFFFFFFFFFB0000; break;
			case 47: trunced.significand = trunced.significand & 0xFFFFFFFFFFFE0000; break;
			case 48: trunced.significand = trunced.significand & 0xFFFFFFFFFFFF0000; break;
			case 49: trunced.significand = trunced.significand & 0xFFFFFFFFFFFF7000; break;
			case 50: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFB000; break;
			case 51: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFE000; break;
			case 52: trunced.significand = trunced.significand & 0xFFFFFFFFFFFFF000; break;
			default: break;
			}

			if (trunced.exponent > 1023ui16)
			{
				trunced.significand = trunced.significand >> trunced.exponent - 1023ui16;

				switch (trunced.exponent)
				{
				case 1023: trunced.significand = trunced.significand | (significand & 0x0000000000000000); break;
				case 1024: trunced.significand = trunced.significand | (significand & 0x7000000000000000); break;
				case 1025: trunced.significand = trunced.significand | (significand & 0xB000000000000000); break;
				case 1026: trunced.significand = trunced.significand | (significand & 0xE000000000000000); break;
				case 1027: trunced.significand = trunced.significand | (significand & 0xF000000000000000); break;
				case 1028: trunced.significand = trunced.significand | (significand & 0xF700000000000000); break;
				case 1029: trunced.significand = trunced.significand | (significand & 0xFB00000000000000); break;
				case 1030: trunced.significand = trunced.significand | (significand & 0xFE00000000000000); break;
				case 1031: trunced.significand = trunced.significand | (significand & 0xFF00000000000000); break;
				case 1032: trunced.significand = trunced.significand | (significand & 0xFF70000000000000); break;
				case 1033: trunced.significand = trunced.significand | (significand & 0xFFB0000000000000); break;
				case 1034: trunced.significand = trunced.significand | (significand & 0xFFE0000000000000); break;
				case 1035: trunced.significand = trunced.significand | (significand & 0xFFF0000000000000); break;
				case 1036: trunced.significand = trunced.significand | (significand & 0xFFF7000000000000); break;
				case 1037: trunced.significand = trunced.significand | (significand & 0xFFFB000000000000); break;
				case 1038: trunced.significand = trunced.significand | (significand & 0xFFFE000000000000); break;
				case 1039: trunced.significand = trunced.significand | (significand & 0xFFFF000000000000); break;
				case 1040: trunced.significand = trunced.significand | (significand & 0xFFFF700000000000); break;
				case 1041: trunced.significand = trunced.significand | (significand & 0xFFFFB00000000000); break;
				case 1042: trunced.significand = trunced.significand | (significand & 0xFFFFE00000000000); break;
				case 1043: trunced.significand = trunced.significand | (significand & 0xFFFFF00000000000); break;
				case 1044: trunced.significand = trunced.significand | (significand & 0xFFFFF70000000000); break;
				case 1045: trunced.significand = trunced.significand | (significand & 0xFFFFFB0000000000); break;
				case 1046: trunced.significand = trunced.significand | (significand & 0xFFFFFE0000000000); break;
				case 1047: trunced.significand = trunced.significand | (significand & 0xFFFFFF0000000000); break;
				case 1048: trunced.significand = trunced.significand | (significand & 0xFFFFFF7000000000); break;
				case 1049: trunced.significand = trunced.significand | (significand & 0xFFFFFFB000000000); break;
				case 1050: trunced.significand = trunced.significand | (significand & 0xFFFFFFE000000000); break;
				case 1051: trunced.significand = trunced.significand | (significand & 0xFFFFFFF000000000); break;
				case 1052: trunced.significand = trunced.significand | (significand & 0xFFFFFFF700000000); break;
				case 1053: trunced.significand = trunced.significand | (significand & 0xFFFFFFFB00000000); break;
				case 1054: trunced.significand = trunced.significand | (significand & 0xFFFFFFFE00000000); break;
				case 1055: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF00000000); break;
				case 1056: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF70000000); break;
				case 1057: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFB0000000); break;
				case 1058: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFE0000000); break;
				case 1059: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF0000000); break;
				case 1060: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF7000000); break;
				case 1061: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFB000000); break;
				case 1062: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFE000000); break;
				case 1063: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF000000); break;
				case 1064: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF700000); break;
				case 1065: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFB00000); break;
				case 1066: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFE00000); break;
				case 1067: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF00000); break;
				case 1068: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF70000); break;
				case 1069: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFB0000); break;
				case 1070: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFE0000); break;
				case 1071: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF0000); break;
				case 1072: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF7000); break;
				case 1073: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFB000); break;
				case 1074: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFE000); break;
				case 1075: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFF000); break;
				default: trunced.significand = 0; break;
				}
			}
			else if (trunced.exponent < 1023ui16)
			{
				trunced.significand = trunced.significand << 1023ui16 - trunced.exponent;
			}

			double ret{ 0.0 };

			try
			{
				ret = trunced.Value<double>();
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
		MaxPrecision Floor<MaxPrecision>() const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.significand = significand & 0x0000000000000000; break;
				case 1024: trunced.significand = significand & 0x7000000000000000; break;
				case 1025: trunced.significand = significand & 0xB000000000000000; break;
				case 1026: trunced.significand = significand & 0xE000000000000000; break;
				case 1027: trunced.significand = significand & 0xF000000000000000; break;
				case 1028: trunced.significand = significand & 0xF700000000000000; break;
				case 1029: trunced.significand = significand & 0xFB00000000000000; break;
				case 1030: trunced.significand = significand & 0xFE00000000000000; break;
				case 1031: trunced.significand = significand & 0xFF00000000000000; break;
				case 1032: trunced.significand = significand & 0xFF70000000000000; break;
				case 1033: trunced.significand = significand & 0xFFB0000000000000; break;
				case 1034: trunced.significand = significand & 0xFFE0000000000000; break;
				case 1035: trunced.significand = significand & 0xFFF0000000000000; break;
				case 1036: trunced.significand = significand & 0xFFF7000000000000; break;
				case 1037: trunced.significand = significand & 0xFFFB000000000000; break;
				case 1038: trunced.significand = significand & 0xFFFE000000000000; break;
				case 1039: trunced.significand = significand & 0xFFFF000000000000; break;
				case 1040: trunced.significand = significand & 0xFFFF700000000000; break;
				case 1041: trunced.significand = significand & 0xFFFFB00000000000; break;
				case 1042: trunced.significand = significand & 0xFFFFE00000000000; break;
				case 1043: trunced.significand = significand & 0xFFFFF00000000000; break;
				case 1044: trunced.significand = significand & 0xFFFFF70000000000; break;
				case 1045: trunced.significand = significand & 0xFFFFFB0000000000; break;
				case 1046: trunced.significand = significand & 0xFFFFFE0000000000; break;
				case 1047: trunced.significand = significand & 0xFFFFFF0000000000; break;
				case 1048: trunced.significand = significand & 0xFFFFFF7000000000; break;
				case 1049: trunced.significand = significand & 0xFFFFFFB000000000; break;
				case 1050: trunced.significand = significand & 0xFFFFFFE000000000; break;
				case 1051: trunced.significand = significand & 0xFFFFFFF000000000; break;
				case 1052: trunced.significand = significand & 0xFFFFFFF700000000; break;
				case 1053: trunced.significand = significand & 0xFFFFFFFB00000000; break;
				case 1054: trunced.significand = significand & 0xFFFFFFFE00000000; break;
				case 1055: trunced.significand = significand & 0xFFFFFFFF00000000; break;
				case 1056: trunced.significand = significand & 0xFFFFFFFF70000000; break;
				case 1057: trunced.significand = significand & 0xFFFFFFFFB0000000; break;
				case 1058: trunced.significand = significand & 0xFFFFFFFFE0000000; break;
				case 1059: trunced.significand = significand & 0xFFFFFFFFF0000000; break;
				case 1060: trunced.significand = significand & 0xFFFFFFFFF7000000; break;
				case 1061: trunced.significand = significand & 0xFFFFFFFFFB000000; break;
				case 1062: trunced.significand = significand & 0xFFFFFFFFFE000000; break;
				case 1063: trunced.significand = significand & 0xFFFFFFFFFF000000; break;
				case 1064: trunced.significand = significand & 0xFFFFFFFFFF700000; break;
				case 1065: trunced.significand = significand & 0xFFFFFFFFFFB00000; break;
				case 1066: trunced.significand = significand & 0xFFFFFFFFFFE00000; break;
				case 1067: trunced.significand = significand & 0xFFFFFFFFFFF00000; break;
				case 1068: trunced.significand = significand & 0xFFFFFFFFFFF70000; break;
				case 1069: trunced.significand = significand & 0xFFFFFFFFFFFB0000; break;
				case 1070: trunced.significand = significand & 0xFFFFFFFFFFFE0000; break;
				case 1071: trunced.significand = significand & 0xFFFFFFFFFFFF0000; break;
				case 1072: trunced.significand = significand & 0xFFFFFFFFFFFF7000; break;
				case 1073: trunced.significand = significand & 0xFFFFFFFFFFFFB000; break;
				case 1074: trunced.significand = significand & 0xFFFFFFFFFFFFE000; break;
				case 1075: trunced.significand = significand & 0xFFFFFFFFFFFFF000; break;
				default: trunced.significand = 0; break;
				}
			}

			return trunced;
		}
		template<>
		float Floor<float>() const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				switch (trunced.exponent)
				{
				case 127: trunced.significand = significand & 0x0000000000000000; break;
				case 128: trunced.significand = significand & 0x7000000000000000; break;
				case 129: trunced.significand = significand & 0xB000000000000000; break;
				case 130: trunced.significand = significand & 0xE000000000000000; break;
				case 131: trunced.significand = significand & 0xF000000000000000; break;
				case 132: trunced.significand = significand & 0xF700000000000000; break;
				case 133: trunced.significand = significand & 0xFB00000000000000; break;
				case 134: trunced.significand = significand & 0xFE00000000000000; break;
				case 135: trunced.significand = significand & 0xFF00000000000000; break;
				case 136: trunced.significand = significand & 0xFF70000000000000; break;
				case 137: trunced.significand = significand & 0xFFB0000000000000; break;
				case 138: trunced.significand = significand & 0xFFE0000000000000; break;
				case 139: trunced.significand = significand & 0xFFF0000000000000; break;
				case 140: trunced.significand = significand & 0xFFF7000000000000; break;
				case 141: trunced.significand = significand & 0xFFFB000000000000; break;
				case 142: trunced.significand = significand & 0xFFFE000000000000; break;
				case 143: trunced.significand = significand & 0xFFFF000000000000; break;
				case 144: trunced.significand = significand & 0xFFFF700000000000; break;
				case 145: trunced.significand = significand & 0xFFFFB00000000000; break;
				case 146: trunced.significand = significand & 0xFFFFE00000000000; break;
				case 147: trunced.significand = significand & 0xFFFFF00000000000; break;
				case 148: trunced.significand = significand & 0xFFFFF70000000000; break;
				case 149: trunced.significand = significand & 0xFFFFFB0000000000; break;
				case 150: trunced.significand = significand & 0xFFFFFE0000000000; break;
				default: trunced.significand = 0; break;
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
		template<>
		double Trunc<double>(size_t sigBits) const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.significand = trunced.significand | (significand & 0x0000000000000000); break;
				case 1024: trunced.significand = trunced.significand | (significand & 0x7000000000000000); break;
				case 1025: trunced.significand = trunced.significand | (significand & 0xB000000000000000); break;
				case 1026: trunced.significand = trunced.significand | (significand & 0xE000000000000000); break;
				case 1027: trunced.significand = trunced.significand | (significand & 0xF000000000000000); break;
				case 1028: trunced.significand = trunced.significand | (significand & 0xF700000000000000); break;
				case 1029: trunced.significand = trunced.significand | (significand & 0xFB00000000000000); break;
				case 1030: trunced.significand = trunced.significand | (significand & 0xFE00000000000000); break;
				case 1031: trunced.significand = trunced.significand | (significand & 0xFF00000000000000); break;
				case 1032: trunced.significand = trunced.significand | (significand & 0xFF70000000000000); break;
				case 1033: trunced.significand = trunced.significand | (significand & 0xFFB0000000000000); break;
				case 1034: trunced.significand = trunced.significand | (significand & 0xFFE0000000000000); break;
				case 1035: trunced.significand = trunced.significand | (significand & 0xFFF0000000000000); break;
				case 1036: trunced.significand = trunced.significand | (significand & 0xFFF7000000000000); break;
				case 1037: trunced.significand = trunced.significand | (significand & 0xFFFB000000000000); break;
				case 1038: trunced.significand = trunced.significand | (significand & 0xFFFE000000000000); break;
				case 1039: trunced.significand = trunced.significand | (significand & 0xFFFF000000000000); break;
				case 1040: trunced.significand = trunced.significand | (significand & 0xFFFF700000000000); break;
				case 1041: trunced.significand = trunced.significand | (significand & 0xFFFFB00000000000); break;
				case 1042: trunced.significand = trunced.significand | (significand & 0xFFFFE00000000000); break;
				case 1043: trunced.significand = trunced.significand | (significand & 0xFFFFF00000000000); break;
				case 1044: trunced.significand = trunced.significand | (significand & 0xFFFFF70000000000); break;
				case 1045: trunced.significand = trunced.significand | (significand & 0xFFFFFB0000000000); break;
				case 1046: trunced.significand = trunced.significand | (significand & 0xFFFFFE0000000000); break;
				case 1047: trunced.significand = trunced.significand | (significand & 0xFFFFFF0000000000); break;
				case 1048: trunced.significand = trunced.significand | (significand & 0xFFFFFF7000000000); break;
				case 1049: trunced.significand = trunced.significand | (significand & 0xFFFFFFB000000000); break;
				case 1050: trunced.significand = trunced.significand | (significand & 0xFFFFFFE000000000); break;
				case 1051: trunced.significand = trunced.significand | (significand & 0xFFFFFFF000000000); break;
				case 1052: trunced.significand = trunced.significand | (significand & 0xFFFFFFF700000000); break;
				case 1053: trunced.significand = trunced.significand | (significand & 0xFFFFFFFB00000000); break;
				case 1054: trunced.significand = trunced.significand | (significand & 0xFFFFFFFE00000000); break;
				case 1055: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF00000000); break;
				case 1056: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF70000000); break;
				case 1057: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFB0000000); break;
				case 1058: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFE0000000); break;
				case 1059: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF0000000); break;
				case 1060: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF7000000); break;
				case 1061: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFB000000); break;
				case 1062: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFE000000); break;
				case 1063: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF000000); break;
				case 1064: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF700000); break;
				case 1065: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFB00000); break;
				case 1066: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFE00000); break;
				case 1067: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF00000); break;
				case 1068: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF70000); break;
				case 1069: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFB0000); break;
				case 1070: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFE0000); break;
				case 1071: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF0000); break;
				case 1072: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF7000); break;
				case 1073: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFB000); break;
				case 1074: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFE000); break;
				case 1075: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFF000); break;
				default: trunced.significand = 0; break;
				}
			}

			double ret{ 0.0 };

			try
			{
				ret = trunced.Value<double>();
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
		MaxPrecision Ceiling<MaxPrecision>() const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.significand = significand & 0x0000000000000000; break;
				case 1024: trunced.significand = significand & 0x7000000000000000; break;
				case 1025: trunced.significand = significand & 0xB000000000000000; break;
				case 1026: trunced.significand = significand & 0xE000000000000000; break;
				case 1027: trunced.significand = significand & 0xF000000000000000; break;
				case 1028: trunced.significand = significand & 0xF700000000000000; break;
				case 1029: trunced.significand = significand & 0xFB00000000000000; break;
				case 1030: trunced.significand = significand & 0xFE00000000000000; break;
				case 1031: trunced.significand = significand & 0xFF00000000000000; break;
				case 1032: trunced.significand = significand & 0xFF70000000000000; break;
				case 1033: trunced.significand = significand & 0xFFB0000000000000; break;
				case 1034: trunced.significand = significand & 0xFFE0000000000000; break;
				case 1035: trunced.significand = significand & 0xFFF0000000000000; break;
				case 1036: trunced.significand = significand & 0xFFF7000000000000; break;
				case 1037: trunced.significand = significand & 0xFFFB000000000000; break;
				case 1038: trunced.significand = significand & 0xFFFE000000000000; break;
				case 1039: trunced.significand = significand & 0xFFFF000000000000; break;
				case 1040: trunced.significand = significand & 0xFFFF700000000000; break;
				case 1041: trunced.significand = significand & 0xFFFFB00000000000; break;
				case 1042: trunced.significand = significand & 0xFFFFE00000000000; break;
				case 1043: trunced.significand = significand & 0xFFFFF00000000000; break;
				case 1044: trunced.significand = significand & 0xFFFFF70000000000; break;
				case 1045: trunced.significand = significand & 0xFFFFFB0000000000; break;
				case 1046: trunced.significand = significand & 0xFFFFFE0000000000; break;
				case 1047: trunced.significand = significand & 0xFFFFFF0000000000; break;
				case 1048: trunced.significand = significand & 0xFFFFFF7000000000; break;
				case 1049: trunced.significand = significand & 0xFFFFFFB000000000; break;
				case 1050: trunced.significand = significand & 0xFFFFFFE000000000; break;
				case 1051: trunced.significand = significand & 0xFFFFFFF000000000; break;
				case 1052: trunced.significand = significand & 0xFFFFFFF700000000; break;
				case 1053: trunced.significand = significand & 0xFFFFFFFB00000000; break;
				case 1054: trunced.significand = significand & 0xFFFFFFFE00000000; break;
				case 1055: trunced.significand = significand & 0xFFFFFFFF00000000; break;
				case 1056: trunced.significand = significand & 0xFFFFFFFF70000000; break;
				case 1057: trunced.significand = significand & 0xFFFFFFFFB0000000; break;
				case 1058: trunced.significand = significand & 0xFFFFFFFFE0000000; break;
				case 1059: trunced.significand = significand & 0xFFFFFFFFF0000000; break;
				case 1060: trunced.significand = significand & 0xFFFFFFFFF7000000; break;
				case 1061: trunced.significand = significand & 0xFFFFFFFFFB000000; break;
				case 1062: trunced.significand = significand & 0xFFFFFFFFFE000000; break;
				case 1063: trunced.significand = significand & 0xFFFFFFFFFF000000; break;
				case 1064: trunced.significand = significand & 0xFFFFFFFFFF700000; break;
				case 1065: trunced.significand = significand & 0xFFFFFFFFFFB00000; break;
				case 1066: trunced.significand = significand & 0xFFFFFFFFFFE00000; break;
				case 1067: trunced.significand = significand & 0xFFFFFFFFFFF00000; break;
				case 1068: trunced.significand = significand & 0xFFFFFFFFFFF70000; break;
				case 1069: trunced.significand = significand & 0xFFFFFFFFFFFB0000; break;
				case 1070: trunced.significand = significand & 0xFFFFFFFFFFFE0000; break;
				case 1071: trunced.significand = significand & 0xFFFFFFFFFFFF0000; break;
				case 1072: trunced.significand = significand & 0xFFFFFFFFFFFF7000; break;
				case 1073: trunced.significand = significand & 0xFFFFFFFFFFFFB000; break;
				case 1074: trunced.significand = significand & 0xFFFFFFFFFFFFE000; break;
				case 1075: trunced.significand = significand & 0xFFFFFFFFFFFFF000; break;
				default: trunced.significand = 0; break;
				}

				trunced.significand = trunced.significand >> ;


			}



			return trunced;
		}
		template<>
		float Floor<float>() const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 127ui16)
			{
				switch (trunced.exponent)
				{
				case 127: trunced.significand = significand & 0x0000000000000000; break;
				case 128: trunced.significand = significand & 0x7000000000000000; break;
				case 129: trunced.significand = significand & 0xB000000000000000; break;
				case 130: trunced.significand = significand & 0xE000000000000000; break;
				case 131: trunced.significand = significand & 0xF000000000000000; break;
				case 132: trunced.significand = significand & 0xF700000000000000; break;
				case 133: trunced.significand = significand & 0xFB00000000000000; break;
				case 134: trunced.significand = significand & 0xFE00000000000000; break;
				case 135: trunced.significand = significand & 0xFF00000000000000; break;
				case 136: trunced.significand = significand & 0xFF70000000000000; break;
				case 137: trunced.significand = significand & 0xFFB0000000000000; break;
				case 138: trunced.significand = significand & 0xFFE0000000000000; break;
				case 139: trunced.significand = significand & 0xFFF0000000000000; break;
				case 140: trunced.significand = significand & 0xFFF7000000000000; break;
				case 141: trunced.significand = significand & 0xFFFB000000000000; break;
				case 142: trunced.significand = significand & 0xFFFE000000000000; break;
				case 143: trunced.significand = significand & 0xFFFF000000000000; break;
				case 144: trunced.significand = significand & 0xFFFF700000000000; break;
				case 145: trunced.significand = significand & 0xFFFFB00000000000; break;
				case 146: trunced.significand = significand & 0xFFFFE00000000000; break;
				case 147: trunced.significand = significand & 0xFFFFF00000000000; break;
				case 148: trunced.significand = significand & 0xFFFFF70000000000; break;
				case 149: trunced.significand = significand & 0xFFFFFB0000000000; break;
				case 150: trunced.significand = significand & 0xFFFFFE0000000000; break;
				default: trunced.significand = 0; break;
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
		template<>
		double Trunc<double>(size_t sigBits) const
		{
			MaxPrecision trunced = *this;

			if (trunced.exponent > 1023ui16)
			{
				switch (trunced.exponent)
				{
				case 1023: trunced.significand = trunced.significand | (significand & 0x0000000000000000); break;
				case 1024: trunced.significand = trunced.significand | (significand & 0x7000000000000000); break;
				case 1025: trunced.significand = trunced.significand | (significand & 0xB000000000000000); break;
				case 1026: trunced.significand = trunced.significand | (significand & 0xE000000000000000); break;
				case 1027: trunced.significand = trunced.significand | (significand & 0xF000000000000000); break;
				case 1028: trunced.significand = trunced.significand | (significand & 0xF700000000000000); break;
				case 1029: trunced.significand = trunced.significand | (significand & 0xFB00000000000000); break;
				case 1030: trunced.significand = trunced.significand | (significand & 0xFE00000000000000); break;
				case 1031: trunced.significand = trunced.significand | (significand & 0xFF00000000000000); break;
				case 1032: trunced.significand = trunced.significand | (significand & 0xFF70000000000000); break;
				case 1033: trunced.significand = trunced.significand | (significand & 0xFFB0000000000000); break;
				case 1034: trunced.significand = trunced.significand | (significand & 0xFFE0000000000000); break;
				case 1035: trunced.significand = trunced.significand | (significand & 0xFFF0000000000000); break;
				case 1036: trunced.significand = trunced.significand | (significand & 0xFFF7000000000000); break;
				case 1037: trunced.significand = trunced.significand | (significand & 0xFFFB000000000000); break;
				case 1038: trunced.significand = trunced.significand | (significand & 0xFFFE000000000000); break;
				case 1039: trunced.significand = trunced.significand | (significand & 0xFFFF000000000000); break;
				case 1040: trunced.significand = trunced.significand | (significand & 0xFFFF700000000000); break;
				case 1041: trunced.significand = trunced.significand | (significand & 0xFFFFB00000000000); break;
				case 1042: trunced.significand = trunced.significand | (significand & 0xFFFFE00000000000); break;
				case 1043: trunced.significand = trunced.significand | (significand & 0xFFFFF00000000000); break;
				case 1044: trunced.significand = trunced.significand | (significand & 0xFFFFF70000000000); break;
				case 1045: trunced.significand = trunced.significand | (significand & 0xFFFFFB0000000000); break;
				case 1046: trunced.significand = trunced.significand | (significand & 0xFFFFFE0000000000); break;
				case 1047: trunced.significand = trunced.significand | (significand & 0xFFFFFF0000000000); break;
				case 1048: trunced.significand = trunced.significand | (significand & 0xFFFFFF7000000000); break;
				case 1049: trunced.significand = trunced.significand | (significand & 0xFFFFFFB000000000); break;
				case 1050: trunced.significand = trunced.significand | (significand & 0xFFFFFFE000000000); break;
				case 1051: trunced.significand = trunced.significand | (significand & 0xFFFFFFF000000000); break;
				case 1052: trunced.significand = trunced.significand | (significand & 0xFFFFFFF700000000); break;
				case 1053: trunced.significand = trunced.significand | (significand & 0xFFFFFFFB00000000); break;
				case 1054: trunced.significand = trunced.significand | (significand & 0xFFFFFFFE00000000); break;
				case 1055: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF00000000); break;
				case 1056: trunced.significand = trunced.significand | (significand & 0xFFFFFFFF70000000); break;
				case 1057: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFB0000000); break;
				case 1058: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFE0000000); break;
				case 1059: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF0000000); break;
				case 1060: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFF7000000); break;
				case 1061: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFB000000); break;
				case 1062: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFE000000); break;
				case 1063: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF000000); break;
				case 1064: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFF700000); break;
				case 1065: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFB00000); break;
				case 1066: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFE00000); break;
				case 1067: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF00000); break;
				case 1068: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFF70000); break;
				case 1069: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFB0000); break;
				case 1070: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFE0000); break;
				case 1071: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF0000); break;
				case 1072: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFF7000); break;
				case 1073: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFB000); break;
				case 1074: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFE000); break;
				case 1075: trunced.significand = trunced.significand | (significand & 0xFFFFFFFFFFFFF000); break;
				default: trunced.significand = 0; break;
				}
			}

			double ret{ 0.0 };

			try
			{
				ret = trunced.Value<double>();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return ret;
		}

	private:
		bool sign{ false };

		uint64_t significand{ 0 };

		uint16_t exponent{ 0 };

	};

}