module;

#include <optional>
#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DGROUP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DHANDLE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DGROUP::CHV4DGROUP()
	{



	}

	CHV4DGROUP::CHV4DGROUP(SysT::CHV4DHASH const& uid)
	{
		UUID = uid;


	}

	SysT::CHV4DHASH const& CHV4DGROUP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DGROUP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	SysT::CHV4DHASH const& CHV4DGROUP::GetMaterialLibrary() const
	{
		return materialLibrary;

	}

	void CHV4DGROUP::UpdateMaterialLibrary(SysT::CHV4DMAXPATH const& name)
	{
		materialLibrary = { materialLibrary().first, name() };

	}

	std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>& CHV4DGROUP::operator()()
	{ 		
		return component; 
	
	}

	std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>& CHV4DGROUP::ComponentCollection()
	{
		return component;

	}

	void CHV4DGROUP::Swap(SysT::CHV4DHASH const& a, SysT::CHV4DHASH const& b)
	{
		std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>::iterator itt;

		std::unordered_map<SysT::CHV4DHASH, std::shared_ptr<CAD::CHV4DHANDLE>, CHV4DTBASIC::CHV4DHASHFN>::iterator jtt;

		try
		{
			itt = component.find(a);

		}
		catch (std::out_of_range)
		{
			throw std::out_of_range{ "Could not locate component." };

		}

		try
		{
			jtt = component.find(b);

		}
		catch (std::out_of_range)
		{
			throw std::out_of_range{ "Could not locate component." };

		}

		std::swap(itt, jtt);

	}

	std::shared_ptr<CAD::CHV4DHANDLE> const CHV4DGROUP::operator ()(SysT::CHV4DHASH const& uid)
	{ 
		try
		{
			return component.at(uid);

		}
		catch (std::out_of_range)
		{
			return std::shared_ptr<CAD::CHV4DHANDLE>{ nullptr };

		}

	}

	void CHV4DGROUP::operator ()(std::shared_ptr<CAD::CHV4DHANDLE> const& in) 
	{ 
		if (!component.insert({ in->GetUUID(), in }).second) throw std::invalid_argument{ "Could not insert component." };

	}

	std::shared_ptr<CAD::CHV4DHANDLE> const CHV4DGROUP::operator ()(size_t const& at)
	{
		if (at < component.size()) return (*std::next(component.begin(), at)).second;

		else return std::shared_ptr<CAD::CHV4DHANDLE>{ nullptr };

	}

}