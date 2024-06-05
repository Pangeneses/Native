module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBYTESTREAM;

export namespace CHV4DTENSOR
{
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() { Data = 0; }
		/*
		CHV4DINTEGER(CHV4DINTEGER const& x) { Data = x.Data; }

		CHV4DINTEGER(int8_t  const& x) { Data = x; }
		CHV4DINTEGER(int16_t const& x) { Data = x; }
		CHV4DINTEGER(int32_t const& x) { Data = x; }
		CHV4DINTEGER(int64_t const& x) { Data = x; }

	public:
		void operator=(CHV4DINTEGER const& x) { Data = x.Data; }

		void operator=(int8_t  const& x) { Data = x; }
		void operator=(int16_t const& x) { Data = x; }
		void operator=(int32_t const& x) { Data = x; }
		void operator=(int64_t const& x) { Data = x; }

		template<typename T> T operator()() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<> int8_t operator() < int8_t > () const
		{
			if (Data >= -127i8 && Data <= 127i8) return Data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int16_t operator() < int16_t > () const
		{
			if (Data >= -32767i16 && Data <= 32767i16) return Data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int32_t operator() < int32_t > () const
		{
			if (Data >= -2147483647i32 && Data <= 2147483647i32) return Data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int64_t operator() < int64_t > () const
		{
			return Data;
		}
		template<> CHV4DINTEGER operator() < CHV4DINTEGER > () const
		{
			return *this;
		}

		CHV4DINTEGER operator++()
		{
			if (Data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data + 1;

			return Data;
		}
		template<typename T>
		T operator++()
		{
			assert_integer < T > ();

			if (Data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			A.Data = A.Data + 1;

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}
		CHV4DINTEGER operator++()
		{
			if (Data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = Data;

			Data = Data + 1;

			return Q;
		}
		template<typename T>
		T operator++(int)
		{
			assert_integer < T > ();

			if (Data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			A.Data = A.Data + 1;

			return ret;
		}

		CHV4DINTEGER operator--()
		{
			if (Data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data - 1;

			return Data;
		}
		template<typename T>
		T operator--()
		{
			assert_integer < T > ();

			if (Data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			A.Data = A.Data - 1;

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}
		CHV4DINTEGER operator++()
		{
			if (Data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = Data;

			Data = Data - 1;

			return Q;
		}
		template<typename T>
		T operator--(int)
		{
			assert_integer < T > ();

			if (Data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			A.Data = A.Data - 1;

			return ret;
		}

		CHV4DINTEGER operator+()
		{
			return *this;
		}
		template<typename T>
		T operator+()
		{
			assert_integer < T > ();

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return static_cast < T > (Data);
		}
		CHV4DINTEGER operator-()
		{
			return CHV4DINTEGER{ -1 } * *this;
		}
		template<typename T>
		T operator-()
		{
			assert_integer < T > ();

			T ret;

			try
			{
				ret = this->operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return static_cast < T > (-1 * Data);
		}

		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (A.Data > 9223372036854775808i64 - B.Data) throw std::overflow_error{ "Integer overrun." };

			A.Data = A.Data + B.Data;

			return A;
		}
		template<typename T, typename I>
		T operator+(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A + B;
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			T ret;

			try
			{
				ret = z.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}

		CHV4DINTEGER operator-(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			B.Data = -1 * B.Data;

			try
			{
				A = this->operator+(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return A;
		}
		template<typename T, typename I> T operator-(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A - B;
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			T ret;

			try
			{
				ret = z.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}

		template<typename T> T operator/(CHV4DINTEGER const& x) const
		{
			static_assert(false, "Non Integer type.");
		}
		template<> float operator/ < float > (CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			float Q = static_cast < float > (A.Data) / static_cast < float > (B.Data);

			return Q;
		}
		template<> double operator/ < double > (CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			float Q = static_cast < double > (A.Data) / static_cast < double > (B.Data);

			return Q;
		}
		template<typename T, typename I> T operator/(I const& x) const
		{
			assert_float < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			T Q;

			try
			{
				Q = A.operator/(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return Q;

		}

		CHV4DINTEGER operator*(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			CHV4DINTEGER MAX_INT{ 9223372036854775808i64 };

			double reciprocal = MAX_INT.operator/ < double, uint64_t > (B.Data);

			if (A.Data <= reciprocal && A.Data >= reciprocal) throw std::overflow_error{ "Integer overrun." };

			A.Data = A.Data * B.Data;

			return A;

		}
		template<typename T, typename I>
		T operator*(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			CHV4DINTEGER MAX_INT{ 9223372036854775808i64 };

			double reciprocal = MAX_INT.operator/ < double, uint64_t > (B.Data);

			if (A.Data <= reciprocal && A.Data >= reciprocal) throw std::overflow_error{ "Integer overrun." };

			A.Data = A.Data * B.Data;

			T ret;

			try
			{
				ret = A.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;

		}

		CHV4DINTEGER operator%(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			uint64_t Q{ 0 };

			if (A.Data == 0) return A;

			A.Data = A.Data < 0 ? -1 * A.Data : A.Data;
			B.Data = B.Data < 0 ? -1 * B.Data : B.Data;

			for (size_t i = 0; i < 64; ++i)
			{
				if (A.Data - B.Data >= 0)
				{
					A.Data = A.Data - B.Data;

					Q |= 0x0000000000000001;
				}

				A.Data << 1;

				Q = Q << 1;
			}

			A.Data = A.Data - (Q * B.Data);

			return A;

		}
		template<typename T, typename I>
		T operator%(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			uint64_t Q{ 0 };

			if (A.Data == 0) return static_cast < T > (0);

			A.Data = A.Data < 0 ? -1 * A.Data : A.Data;
			B.Data = B.Data < 0 ? -1 * B.Data : B.Data;

			for (size_t i = 0; i < 64; ++i)
			{
				if (A.Data - B.Data >= 0)
				{
					A.Data = A.Data - B.Data;

					Q |= 0x0000000000000001;
				}

				A.Data << 1;

				Q = Q << 1;
			}

			A.Data = A.Data - (Q * B.Data);

			T ret;

			try
			{
				ret = A.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;

		}




		CHV4DBYTE<8> operator~() const
		{
			return { ToByte(~Data) };
		}
		CHV4DBYTE<8> operator&(CHV4DBYTE<8> const x) const
		{
			return { ToByte(Data & x.Data) };
		}
		CHV4DBYTE<8> operator|(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator^(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator>>(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DBYTE<8> operator<<(CHV4DBYTE<8> const x) const
		{

		}
		CHV4DINTEGER operator!() const
		{

		}
		bool operator&&(CHV4DINTEGER const& x) const
		{

		}
		bool operator||(CHV4DINTEGER const& x) const
		{

		}

		bool operator==(CHV4DINTEGER const& x) const
		{
			return Data == x.Data;
		}
		bool operator!=(CHV4DINTEGER const& x) const
		{
			return Data != x.Data;
		}
		bool operator<(CHV4DINTEGER const& x) const
		{
			return Data < x.Data;
		}
		bool operator>(CHV4DINTEGER const& x) const
		{
			return Data > x.Data;
		}
		bool operator<=(CHV4DINTEGER const& x) const
		{
			return Data <= x.Data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return Data >= x.Data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return Data <=> x.Data;
		}






		void operator+=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator+(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator-=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator-(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator*=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator*(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator/=(CHV4DINTEGER const& x)
		{

		}

		void operator%=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator%(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			*this = A;
		}

		void operator&=(CHV4DINTEGER const& x)
		{

		}

		void operator|=(CHV4DINTEGER const& x)
		{

		}

		void operator^=(CHV4DINTEGER const& x)
		{

		}
		void operator>>=(CHV4DINTEGER const& x)
		{

		}

		void operator<<=(CHV4DINTEGER const& x)
		{

		}

	public:
		CHV4DINTEGER Pow(CHV4DINTEGER pow)
		{
			if (pow.sign) throw std::runtime_error{ "Unsigned powers." };

			if (pow.Data == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.Data != 0 && Data == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.Data; i++)
			{
				try
				{
					z = z.operator*< CHV4DINTEGER >(*this);
				}
				catch (std::overflow_error error)
				{
					throw error;
				}
				catch (std::runtime_error error)
				{
					throw error;
				}
			}

			return z;

		}
		template<typename T, typename I>
		T Pow(I x)
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER pow{ x };

			CHV4DINTEGER res;

			try
			{
				res = this->Pow(pow);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			T ret;

			try
			{
				ret = res.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}

		CHV4DINTEGER Root(CHV4DINTEGER pow)
		{
			if (pow.sign) throw std::runtime_error{ "Unsigned powers." };

			if (pow.Data == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.Data != 0 && Data == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.Data; i++)
			{
				try
				{
					z = z.operator*< CHV4DINTEGER >(*this);
				}
				catch (std::overflow_error error)
				{
					throw error;
				}
				catch (std::runtime_error error)
				{
					throw error;
				}
			}

			return z;

		}
		template<typename T, typename I>
		T Root(I x)
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER pow{ x };

			CHV4DINTEGER res;

			try
			{
				res = this->Root(pow);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			T ret;

			try
			{
				ret = res.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return ret;
		}

		void ToFrac(float const& p, CHV4DINTEGER& a, CHV4DINTEGER& b)
		{
			float pow{ p };

			if (pow < 0.0f) throw std::out_of_range{ "Invert x to remove negative power." };

			if (pow >= 1.0f)
			{
				a = 1;

				b = 1;

			}
			else if (pow > 1.0f)
			{
				size_t mag;

				for (mag = 1; (pow / 2.0f) > 1.0; mag++)
				{
					pow = pow / 2.0f;

				}

				float scan;

				for (scan = 0.0f; scan < 2147483648.0f; scan += 80000.0f)
				{
					float frac = (2147483648.0f + scan) / (2147483648.0f - scan);

					float floor = fTrunc(frac, 1000000.0f);

					float roof = fTrunc(frac, 1000000.0f) + 0.0001f;

					if (floor < pow && pow < roof) break;

				}

				a = (2147483648 + static_cast<uint64_t>(scan));

				b = 2147483648 - static_cast<uint64_t>(scan);

				for (size_t i = 0; i < mag; i++)
				{
					a *= FloatToUint32(fIPow(2, i));

					if (i > 2)
					{
						if ((i - 1) % 2 == 0)
						{
							b /= DoubleToUint64(cIPow(2, i));

						}

					}

				}

			}
			else if (pow < 1.0f && pow > 0.0f)
			{
			}
			else if (pow == 0.0f)
			{
			}
			else if (pow < 0.0f)
			{
			}

		} // 1.xxxxx shift to integer reduce
		void ToFrac(double const& p, CHV4DINTEGER& a, CHV4DINTEGER& b)
		{
			float pow{ p };

			if (pow < 0.0f) throw std::out_of_range{ "Invert x to remove negative power." };

			if (pow >= 1.0f)
			{
				a = 1;

				b = 1;

			}
			else if (pow > 1.0f)
			{
				size_t mag;

				for (mag = 1; (pow / 2.0f) > 1.0; mag++)
				{
					pow = pow / 2.0f;

				}

				float scan;

				for (scan = 0.0f; scan < 2147483648.0f; scan += 80000.0f)
				{
					float frac = (2147483648.0f + scan) / (2147483648.0f - scan);

					float floor = fTrunc(frac, 1000000.0f);

					float roof = fTrunc(frac, 1000000.0f) + 0.0001f;

					if (floor < pow && pow < roof) break;

				}

				a = (2147483648 + static_cast<uint64_t>(scan));

				b = 2147483648 - static_cast<uint64_t>(scan);

				for (size_t i = 0; i < mag; i++)
				{
					a *= FloatToUint32(fIPow(2, i));

					if (i > 2)
					{
						if ((i - 1) % 2 == 0)
						{
							b /= DoubleToUint64(cIPow(2, i));

						}

					}

				}

			}
			else if (pow < 1.0f && pow > 0.0f)
			{
			}
			else if (pow == 0.0f)
			{
			}
			else if (pow < 0.0f)
			{
			}

		}
		*/
	private:
		int64_t Data{ 0 };

	};

}