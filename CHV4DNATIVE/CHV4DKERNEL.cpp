module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DKERNEL;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

import :CHV4DMASTER;
import :CHV4DCONTAINER;
import :CHV4DVISSTATE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	CHV4DKERNEL::CHV4DKERNEL()
	{


	}

	CHV4DKERNEL::CHV4DKERNEL(SysT::CHV4DHASH const& uid)
	{
		UUID = uid;

	}

	SysT::CHV4DHASH const& CHV4DKERNEL::GetUUID() const
	{
		return UUID;

	}

	void CHV4DKERNEL::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	void CHV4DKERNEL::NewMaster(SysT::CHV4DHASH const& uid)
	{
		Master.first = uid;

		Master.second = std::make_shared<CHV4DMASTER>(uid);

		return;

	}

	void CHV4DKERNEL::NewContainer(SysT::CHV4DHASH const& uid)
	{
		Container.first = uid;

		Container.second = std::make_shared<CHV4DCONTAINER>(uid);

		return;

	}

	void CHV4DKERNEL::NewVisState(SysT::CHV4DHASH const& uid)
	{
		VisState.first = uid;

		VisState.second = std::make_shared<CHV4DVISSTATE>(uid);

		return;

	}

	void CHV4DKERNEL::RemoveMaster()
	{
		Master = { { L"" }, std::shared_ptr<CHV4DMASTER>{ nullptr } };

		return;

	}

	void CHV4DKERNEL::RemoveContainer()
	{
		Container = { { L"" }, std::shared_ptr<CHV4DCONTAINER>{ nullptr } };

		return;

	}

	void CHV4DKERNEL::RemoveVisState()
	{
		VisState = { { L"" }, std::shared_ptr<CHV4DVISSTATE>{ nullptr } };

		return;

	}

	std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DMASTER>> CHV4DKERNEL::GetMaster()
	{
		return Master;

	}

	std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DCONTAINER>> CHV4DKERNEL::GetContainer()
	{
		return Container;

	}

	std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DVISSTATE>> CHV4DKERNEL::GetVisState()
	{
		return VisState;

	}

}