module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:CHV4DKERNEL;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DMASTER;
import :CHV4DCONTAINER;
import :CHV4DVISSTATE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DKERNEL
	{
	public:
		CHV4DKERNEL();

		CHV4DKERNEL(SysT::CHV4DHASH const& uid);

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

	public:
		void NewMaster(SysT::CHV4DHASH const& uid);

		void NewContainer(SysT::CHV4DHASH const& uid);

		void NewVisState(SysT::CHV4DHASH const& uid);

	public:
		void RemoveMaster();

		void RemoveContainer();

		void RemoveVisState();

	public:
		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DMASTER>> GetMaster();

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DCONTAINER>> GetContainer();

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DVISSTATE>> GetVisState();

	private:
		SysT::CHV4DHASH UUID{ L"" };

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DMASTER>> Master
		{
			{ L"" }, std::shared_ptr<CHV4DMASTER>{ nullptr }

		};

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DCONTAINER>> Container
		{
			{ L"" }, std::shared_ptr<CHV4DCONTAINER>{ nullptr }

		};

		std::pair<SysT::CHV4DHASH, std::shared_ptr<CHV4DVISSTATE>> VisState
		{
			{ L"" }, std::shared_ptr<CHV4DVISSTATE>{ nullptr }

		};

	};

}