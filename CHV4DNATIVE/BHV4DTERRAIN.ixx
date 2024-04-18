module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DTERRAIN;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :BHV4DKNOWN;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DTERRAIN
	{
	public:
		BHV4DTERRAIN() = default;

		BHV4DTERRAIN(SysT::CHV4DHASH const& uid)
		{
			UUID = uid;

		}

	public:
		SysT::CHV4DHASH const& GetUUID() const;

		void UpdateName(SysT::CHV4DMAXPATH const& name);

	private:
		SysT::CHV4DHASH UUID{ L"" };

		typedef struct PerVertex
		{
			float Position[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

			float TextUV[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

			float Normal[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

		} PerVertex;

		std::vector<PerVertex> Terrain;

	};

}