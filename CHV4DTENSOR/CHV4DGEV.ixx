module;

#include <stdexcept>

#include <string>
#include <vector>

export module CHV4DTENSOR:CHV4DGEV;

import :CHV4DCALC;

namespace Base = Calc;

export namespace GeV
{
	class CHV4DFLOAT
	{
	public:
		CHV4DFLOAT() = default;

		CHV4DFLOAT(float const& e) { data[0] = e; }

		CHV4DFLOAT(CHV4DFLOAT const& e) { *this = e; }

	public:
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

		inline float operator ^(CHV4DFLOAT const p) { return Calc::fPower{ data[0], p() }(); }

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

		inline float operator ()() const { return data[0]; }

		inline float operator ()(float sigFigs) const { return Calc::Trunc(data[0], sigFigs); }

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

		inline double operator ^(CHV4DDOUBLE const p) { return Calc::dPower{ data[0], p() }(); }

		inline double operator -(double const& e) { return data[0] - e; }

		inline double operator -(CHV4DDOUBLE const& e) { return data[0] - e(); }

		inline double operator +(double const& e) { return data[0] + e; }

		inline double operator +(CHV4DDOUBLE const& e) { return data[0] + e(); }

		inline double operator /(double const& e) { return data[0] / e; }

		inline double operator /(CHV4DDOUBLE const& e) { return data[0] / e(); }

		inline double operator *(double const& e) { return data[0] * e; }

		inline double operator *(CHV4DDOUBLE const& e) { return data[0] * e(); }

		inline double operator ^(CHV4DDOUBLE const& e) { return data[0] * e(); }

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

		inline double operator ()() const { return data[0]; }

		inline double operator ()(double const sigFigs) const { return Calc::Trunc(data[0], sigFigs); }

	private:
		double data[1];

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
		CHV4DFLOAT const operator ~() { return static_cast<float>(Calc::Length(data[0](), data[1]())); }

		CHV4DDOUBLE const operator !() { return Calc::Length(data[0](), data[1]()); }

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

		inline CHV4DFLOAT3 operator ()() const {	return CHV4DFLOAT3{ data[0], data[1], data[2] }; }

	public:
		CHV4DFLOAT const operator ~() { return static_cast<float>(Calc::Length(data[0](), data[1](), data[3]())); }

		CHV4DDOUBLE const operator !() { return Calc::Length(data[0](), data[1](), data[3]()); }

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
		CHV4DFLOAT const operator ~() { return static_cast<float>(Calc::Length(data[0](), data[1](), data[3](), data[4]())); }

		CHV4DDOUBLE const operator !() { return Calc::Length(data[0](), data[1](), data[3](), data[4]()); }

		inline CHV4DFLOAT& operator [](size_t const& i) { return data[i]; }

		inline CHV4DFLOAT const A() const { return data[0]; }

		inline CHV4DFLOAT const B() const { return data[1]; }

		inline CHV4DFLOAT const C() const { return data[2]; }

		inline CHV4DFLOAT const D() const { return data[3]; }

	private:
		CHV4DFLOAT data[4];

	};

	class CHV4DFLOAT2X2
	{
	public:
		CHV4DFLOAT2X2() = default;

		CHV4DFLOAT2X2(CHV4DFLOAT2 rowA, CHV4DFLOAT2 rowB)
		{
			data[0][0] = rowA[0]; data[0][1] = rowA[1]; data[1][0] = rowB[0]; data[1][1] = rowB[1];

		}

		CHV4DFLOAT2X2(CHV4DFLOAT2X2 const& e) { *this = e; }

	public:
		inline void operator =(CHV4DFLOAT2X2 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT2X2)); }

		inline bool operator ==(CHV4DFLOAT2X2 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT2X2)) != 0; }

		inline bool operator !=(CHV4DFLOAT2X2 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT2X2)) == 0; }

		inline CHV4DFLOAT2X2 const operator ()() const { return *this; }
		
	public:
		inline CHV4DFLOAT2& operator [](size_t i) { return *(CHV4DFLOAT2*)&data[i][0]; }

		inline CHV4DFLOAT2 const ROW1() const { return CHV4DFLOAT2{data[0][0], data[0][1]}; }

		inline CHV4DFLOAT2 const ROW2() const { return CHV4DFLOAT2{data[1][0], data[1][1]}; }

	private:
		CHV4DFLOAT data[2][2];

	};

	class CHV4DFLOAT3X3
	{
	public:
		CHV4DFLOAT3X3() = default;

		CHV4DFLOAT3X3(CHV4DFLOAT3 rowA, CHV4DFLOAT3 rowB, CHV4DFLOAT3 rowC)
		{
			data[0][0] = rowA[0]; data[0][1] = rowA[1]; data[0][2] = rowA[2];
			data[1][0] = rowB[0]; data[1][1] = rowB[1]; data[1][2] = rowB[2];
			data[2][0] = rowC[0]; data[2][1] = rowC[1]; data[2][2] = rowC[2];
		}

		CHV4DFLOAT3X3(CHV4DFLOAT3X3 const& e) { *this = e; }

	public:
		inline void operator =(CHV4DFLOAT3X3 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT3X3)); }

		inline bool operator ==(CHV4DFLOAT3X3 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT3X3)) != 0; }

		inline bool operator !=(CHV4DFLOAT3X3 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT3X3)) == 0; }

		inline CHV4DFLOAT3X3 const operator ()() const { return *this; }

	public:
		inline CHV4DFLOAT3& operator [](size_t const& i) { return *(CHV4DFLOAT3*)&data[i][0]; }
						   
		inline CHV4DFLOAT3 const ROW1() const { return CHV4DFLOAT3{ data[0][0], data[0][1], data[0][2] }; }
						   
		inline CHV4DFLOAT3 const ROW2() const { return CHV4DFLOAT3{ data[1][0], data[1][1], data[1][2] }; }
						   
		inline CHV4DFLOAT3 const ROW3() const { return CHV4DFLOAT3{ data[2][0], data[2][1], data[2][2] }; }

	private:
		CHV4DFLOAT data[3][3];

	};

	class CHV4DFLOAT4X4
	{
	public:
		CHV4DFLOAT4X4() = default;

		CHV4DFLOAT4X4(CHV4DFLOAT4 rowA, CHV4DFLOAT4 rowB, CHV4DFLOAT4 rowC, CHV4DFLOAT4 rowD)
		{
			data[0][0] = rowA[0]; data[0][1] = rowA[1]; data[0][2] = rowA[2]; data[0][3] = rowA[3];
			data[1][0] = rowB[0]; data[1][1] = rowB[1]; data[1][2] = rowB[2]; data[1][3] = rowB[3];
			data[2][0] = rowC[0]; data[2][1] = rowC[1]; data[2][2] = rowC[2]; data[2][3] = rowC[3];
			data[3][0] = rowD[0]; data[3][1] = rowD[1]; data[3][2] = rowD[2]; data[3][3] = rowD[3];
		}

		CHV4DFLOAT4X4(CHV4DFLOAT4X4 const& e) { *this = e; }

	public:
		inline void operator =(CHV4DFLOAT4X4 const& e) { memcpy(this, &e, sizeof(CHV4DFLOAT4X4)); }

		inline bool operator ==(CHV4DFLOAT4X4 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT4X4)) != 0; }

		inline bool operator !=(CHV4DFLOAT4X4 const& e) const { return memcmp(data, e.data, sizeof(CHV4DFLOAT4X4)) == 0; }

		inline CHV4DFLOAT4X4 const operator ()() const { return *this; }

	public:
		inline CHV4DFLOAT4& operator [](size_t const& i) { return *(CHV4DFLOAT4*)&data[i][0]; }

		inline CHV4DFLOAT4 const ROW1() const { return CHV4DFLOAT4{ data[0][0], data[0][1], data[0][2], data[0][3] }; }

		inline CHV4DFLOAT4 const ROW2() const { return CHV4DFLOAT4{ data[1][0], data[1][1], data[1][2], data[1][3] }; }

		inline CHV4DFLOAT4 const ROW3() const { return CHV4DFLOAT4{ data[2][0], data[2][1], data[2][2], data[2][3] }; }

		inline CHV4DFLOAT4 const ROW4() const { return CHV4DFLOAT4{ data[3][0], data[3][1], data[3][2], data[3][3] }; }

	private:
		CHV4DFLOAT data[4][4];

	};

}
