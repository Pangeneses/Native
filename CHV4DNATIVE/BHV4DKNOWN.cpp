module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:BHV4DKNOWN;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& BHV4DKNOWN::GetUUID() const
	{
		return UUID;

	}

	void BHV4DKNOWN::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	void BHV4DKNOWN::GetBigWorld(float& bigX, float& bigY, float& bigZ)
	{
		bigX = BigX;

		bigY = BigY;

		bigZ = BigZ;

	}

	size_t BHV4DKNOWN::GetVertexBufferAllocSz()
	{
		return VertexReserved;
	
	}

}