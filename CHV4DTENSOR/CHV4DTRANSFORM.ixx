module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DTRANSFORM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMATRIX;

export namespace CHV4DTENSOR
{
	/*
	CHV4DFLOAT3 const Mul(CHV4DFLOAT3 vector, CHV4DFLOAT3X3 transform)
	{
		CHV4DFLOAT3 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] }
		};

		return result;

	}

	CHV4DFLOAT4 const Mul(CHV4DFLOAT4 vector, CHV4DFLOAT4X4 transform)
	{
		CHV4DFLOAT4 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] + vector[3] * transform[0][3] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] + vector[3] * transform[1][3] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] + vector[3] * transform[2][3] },
			{ vector[0] * transform[3][0] + vector[1] * transform[3][1] + vector[2] * transform[3][2] + vector[3] * transform[3][3] }
		};

		return result;

	}

	CHV4DFLOAT3X3 const MatrixMul3X3(CHV4DFLOAT3X3 A, CHV4DFLOAT3X3 B)
	{
		return CHV4DFLOAT3X3{
			CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()()
			},
			CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()(),
			},
			CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()(),
			}

		};

	}

	CHV4DFLOAT4X4 const MatrixMul4X4(CHV4DFLOAT4X4 A, CHV4DFLOAT4X4 B)
	{
		return CHV4DFLOAT4X4{
			CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()() + A.ROW4().A()() * B.ROW1().D()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()() + A.ROW4().B()() * B.ROW1().D()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()() + A.ROW4().C()() * B.ROW1().D()(),
				A.ROW1().D()() * B.ROW1().A()() + A.ROW2().D()() * B.ROW1().B()() + A.ROW3().D()() * B.ROW1().C()() + A.ROW4().D()() * B.ROW1().D()()
			},
			CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()() + A.ROW4().A()() * B.ROW2().D()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()() + A.ROW4().B()() * B.ROW2().D()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()() + A.ROW4().C()() * B.ROW2().D()(),
				A.ROW1().D()() * B.ROW2().A()() + A.ROW2().D()() * B.ROW2().B()() + A.ROW3().D()() * B.ROW2().C()() + A.ROW4().D()() * B.ROW2().D()()
			},
			CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()() + A.ROW4().A()() * B.ROW3().D()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()() + A.ROW4().B()() * B.ROW3().D()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()() + A.ROW4().C()() * B.ROW3().D()(),
				A.ROW1().D()() * B.ROW3().A()() + A.ROW2().D()() * B.ROW3().B()() + A.ROW3().D()() * B.ROW3().C()() + A.ROW4().D()() * B.ROW3().D()()
			},
			CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW4().A()() + A.ROW2().A()() * B.ROW4().B()() + A.ROW3().A()() * B.ROW4().C()() + A.ROW4().A()() * B.ROW4().D()(),
				A.ROW1().B()() * B.ROW4().A()() + A.ROW2().B()() * B.ROW4().B()() + A.ROW3().B()() * B.ROW4().C()() + A.ROW4().B()() * B.ROW4().D()(),
				A.ROW1().C()() * B.ROW4().A()() + A.ROW2().C()() * B.ROW4().B()() + A.ROW3().C()() * B.ROW4().C()() + A.ROW4().C()() * B.ROW4().D()(),
				A.ROW1().D()() * B.ROW4().A()() + A.ROW2().D()() * B.ROW4().B()() + A.ROW3().D()() * B.ROW4().C()() + A.ROW4().D()() * B.ROW4().D()()
			}

		};

	}

	CHV4DFLOAT3 const RotateX(CHV4DFLOAT3 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT3X3 rotMatrixX{
			CHV4DFLOAT3{1.0f, 0.0f, 0.0f},
			CHV4DFLOAT3{0.0f, static_cast<float>(cos(deg())), static_cast<float>(-sin(deg()))},
			CHV4DFLOAT3{0.0f, static_cast<float>(sin(deg())), static_cast<float>(cos(deg()))}
		};

		return Mul(vector, rotMatrixX);

	}

	CHV4DFLOAT4 const RotateX(CHV4DFLOAT4 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT4X4 rotMatrixX{
			CHV4DFLOAT4{1.0f, 0.0f, 0.0f, 0.0f},
			CHV4DFLOAT4{0.0f, static_cast<float>(cos(deg())), static_cast<float>(-sin(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, static_cast<float>(sin(deg())), static_cast<float>(cos(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Mul(vector, rotMatrixX);

	}

	CHV4DFLOAT4X4 const RotMatrixX(CHV4DFLOAT deg)
	{
		return CHV4DFLOAT4X4{
			CHV4DFLOAT4{1.0f, 0.0f, 0.0f, 0.0f},
			CHV4DFLOAT4{0.0f, static_cast<float>(cos(deg())), static_cast<float>(-sin(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, static_cast<float>(sin(deg())), static_cast<float>(cos(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	CHV4DFLOAT3 const RotateY(CHV4DFLOAT3 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT3X3 rotMatrixY{
			CHV4DFLOAT3{static_cast<float>(cos(deg())), 0.0f, static_cast<float>(sin(deg()))},
			CHV4DFLOAT3{0.0f, 1.0f, 0.0f},
			CHV4DFLOAT3{static_cast<float>(-sin(deg())), 0.0f, static_cast<float>(cos(deg()))}
		};

		return Mul(vector, rotMatrixY);

	}

	CHV4DFLOAT4 const RotateY(CHV4DFLOAT4 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT4X4 rotMatrixY{
			CHV4DFLOAT4{static_cast<float>(cos(deg())), 0.0f, static_cast<float>(sin(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 1.0f, 0.0f, 0.0f},
			CHV4DFLOAT4{static_cast<float>(-sin(deg())), 0.0f, static_cast<float>(cos(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Mul(vector, rotMatrixY);

	}

	CHV4DFLOAT4X4 const RotMatrixY(CHV4DFLOAT deg)
	{
		return CHV4DFLOAT4X4{
			CHV4DFLOAT4{static_cast<float>(cos(deg())), 0.0f, static_cast<float>(sin(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 1.0f, 0.0f, 0.0f},
			CHV4DFLOAT4{static_cast<float>(-sin(deg())), 0.0f, static_cast<float>(cos(deg())), 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	CHV4DFLOAT3 const RotateZ(CHV4DFLOAT3 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT3X3 rotMatrixZ{
			CHV4DFLOAT3{static_cast<float>(cos(deg())), static_cast<float>(-sin(deg())), 0.0f},
			CHV4DFLOAT3{static_cast<float>(sin(deg())), static_cast<float>(cos(deg())), 0.0f},
			CHV4DFLOAT3{0.0f, 0.0f, 1.0f}
		};

		return Mul(vector, rotMatrixZ);

	}

	CHV4DFLOAT4 const RotateZ(CHV4DFLOAT4 vector, CHV4DFLOAT deg)
	{
		CHV4DFLOAT4X4 rotMatrixZ{
			CHV4DFLOAT4{static_cast<float>(cos(deg())), static_cast<float>(-sin(deg())), 0.0f, 0.0f},
			CHV4DFLOAT4{static_cast<float>(sin(deg())), static_cast<float>(cos(deg())), 0.0f, 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 1.0f, 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Mul(vector, rotMatrixZ);

	}

	CHV4DFLOAT4X4 const RotMatrixZ(CHV4DFLOAT deg)
	{
		return CHV4DFLOAT4X4{
			CHV4DFLOAT4{static_cast<float>(cos(deg())), static_cast<float>(-sin(deg())), 0.0f, 0.0f},
			CHV4DFLOAT4{static_cast<float>(sin(deg())), static_cast<float>(cos(deg())), 0.0f, 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 1.0f, 0.0f},
			CHV4DFLOAT4{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	CHV4DFLOAT4X4 const MatrixRotateWorld(CHV4DFLOAT4 deg)
	{
		CHV4DFLOAT4X4 World{ HV4DIDENTITY };

		CHV4DFLOAT4X4 X = RotMatrixX(deg.A());

		CHV4DFLOAT4X4 Y = RotMatrixY(deg.B());

		CHV4DFLOAT4X4 Z = RotMatrixZ(deg.C());

		World = MatrixMul4X4(X, Y);

		World = MatrixMul4X4(World, Z);

		return World;

	}

	CHV4DFLOAT4X4 const MatrixTranslationWorld(CHV4DFLOAT4X4 world, CHV4DFLOAT3 distance)
	{
		return CHV4DFLOAT4X4{
			{world.ROW1().A()(), world.ROW2().A()(), world.ROW3().A()(), world.ROW4().A()() + distance.A()()},
			{world.ROW1().B()(), world.ROW2().B()(), world.ROW3().B()(), world.ROW4().B()() + distance.B()()},
			{world.ROW1().C()(), world.ROW2().C()(), world.ROW3().C()(), world.ROW4().C()() + distance.C()()},
			{world.ROW1().D()(), world.ROW2().D()(), world.ROW3().D()(), world.ROW4().D()()}
		};

	}
	*/
}