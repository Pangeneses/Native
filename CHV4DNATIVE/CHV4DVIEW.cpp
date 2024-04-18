module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DVIEW;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DVIEW::CHV4DVIEW()
	{



	}

	CHV4DVIEW::CHV4DVIEW(SysT::CHV4DHASH const& uid)
	{
		uUID = uid;

	}

	SysT::CHV4DHASH const& CHV4DVIEW::GetUuID() const
	{
		return uUID;

	}

	void CHV4DVIEW::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		uUID = { uUID().first, name() };

	}

	bool CHV4DVIEW::IsSetViewTransform()
	{
		return viewTransform != GeV::CHV4DFLOAT4X4{};

	}

	void CHV4DVIEW::UpdateViewTransform(GeV::CHV4DFLOAT4X4 const& view)
	{
		viewTransform = view;

	}

	void CHV4DVIEW::ClearViewTransform()
	{
		viewTransform = GeV::CHV4DFLOAT4X4{};

	}

}