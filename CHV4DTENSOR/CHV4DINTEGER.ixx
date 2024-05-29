module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	class CHV4DINTEGER
	{
	public:
		CHV4DINTEGER() { sign = false; val = 0; }

		CHV4DINTEGER(CHV4DINTEGER const& x) { sign = x.sign; val = x.val; }

		CHV4DINTEGER(uint8_t  const& x) { sign = false; val = x; }
		CHV4DINTEGER(uint16_t const& x) { sign = false; val = x; }
		CHV4DINTEGER(uint32_t const& x) { sign = false; val = x; }
		CHV4DINTEGER(uint64_t const& x) { sign = false; val = x; }

		CHV4DINTEGER(int8_t  const& x) { x < 0 ? sign = true : sign = false; val = x; }
		CHV4DINTEGER(int16_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		CHV4DINTEGER(int32_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		CHV4DINTEGER(int64_t const& x) { x < 0 ? sign = true : sign = false; val = x; }

	public:
		void operator=(CHV4DINTEGER const& x) { sign = x.sign; val = x.val; }

		void operator=(uint8_t  const& x) { sign = false; val = x; }
		void operator=(uint16_t const& x) { sign = false; val = x; }
		void operator=(uint32_t const& x) { sign = false; val = x; }
		void operator=(uint64_t const& x) { sign = false; val = x; }

		void operator=(int8_t  const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int16_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int32_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int64_t const& x) { x < 0 ? sign = true : sign = false; val = x; }

		template<typename T> T operator()() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<> uint8_t operator() < uint8_t > () const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 255) return static_cast<uint8_t>(val);

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint16_t operator() < uint16_t > () const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 65535) return static_cast<uint16_t>(val);

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint32_t operator() < uint32_t > () const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 4294967295) return static_cast<uint32_t>(val);

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint64_t operator() < uint64_t > () const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 18446744073709551615) return static_cast<uint64_t>(val);

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int8_t operator() < int8_t > () const
		{
			if (!sign)
			{
				if (val <= 127) return static_cast<int8_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 127) return -static_cast<int8_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int16_t operator() < int16_t > () const
		{
			if (!sign)
			{
				if (val <= 32767) return static_cast<int16_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 32767) return -static_cast<int16_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int32_t operator() < int32_t > () const
		{
			if (!sign)
			{
				if (val <= 2147483647) return static_cast<int32_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 2147483647) return -static_cast<int32_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int64_t operator() < int64_t > () const
		{
			if (!sign)
			{
				if (val <= 9223372036854775807) return static_cast<int64_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 9223372036854775807) return -static_cast<int64_t>(val);

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> CHV4DINTEGER operator() < CHV4DINTEGER > () const
		{
			return *this;
		}

		CHV4DINTEGER operator+(CHV4DINTEGER const& x) const
		{
			CHV4DINTEGER A{ *this }, B{ x };

			if(!A.sign != !B.sign) 
			{
				if (A.sign) std::swap(A.val, B.val);

				if(A.val > 9223372036854775808ui64) throw std::overflow_error{ "Signing Integer overrun." };

				if ((A.val + 9223372036854775808i64) < B.val) throw std::overflow_error{ "Integer overrun." };

				A.sign = A.val > B.val ? false : true;

				A.val = A.val > B.val ? A.val - B.val : B.val - A.val;
			}
			else
			{
				if (A.val <= (18446744073709551615 - B.val)) throw std::overflow_error{ "Integer overrun." };

				A.val = A.val + B.val;
			}
		}
		template<typename T, typename I>
		T operator+(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			try
			{
				z = *this + z;
			}
			catch (std::overflow_error error)
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
			CHV4DINTEGER A{ 0ui64 }, B{ x };

			B.sign = B.sign ? false : true;

			try
			{
				A = this->operator+(B);
			}
			catch (std::overflow_error error)
			{
				throw error;
			}

			return A;
		}
		template<typename T, typename I> T operator-(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			try
			{
				z = *this - z;
			}
			catch (std::overflow_error error)
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

		template<typename T> T operator/(CHV4DINTEGER const& x)
		{
			static_assert(false, "Non Integer type.");
		}
		template<> float operator/ < float > (CHV4DINTEGER const& x)
		{
			float z = static_cast<float>(this->val) / static_cast<float>(x.val);

			return (!sign != !x.sign) ? -z : z;
		}
		template<> double operator/ < double > (CHV4DINTEGER const& x)
		{
			double z = static_cast<double>(this->val) / static_cast<double>(x.val);

			return (!sign != !x.sign) ? -z : z;
		}
		template<typename T, typename I> T operator/(I const& x)
		{
			assert_float<T>();
			assert_integer<I>();

			return this->operator/ < T > ({ x });
		}





		template<typename T, typename I>
		T operator*(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			CHV4DINTEGER MAX_INT{ 18446744073709551615 };

			long double reciprocal = MAX_INT.operator/ < long double, uint64_t > (z.val);

			if (val <= reciprocal) throw std::overflow_error{ "Integer overrun." };

			z.val *= val;

			(!sign != !x.sign) ? z.sign = true : z.sign = false;

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



		template<typename T, typename I>
		T operator%(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			CHV4DINTEGER MAX_INT{ 18446744073709551615 };

			long double reciprocal = MAX_INT.operator/ < long double, uint64_t > (z.val);

			if (val <= reciprocal) throw std::overflow_error{ "Integer overrun." };

			z.val *= val;

			(!sign != !x.sign) ? z.sign = true : z.sign = false;

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



		template<typename T, typename I>
		T operator++(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			CHV4DINTEGER MAX_INT{ 18446744073709551615 };

			long double reciprocal = MAX_INT.operator/ < long double, uint64_t > (z.val);

			if (val <= reciprocal) throw std::overflow_error{ "Integer overrun." };

			z.val *= val;

			(!sign != !x.sign) ? z.sign = true : z.sign = false;

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



		template<typename T, typename I>
		T operator--(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			CHV4DINTEGER z{ x };

			CHV4DINTEGER MAX_INT{ 18446744073709551615 };

			long double reciprocal = MAX_INT.operator/ < long double, uint64_t > (z.val);

			if (val <= reciprocal) throw std::overflow_error{ "Integer overrun." };

			z.val *= val;

			(!sign != !x.sign) ? z.sign = true : z.sign = false;

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



		void operator+=(CHV4DINTEGER const& x)
		{

		}

		void operator-=(CHV4DINTEGER const& x)
		{

		}

		void operator*=(CHV4DINTEGER const& x)
		{

		}

		void operator/=(CHV4DINTEGER const& x)
		{

		}

		void operator%=(CHV4DINTEGER const& x)
		{

		}

		void operator&=(CHV4DINTEGER const& x)
		{

		}

		void operator|=(CHV4DINTEGER const& x)
		{

		}

		void operator>>=(CHV4DINTEGER const& x)
		{

		}

		void operator<<=(CHV4DINTEGER const& x)
		{

		}

		bool operator==(CHV4DINTEGER const& x) const
		{
			return (val == x.val) && (sign == x.sign) ? true : false;
		}
		bool operator!=(CHV4DINTEGER const& x) const
		{
			return (val != x.val) || (sign != x.sign) ? true : false;
		}
		bool operator<(CHV4DINTEGER const& x) const
		{
			if ((val == x.val) && (sign == x.sign)) return false;

			else if ((val < x.val) && (!sign && !x.sign)) return true;

			else if ((val > x.val) && (sign && x.sign)) return true;

			else if (!sign && x.sign) return true;

			else if (sign && !x.sign) return false;
		}
		bool operator>(CHV4DINTEGER const& x) const
		{
			if ((val == x.val) && (sign == x.sign)) return false;

			else if ((val < x.val) && (!sign && !x.sign)) return false;

			else if ((val > x.val) && (sign && x.sign)) return false;

			else if (!sign && x.sign) return false;

			else if (sign && !x.sign) return true;
		}
		bool operator<=(CHV4DINTEGER const& x) const
		{
			if ((val == x.val) && (sign == x.sign)) return true;

			else if ((val < x.val) && (!sign && !x.sign)) return true;

			else if ((val > x.val) && (sign && x.sign)) return true;

			else if (!sign && x.sign) return true;

			else if (sign && !x.sign) return false;
		}
		bool operator>=(CHV4DINTEGER const& x) const
		{
			if ((val == x.val) && (sign == x.sign)) return true;

			else if ((val < x.val) && (!sign && !x.sign)) return false;

			else if ((val > x.val) && (sign && x.sign)) return false;

			else if (!sign && x.sign) return false;

			else if (sign && !x.sign) return true;
		}

	public:
		CHV4DINTEGER Pow(CHV4DINTEGER pow)
		{
			if (pow.sign) throw std::runtime_error{ "Unsigned powers." };

			if (pow.val == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.val != 0 && val == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.val; i++)
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
			assert_integer<T>();
			assert_integer<I>();

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

			if (pow.val == 0)
			{
				return CHV4DINTEGER{ 1ui64 };
			}
			else if (pow.val != 0 && val == 0ui64)
			{
				return CHV4DINTEGER{ 0ui64 };
			}

			CHV4DINTEGER z{ *this };

			for (uint64_t i = 0; i < pow.val; i++)
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
			assert_integer<T>();
			assert_integer<I>();

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
		bool sign{ false };

		uint64_t val{ 0 };

	};

}