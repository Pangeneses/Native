module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DCMATH;

import :CHV4DPRECISION;
import :CHV4DINTEGER;

export namespace CHV4DTENSOR
{
	uint64_t iIPow(uint64_t const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0f;

		if (pow != 0 && var == 0.0f) return 0.0f;

		float inPlace{ 1.0f };

		for (size_t i = 0; i < pow; i++)
		{
			inPlace *= var;

		}

		return inPlace;

	}

	float fIPow(float const& var, size_t const& pow)
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

	double dIPow(double const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0;

		if (pow != 0 && var == 0.0) return 0.0;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		double inPlace{ 1.0 };

		for (size_t i = 0; i < pow; i++)
		{
			inPlace *= var;

		}

		return inPlace;

	}

	long double ldIPow(long double const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0l;

		if (pow != 0 && var == 0.0l) return 0.0l;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		long double inPlace{ 1.0l };

		for (size_t i = 0; i < pow; i++)
		{
			inPlace *= var;

		}

		return inPlace;

	}


	float fRoot(float const& var, size_t const& pow)
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

	double dRoot(double const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0;

		if (pow != 0 && var == 0.0) return 0.0;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		double root{ 0.0 };

		double ret{ 1.0 };

		while (dAbs(dIPow(ret, pow) - var) > 0.0000000001)
		{
			root = ret;

			ret = root - ((dIPow(root, pow) - var) / (pow * dIPow(root, pow - 1)));

		}

		return ret;

	}

	long double ldRoot(long double const& var, size_t const& pow)
	{
		if (pow == 0) return 1.0l;

		if (pow != 0 && var == 0.0l) return 0.0l;

		if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

		long double root{ 0.0l };

		long double ret{ 1.0l };

		while (ldAbs(ldIPow(ret, pow) - var) > 0.0000000001l)
		{
			root = ret;

			ret = root - ((ldIPow(root, pow) - var) / (pow * ldIPow(root, pow - 1)));

		}

		return ret;

	}

	void fPowToFrac(float const& p, uint64_t& a, uint64_t& b)
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
		else if(pow < 1.0f && pow > 0.0f)
		{
		}
		else if (pow == 0.0f)
		{
		}
		else if (pow < 0.0f)
		{
		}
		
	}

	void dPowToFrac(double const& p, uint64_t& a, uint64_t& b);
	void ldPowToFrac(long double const& p, uint64_t& a, uint64_t& b);

	float fPower(float const& var, size_t const& pow);
	double dPower(double const& var, size_t const& pow);
	long double ldPower(long double const& var, size_t const& pow);

	float fLength(float const& a, float const& b);
	double dLength(double const& a, double const& b);
	long double ldLength(long double const& a, long double const& b);

	float fLength(float const& a, float const& b, float const& c);
	double dLength(double const& a, double const& b, double const& c);
	long double ldLength(long double const& a, long double const& b, long double const& c);

	float fLength(float const& a, float const& b, float const& c, float const& n);
	double dLength(double const& a, double const& b, double const& c, double const& n);
	long double ldLength(long double const& a, long double const& b, long double const& c, long double const& n);

	float Ln(float const& x, size_t const& iterations = 20);
	double Ln(double const& x, size_t const& iterations = 20);
	long double Ln(long double const& x, size_t const& iterations = 20);

	float Log(float const& b, float const& x, size_t const& iterations = 50);
	double Log(double const& b, double const& x, size_t const& iterations = 50);
	long double Log(long double const& b, long double const& x, size_t const& iterations = 50);

	float Exp(float const& x, size_t const& iterations = 10);
	double Exp(double const& x, size_t const& iterations = 10);
	long double Exp(long double const& x, size_t const& iterations = 10);

	float Gamma(float const& x, size_t const& iterations = 50);
	double Gamma(double const& x, size_t const& iterations = 50);
	long double Gamma(long double const& x, size_t const& iterations = 50);


	float cFPower(float const& var, size_t const& pow)
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

	double cFPower(double const& var, size_t const& pow)
	{
		if (pow == 0.0) return 1.0f;

		if (pow != 0.0 && var == 0.0f) return 0.0f;

		double inPlace{ var };

		if (pow < 0.0) inPlace = 1.0f / inPlace;

		size_t a, b;

		cPowToFrac(pow, a, b);

		inPlace = static_cast<double>(cIPow(inPlace, a));

		inPlace = static_cast<double>(cRoot(inPlace, b));

		return inPlace;

	}

	double const cLength(double a, double b)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqAsqB{ sqrOfA + sqrOfB };

		return cRoot(sqAsqB, 2);

	}

	double const cLength(double a, double b, double c)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqAsqBsqC{ sqrOfA + sqrOfB + sqrOfC };

		return cRoot(sqAsqBsqC, 2);

	}

	double const cLength(double a, double b, double c, double n)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqrOfN{ n * n };

		double sqAsqBsqCsqN{ sqrOfA + sqrOfB + sqrOfC + sqrOfN };

		return cRoot(sqAsqBsqCsqN, 2);

	}

	float const cLn(float x, size_t iterations = 20)
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

	double const cLn(double x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<double>::infinity();

		double inPlace = x - 1.0;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = DoubleToUint64(cIPow(2, k));

			double root = cRoot(x, p2k);

			inPlace *= (2.0 / (1.0 + root));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	float const cLog(float b, float x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		float Algebra{ b }, var{ x };

		float inPlace = cLn(Algebra, iterations) / cLn(var, iterations);

		return inPlace;

	}

	double const cLog(double b, double x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<double>::infinity();

		double Algebra{ b }, var{ x };

		double inPlace = cLn(Algebra, iterations) / cLn(var, iterations);

		return inPlace;

	}

	double const cGamma(double x, size_t iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	double cExp(double x, size_t iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}

}