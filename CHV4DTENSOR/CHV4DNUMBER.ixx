module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DNUMBER;

export namespace Algebra
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

		inline float operator ^(CHV4DFLOAT const p) { return Algebra::fPower{ data[0], p() }(); }

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

		inline float operator ()(float sigFigs) const 
		{
			uint64_t iValue = static_cast<uint64_t>(data[0] * sigFigs);

			float fValue = static_cast<float>(iValue);

			fValue = fValue / sigFigs;

			return fValue;

		}

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

		inline double operator ^(CHV4DDOUBLE const p) { return Algebra::dPower{ data[0], p() }(); }

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

		inline double operator ()(double const sigFigs) const
		{
			uint64_t iValue = static_cast<uint64_t>(data[0] * sigFigs);

			double fValue = static_cast<double>(iValue);

			fValue = fValue / sigFigs;

			return fValue;

		}

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
		CHV4DFLOAT const operator ~() { return static_cast<float>(Algebra::Length(data[0](), data[1]())); }

		CHV4DDOUBLE const operator !() { return Algebra::Length(data[0](), data[1]()); }

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
		CHV4DFLOAT const operator ~() { return static_cast<float>(Algebra::Length(data[0](), data[1](), data[3]())); }

		CHV4DDOUBLE const operator !() { return Algebra::Length(data[0](), data[1](), data[3]()); }

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
		CHV4DFLOAT const operator ~() { return static_cast<float>(Algebra::Length(data[0](), data[1](), data[3](), data[4]())); }

		CHV4DDOUBLE const operator !() { return Algebra::Length(data[0](), data[1](), data[3](), data[4]()); }

		inline CHV4DFLOAT& operator [](size_t const& i) { return data[i]; }

		inline CHV4DFLOAT const A() const { return data[0]; }

		inline CHV4DFLOAT const B() const { return data[1]; }

		inline CHV4DFLOAT const C() const { return data[2]; }

		inline CHV4DFLOAT const D() const { return data[3]; }

	private:
		CHV4DFLOAT data[4];

	};

	CHV4DFLOAT Absolute(CHV4DFLOAT x) { return x < 0 ? x() * -1.0 : x; }

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
		Root(CHV4DDOUBLE const x, size_t const p, CHV4DFLOAT const epsilon = 0.0000000001)
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

			while (Absolute( CHV4DDOUBLE{ iPow{ ret, pow }()() - var() } ) > eps)
			{
				root = ret;

				ret = root - ((iPow{ root, pow }()() - var()) / (pow * iPow(root, pow - 1)()));

			}

			return ret;

		}

	private:
		CHV4DDOUBLE var{};

		size_t pow{};

		CHV4DDOUBLE eps{};

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

	Matrix::CHV4DFLOAT const Ln(Matrix::CHV4DFLOAT x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<float>::infinity();

		Matrix::CHV4DFLOAT inPlace = x() - 1.0f;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = Algebra::iPow{ size_t{ 2 }, k }(0);

			float root = static_cast<float>(Algebra::Root{ x(), p2k }());

			inPlace *= (2.0f / (1.0f + root));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	Matrix::CHV4DDOUBLE const Ln(Matrix::CHV4DDOUBLE x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<double>::infinity();

		Matrix::CHV4DDOUBLE inPlace = x() - 1.0;

		//std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = Algebra::iPow{ size_t{ 2 }, k }(0);

			double root = Algebra::Root{ x(), p2k }();

			inPlace *= (2.0 / (1.0 + root));

			//std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	Matrix::CHV4DFLOAT const Log(Matrix::CHV4DFLOAT b, Matrix::CHV4DFLOAT x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		Matrix::CHV4DFLOAT Algebra{ b }, var{ x };

		Matrix::CHV4DFLOAT inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	Matrix::CHV4DDOUBLE const Log(Matrix::CHV4DDOUBLE b, Matrix::CHV4DDOUBLE x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<double>::infinity();

		Matrix::CHV4DDOUBLE Algebra{ b }, var{ x };

		Matrix::CHV4DDOUBLE inPlace = Ln(Algebra, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	Matrix::CHV4DDOUBLE const Gamma(Matrix::CHV4DDOUBLE x, size_t iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	Matrix::CHV4DDOUBLE Exp(Matrix::CHV4DDOUBLE x, size_t iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}

}