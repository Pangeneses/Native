module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DARITHMETIC;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DINTEGER;

export namespace CHV4DTENSOR
{
	/*



	template<typename T>
	T Abs(T const&)
	{
		assert_precision < T > ();
	}
	template<>
	float Abs < float > (float const& x)
	{
		float A{ x };

		unsigned char* Data;

		Data = reinterpret_cast<unsigned char*>(&A);

		{
			if (exponent > 255ui16) throw std::overflow_error{ "Precision overrun" };

			unsigned char fpexp = *reinterpret_cast<unsigned char*>(const_cast<uint16_t*>(&exponent));

			Data[0] = Data[0] | fpexp >> 1;

			Data[1] = 0 | fpexp << 7;
		}

		{
			if (mantissa > 8388607ui64) throw std::overflow_error{ "Precision overrun" };

			unsigned char* fpmantissa = reinterpret_cast<unsigned char*>(const_cast<uint64_t*>(&mantissa));

			Data[3] = fpmantissa[0];
			Data[2] = fpmantissa[1];
			Data[1] = Data[1] | (fpmantissa[2] & 0b01111111);
		}

		return *reinterpret_cast<float*>(Data);
	}
	
	template<typename T, typename I> T IntegerPower(I const& base, int64_t pow)
	{
		static_assert(false, "Non Integer type.");
	}
	template<>
	CHV4DINTEGER IntegerPower <CHV4DINTEGER, CHV4DINTEGER>(CHV4DINTEGER const& base, int64_t pow)
	{
		if (pow < 0) throw std::runtime_error{ "Unsigned powers." };

		if (pow == 0)
		{
			return CHV4DINTEGER{ 1i64 };
		}
		else if (pow != 0 && base() == 0ui64)
		{
			return CHV4DINTEGER{ 0i64 };
		}

		CHV4DINTEGER A{ base() };

		try
		{
			A = A.operator^< CHV4DINTEGER >(pow);
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
	template<>
	int64_t IntegerPower <int64_t, CHV4DINTEGER>(CHV4DINTEGER const& base, int64_t pow)
	{
		if (pow < 0) throw std::runtime_error{ "Unsigned powers." };

		if (pow == 0)
		{
			return 1i64;
		}
		else if (pow != 0 && base() == 0ui64)
		{
			return 0i64;
		}

		CHV4DINTEGER A{ base() };

		try
		{
			A = A.operator^< CHV4DINTEGER >(pow);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		return A.operator() < int64_t > ();
	}
	template<>
	int64_t IntegerPower <int64_t, int64_t>(int64_t const& base, int64_t pow)
	{
		if (pow < 0) throw std::runtime_error{ "Unsigned powers." };

		if (pow == 0)
		{
			return 1i64;
		}
		else if (pow != 0 && base == 0ui64)
		{
			return 0i64;
		}

		CHV4DINTEGER A{ base };

		try
		{
			A = A.operator^< CHV4DINTEGER >(pow);
		}
		catch (std::overflow_error error)
		{
			throw error;
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		return A.operator() < int64_t > ();
	}

	uint64_t nWholeRoot(CHV4DINTEGER const& number, size_t n, float eps = 0.0000000001f)
	{
		if (number == 0)
		{
			return 0ui64;
		}
		else if (number < 0)
		{
			throw std::runtime_error{ "Imaginary." };
		}

		if (n == 0)
		{
			return 0ui64;
		}

		int64_t var = number();

		double root{ 0.0 };

		double ret{ 1.0 };

		while (Absolute(IntegerPower < int64_t, int64_t > (ret, n) - var) > eps)
		{
			root = ret;

			ret = root - ((iPow{ root, pow }()() - var()) / (pow * iPow{ root, pow - 1 }()()));

		}

		return ret;

	}

	{
			while (Absolute(CHV4DDOUBLE{ iPow{ ret, pow }()() - var() }) > eps)
			{
				root = ret;

				ret = root - ((iPow{ root, pow }()() - var()) / (pow * iPow{ root, pow - 1 }()()));

			}

			return ret;

	};





	int64_t Root(int64_t const& number, int64_t n)
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

	* 
	* 
	class fPow;
	class iPow
	{
	public:
		iPow(size_t const x, size_t const p)
		{
			iVar = x;

			pow = p;

		}

		iPow(CHV4DDOUBLE const x, size_t const p)
		{
			dVar = x();

			pow = p;

		}

	public:
		size_t const operator ()(size_t const& reserved)
		{
			if (pow == 0) return 1;

			if (pow != 0 && iVar == 0) return 0;

			if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

			if (reserved) throw std::invalid_argument{ "Reserved. Must be null." };

			size_t inPlace{ 1 };

			for (size_t i = 0; i < pow; i++)
			{
				inPlace *= iVar;

			}

			return inPlace;

		}

		CHV4DDOUBLE const operator ()()
		{
			if (pow == 0) return 1.0;

			if (pow != 0 && dVar == 0.0) return 0.0;

			if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative integers." };

			CHV4DDOUBLE inPlace{ 1.0 };

			for (size_t i = 0; i < pow; i++)
			{
				inPlace *= dVar;

			}

			return inPlace;

		}

	private:
		size_t iVar{};

		CHV4DDOUBLE dVar{};

		size_t pow{};

	};

	class Root
	{
	public:
		Root(CHV4DDOUBLE const x, size_t const p, CHV4DFLOAT const epsilon = 0.0000000001f)
		{
			var = x();

			pow = p;

			eps = epsilon();

		}

	public:
		CHV4DDOUBLE const operator ()()
		{
			if (pow == 0) return 1.0;

			if (pow != 0 && var == 0) return 0;

			if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

			CHV4DDOUBLE root{ 0.0 };

			CHV4DDOUBLE ret{ 1.0 };

			while (Absolute(CHV4DDOUBLE{ iPow{ ret, pow }()() - var() }) > eps)
			{
				root = ret;

				ret = root - ((iPow{ root, pow }()() - var()) / (pow * iPow{ root, pow - 1 }()()));

			}

			return ret;

		}

	private:
		CHV4DDOUBLE var{};

		size_t pow{};

		CHV4DDOUBLE eps{};

	};

	void PowToFrac(CHV4DDOUBLE const p, uint64_t& a, uint64_t& b)
	{
		CHV4DDOUBLE pow{ p };

		if (pow < 0.0) throw std::out_of_range{ "Invert x to remove negative power." };

		size_t mag;

		if (pow >= 1.0)
		{
			for (mag = 1; pow / 2.0 > 1.0; mag++)
			{
				pow = pow / 2.0f;

			}

			CHV4DDOUBLE scan;

			for (scan = 0.0; scan < 2147483648.0; scan += 80000.0)
			{
				CHV4DDOUBLE frac = (2147483648.0 + scan()) / (2147483648.0 - scan());

				CHV4DDOUBLE floor = Trunc(frac, 1000000.0);

				CHV4DDOUBLE roof = Trunc(frac, 1000000.0) + 0.0001;

				if (floor < pow && pow < roof) break;

				//std::cout << frac << ", " << floor << ", " << roof << std::endl;

			}

			a = (2147483648 + static_cast<uint64_t>(scan()));

			b = 2147483648 - static_cast<uint64_t>(scan());

			for (size_t i = 0; i < mag; i++)
			{
				a *= iPow{ 2, i }(0);

				if (i > 2)
				{
					if ((i - 1) % 2 == 0)
					{
						b /= iPow{ 2, i }(0);

					}

				}

			}

		}
		else
		{
		}

	}

	class fPower
	{
	public:
		fPower(CHV4DFLOAT const x, CHV4DFLOAT const p)
		{
			var = x;

			pow = p;

		}

	public:
		CHV4DFLOAT const operator ()() const
		{
			if (pow == 0.0) return 1.0f;

			if (pow != 0.0 && var == 0.0f) return 0.0f;

			CHV4DDOUBLE inPlace{ var() };

			if (pow < 0.0) inPlace = 1.0f / inPlace();

			size_t a, b;

			PowToFrac({ pow() }, a, b);

			inPlace = iPow{ inPlace, a }()();

			inPlace = Root{ inPlace, b }()();

			return static_cast<float>(inPlace());

		}

	public:
		CHV4DFLOAT var{ 0 };

		CHV4DFLOAT pow{ 0 };

	};

	class dPower
	{
	public:
		dPower(CHV4DDOUBLE const x, CHV4DDOUBLE const p)
		{
			var = x;

			pow = p;

		}

	public:
		CHV4DDOUBLE const operator ()() const
		{
			if (pow == 0.0) return 1.0f;

			if (pow != 0.0 && var == 0.0f) return 0.0f;

			CHV4DDOUBLE inPlace{ var };

			if (pow < 0.0) inPlace = 1.0f / inPlace();

			uint64_t a, b;

			PowToFrac(pow, a, b);

			inPlace = iPow{ inPlace, a }();

			inPlace = Root{ inPlace, b }();

			return inPlace;

		}

	public:
		CHV4DDOUBLE var{ 0 };

		CHV4DDOUBLE pow{ 0 };

	};

	CHV4DDOUBLE const Length(CHV4DDOUBLE a, CHV4DDOUBLE b)
	{
		CHV4DDOUBLE sqrOfA{ a * a };

		CHV4DDOUBLE sqrOfB{ b * b };

		CHV4DDOUBLE sqAsqB{ sqrOfA + sqrOfB };

		return Root{ sqAsqB, 2 }();

	}

	CHV4DDOUBLE const Length(CHV4DDOUBLE a, CHV4DDOUBLE b, CHV4DDOUBLE c)
	{
		CHV4DDOUBLE sqrOfA{ a * a };

		CHV4DDOUBLE sqrOfB{ b * b };

		CHV4DDOUBLE sqrOfC{ c * c };

		CHV4DDOUBLE sqAsqBsqC{ sqrOfA() + sqrOfB() + sqrOfC() };

		return Root{ sqAsqBsqC, 2 }();

	}

	CHV4DDOUBLE const Length(CHV4DDOUBLE a, CHV4DDOUBLE b, CHV4DDOUBLE c, CHV4DDOUBLE n)
	{
		CHV4DDOUBLE sqrOfA{ a * a };

		CHV4DDOUBLE sqrOfB{ b * b };

		CHV4DDOUBLE sqrOfC{ c * c };

		CHV4DDOUBLE sqrOfN{ n * n };

		CHV4DDOUBLE sqAsqBsqCsqN{ sqrOfA() + sqrOfB() + sqrOfC() + sqrOfN() };

		return Root{ sqAsqBsqCsqN, 2 }();

	}

	CHV4DFLOAT const Ln(CHV4DFLOAT x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<float>::infinity();

		CHV4DFLOAT inPlace = x() - 1.0f;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = iPow{ 2, k }(0);

			CHV4DFLOAT root = static_cast<float>(Root{ x(), p2k }()());

			inPlace *= (2.0f / (1.0f + root()));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	CHV4DDOUBLE const Ln(CHV4DDOUBLE x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<double>::infinity();

		CHV4DDOUBLE inPlace = x() - 1.0;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = iPow{ 2, k }(0);

			CHV4DDOUBLE root = Root{ x(), p2k }();

			inPlace *= (2.0 / (1.0 + root()));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	CHV4DFLOAT const Log(CHV4DFLOAT b, CHV4DFLOAT x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		CHV4DFLOAT Algebra{ b }, var{ x };

		CHV4DFLOAT inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	CHV4DDOUBLE const Log(CHV4DDOUBLE b, CHV4DDOUBLE x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<double>::infinity();

		CHV4DDOUBLE Algebra{ b }, var{ x };

		CHV4DDOUBLE inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	CHV4DDOUBLE const Gamma(CHV4DDOUBLE x, size_t iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	CHV4DDOUBLE Exp(CHV4DDOUBLE x, size_t iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}

}



/*
module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DCMATH;

import :CHV4DINTEGER;
import :CHV4DPRECISION;

export namespace CHV4DTENSOR
{
	CHV4DINTEGER Pow(CHV4DINTEGER const& var, size_t const& pow)
	{
		if (pow == 0) return CHV4DINTEGER{ 1 };

		if ((pow != 0) && ((var.operator() < uint64_t > ()) == 0)) return CHV4DINTEGER{ 0 };

		uint64_t inPlace{ 1 };

		for (size_t i = 0; i < pow; i++)
		{
			inPlace *= (var.operator() < uint64_t > ());

		}

		return inPlace;

	}

	MaxPrecision Pow(MaxPrecision const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0f;

		if (pow != 0 && var == 0.0f) return 0.0f;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		float inPlace{ 1.0f };

		for (size_t i = 0; i < pow; i++)
		{
			inPlace *= var;

		}

		return inPlace;

	}

	MaxPrecision Root(MaxPrecision const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0f;

		if (pow != 0 && var == 0.0f) return 0.0f;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		float root{ 0.0f };

		float ret{ 1.0f };

		while (fAbs(fIPow(ret, pow) - var) > 0.0000000001f)
		{
			root = ret;

			ret = root - ((fIPow(root, pow) - var) / (pow * fIPow(root, pow - 1)));

		}

		return ret;

	}

	void ToFrac(MaxPrecision const& p, CHV4DINTEGER& a, CHV4DINTEGER& b)
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

	MaxPrecision fPow(MaxPrecision const& var, MaxPrecision const& pow)
	{
		if (pow == 0.0) return 1.0f;

		if (pow != 0.0 && var == 0.0f) return 0.0f;

		float inPlace{ var };

		if (pow < 0.0) inPlace = 1.0f / inPlace;

		size_t a, b;

		cPowToFrac(pow, a, b);

		inPlace = static_cast<float>(cIPow(inPlace, a));

		inPlace = static_cast<float>(cRoot(inPlace, b));

		return inPlace;

	}

	MaxPrecision Length2(MaxPrecision const& a, MaxPrecision const& b)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqAsqB{ sqrOfA + sqrOfB };

		return cRoot(sqAsqB, 2);

	}

	MaxPrecision Length3(MaxPrecision const& a, MaxPrecision const& b, MaxPrecision const& c)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqAsqBsqC{ sqrOfA + sqrOfB + sqrOfC };

		return cRoot(sqAsqBsqC, 2);

	}

	MaxPrecision Length4(MaxPrecision const& a, MaxPrecision const& b, MaxPrecision const& c, MaxPrecision const& n)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqrOfN{ n * n };

		double sqAsqBsqCsqN{ sqrOfA + sqrOfB + sqrOfC + sqrOfN };

		return cRoot(sqAsqBsqCsqN, 2);

	}

	MaxPrecision Ln(MaxPrecision const& x, size_t const& iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<float>::infinity();

		float inPlace = x - 1.0f;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = DoubleToUint64(cIPow(2, k));

			float root = static_cast<float>(cRoot(x, p2k));

			inPlace *= (2.0f / (1.0f + root));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	MaxPrecision Log(MaxPrecision const& b, MaxPrecision const& x, size_t const& iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		float Algebra{ b }, var{ x };

		float inPlace = cLn(Algebra, iterations) / cLn(var, iterations);

		return inPlace;

	}

	MaxPrecision Exp(MaxPrecision const& x, size_t const& iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}

	MaxPrecision Gamma(MaxPrecision const& x, size_t const& iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	*/
}