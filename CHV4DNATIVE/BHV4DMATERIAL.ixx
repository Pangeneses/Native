module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DMATERIAL;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DMATERIAL
	{
	public:
		BHV4DMATERIAL() = default;

        BHV4DMATERIAL(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

    private:
        SysT::CHV4DHASH UUID{ L"" };

	};

}
