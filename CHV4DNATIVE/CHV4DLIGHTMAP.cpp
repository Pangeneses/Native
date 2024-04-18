module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

#undef TEXT

module CHV4DNATIVE:CHV4DLIGHTMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DLIGHTMAP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DLIGHTMAP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}