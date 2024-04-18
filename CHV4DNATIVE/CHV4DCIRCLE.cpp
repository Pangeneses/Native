module;

#include <combaseapi.h>

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

#undef TEXT

module CHV4DNATIVE:CHV4DCIRCLE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DCIRCLE::CHV4DCIRCLE()
	{



		return;

	}
	CHV4DCIRCLE::CHV4DCIRCLE(SysT::CHV4DHASH const& uid)
	{
		UUID = uid;

	}

	CHV4DCIRCLE::CHV4DCIRCLE(CHV4DCIRCLE const& e)
	{
		UUID = e.UUID;

		worldTransform = e.worldTransform;

		return;

	}

	SysT::CHV4DHASH const& CHV4DCIRCLE::GetUUID() const
	{
		return UUID;

	}

	void CHV4DCIRCLE::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	void CHV4DCIRCLE::UpdateWorld(GeV::CHV4DFLOAT4X4 const& world)
	{
		worldTransform = world;

	}

}