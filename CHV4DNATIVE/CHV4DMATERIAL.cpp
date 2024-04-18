module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DMATERIAL;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DMATERIAL::CHV4DMATERIAL()
	{



	}

	CHV4DMATERIAL::CHV4DMATERIAL(SysT::CHV4DHASH const& uid)
	{ 
		UUID = uid;
	
	}

	SysT::CHV4DHASH const& CHV4DMATERIAL::GetUUID() const
	{
		return UUID;

	}

	void CHV4DMATERIAL::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	bool CHV4DMATERIAL::IsWellFormed()
	{
		return false;

	}

}