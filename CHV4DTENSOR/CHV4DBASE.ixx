module;

#include <stdexcept>

#include <string>
#include <vector>

#include <istream>
#include <ostream>
#include <iostream>

export module CHV4DTENSOR:CHV4DCALC;

export namespace Calc
{
	class FloatingPoint
	{
	public:
		FloatingPoint(double fp)
		{
			if (fp < 0.0) negative = true;

			exponent = (size_t)fp | 0x7FF0000000000000;

			exponent = exponent >> 52;

			mantissa = 0x000FFFFFFFFFFFFF;

		}

	public:
		inline bool const Sign() const { return negative; };

		inline size_t Exponent() const { return exponent; }

		inline size_t Mantissa() const { return mantissa; }

	private:
		bool negative{ false };

		size_t exponent{ 0 };

		size_t mantissa{ 0 };

	};

	uint32_t FloatToUint32(float const& x)
	{
		uint32_t out;

		memcpy(&out, &x, sizeof out);

		return out;
	}

	float Uint32ToFloat(uint32_t const& x)
	{
		float out;

		memcpy(&out, &x, sizeof out);

		return out;
	}

	uint64_t DoubleToUint64(double const& x)
	{
		uint64_t out;

		memcpy(&out, &x, sizeof out);

		return out;
	}

	double Uint64ToDouble(uint64_t const& x)
	{
		float out;

		memcpy(&out, &x, sizeof out);

		return out;
	}

	float Trunc(float x, float sigFigs = 1.0f)
	{
		uint64_t iValue = static_cast<uint64_t>(x * sigFigs);

		float fValue = static_cast<float>(iValue);

		fValue = fValue / sigFigs;

		return fValue;

	}

	double Trunc(double x, double sigFigs = 1.0f)
	{
		uint64_t iValue = static_cast<uint64_t>(x * sigFigs);

		double dValue = static_cast<double>(iValue);

		dValue = dValue / sigFigs;

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

		iPow(double const x, size_t const p)
		{
			dVar = x;

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

		double const operator ()()
		{
			if (pow == 0) return 1.0;

			if (pow != 0 && dVar == 0.0) return 0.0;

			if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative integers." };

			double inPlace{ 1.0 };

			for (size_t i = 0; i < pow; i++)
			{
				inPlace *= dVar;

			}

			return inPlace;

		}

	private:
		size_t iVar{};

		double dVar{};

		size_t pow{};

	};

	class Root
	{
	public:
		Root(double const x, size_t const p, float const epsilon = 0.0000000001)
		{
			var = x;

			pow = p;

			eps = epsilon;

		}

	public:
		double const operator ()()
		{
			if (pow == 0) return 1.0;

			if (pow != 0 && var == 0) return 0;

			if (pow < 0) throw std::out_of_range{ "Integer conversion. Use float for negative powers." };

			double root{ 0.0 };

			double ret{ 1.0 };

			while (std::abs(iPow{ ret, pow }() - var) > eps)
			{
				root = ret;

				ret = root - ((iPow{ root, pow }() - var) / (pow * iPow(root, pow - 1)()));

			}

			return ret;

		}

	private:
		double var{};

		size_t pow{};

		double eps{};

	};

	void PowToFrac(double const p, uint64_t& a, uint64_t& b)
	{
		double pow{ p };

		if (pow < 0.0) throw std::out_of_range{ "Invert x to remove negative power." };

		size_t mag;

		if (pow >= 1.0)
		{
			for (mag = 1; pow / 2.0 > 1.0; mag++)
			{
				pow = pow / 2.0f;

			}

			double scan;

			for (scan = 0.0; scan < 2147483648.0; scan += 80000.0)
			{
				double frac = (2147483648.0 + scan) / (2147483648.0 - scan);

				double floor = Trunc(frac, 1000000.0);

				double roof = Trunc(frac, 1000000.0) + 0.0001;

				if (floor < pow && pow < roof) break;

				//std::cout << frac << ", " << floor << ", " << roof << std::endl;

			}

			a = (2147483648 + static_cast<uint64_t>(scan));

			b = 2147483648 - static_cast<uint64_t>(scan);

			for (size_t i = 0; i < mag; i++)
			{
				a *= iPow{ size_t{ 2 }, i }(0);

				if (i > 2)
				{
					if ((i - 1) % 2 == 0)
					{
						b /= iPow{ size_t{ 2 }, i }(0);

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
		fPower(float const x, float const p)
		{
			var = x;

			pow = p;

		}

	public:
		float const operator ()() const
		{
			if (pow == 0.0) return 1.0f;

			if (pow != 0.0 && var == 0.0f) return 0.0f;

			float inPlace{ var };

			if (pow < 0.0) inPlace = 1.0f / inPlace;

			size_t a, b;

			PowToFrac(pow, a, b);

			iPow{ inPlace, a }();

			Root{ inPlace, b }();

			return inPlace;

		}

	public:
		float var{ 0 };

		float pow{ 0 };

	};

	class dPower
	{
	public:
		dPower(double const x, double const p)
		{
			var = x;

			pow = p;

		}

	public:
		double const operator ()() const
		{
			if (pow == 0.0) return 1.0f;

			if (pow != 0.0 && var == 0.0f) return 0.0f;

			double inPlace{ var };

			if (pow < 0.0) inPlace = 1.0f / inPlace;

			uint64_t a, b;

			PowToFrac(pow, a, b);

			iPow{ inPlace, a }();

			Root{ inPlace, b }();

			return inPlace;

		}

	public:
		double var{ 0 };

		double pow{ 0 };

	};

	double const Length(double a, double b)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqAsqB{ sqrOfA + sqrOfB };

		return Root{ sqAsqB, 2 }();

	}

	double const Length(double a, double b, double c)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqAsqBsqC{ sqrOfA + sqrOfB + sqrOfC };

		return Root{ sqAsqBsqC, 2 }();

	}

	double const Length(double a, double b, double c, double n)
	{
		double sqrOfA{ a * a };

		double sqrOfB{ b * b };

		double sqrOfC{ c * c };

		double sqrOfN{ n * n };

		double sqAsqBsqCsqN{ sqrOfA + sqrOfB + sqrOfC + sqrOfN };

		return Root{ sqAsqBsqCsqN, 2 }();

	}

}