module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DTRANSFORM;

import :CHV4DNUMBER;
import :CHV4DMATRIX;

export namespace Matrix
{
	Matrix::CHV4DFLOAT3 const Mul(Matrix::CHV4DFLOAT3 vector, Matrix::CHV4DFLOAT3X3 transform)
	{
		Matrix::CHV4DFLOAT3 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] }
		};

		return result;

	}

	Matrix::CHV4DFLOAT4 const Mul(Matrix::CHV4DFLOAT4 vector, Matrix::CHV4DFLOAT4X4 transform)
	{
		Matrix::CHV4DFLOAT4 result{};

		result = {
			{ vector[0] * transform[0][0] + vector[1] * transform[0][1] + vector[2] * transform[0][2] + vector[3] * transform[0][3] },
			{ vector[0] * transform[1][0] + vector[1] * transform[1][1] + vector[2] * transform[1][2] + vector[3] * transform[1][3] },
			{ vector[0] * transform[2][0] + vector[1] * transform[2][1] + vector[2] * transform[2][2] + vector[3] * transform[2][3] },
			{ vector[0] * transform[3][0] + vector[1] * transform[3][1] + vector[2] * transform[3][2] + vector[3] * transform[3][3] }
		};

		return result;

	}

	Matrix::CHV4DFLOAT3X3 const MatrixMul3X3(Matrix::CHV4DFLOAT3X3 A, Matrix::CHV4DFLOAT3X3 B)
	{
		return Matrix::CHV4DFLOAT3X3{
			Matrix::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()()
			},
			Matrix::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()(),
			},
			Matrix::CHV4DFLOAT3{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()(),
			}

		};

	}
	
	Matrix::CHV4DFLOAT4X4 const MatrixMul4X4(Matrix::CHV4DFLOAT4X4 A, Matrix::CHV4DFLOAT4X4 B)
	{
		return Matrix::CHV4DFLOAT4X4{
			Matrix::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW1().A()() + A.ROW2().A()() * B.ROW1().B()() + A.ROW3().A()() * B.ROW1().C()() + A.ROW4().A()() * B.ROW1().D()(),
				A.ROW1().B()() * B.ROW1().A()() + A.ROW2().B()() * B.ROW1().B()() + A.ROW3().B()() * B.ROW1().C()() + A.ROW4().B()() * B.ROW1().D()(),
				A.ROW1().C()() * B.ROW1().A()() + A.ROW2().C()() * B.ROW1().B()() + A.ROW3().C()() * B.ROW1().C()() + A.ROW4().C()() * B.ROW1().D()(),
				A.ROW1().D()() * B.ROW1().A()() + A.ROW2().D()() * B.ROW1().B()() + A.ROW3().D()() * B.ROW1().C()() + A.ROW4().D()() * B.ROW1().D()()
			},
			Matrix::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW2().A()() + A.ROW2().A()() * B.ROW2().B()() + A.ROW3().A()() * B.ROW2().C()() + A.ROW4().A()() * B.ROW2().D()(),
				A.ROW1().B()() * B.ROW2().A()() + A.ROW2().B()() * B.ROW2().B()() + A.ROW3().B()() * B.ROW2().C()() + A.ROW4().B()() * B.ROW2().D()(),
				A.ROW1().C()() * B.ROW2().A()() + A.ROW2().C()() * B.ROW2().B()() + A.ROW3().C()() * B.ROW2().C()() + A.ROW4().C()() * B.ROW2().D()(),
				A.ROW1().D()() * B.ROW2().A()() + A.ROW2().D()() * B.ROW2().B()() + A.ROW3().D()() * B.ROW2().C()() + A.ROW4().D()() * B.ROW2().D()()
			},
			Matrix::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW3().A()() + A.ROW2().A()() * B.ROW3().B()() + A.ROW3().A()() * B.ROW3().C()() + A.ROW4().A()() * B.ROW3().D()(),
				A.ROW1().B()() * B.ROW3().A()() + A.ROW2().B()() * B.ROW3().B()() + A.ROW3().B()() * B.ROW3().C()() + A.ROW4().B()() * B.ROW3().D()(),
				A.ROW1().C()() * B.ROW3().A()() + A.ROW2().C()() * B.ROW3().B()() + A.ROW3().C()() * B.ROW3().C()() + A.ROW4().C()() * B.ROW3().D()(),
				A.ROW1().D()() * B.ROW3().A()() + A.ROW2().D()() * B.ROW3().B()() + A.ROW3().D()() * B.ROW3().C()() + A.ROW4().D()() * B.ROW3().D()()
			},
			Matrix::CHV4DFLOAT4{
				A.ROW1().A()() * B.ROW4().A()() + A.ROW2().A()() * B.ROW4().B()() + A.ROW3().A()() * B.ROW4().C()() + A.ROW4().A()() * B.ROW4().D()(),
				A.ROW1().B()() * B.ROW4().A()() + A.ROW2().B()() * B.ROW4().B()() + A.ROW3().B()() * B.ROW4().C()() + A.ROW4().B()() * B.ROW4().D()(),
				A.ROW1().C()() * B.ROW4().A()() + A.ROW2().C()() * B.ROW4().B()() + A.ROW3().C()() * B.ROW4().C()() + A.ROW4().C()() * B.ROW4().D()(),
				A.ROW1().D()() * B.ROW4().A()() + A.ROW2().D()() * B.ROW4().B()() + A.ROW3().D()() * B.ROW4().C()() + A.ROW4().D()() * B.ROW4().D()()
			}

		};

	}
	
	Matrix::CHV4DFLOAT3 const RotateX(Matrix::CHV4DFLOAT3 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT3X3 rotMatrixX{
			{1.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg())},
			{0.0f, sin(deg()), cos(deg())}
		};

		return Matrix::Mul(vector, rotMatrixX);

	}

	Matrix::CHV4DFLOAT4 const RotateX(Matrix::CHV4DFLOAT4 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT4X4 rotMatrixX{
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg()), 0.0f},
			{0.0f, sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Matrix::Mul(vector, rotMatrixX);

	}

	Matrix::CHV4DFLOAT4X4 const RotMatrixX(Matrix::CHV4DFLOAT deg)
	{
		return Matrix::CHV4DFLOAT4X4 {
			{1.0f, 0.0f, 0.0f, 0.0f},
			{0.0f, cos(deg()), -sin(deg()), 0.0f},
			{0.0f, sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	Matrix::CHV4DFLOAT3 const RotateY(Matrix::CHV4DFLOAT3 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT3X3 rotMatrixY{
			{cos(deg()), 0.0f, sin(deg())},
			{0.0f, 1.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg())}
		};

		return Matrix::Mul(vector, rotMatrixY);

	}

	Matrix::CHV4DFLOAT4 const RotateY(Matrix::CHV4DFLOAT4 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT4X4 rotMatrixY{
			{cos(deg()), 0.0f, sin(deg()), 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Matrix::Mul(vector, rotMatrixY);

	}

	Matrix::CHV4DFLOAT4X4 const RotMatrixY(Matrix::CHV4DFLOAT deg)
	{
		return Matrix::CHV4DFLOAT4X4 {
			{cos(deg()), 0.0f, sin(deg()), 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{-sin(deg()), 0.0f, cos(deg()), 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	Matrix::CHV4DFLOAT3 const RotateZ(Matrix::CHV4DFLOAT3 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT3X3 rotMatrixZ{
			{cos(deg()), -sin(deg()), 0.0f},
			{sin(deg()), cos(deg()), 0.0f},
			{0.0f, 0.0f, 1.0f}
		};

		return Matrix::Mul(vector, rotMatrixZ);

	}

	Matrix::CHV4DFLOAT4 const RotateZ(Matrix::CHV4DFLOAT4 vector, Matrix::CHV4DFLOAT deg)
	{
		Matrix::CHV4DFLOAT4X4 rotMatrixZ{
			{cos(deg()), -sin(deg()), 0.0f, 0.0f},
			{sin(deg()), cos(deg()), 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		return Matrix::Mul(vector, rotMatrixZ);

	}

	Matrix::CHV4DFLOAT4X4 const RotMatrixZ(Matrix::CHV4DFLOAT deg)
	{
		return Matrix::CHV4DFLOAT4X4 {
			{cos(deg()), -sin(deg()), 0.0f, 0.0f},
			{sin(deg()), cos(deg()), 0.0f, 0.0f},
			{0.0f, 0.0f, 1.0f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

	}

	Matrix::CHV4DFLOAT4X4 const MatrixRotateWorld(Matrix::CHV4DFLOAT4 deg)
	{
		Matrix::CHV4DFLOAT4X4 World{ Matrix::HV4DIDENTITY };

		Matrix::CHV4DFLOAT4X4 X = RotMatrixX(deg.A());

		Matrix::CHV4DFLOAT4X4 Y = RotMatrixY(deg.B());

		Matrix::CHV4DFLOAT4X4 Z = RotMatrixZ(deg.C());

		World = MatrixMul4X4(X, Y);

		World = MatrixMul4X4(World, Z);

		return World;

	}

	Matrix::CHV4DFLOAT4X4 const MatrixTranslationWorld(Matrix::CHV4DFLOAT4X4 world, Matrix::CHV4DFLOAT3 distance)
	{
		return Matrix::CHV4DFLOAT4X4{
			{world.ROW1().A()(), world.ROW2().A()(), world.ROW3().A()(), world.ROW4().A()() + distance.A()()},
			{world.ROW1().B()(), world.ROW2().B()(), world.ROW3().B()(), world.ROW4().B()() + distance.B()()},
			{world.ROW1().C()(), world.ROW2().C()(), world.ROW3().C()(), world.ROW4().C()() + distance.C()()},
			{world.ROW1().D()(), world.ROW2().D()(), world.ROW3().D()(), world.ROW4().D()()}
		};

	}

}