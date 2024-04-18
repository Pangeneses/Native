module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:CHV4DWORLDTREE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DWORLDTREE
	{
	public:
		CHV4DWORLDTREE() = default;

		CHV4DWORLDTREE(SysT::CHV4DHASH const& uid) 
		{
			UUID = uid;

		}

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		bool Empty()
		{


		}


	private:
		SysT::CHV4DHASH UUID{ L"" };

	};

}