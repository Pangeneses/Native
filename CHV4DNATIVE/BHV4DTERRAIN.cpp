module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:BHV4DTERRAIN;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& BHV4DTERRAIN::GetUUID() const
	{
		return UUID;

	}

	void BHV4DTERRAIN::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}