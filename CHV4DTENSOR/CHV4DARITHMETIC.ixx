module;

#include <vector>

#include <compare>

#include <optional>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DARITHMETIC;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMANTISSA;
import :CHV4DZINTEGER;
import :CHV4DPRECISION;

export namespace CHV4DTENSOR
{ 
	template<ASSERT_CHV4DZINTEGER T = CHV4DZINTEGER<size_t>>
	std::optional<T> ZPositivePower(T const& base, T const& pow)
	{
		T A{ base }, B{ pow }, Q{ 1 };

		if (B <= 0ui8) return {};

		if (A == 0ui8)	return T { 0ui8 };

		while (B != 0ui8)
		{
			if ((B & 1ui8) == 1ui8)
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

			B >>= 1ui8;

			if (B != 0ui8)
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
			if ((pow & 1ui8) == 1ui8) Q.operator*(-1ui8);
		}

		return Q;		
	}

	template<ASSERT_CHV4DZINTEGER T = CHV4DZINTEGER<size_t>>
	T ZCyclic(T const& z, T const& n)
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

		if (Q == 0) return CHV4DMANTISSA < double > { A / B }.Integer();

		else return 0ui8;
	};
	/*
	template<ASSERT_CHV4DZINTEGER T = CHV4DZINTEGER<size_t>>
	void AsFraction(CHV4DPRECISION < double > const& precision, T& a, T& b)
	{
		CHV4DMANTISSA < double > P{ precision };

		CHV4DZINTEGER<size_t> W = P.Floor();

		CHV4DMANTISSA < double > D = P() - P.Floor();

		CHV4DZINTEGER<size_t> A{ D.Mantissa() | 0x0008000000000000 }, B{ 0x000FFFFFFFFFFFFF };

		while (B != static_cast<CHV4DZINTEGER<size_t>>(0)) 
		{ 
			CHV4DZINTEGER<size_t> Q;

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

	template <ASSERT_CHV4DZINTEGER T = CHV4DZINTEGER<size_t>>
	T ZPositiveWholeRoot(T const& a, T const& b)
	{
		CHV4DZINTEGER<size_t> A{ a }, B{ b }, BitPos{ 2ui64 }, Mask{ 1ui64 }, Mod{ 0ui64 }, N{ 0ui64 };

		CHV4DMANTISSA < double > Q{ 0.0 };

		std::vector<size_t> factors;

		factors.push_back(0ui64);

		for (size_t i = 62ui64; i >= 1ui64; --i)
		{
			while (A & Mask == 0 && A & BitPos == 1)
			{
				try
				{
					Q = A / BitPos;
				}
				catch (std::runtime_error error)
				{
					throw error;
				}

				A = Q.

				A -= Mod;

				N = ZCyclic(A, BitPos);

				*std::prev(factors.end(), 1ui64) = N;

				A = Mod;
			}

			if (A == 0ui64) break;

			BitPos <<= 1ui64;

			Mask <<= 1ui64;

			Mask |= 1ui64;

			factors.push_back(0);
		}

		for (size_t i = 0; i < factors.size(); ++i)
		{
			if (factor[i] % B != 0) return 0;

			else factor[i] /= B;
		}
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
			CHV4DZINTEGER<uint64_t> p2k = PositivePower(CHV4DZINTEGER<size_t>{ 2 }, CHV4DZINTEGER<size_t>{ k });

			CHV4DPRECISION <float> root = static_cast<float>(IsCyclic(CHV4DZINTEGER<size_t>{ x() }, CHV4DZINTEGER<size_t>{ p2k })());

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
			CHV4DZINTEGER<size_t> p2k = PositivePower(CHV4DZINTEGER<size_t>{ 2 }, CHV4DZINTEGER<size_t>{ k });

			CHV4DPRECISION <double> root = static_cast<double>(IsCyclic(CHV4DZINTEGER<size_t>{ x() }, CHV4DZINTEGER<size_t>{ p2k })());

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
	*/
}
