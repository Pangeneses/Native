module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DCMATH;

import :CHV4DPRECISION;

export namespace CHV4DMATH
{
	float iIPow(int64_t const& var, size_t const& pow);
	float fIPow(float const& var, size_t const& pow);
	double dIPow(double const& var, size_t const& pow);
	long double ldIPow(long double const& var, size_t const& pow);

	float fRoot(float const& var, size_t const& pow);
	double dRoot(double const& var, size_t const& pow);
	long double ldRoot(long double const& var, size_t const& pow);

	void fPowToFrac(float const& p, uint64_t& a, uint64_t& b);
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

}