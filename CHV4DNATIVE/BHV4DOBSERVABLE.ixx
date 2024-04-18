module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DOBSERVABLE;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DOBSERVABLE
	{
	public:
		BHV4DOBSERVABLE() = default;

        BHV4DOBSERVABLE(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

    private:
        SysT::CHV4DHASH UUID{ L"" };

        std::vector<size_t> ObservableStatic;

        std::vector<size_t> ObservableDynamic;

        std::vector<size_t> ObservableSoft;

        std::vector<size_t> ObservableInstanced;

        std::vector<size_t> ObservableRays;

	};

}