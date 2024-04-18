module;

#include <combaseapi.h>

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

#undef TEXT

export module CHV4DNATIVE:CHV4DHANDLE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

import :CHV4DPOINTMAP;
import :CHV4DTEXTMAP;
import :CHV4DNORMMAP;
import :CHV4DMATERIAL;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DHANDLE
	{
	public:
		CHV4DHANDLE();

		CHV4DHANDLE(SysT::CHV4DHASH const& uid);

		CHV4DHANDLE(CAD::CHV4DHANDLE const& e);

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		void UpdateWorld(GeV::CHV4DFLOAT4X4 const& world);

	public:
		std::shared_ptr<CAD::CHV4DPOINTMAP>& Point();

		std::shared_ptr<CAD::CHV4DTEXTMAP>& Text();

		std::shared_ptr<CAD::CHV4DNORMMAP>& Normal();

		std::shared_ptr<CAD::CHV4DMATERIAL>& Material();

	private:
		SysT::CHV4DHASH UUID{ L"" };

		GeV::CHV4DFLOAT4X4 worldTransform{ Math::HV4DIDENTITY };

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DPOINTMAP>> pointMap
		{
			{ L"" }, std::shared_ptr<CAD::CHV4DPOINTMAP>{ nullptr }

		};

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DTEXTMAP>> textMap
		{
			{ L"" }, std::shared_ptr<CAD::CHV4DTEXTMAP>{ nullptr }

		};

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DNORMMAP>> normMap
		{
			{ L"" }, std::shared_ptr<CAD::CHV4DNORMMAP>{ nullptr }

		};

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DMATERIAL>> material
		{ 
			{ L"" }, std::shared_ptr<CAD::CHV4DMATERIAL>{ nullptr }
		
		};

	};

}