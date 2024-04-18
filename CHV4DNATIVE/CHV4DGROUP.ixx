module;

#include <memory>
#include <stdexcept>

#include <string>
#include <unordered_map>

export module CHV4DNATIVE:CHV4DGROUP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

import :CHV4DHANDLE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DGROUP
	{
	public:
		CHV4DGROUP();

		CHV4DGROUP(SysT::CHV4DHASH const& uid);

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		SysT::CHV4DHASH const& GetMaterialLibrary() const;

		void UpdateMaterialLibrary(SysT::CHV4DMAXPATH const& name);

	public:
		void Swap(SysT::CHV4DHASH const& a, SysT::CHV4DHASH const& b);

	public:
		std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>& operator()();

		std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>& ComponentCollection();

		std::shared_ptr<CAD::CHV4DHANDLE> const operator ()(SysT::CHV4DHASH const& uid);

		void operator ()(std::shared_ptr<CAD::CHV4DHANDLE> const& in);

		std::shared_ptr<CAD::CHV4DHANDLE> const operator ()(size_t const& at);

	private:
		SysT::CHV4DHASH UUID{ L"" };

		SysT::CHV4DHASH materialLibrary{ L"" };

		std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN> component;

	};

}