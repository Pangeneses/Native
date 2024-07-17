module;

#include <compare>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DARITHMETIC;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;
import :CHV4DINTEGER;
import :CHV4DPRECISION;

export namespace CHV4DTENSOR
{ 
	template<ASSERT_CHV4DZINTEGER T = CHV4DINTEGER<size_t>>
	T PositivePower(T const& base, T const& pow)
	{
		T A{ base }, B{ pow }, Q{ static_cast<T>(1) };

		if (B < 0) throw std::runtime_error{ "PositivePower works with positive numbers." };

		if (A == static_cast<T>(0) && B == static_cast<T>(0))
		{
			throw std::runtime_error{ "Zero division by zero undefined." };
		}

		if (B == 0)
		{
			return static_cast<T>(1);
		}
		else if (B != static_cast<T>(0) && A == static_cast<T>(0))
		{
			return static_cast<T>(0);
		}

		while (B != static_cast<T>(0))
		{
			if ((B & static_cast<T>(1)) == static_cast<T>(1))
			{
				try
				{
					Q *= A;
				}
				catch (std::overflow_error error)
				{
					throw error;
				}
			}

			B >>= 1;

			if (B != static_cast<T>(0))
			{
				try
				{
					A *= A;
				}
				catch (std::overflow_error error)
				{
					throw error;
				}
			}
		}

		if (pow.Sign())
		{
			if (pow & static_cast<T>(1) == static_cast<T>(1)) Q.operator*(static_cast<T>(-1));
		}

		return Q;		
	}

	template<ASSERT_CHV4DZINTEGER T = CHV4DINTEGER<size_t>>
	T IsCyclic(T const& z, T const& n)
	{
		T A{ z }, B{ n }, Q{ 0 };

		try
		{
			Q = A.operator%(B);
		}
		catch (std::runtime_error error)
		{
			throw error;
		}

		if (Q == 0) return A / B;

		else return static_cast<T>(0);
	};

	template<ASSERT_CHV4DZINTEGER T = CHV4DINTEGER<size_t>>
	void AsFraction(CHV4DPRECISION < double > const& precision, T& a, T& b)
	{
		CHV4DMANTISSA < double > P{ precision };

		CHV4DINTEGER<size_t> W = P.Floor();

		CHV4DMANTISSA < double > D = P() - P.Floor();

		CHV4DINTEGER<size_t> A{ D.Mantissa() | 0x0008000000000000 }, B{ 0x000FFFFFFFFFFFFF };

		while (B != static_cast<CHV4DINTEGER<size_t>>(0)) 
		{ 
			CHV4DINTEGER<size_t> Q;

			try
			{
				Q = A % B;
			}
			catch (std::runtime_error error)
			{
				throw error;
			}
		
			A = B;

			B = Q;
		}

		a = (D.Mantissa() | 0x0008000000000000) / A();

		b = 0x000FFFFFFFFFFFFF / A();
	}

	CHV4DPRECISION < double > PositiveRoot(CHV4DINTEGER<size_t> const& a, CHV4DINTEGER<size_t> const& b)
	{


	}

	template<ASSERT_CHV4DPRECISION T = CHV4DPRECISION<double>>
	T PrecisionPower(T const& a, T const& b)
	{


	}

	template<ASSERT_CHV4DPRECISION T>
	T Ln(T const& x, size_t iterations = 20)
	{

	}

	template<>
	CHV4DPRECISION <float> Ln <CHV4DPRECISION <float>> (CHV4DPRECISION <float> const& x, size_t iterations)
	{
		if (x <= 0.0f) return -std::numeric_limits<float>::infinity();

		CHV4DPRECISION <float> inPlace = x() - 1.0f;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			CHV4DINTEGER<size_t> p2k = PositivePower(CHV4DINTEGER<size_t>{ 2 }, CHV4DINTEGER<size_t>{ k });

			CHV4DPRECISION <float> root = static_cast<float>(IsCyclic(CHV4DINTEGER<size_t>{ x() }, CHV4DINTEGER<size_t>{ p2k })());

			inPlace *= (2.0f / (1.0f + root()));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;
	}

	template<>
	CHV4DPRECISION <double> Ln <CHV4DPRECISION <double>> (CHV4DPRECISION <double> const& x, size_t iterations)
	{
		if (x <= 0.0f) return -std::numeric_limits<double>::infinity();

		CHV4DPRECISION <double> inPlace = x() - 1.0f;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			CHV4DINTEGER<size_t> p2k = PositivePower(CHV4DINTEGER<size_t>{ 2 }, CHV4DINTEGER<size_t>{ k });

			CHV4DPRECISION <double> root = static_cast<double>(IsCyclic(CHV4DINTEGER<size_t>{ x() }, CHV4DINTEGER<size_t>{ p2k })());

			inPlace *= (2.0f / (1.0f + root()));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";
		}

		return inPlace;
	}

	template<ASSERT_CHV4DPRECISION T>
	T Log (T const& x, size_t iterations = 20)
	{

	}

	template<>
	CHV4DPRECISION <float> Log <CHV4DPRECISION <float>> (CHV4DPRECISION <float> const& x, size_t iterations)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		CHV4DPRECISION <float> Algebra{ b }, var{ x };

		CHV4DPRECISION <float> inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	template<>
	CHV4DPRECISION <double> Log <CHV4DPRECISION <double>>(CHV4DPRECISION <double> const& x, size_t iterations)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<double>::infinity();

		CHV4DPRECISION <double> Algebra{ b }, var{ x };

		CHV4DPRECISION <double> inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	CHV4DPRECISION <double> const Gamma(CHV4DPRECISION <double> x, size_t iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	CHV4DPRECISION <double> Exp(CHV4DPRECISION <double> x, size_t iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}
}
