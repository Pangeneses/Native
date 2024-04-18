module;

#include <memory>
#include <stdexcept>

#include <string>

#undef TEXT

export module CHV4DNATIVE:CHV4DCIRCLE;

import CHV4DTBASIC;
import CHV4DTENSOR;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class CHV4DCIRCLE
	{
	public:
		CHV4DCIRCLE();

		CHV4DCIRCLE(SysT::CHV4DHASH const& uid);

		CHV4DCIRCLE(CAD::CHV4DCIRCLE const& e);

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

		void UpdateWorld(GeV::CHV4DFLOAT4X4 const& world);

	private:
		SysT::CHV4DHASH UUID{ L"" };

		GeV::CHV4DFLOAT4X4 worldTransform{ Math::HV4DIDENTITY };

	};

}