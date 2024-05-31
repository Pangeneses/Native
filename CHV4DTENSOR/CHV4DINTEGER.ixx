module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBYTE;

export namespace CHV4DTENSOR
{
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() { data = 0; }

		CHV4DINTEGER(CHV4DINTEGER const& x) { data = x.data; }

		CHV4DINTEGER(int8_t  const& x) { data = x; }
		CHV4DINTEGER(int16_t const& x) { data = x; }
		CHV4DINTEGER(int32_t const& x) { data = x; }
		CHV4DINTEGER(int64_t const& x) { data = x; }

	public:
		void operator=(CHV4DINTEGER const& x) { data = x.data; }

		void operator=(int8_t  const& x) { data = x; }
		void operator=(int16_t const& x) { data = x; }
		void operator=(int32_t const& x) { data = x; }
		void operator=(int64_t const& x) { data = x; }

		template<typename T> T operator()() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<> int8_t operator() < int8_t > () const
		{
			if (data >= -127i8 && data <= 127i8) return data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int16_t operator() < int16_t > () const
		{
			if (data >= -32767i16 && data <= 32767i16) return data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int32_t operator() < int32_t > () const
		{
			if (data >= -2147483647i32 && data <= 2147483647i32) return data;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int64_t operator() < int64_t > () const
		{
			return data;
		}
		template<> CHV4DINTEGER operator() < CHV4DINTEGER > () const
		{
			return *this;
		}

		CHV4DINTEGER operator++()
		{
			if (data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			data = data + 1;

			return data;
		}
		template<typename T>
		T operator++()
		{
			assert_integer < T > ();

			if (data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			A.data = A.data + 1;

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
			if (data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = data;

			data = data + 1;

			return Q;
		}
		template<typename T>
		T operator++(int)
		{
			assert_integer < T > ();

			if (data >= 9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

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

			A.data = A.data + 1;

			return ret;
		}

		CHV4DINTEGER operator--()
		{
			if (data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			data = data - 1;

			return data;
		}
		template<typename T>
		T operator--()
		{
			assert_integer < T > ();

			if (data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			A.data = A.data - 1;

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
			if (data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = data;

			data = data - 1;

			return Q;
		}
		template<typename T>
		T operator--(int)
		{
			assert_integer < T > ();

			if (data >= -9223372036854775808i64) throw std::overflow_error{ "Integer overflow" };

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

			A.data = A.data - 1;

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

			return static_cast < T > (data);
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

			return static_cast < T > (-1 * data);
		}

		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (A.data > 9223372036854775808i64 - B.data) throw std::overflow_error{ "Integer overrun." };

			A.data = A.data + B.data;

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

			B.data = -1 * B.data;

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

			float Q = static_cast < float > (A.data) / static_cast < float > (B.data);

			return Q;
		}
		template<> double operator/ < double > (CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			float Q = static_cast < double > (A.data) / static_cast < double > (B.data);

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

			double reciprocal = MAX_INT.operator/ < double, uint64_t > (B.data);

			if (A.data <= reciprocal && A.data >= reciprocal) throw std::overflow_error{ "Integer overrun." };

			A.data = A.data * B.data;

			return A;

		}
		template<typename T, typename I>
		T operator*(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			CHV4DINTEGER MAX_INT{ 9223372036854775808i64 };

			double reciprocal = MAX_INT.operator/ < double, uint64_t > (B.data);

			if (A.data <= reciprocal && A.data >= reciprocal) throw std::overflow_error{ "Integer overrun." };

			A.data = A.data * B.data;

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

			if (A.data == 0) return A;

			A.data = A.data < 0 ? -1 * A.data : A.data;
			B.data = B.data < 0 ? -1 * B.data : B.data;

			for (size_t i = 0; i < 64; ++i)
			{
				if (A.data - B.data >= 0)
				{
					A.data = A.data - B.data;

					Q |= 0x0000000000000001;
				}

				A.data << 1;

				Q = Q << 1;
			}

			A.data = A.data - (Q * B.data);

			return A;

		}
		template<typename T, typename I>
		T operator%(I const& x) const
		{
			assert_integer < T > ();
			assert_integer < I > ();

			CHV4DINTEGER A{ *this }, B{ x };

			uint64_t Q{ 0 };

			if (A.data == 0) return static_cast < T > (0);

			A.data = A.data < 0 ? -1 * A.data : A.data;
			B.data = B.data < 0 ? -1 * B.data : B.data;

			for (size_t i = 0; i < 64; ++i)
			{
				if (A.data - B.data >= 0)
				{
					A.data = A.data - B.data;

					Q |= 0x0000000000000001;
				}

				A.data << 1;

				Q = Q << 1;
			}

			A.data = A.data - (Q * B.data);

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
			return { ToByte(~data) };
		}
		CHV4DBYTE<8> operator&(CHV4DBYTE<8> const x) const
		{
			return { ToByte(data & x.data) };
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
			return data == x.data;
		}
		bool operator!=(CHV4DINTEGER const& x) const
		{
			return data != x.data;
		}
		bool operator<(CHV4DINTEGER const& x) const
		{
			return data < x.data;
		}
		bool operator>(CHV4DINTEGER const& x) const
		{
			return data > x.data;
		}
		bool operator<=(CHV4DINTEGER const& x) const
		{
			return data <= x.data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return data >= x.data;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			return data <=> x.data;
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

			if (pow.data == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.data != 0 && data == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.data; i++)
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

			if (pow.data == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.data != 0 && data == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.data; i++)
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

	private:
		int64_t data{ 0 };

	};

}