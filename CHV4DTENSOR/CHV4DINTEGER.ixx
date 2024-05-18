module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;

import :CHV4DRESOURCE;

export namespace CHV4DTENSOR
{
	class MaxInteger
	{
	public:
		MaxInteger() { sign = false; val = 0; }

		MaxInteger(MaxInteger const& x) { sign = x.sign; val = x.val; }

		MaxInteger(uint8_t  const& x) { sign = false; val = x; }
		MaxInteger(uint16_t const& x) { sign = false; val = x; }
		MaxInteger(uint32_t const& x) { sign = false; val = x; }
		MaxInteger(uint64_t const& x) { sign = false; val = x; }

		MaxInteger(int8_t  const& x) { x < 0 ? sign = true : sign = false; val = x; }
		MaxInteger(int16_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		MaxInteger(int32_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		MaxInteger(int64_t const& x) { x < 0 ? sign = true : sign = false; val = x; }

	public:
		template<typename T> T operator()() const
		{
			static_assert(false, "Non Integer type.");
		}
		template<> uint8_t operator()() const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 255) return val;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint16_t operator()() const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 65535) return val;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint32_t operator()() const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 4294967295) return val;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> uint64_t operator()() const
		{
			if (sign) throw std::runtime_error{ "Signed Integer." };

			if (val <= 18446744073709551615) return val;

			else throw std::overflow_error{ "Integer overrun." };
		}
		template<> int8_t operator()() const
		{
			if (!sign)
			{
				if (val <= 127) return val;

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 127) return -val;

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int16_t operator()() const
		{
			if (!sign)
			{
				if (val <= 32767) return val;

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 32767) return -val;

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int32_t operator()() const
		{
			if (!sign)
			{
				if (val <= 2147483647) return val;

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 2147483647) return -val;

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> int64_t operator()() const
		{
			if (!sign)
			{
				if (val <= 9223372036854775807) return val;

				else throw std::overflow_error{ "Integer overrun." };
			}
			else if (sign)
			{
				if (val <= 9223372036854775807) return -val;

				else throw std::overflow_error{ "Integer overrun." };
			}
		}
		template<> MaxInteger operator()() const
		{
			return *this;
		}

		void operator=(MaxInteger const& x) { sign = x.sign; val = x.val; }

		void operator=(uint8_t  const& x) { sign = false; val = x; }
		void operator=(uint16_t const& x) { sign = false; val = x; }
		void operator=(uint32_t const& x) { sign = false; val = x; }
		void operator=(uint64_t const& x) { sign = false; val = x; }

		void operator=(int8_t  const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int16_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int32_t const& x) { x < 0 ? sign = true : sign = false; val = x; }
		void operator=(int64_t const& x) { x < 0 ? sign = true : sign = false; val = x; }

		MaxInteger operator+(MaxInteger const& x) const
		{
			if ((x.sign && sign) || (!x.sign && !sign))
			{
				if (x.val <= (18446744073709551615 - val)) { MaxInteger z{ val + x.val }; z.sign = x.sign; return z; }

				else throw std::overflow_error{ "Integer overrun." };
			}
			else
			{
				if (x.sign)
				{
					if (val > x.val) { MaxInteger z{ val - x.val }; z.sign = false; return z; }

					else { MaxInteger z{ x.val - val }; z.sign = true; return z; }
				}
				else if (sign)
				{
					if (val > x.val) { MaxInteger z{ val - x.val }; z.sign = false; return z; }

					else { MaxInteger z{ x.val - val }; z.sign = true; return z; }
				}
			}
		}

		template<typename T, typename I>
		T operator+(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			MaxInteger z{ x };

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

		MaxInteger operator-(MaxInteger const& x) const
		{
			MaxInteger z;

			if (val == x.val) { z.val = 0; z.sign = false; return z; }

			else if (val > x.val) { z.val = val - x.val; z.sign = false; return z; }

			else if (val < x.val) { z.val = x.val - val; z.sign = true; return z; }
		}

		template<typename T, typename I> T operator-(I const& x)
		{
			assert_integer<T>();
			assert_integer<I>();

			MaxInteger z{ x };

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

		template<typename T> T operator/(MaxInteger const& x)
		{
			static_assert(false, "Non Integer type.");
		}
		template<> float operator/ < float > (MaxInteger const& x)
		{
			float z = this->val / x.val;

			return (!sign != !x.sign) ? -z : z;
		}
		template<> double operator/ < double > (MaxInteger const& x)
		{
			double z = this->val / x.val;

			return (!sign != !x.sign) ? -z : z;
		}
		template<> long double operator/ < long double > (MaxInteger const& x)
		{
			long double z = this->val / x.val;

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

			MaxInteger z{ x };

			MaxInteger MAX_INT{ 18446744073709551615 };

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

		MaxInteger operator^(MaxInteger pow)
		{
			if (pow.sign) throw std::runtime_error{ "Unsigned powers." };

			if (pow.val == 0)
			{
				return MaxInteger{ 1ui64 };
			}
			else if (pow.val != 0 && val == 0ui64)
			{
				return MaxInteger{ 0ui64 };
			}

			MaxInteger z{ *this };

			for (uint64_t i = 0; i < pow.val; i++)
			{
				try
				{
					z = z.operator*< MaxInteger >(this);
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
		T operator^(I x)
		{
			assert_integer<T>();
			assert_integer<I>();

			MaxInteger pow{ x };

			MaxInteger res;

			try
			{
				res = this->operator^(pow);
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

	public:
		bool sign{ false };

		uint64_t val{ 0 };

	};

}