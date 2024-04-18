module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DCONSTRAINT;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DCONSTRAINT::CHV4DCONSTRAINT()
	{


	}

	CHV4DCONSTRAINT::CHV4DCONSTRAINT(SysT::CHV4DHASH const& uid)
	{
		UUID = uid;

	}

	SysT::CHV4DHASH const& CHV4DCONSTRAINT::GetUUID() const
	{
		return UUID;

	}

	void CHV4DCONSTRAINT::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

}