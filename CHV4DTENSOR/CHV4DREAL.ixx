module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DREAL;

import :CHV4DCMATH;

export namespace CHV4DTENSOR
{
	class CHV4DFLOAT
	{
	public:
		CHV4DFLOAT() = default;

		CHV4DFLOAT(float const& e) { data[0] = e; }

		CHV4DFLOAT(CHV4DFLOAT const& e) { *this = e; }

	public:
		inline float operator ()() const { return data[0]; }

		inline float operator ()(float sigFigs) const
		{
			uint64_t iValue = static_cast<uint64_t>(data[0] * sigFigs);

			float fValue = static_cast<float>(iValue);

			fValue = fValue / sigFigs;

			return fValue;

		}

		inline void operator =(float const& e) { data[0] = e; }

		inline void operator =(CHV4DFLOAT const& e) { data[0] = e.data[0]; }

		inline void operator -=(float const& e) { data[0] = data[0] - e; }

		inline void operator -=(CHV4DFLOAT const& e) { data[0] = data[0] - e(); }

		inline void operator +=(float const& e) { data[0] = data[0] + e; }

		inline void operator +=(CHV4DFLOAT const& e) { data[0] = data[0] + e(); }

		inline void operator /=(float const& e) { data[0] = data[0] / e; }

		inline void operator /=(CHV4DFLOAT const& e) { data[0] = data[0] / e(); }

		inline void operator *=(float const& e) { data[0] = data[0] * e; }

		inline void operator *=(CHV4DFLOAT const& e) { data[0] = data[0] * e(); }

		inline float operator -(float const& e) { return data[0] - e; }

		inline float operator -(CHV4DFLOAT const& e) { return data[0] - e(); }

		inline float operator +(float const& e) { return data[0] + e; }

		inline float operator +(CHV4DFLOAT const& e) { return data[0] + e(); }

		inline float operator /(float const& e) { return data[0] / e; }

		inline float operator /(CHV4DFLOAT const& e) { return data[0] / e(); }

		inline float operator *(float const& e) { return data[0] * e; }

		inline float operator *(CHV4DFLOAT const& e) { return data[0] * e(); }

		inline float operator ^(CHV4DFLOAT const p) { return cFPower{ data[0], p() }(); }

		inline bool operator ==(float const& e) const { return data[0] == e; }

		inline bool operator ==(CHV4DFLOAT const& e) const { return  data[0] == e.data[0]; }

		inline bool operator !=(float const& e) const { return data[0] != e; }

		inline bool operator !=(CHV4DFLOAT const& e) const { return data[0] != e.data[0]; }

		inline bool operator <(float const& e) const { return data[0] < e; }

		inline bool operator <(CHV4DFLOAT const& e) const { return data[0] < e.data[0]; }

		inline bool operator <=(float const& e) const { return data[0] <= e; }

		inline bool operator <=(CHV4DFLOAT const& e) const { return data[0] <= e.data[0]; }

		inline bool operator >(float const& e) const { return data[0] > e; }

		inline bool operator >(CHV4DFLOAT const& e) const { return data[0] > e.data[0]; }

		inline bool operator >=(float const& e) const { return data[0] >= e; }

		inline bool operator >=(CHV4DFLOAT const& e) const { return data[0] >= e.data[0]; }

	private:
		float data[1];

	};

	class CHV4DDOUBLE
	{
	public:
		CHV4DDOUBLE() = default;

		CHV4DDOUBLE(double const& e) { data[0] = e; }

		CHV4DDOUBLE(CHV4DDOUBLE const& e) { *this = e; }

	public:
		inline double operator ()() const { return data[0]; }

		inline double operator ()(double const sigFigs) const
		{
			uint64_t iValue = static_cast<uint64_t>(data[0] * sigFigs);

			double fValue = static_cast<double>(iValue);

			fValue = fValue / sigFigs;

			return fValue;

		}

		inline void operator =(double const& e) { data[0] = e; }

		inline void operator =(CHV4DDOUBLE const& e) { data[0] = e.data[0]; }

		inline void operator -=(double const& e) { data[0] = data[0] - e; }

		inline void operator -=(CHV4DDOUBLE const& e) { data[0] = data[0] - e(); }

		inline void operator +=(double const& e) { data[0] = data[0] + e; }

		inline void operator +=(CHV4DDOUBLE const& e) { data[0] = data[0] + e(); }

		inline void operator /=(double const& e) { data[0] = data[0] / e; }

		inline void operator /=(CHV4DDOUBLE const& e) { data[0] = data[0] / e(); }

		inline void operator *=(double const& e) { data[0] = data[0] * e; }

		inline void operator *=(CHV4DDOUBLE const& e) { data[0] = data[0] * e(); }

		inline double operator -(double const& e) { return data[0] - e; }

		inline double operator -(CHV4DDOUBLE const& e) { return data[0] - e(); }

		inline double operator +(double const& e) { return data[0] + e; }

		inline double operator +(CHV4DDOUBLE const& e) { return data[0] + e(); }

		inline double operator /(double const& e) { return data[0] / e; }

		inline double operator /(CHV4DDOUBLE const& e) { return data[0] / e(); }

		inline double operator *(double const& e) { return data[0] * e; }

		inline double operator *(CHV4DDOUBLE const& e) { return data[0] * e(); }

		inline double operator ^(double const e) { return cDPower{ data[0], e }(); }

		inline double operator ^(CHV4DDOUBLE const& e) { return cDPower{ data[0], e() }(); }

		inline bool operator ==(double const& e) const { return data[0] == e; }

		inline bool operator ==(CHV4DDOUBLE const& e) const { return  data[0] == e.data[0]; }

		inline bool operator !=(double const& e) const { return data[0] != e; }

		inline bool operator !=(CHV4DDOUBLE const& e) const { return data[0] != e.data[0]; }

		inline bool operator <(double const& e) const { return data[0] < e; }

		inline bool operator <(CHV4DDOUBLE const& e) const { return data[0] < e.data[0]; }

		inline bool operator <=(double const& e) const { return data[0] <= e; }

		inline bool operator <=(CHV4DDOUBLE const& e) const { return data[0] <= e.data[0]; }

		inline bool operator >(double const& e) const { return data[0] > e; }

		inline bool operator >(CHV4DDOUBLE const& e) const { return data[0] > e.data[0]; }

		inline bool operator >=(double const& e) const { return data[0] >= e; }

		inline bool operator >=(CHV4DDOUBLE const& e) const { return data[0] >= e.data[0]; }

	private:
		double data[1];

	};

	class CHV4DLDOUBLE
	{
	public:
		CHV4DLDOUBLE() = default;

		CHV4DLDOUBLE(long double const& e) { data[0] = e; }

		CHV4DLDOUBLE(CHV4DLDOUBLE const& e) { *this = e; }

	public:
		inline long double operator ()() const { return data[0]; }

		inline long double operator ()(long double const sigFigs) const
		{
			uint64_t iValue = static_cast<uint64_t>(data[0] * sigFigs);

			long double fValue = static_cast<long double>(iValue);

			fValue = fValue / sigFigs;

			return fValue;

		}

		inline void operator =(long double const& e) { data[0] = e; }

		inline void operator =(CHV4DLDOUBLE const& e) { data[0] = e.data[0]; }

		inline void operator -=(long double const& e) { data[0] = data[0] - e; }

		inline void operator -=(CHV4DLDOUBLE const& e) { data[0] = data[0] - e(); }

		inline void operator +=(long double const& e) { data[0] = data[0] + e; }

		inline void operator +=(CHV4DLDOUBLE const& e) { data[0] = data[0] + e(); }

		inline void operator /=(long double const& e) { data[0] = data[0] / e; }

		inline void operator /=(CHV4DLDOUBLE const& e) { data[0] = data[0] / e(); }

		inline void operator *=(long double const& e) { data[0] = data[0] * e; }

		inline void operator *=(CHV4DLDOUBLE const& e) { data[0] = data[0] * e(); }

		inline long double operator -(long double const& e) { return data[0] - e; }

		inline long double operator -(CHV4DLDOUBLE const& e) { return data[0] - e(); }

		inline long double operator +(long double const& e) { return data[0] + e; }

		inline long double operator +(CHV4DLDOUBLE const& e) { return data[0] + e(); }

		inline long double operator /(long double const& e) { return data[0] / e; }

		inline long double operator /(CHV4DLDOUBLE const& e) { return data[0] / e(); }

		inline long double operator *(long double const& e) { return data[0] * e; }

		inline long double operator *(CHV4DLDOUBLE const& e) { return data[0] * e(); }

		inline long double operator ^(long double const e) { return cDPower{ data[0], e }(); }

		inline long double operator ^(CHV4DLDOUBLE const& e) { return cDPower{ data[0], e() }(); }

		inline bool operator ==(long double const& e) const { return data[0] == e; }

		inline bool operator ==(CHV4DLDOUBLE const& e) const { return  data[0] == e.data[0]; }

		inline bool operator !=(long double const& e) const { return data[0] != e; }

		inline bool operator !=(CHV4DLDOUBLE const& e) const { return data[0] != e.data[0]; }

		inline bool operator <(long double const& e) const { return data[0] < e; }

		inline bool operator <(CHV4DLDOUBLE const& e) const { return data[0] < e.data[0]; }

		inline bool operator <=(long double const& e) const { return data[0] <= e; }

		inline bool operator <=(CHV4DLDOUBLE const& e) const { return data[0] <= e.data[0]; }

		inline bool operator >(long double const& e) const { return data[0] > e; }

		inline bool operator >(CHV4DLDOUBLE const& e) const { return data[0] > e.data[0]; }

		inline bool operator >=(long double const& e) const { return data[0] >= e; }

		inline bool operator >=(CHV4DLDOUBLE const& e) const { return data[0] >= e.data[0]; }

	private:
		long double data[1];

	};

	class CHV4DFLOAT2
	{
	public:
		CHV4DFLOAT2() = default;

		CHV4DFLOAT2(CHV4DFLOAT x, CHV4DFLOAT y) { data[0] = x; data[1] = y; };

		CHV4DFLOAT2(CHV4DFLOAT2 const& e) { *this = e; }

	public:
		inline void operator =(CHV4DFLOAT2 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT2)); }

		inline bool operator ==(CHV4DFLOAT2 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT2)) == 0; }

		inline bool operator !=(CHV4DFLOAT2 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT2)) != 0; }

		inline CHV4DFLOAT2 const operator ()() const { return *this; }

	public:
		CHV4DFLOAT const operator ~() { return static_cast<float>(cLength(data[0](), data[1]())); }

		CHV4DLDOUBLE const operator !() { return cLength(data[0](), data[1]()); }

		inline CHV4DFLOAT& operator [](size_t const& i) { return data[i]; }

		inline CHV4DFLOAT const A() { return data[0]; }

		inline CHV4DFLOAT const B() { return data[1]; }

	private:
		CHV4DFLOAT data[2];

	};

	class CHV4DFLOAT3
	{
	public:
		CHV4DFLOAT3() = default;

		CHV4DFLOAT3(CHV4DFLOAT x, CHV4DFLOAT y, CHV4DFLOAT z)
		{
			data[0] = x; data[1] = y; data[2] = z;

		}

		CHV4DFLOAT3(CHV4DFLOAT3 const& e)
		{
			*this = e;

		}

	public:
		inline void operator =(CHV4DFLOAT3 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT3)); }

		inline bool operator ==(CHV4DFLOAT3 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT3)) != 0; }

		inline bool operator !=(CHV4DFLOAT3 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT3)) == 0; }

		inline CHV4DFLOAT3 operator ()() const { return CHV4DFLOAT3{ data[0], data[1], data[2] }; }

	public:
		CHV4DFLOAT const operator ~() { return static_cast<float>(cLength(data[0](), data[1](), data[3]())); }

		CHV4DDOUBLE const operator !() { return cLength(data[0](), data[1](), data[3]()); }

		inline CHV4DFLOAT& operator [](size_t const& i) { return data[i]; }

		inline CHV4DFLOAT const A() const { return data[0]; }

		inline CHV4DFLOAT const B() const { return data[1]; }

		inline CHV4DFLOAT const C() const { return data[2]; }

	private:
		CHV4DFLOAT data[3];

	};

	class CHV4DFLOAT4
	{
	public:
		CHV4DFLOAT4() = default;

		CHV4DFLOAT4(CHV4DFLOAT x, CHV4DFLOAT y, CHV4DFLOAT z, CHV4DFLOAT w)
		{
			data[0] = x; data[1] = y; data[2] = z; data[3] = w;

		}

		CHV4DFLOAT4(CHV4DFLOAT4 const& e)
		{
			*this = e;

		}

	public:
		inline void operator =(CHV4DFLOAT4 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT4)); }

		inline bool operator ==(CHV4DFLOAT4 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT4)) != 0; }

		inline bool operator !=(CHV4DFLOAT4 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT4)) == 0; }

		inline CHV4DFLOAT4 operator ()() const { return CHV4DFLOAT4{ data[0], data[1], data[2], data[4] }; }

	public:
		CHV4DFLOAT const operator ~() { return static_cast<float>(cLength(data[0](), data[1](), data[3](), data[4]())); }

		CHV4DDOUBLE const operator !() { return cLength(data[0](), data[1](), data[3](), data[4]()); }

		inline CHV4DFLOAT& operator [](size_t const& i) { return data[i]; }

		inline CHV4DFLOAT const A() const { return data[0]; }

		inline CHV4DFLOAT const B() const { return data[1]; }

		inline CHV4DFLOAT const C() const { return data[2]; }

		inline CHV4DFLOAT const D() const { return data[3]; }

	private:
		CHV4DFLOAT data[4];

	};

}