module;

#include <deque>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DSIMD;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFIXEDBYTES;

export namespace CHV4DTENSOR
{
	class CHV4DSIMD
	{
	public:
		CHV4DSIMD() = default;

		CHV4DSIMD(std::deque<CHV4DFIXEDBYTES<16>> const& A)
		{
			A;
		}

	private:


	};

}