module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:CHV4DMATERIAL;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

import :CHV4DDIVMAP;
import :CHV4DNORMALMAP;
import :CHV4DCOLORMAP;
import :CHV4DLIGHTMAP;
import :CHV4DBULKMAP;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DMATERIAL
	{
	public:
		CHV4DMATERIAL();

		CHV4DMATERIAL(SysT::CHV4DHASH const& uid);

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		bool IsWellFormed();



	private:
		SysT::CHV4DHASH UUID{ L"" };

		std::tuple<SysT::CHV4DHASH, std::shared_ptr<CHV4DDIVMAP>> geometryMap
		{
			std::make_tuple(L"", std::shared_ptr<CHV4DDIVMAP>{ nullptr })

		};

		std::tuple<SysT::CHV4DHASH, std::shared_ptr<CHV4DNORMALMAP>> normalMap
		{
			std::make_tuple(L"", std::shared_ptr<CHV4DNORMALMAP>{ nullptr })

		};

		std::tuple<SysT::CHV4DHASH, std::shared_ptr<CHV4DCOLORMAP>> colorMap
		{
			std::make_tuple(L"", std::shared_ptr<CHV4DCOLORMAP>{ nullptr })

		};

		std::tuple<SysT::CHV4DHASH, std::shared_ptr<CHV4DLIGHTMAP>> lightMap
		{
			std::make_tuple(L"", std::shared_ptr<CHV4DLIGHTMAP>{ nullptr })

		};

		std::tuple<SysT::CHV4DHASH, std::shared_ptr<CHV4DBULKMAP>> bulkMap
		{
			std::make_tuple(L"", std::shared_ptr<CHV4DBULKMAP>{ nullptr })

		};

	};

}