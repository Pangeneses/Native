module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DCONTAINER;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DCONTAINER::GetUUID() const
	{
		return UUID;

	}

	void CHV4DCONTAINER::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}