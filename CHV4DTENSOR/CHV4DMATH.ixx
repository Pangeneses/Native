module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DMATH;

import :CHV4DREAL;

export namespace CHV4DTENSOR
{
	CHV4DFLOAT Absolute(CHV4DFLOAT x) { return x < 0.0f ? x() * -1.0f : x; }

	CHV4DDOUBLE Absolute(CHV4DDOUBLE x) { return x < 0 ? x() * -1.0 : x; }

	uint64_t Floor(CHV4DFLOAT x)
	{
		return static_cast<uint64_t>(x());

	}

	uint64_t Floor(CHV4DDOUBLE x)
	{
		return static_cast<uint64_t>(x());

	}

	uint64_t Ceiling(CHV4DFLOAT x)
	{
		return static_cast<uint64_t>(x()) + 1;

	}

	uint64_t Ceiling(CHV4DDOUBLE x)
	{
		return static_cast<uint64_t>(x()) + 1;

	}

	CHV4DFLOAT Trunc(CHV4DFLOAT x, CHV4DFLOAT sigFigs = 1.0f)
	{
		uint64_t iValue = static_cast<uint64_t>(x() * sigFigs());

		float fValue = static_cast<float>(iValue);

		fValue = fValue / sigFigs();

		return fValue;

	}

	CHV4DDOUBLE Trunc(CHV4DDOUBLE x, CHV4DDOUBLE sigFigs = 1.0f)
	{
		uint64_t iValue = static_cast<uint64_t>(x() * sigFigs());

		double dValue = static_cast<double>(iValue);

		dValue = dValue / sigFigs();

		return dValue;

	}

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