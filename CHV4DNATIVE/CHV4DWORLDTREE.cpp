module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DWORLDTREE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DWORLDTREE::GetUUID() const
	{
		return UUID;

	}

	void CHV4DWORLDTREE::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}