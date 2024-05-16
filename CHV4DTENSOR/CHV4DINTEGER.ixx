module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DINTEGER;


export namespace CHV4DMATH
{
	class MaxInteger
	{
	public:
		MaxInteger(MaxInteger const& x)
		{
			sign = x.sign;

			val = x.val;

		}

		MaxInteger(int64_t const& x)
		{
			sign = false;

			val = x;

		}

		MaxInteger(uint64_t const& x)
		{
			x < 0 ? sign = true : sign = false;

			val = x;

		}

	public:
		template<typename T> T operator()() { throw std::runtime_error{ "Unsupported type." }; }
		template<typename uint8_t> uint8_t operator()()
		{
			if (!sign) val < 256 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename uint16_t> uint16_t operator()()
		{
			if (!sign) val < 65536 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename uint32_t> uint32_t operator()()
		{
			if (!sign) val < 4294967296 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename uint64_t> uint64_t operator()()
		{
			if (!sign) val < 18446744073709551616dl ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename int8_t> int8_t operator()()
		{
			if (sign) val < 128 ? return -val : throw std::overflow_error{ "Integer overrun." };

			else if (!sign) val < 128 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename int16_t> int16_t operator()()
		{
			if (sign) val < 32768 ? return -val : throw std::overflow_error{ "Integer overrun." };

			else if (!sign) val < 32768 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename int32_t> int32_t operator()()
		{
			if (sign) val < 2147483648 ? return -val : throw std::overflow_error{ "Integer overrun." };

			else if (!sign) val < 2147483648 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename int64_t> int64_t operator()()
		{
			if (sign) val < 9223372036854775808 ? return -val : throw std::overflow_error{ "Integer overrun." };

			else if (!sign) val < 9223372036854775808 ? return val : throw std::overflow_error{ "Integer overrun." };
		}
		template<typename MaxInteger> MaxInteger operator()()
		{
			return *this;

		}

		void operator=(MaxInteger const& x) { sign = x.sign; val = x.val; }
		void operator=(uint64_t const& x) { sign = false; val = x; }
		void operator=(int64_t const& x) { if (x < 0) { sign = true; } else { sign = false; } val = x; }

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
			MaxInteger y{ x };

			return (*this + y).operator() < T > ();
		}

		template<typename T, typename I> T operator-(I const& x) { *this->operator+<T, I>(-x); }

		template<typename T> T operator/(MaxInteger const& x) { throw std::runtime_error{ "Unsupported type." }; }
		template<typename float> float operator/(MaxInteger const& x) { float z = this->val / x.val; return (!sign != !x.sign) ? -z : z; }
		template<typename double> double operator/(MaxInteger const& x) { double z = this->val / x.val; return (!sign != !x.sign) ? -z : z; }
		template<typename long double> long double operator/(MaxInteger const& x) { long double z = this->val / x.val; return (!sign != !x.sign) ? -z : z; }
		template<typename T, typename I> T operator/(I const& x) { *this->operator/<T>(MaxInteger{ x }); }

		template<typename T, typename I>
		T operator*(I const& x)
		{
			MaxInteger z{ x };

			if (!(val > MaxInteger{ 18446744073709551615 }.operator/<double>(z))) throw std::overflow_error{ "Integer overrun." };

			z.val *= val;

			(!sign != !x.sign) ? z.sign = true : z.sign = false;

			return z.operator() < T > ();

		}


		template<typename T, typename I>
		T operator^(I x)
		{



		}

		template<typename T>
		T operator^(MaxInteger x)
		{



		}

	public:
		bool sign{ false };

		uint64_t val{ 0 };

	};

}