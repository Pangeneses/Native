module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:CHV4DVIEW;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DVIEW
	{
	public:
		CHV4DVIEW();

		CHV4DVIEW(SysT::CHV4DHASH const& uid);

	public:
		SysT::CHV4DHASH const& GetUuID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		void UpdateViewTransform(GeV::CHV4DFLOAT4X4 const& view);

		bool IsSetViewTransform();

		void ClearViewTransform();

	public:
		inline GeV::CHV4DFLOAT4X4 const& GetViewTransform() { return viewTransform; }

		inline GeV::CHV4DFLOAT4X4 const& operator()() { return viewTransform; }

		inline GeV::CHV4DFLOAT4 const& operator()(GeV::CHV4DFLOAT4 const& transform) 
		{ 
			return Math::Mul(transform, viewTransform); 
		
		}

	private:
		SysT::CHV4DHASH uUID{ L"" };

		GeV::CHV4DFLOAT4X4 viewTransform;

	};

}