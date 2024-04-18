module;

#include <stdexcept>

#include <string>
#include <vector>

#include <cmath>

#include <iostream>

export module CHV4DTENSOR:CHV4DDECK;

import :CHV4DCALC;
import :CHV4DGEV;

export namespace Deck
{
	using CHV4DPOINT = GeV::CHV4DFLOAT4;

	using CHV4DTEXT = GeV::CHV4DFLOAT4;

	using CHV4DNORMAL = GeV::CHV4DFLOAT4;

	typedef struct tagCHV4DVERTEX {
		CHV4DPOINT point;
		CHV4DTEXT text;
		CHV4DNORMAL norm;
	}CHV4DVERTEX;

	typedef struct tagCHV4DFACE {
		CHV4DVERTEX A;
		CHV4DVERTEX B;
		CHV4DVERTEX C;
	}CHV4DFACE;

	using CHV4DMESH = std::vector<CHV4DFACE>;

	using CHV4DGROUP = std::pair<std::string, CHV4DMESH>;

	using CHV4DOBJECT = std::pair<std::string, std::vector<size_t>>;

	class CHV4DOBJ
	{
	public:
		CHV4DOBJ() = default;

	public:
		std::vector<std::string> MatLib;

		std::vector<CHV4DGROUP> Groups;

		std::vector<CHV4DOBJECT> Objects;
		 
	};

}