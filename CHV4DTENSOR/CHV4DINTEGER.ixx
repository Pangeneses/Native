module;

#include <type_traits>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	/*
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() { Data = 0; }

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

		int64_t operator()() const { return Data; }

		template<typename T> T operator()() const
		{
			static_assert(
				std::is_same<T, int8_t>::value ||
				std::is_same<T, int16_t>::value ||
				std::is_same<T, int32_t>::value ||
				std::is_same<T, int64_t>::value,
				"Non Integer type.");
		}
		template<> int8_t operator() < int8_t > () const
		{
			if (Data >= -127i8 && Data <= 127i8) return static_cast <int8_t> (Data);

			else throw std::overflow_error{ "Integer overflow." };
		}
		template<> int16_t operator() < int16_t > () const
		{
			if (Data >= -32767i16 && Data <= 32767i16) return static_cast <int16_t> (Data);

			else throw std::overflow_error{ "Integer overflow." };
		}
		template<> int32_t operator() < int32_t > () const
		{
			if (Data >= -2147483647i32 && Data <= 2147483647i32) return static_cast < int32_t > (Data);

			else throw std::overflow_error{ "Integer overflow." };
		}
		template<> int64_t operator() < int64_t > () const
		{
			return Data;
		}
		template<> CHV4DINTEGER operator() < CHV4DINTEGER > () const
		{
			return *this;
		}

		unsigned char& operator[](size_t const& i)
		{
			if (i > 15) throw std::runtime_error{ "Index out of range." };

			return reinterpret_cast<unsigned char*>(Data)[15 - i];
		}

		CHV4DINTEGER operator++()
		{
			if (Data >= 9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data + 1;

			return Data;
		}
		template<typename T>
		T operator++()
		{
			assert_integer < T >();

			if (Data >= 9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data + 1;

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
		CHV4DINTEGER operator++(int)
		{
			if (Data >= 9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = Data;

			Data = Data + 1;

			return Q;
		}
		template<typename T>
		T operator++(int)
		{
			assert_integer < T >();

			if (Data >= 9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

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

			Data = Data + 1;

			return ret;
		}

		CHV4DINTEGER operator--()
		{
			if (Data >= -9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data - 1;

			return Data;
		}
		template<typename T>
		T operator--()
		{
			assert_integer < T >();

			if (Data >= -9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			Data = Data - 1;

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
		CHV4DINTEGER operator--(int)
		{
			if (Data >= -9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

			int64_t Q = Data;

			Data = Data - 1;

			return Q;
		}
		template<typename T>
		T operator--(int)
		{
			assert_integer < T >();

			if (Data >= -9223372036854775807i64) throw std::overflow_error{ "Integer overflow" };

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

			Data = Data - 1;

			return ret;
		}

		CHV4DINTEGER operator+()
		{
			return *this;
		}
		template<typename T>
		T operator+()
		{
			assert_integer < T >();

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

			return static_cast <T> (Data);
		}
		CHV4DINTEGER operator-()
		{
			return CHV4DINTEGER{ -1 } **this;
		}
		template<typename T>
		T operator-()
		{
			assert_integer < T >();

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

			return static_cast <T> (-1 * Data);
		}

		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (A.Data < 0 && B.Data < 0)
			{
				if (A.Data < -9223372036854775808i64 - B.Data) throw std::overflow_error{ "Integer overflow." };
			}
			else if (A.Data >= 0 && B.Data >= 0)
			{
				if (A.Data > 9223372036854775808i64 - B.Data) throw std::overflow_error{ "Integer overflow." };
			}

			A.Data = A.Data + B.Data;

			return A;
		}
		template<typename T, typename I>
		T operator+(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

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
			assert_integer < T >();
			assert_integer < I >();

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

		template<typename T> T operator/(CHV4DINTEGER const& x) const
		{
			static_assert(
				
				
				"Non Integer type.");
		}
		template<> float operator/ < float > (CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (B.Data == 0) throw std::runtime_error{ "Division by zero." };

			if (A.Data == 0) return 0.0f;

			return static_cast <float> (A.Data) / static_cast <float> (B.Data);
		}
		template<> double operator/ < double > (CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if (B.Data == 0) throw std::runtime_error{ "Division by zero." };

			if (A.Data == 0) return 0.0;

			return static_cast <double> (A.Data) / static_cast <double> (B.Data);
		}
		template<typename T, typename I> T operator/(I const& x) const
		{
			assert_float < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			T Q;

			try
			{
				Q = A.operator/(B);
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

			double reciprocal{ 0 };

			try
			{
				reciprocal = MAX_INT.operator/ < double, uint64_t > (B.Data);
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			if (reciprocal >= 0)
			{
				if (A.Data > reciprocal) throw std::overflow_error{ "Integer overrun." };
			}
			else if (reciprocal < 0)
			{
				if (A.Data < reciprocal) throw std::overflow_error{ "Integer overrun." };
			}

			A.Data = A.Data * B.Data;

			return A;
		}
		template<typename T, typename I>
		T operator*(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator* < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			uint64_t Q{ 0 };

			if (A.Data == 0) return static_cast <T> (0);

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

		CHV4DINTEGER operator~() const
		{
			return ~Data;
		}
		template<typename T>
		T operator~() const
		{
			assert_integer < T >();

			T ret;

			try
			{
				ret = Data.operator() < T > ();
			}
			catch (std::overflow_error error)
			{
				throw error;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}

			return static_cast<T>(~ret);
		}

		CHV4DINTEGER operator&(CHV4DINTEGER const& x) const
		{
			return Data & x.Data;
		}
		template<typename T, typename I>
		T operator&(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator& < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		CHV4DINTEGER operator|(CHV4DINTEGER const x) const
		{
			return Data | x.Data;
		}
		template<typename T, typename I>
		T operator|(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator| < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		CHV4DINTEGER operator^(CHV4DINTEGER const x) const
		{
			return Data ^ x.Data;
		}
		template<typename T, typename I>
		T operator^(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator^ < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		CHV4DINTEGER operator>>(CHV4DINTEGER const x) const
		{
			return Data >> x.Data;
		}
		template<typename T, typename I>
		T operator>>(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator>> < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		CHV4DINTEGER operator<<(CHV4DINTEGER const x) const
		{
			return Data << x.Data;
		}
		template<typename T, typename I>
		T operator<<(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator<< < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		bool operator!() const
		{
			return !Data;
		}
		bool operator&&(CHV4DINTEGER const& x) const
		{
			return Data && x.Data;
		}
		bool operator||(CHV4DINTEGER const& x) const
		{
			return Data || x.Data;
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
		auto operator<=>(CHV4DINTEGER const& x) const
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
		template<typename T, typename I>
		T operator+=(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator+= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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
		template<typename T, typename I>
		T operator-=(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator-= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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
		template<typename T, typename I>
		T operator*=(I const& x) const
		{
			assert_integer < T >();
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator*= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

	private:
		void operator/=(CHV4DINTEGER const& x) {}

	public:
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
		template<typename I>
		void operator%=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A.operator%= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		void operator&=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator&(B);
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
		template<typename I>
		void operator&=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A.operator&= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		void operator|=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator|(B);
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
		template<typename I>
		void operator|=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A.operator|= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		void operator^=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator^(B);
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
		template<typename I>
		void operator^=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A.operator^= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		void operator>>=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator>>(B);
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
		template<typename I>
		void operator>>=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operaton >>= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

		void operator<<=(CHV4DINTEGER const& x)
		{
			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A = A.operator<<(B);
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
		template<typename I>
		void operator<<=(I const& x) const
		{
			assert_integer < I >();

			CHV4DINTEGER A{ *this }, B{ x };

			try
			{
				A.operator<<= < T > (B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

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

	private:
		int64_t Data{ 0 };

	};
	*/
}