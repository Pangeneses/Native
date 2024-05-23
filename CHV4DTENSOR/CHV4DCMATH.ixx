module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DCMATH;

import :CHV4DINTEGER;
import :CHV4DPRECISION;

export namespace CHV4DTENSOR
{
	MaxInteger Pow(MaxInteger const& var, size_t const& pow)
	{
		if (pow == 0) return MaxInteger{ 1 };

		if ((pow != 0) && ((var.operator() < uint64_t > ()) == 0)) return MaxInteger{ 0 };

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

	void ToFrac(MaxPrecision const& p, MaxInteger& a, MaxInteger& b)
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


}