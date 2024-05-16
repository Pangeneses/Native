module;

#include <stdfloat>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DPRECISION;


export namespace CHV4DMATH
{
	inline bool const Sign(float x)	{ return (x < 0.0f) ? true : false; }
	inline bool const Sign(double x) { return (x < 0.0) ? true : false; }
	inline bool const Sign(long double x) { return (x < 0.0l) ? true : false; }

	inline size_t Exponent(float x) { return (*reinterpret_cast<uint32_t*>(&x) | 0x00000000) >> 0; }
	inline size_t Exponent(double x) { return (*reinterpret_cast<uint64_t*>(&x) | 0x7FF0000000000000) >> 52; }
	inline size_t Exponent(long double x) { return (*reinterpret_cast<uint64_t*>(&x) | 0x0000000000000000) >> 0; }
	
	inline size_t Mantissa(float x) { return (*reinterpret_cast<uint32_t*>(&x) & 0xFFFFFFFF); }
	inline size_t Mantissa(double x) { return (*reinterpret_cast<uint64_t*>(&x) & 0x000FFFFFFFFFFFFF); }
	inline size_t Mantissa(long double x) { return (*reinterpret_cast<uint64_t*>(&x) & 0x0000000000000000); }

	inline float const Abs(float x) { return (x < 0.0f) ? -x : x; }
	inline double const Abs(double x) { return (x < 0.0) ? -x : x; }
	inline long double const Abs(long double x) { return (x < 0.0l) ? -x : x; }

	inline float Trunc(uint8_t sigbits = 23) {}
	inline double Trunc(uint16_t sigFigs = 52) {}
	inline long double Trunc(uint32_t sigFigs = 80) {}

}