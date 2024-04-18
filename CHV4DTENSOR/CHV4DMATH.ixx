module;

#include <stdexcept>

#include <string>
#include <vector>

#include <cmath>

#include <iostream>

export module CHV4DTENSOR:CHV4DMATH;

import :CHV4DCALC;
import :CHV4DGEV;

export namespace Math
{
	const GeV::CHV4DFLOAT4X4 HV4DIDENTITY{
		  GeV::CHV4DFLOAT4{ 1.0f, 0.0f, 0.0f, 0.0f },
		  GeV::CHV4DFLOAT4{ 0.0f, 1.0f, 0.0f, 0.0f },
		  GeV::CHV4DFLOAT4{ 0.0f, 0.0f, 1.0f, 0.0f },
		  GeV::CHV4DFLOAT4{ 0.0f, 0.0f, 0.0f, 1.0f } };

	GeV::CHV4DFLOAT3 const Mul(GeV::CHV4DFLOAT3 vector, GeV::CHV4DFLOAT3X3 transform)
	{
		GeV::CHV4DFLOAT3 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] }
		};

		return result;

	}

	GeV::CHV4DFLOAT4 const Mul(GeV::CHV4DFLOAT4 vector, GeV::CHV4DFLOAT4X4 transform)
	{
		GeV::CHV4DFLOAT4 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] + vector[3] * transform[0][3] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] + vector[3] * transform[1][3] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] + vector[3] * transform[2][3] },
			{ vector[0] * transform[3][0] + vector[1] * transform[3][1] + vector[2] * transform[3][2] + vector[3] * transform[3][3] }
		};

		return result;

	}

	GeV::CHV4DFLOAT3X3 const MatrixMul3X3(GeV::CHV4DFLOAT3X3 A, GeV::CHV4DFLOAT3X3 B)
	{
		return GeV::CHV4DFLOAT3X3{
			GeV::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()()
			},
			GeV::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()(),
			},
			GeV::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()(),
			}

		};

	}
	
	GeV::CHV4DFLOAT4X4 const MatrixMul4X4(GeV::CHV4DFLOAT4X4 A, GeV::CHV4DFLOAT4X4 B)
	{
		return GeV::CHV4DFLOAT4X4{
			GeV::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()() + A.ROW4().A()() * B.ROW1().D()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()() + A.ROW4().B()() * B.ROW1().D()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()() + A.ROW4().C()() * B.ROW1().D()(),
				A.ROW1().D()() * B.ROW1().A()() + A.ROW2().D()() * B.ROW1().B()() + A.ROW3().D()() * B.ROW1().C()() + A.ROW4().D()() * B.ROW1().D()()
			},
			GeV::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()() + A.ROW4().A()() * B.ROW2().D()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()() + A.ROW4().B()() * B.ROW2().D()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()() + A.ROW4().C()() * B.ROW2().D()(),
				A.ROW1().D()() * B.ROW2().A()() + A.ROW2().D()() * B.ROW2().B()() + A.ROW3().D()() * B.ROW2().C()() + A.ROW4().D()() * B.ROW2().D()()
			},
			GeV::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()() + A.ROW4().A()() * B.ROW3().D()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()() + A.ROW4().B()() * B.ROW3().D()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()() + A.ROW4().C()() * B.ROW3().D()(),
				A.ROW1().D()() * B.ROW3().A()() + A.ROW2().D()() * B.ROW3().B()() + A.ROW3().D()() * B.ROW3().C()() + A.ROW4().D()() * B.ROW3().D()()
			},
			GeV::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW4().A()() + A.ROW2().A()() * B.ROW4().B()() + A.ROW3().A()() * B.ROW4().C()() + A.ROW4().A()() * B.ROW4().D()(),
				A.ROW1().B()() * B.ROW4().A()() + A.ROW2().B()() * B.ROW4().B()() + A.ROW3().B()() * B.ROW4().C()() + A.ROW4().B()() * B.ROW4().D()(),
				A.ROW1().C()() * B.ROW4().A()() + A.ROW2().C()() * B.ROW4().B()() + A.ROW3().C()() * B.ROW4().C()() + A.ROW4().C()() * B.ROW4().D()(),
				A.ROW1().D()() * B.ROW4().A()() + A.ROW2().D()() * B.ROW4().B()() + A.ROW3().D()() * B.ROW4().C()() + A.ROW4().D()() * B.ROW4().D()()
			}

		};

	}
	
	GeV::CHV4DFLOAT3 const RotateX(GeV::CHV4DFLOAT3 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT3X3 rotMatrixX{
			{1.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg())},
			{0.0f, sin(deg()), cos(deg())}
		};

		return Math::Mul(vector, rotMatrixX);

	}

	GeV::CHV4DFLOAT4 const RotateX(GeV::CHV4DFLOAT4 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT4X4 rotMatrixX{
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg()), 0.0f},
			{0.0f, sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Math::Mul(vector, rotMatrixX);

	}

	GeV::CHV4DFLOAT4X4 const RotMatrixX(GeV::CHV4DFLOAT deg)
	{
		return GeV::CHV4DFLOAT4X4 {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg()), 0.0f},
			{0.0f, sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	GeV::CHV4DFLOAT3 const RotateY(GeV::CHV4DFLOAT3 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT3X3 rotMatrixY{
			{cos(deg()), 0.0f, sin(deg())},
			{0.0f, 1.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg())}
		};

		return Math::Mul(vector, rotMatrixY);

	}

	GeV::CHV4DFLOAT4 const RotateY(GeV::CHV4DFLOAT4 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT4X4 rotMatrixY{
			{cos(deg()), 0.0f, sin(deg()), 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Math::Mul(vector, rotMatrixY);

	}

	GeV::CHV4DFLOAT4X4 const RotMatrixY(GeV::CHV4DFLOAT deg)
	{
		return GeV::CHV4DFLOAT4X4 {
			{cos(deg()), 0.0f, sin(deg()), 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	GeV::CHV4DFLOAT3 const RotateZ(GeV::CHV4DFLOAT3 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT3X3 rotMatrixZ{
			{cos(deg()), -sin(deg()), 0.0f},
			{sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 1.0f}
		};

		return Math::Mul(vector, rotMatrixZ);

	}

	GeV::CHV4DFLOAT4 const RotateZ(GeV::CHV4DFLOAT4 vector, GeV::CHV4DFLOAT deg)
	{
		GeV::CHV4DFLOAT4X4 rotMatrixZ{
			{cos(deg()), -sin(deg()), 0.0f, 0.0f},
			{sin(deg()), cos(deg()), 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Math::Mul(vector, rotMatrixZ);

	}

	GeV::CHV4DFLOAT4X4 const RotMatrixZ(GeV::CHV4DFLOAT deg)
	{
		return GeV::CHV4DFLOAT4X4 {
			{cos(deg()), -sin(deg()), 0.0f, 0.0f},
			{sin(deg()), cos(deg()), 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	GeV::CHV4DFLOAT4X4 const MatrixRotateWorld(GeV::CHV4DFLOAT4 deg)
	{
		GeV::CHV4DFLOAT4X4 World{ Math::HV4DIDENTITY };

		GeV::CHV4DFLOAT4X4 X = RotMatrixX(deg.A());

		GeV::CHV4DFLOAT4X4 Y = RotMatrixY(deg.B());

		GeV::CHV4DFLOAT4X4 Z = RotMatrixZ(deg.C());

		World = MatrixMul4X4(X, Y);

		World = MatrixMul4X4(World, Z);

		return World;

	}

	GeV::CHV4DFLOAT4X4 const MatrixTranslationWorld(GeV::CHV4DFLOAT4X4 world, GeV::CHV4DFLOAT3 distance)
	{
		return GeV::CHV4DFLOAT4X4{
			{world.ROW1().A()(), world.ROW2().A()(), world.ROW3().A()(), world.ROW4().A()() + distance.A()()},
			{world.ROW1().B()(), world.ROW2().B()(), world.ROW3().B()(), world.ROW4().B()() + distance.B()()},
			{world.ROW1().C()(), world.ROW2().C()(), world.ROW3().C()(), world.ROW4().C()() + distance.C()()},
			{world.ROW1().D()(), world.ROW2().D()(), world.ROW3().D()(), world.ROW4().D()()}
		};

	}

	GeV::CHV4DFLOAT const Ln(GeV::CHV4DFLOAT x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<float>::infinity();

		GeV::CHV4DFLOAT inPlace = x() - 1.0f;

		std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = Calc::iPow{ size_t{ 2 }, k }(0);

			float root = static_cast<float>(Calc::Root{ x(), p2k }());

			inPlace *= (2.0f / (1.0f + root));

			std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	GeV::CHV4DDOUBLE const Ln(GeV::CHV4DDOUBLE x, size_t iterations = 20)
	{
		if (x <= 0.0f) return -std::numeric_limits<double>::infinity();

		GeV::CHV4DDOUBLE inPlace = x() - 1.0;

		std::cout << "var: " << inPlace() << std::endl;

		for (size_t k = 1; k < iterations; k++)
		{
			size_t p2k = Calc::iPow{ size_t{ 2 }, k }(0);

			double root = Calc::Root{ x(), p2k }();

			inPlace *= (2.0 / (1.0 + root));

			std::cout << "var: " << inPlace() << " n-th root: " << p2k << " root: " << "\n";

		}

		return inPlace;

	}

	GeV::CHV4DFLOAT const Log(GeV::CHV4DFLOAT b, GeV::CHV4DFLOAT x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<float>::infinity();

		GeV::CHV4DFLOAT Calc{ b }, var{ x };

		GeV::CHV4DFLOAT inPlace = Ln(Calc, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	GeV::CHV4DDOUBLE const Log(GeV::CHV4DDOUBLE b, GeV::CHV4DDOUBLE x, size_t iterations = 50)
	{
		if (x <= 0.0f || b <= 0.0f) return -std::numeric_limits<double>::infinity();

		GeV::CHV4DDOUBLE Calc{ b }, var{ x };

		GeV::CHV4DDOUBLE inPlace = Ln(Calc, iterations)() / Ln(var, iterations)();

		return inPlace;

	}

	GeV::CHV4DDOUBLE const Gamma(GeV::CHV4DDOUBLE x, size_t iterations = 50)
	{
		return x * static_cast<double>(iterations);

	}

	GeV::CHV4DDOUBLE Exp(GeV::CHV4DDOUBLE x, size_t iterations = 10)
	{
		return x * static_cast<double>(iterations);

	}

}