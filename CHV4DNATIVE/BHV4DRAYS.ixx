module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DRAYS;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DRAYS
	{
	public:
		BHV4DRAYS() = default;

        BHV4DRAYS(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

    private:
        SysT::CHV4DHASH UUID{ L"" };

        typedef struct Light
        {
            GeV::CHV4DFLOAT3 Position{ 0.0f, 0.0f, 0.0f };

            GeV::CHV4DFLOAT4 Color{ 0.0f, 0.0f, 0.0f, 0.0f };

            GeV::CHV4DFLOAT3 Direction{ 0.0f, 0.0f, 0.0f };

            GeV::CHV4DFLOAT SweepLeft{ 0.0f };

            GeV::CHV4DFLOAT SweepRight{ 0.0f };

            GeV::CHV4DFLOAT SweepUp{ 0.0f };

            GeV::CHV4DFLOAT SweepDown{ 0.0f };

            bool OmniDirectional{ false }; 

            bool Ambient{ false };

            void(*falloff)();

            GeV::CHV4DFLOAT LensPosition{ 0.0f };

            GeV::CHV4DFLOAT Refraction{ 1.0f };

        } Light;

	};

}