module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

#undef TEXT

module CHV4DNATIVE:CHV4DDIVMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DDIVMAP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DDIVMAP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}