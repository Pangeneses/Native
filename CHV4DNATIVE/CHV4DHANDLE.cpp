module;

#include <combaseapi.h>

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

#undef TEXT

module CHV4DNATIVE:CHV4DHANDLE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DHANDLE::CHV4DHANDLE()
	{



		return;

	}
	CHV4DHANDLE::CHV4DHANDLE(SysT::CHV4DHASH const& uid)
	{
		UUID = uid;

		pointMap = { uid, std::make_shared<CAD::CHV4DPOINTMAP>(uid) };
		textMap = { uid, std::make_shared<CAD::CHV4DTEXTMAP>(uid) };
		normMap = { uid, std::make_shared<CAD::CHV4DNORMMAP>(uid) };
		material = { { L"" }, std::make_shared<CAD::CHV4DMATERIAL>()};



	}

	CHV4DHANDLE::CHV4DHANDLE(CHV4DHANDLE const& e)
	{
		UUID = e.UUID;
		
		worldTransform = e.worldTransform;

		pointMap = e.pointMap;
		textMap = e.textMap;
		normMap = e.normMap;
		material = e.material;

		return;

	}

	SysT::CHV4DHASH const& CHV4DHANDLE::GetUUID() const
	{
		return UUID;

	}

	void CHV4DHANDLE::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	void CHV4DHANDLE::UpdateWorld(GeV::CHV4DFLOAT4X4 const& world)
	{
		worldTransform = world;

	}

	std::shared_ptr<CAD::CHV4DPOINTMAP>& CHV4DHANDLE::Point()
	{
		return pointMap.second;

	}

	std::shared_ptr<CAD::CHV4DTEXTMAP>& CHV4DHANDLE::Text()
	{
		return textMap.second;

	}

	std::shared_ptr<CAD::CHV4DNORMMAP>& CHV4DHANDLE::Normal()
	{
		return normMap.second;

	}

	std::shared_ptr<CAD::CHV4DMATERIAL>& CHV4DHANDLE::Material()
	{
		return material.second;

	}

}