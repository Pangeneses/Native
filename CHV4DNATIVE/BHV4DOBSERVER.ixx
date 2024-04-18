module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DOBSERVER;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DOBSERVER
	{
	public:
		BHV4DOBSERVER() = default;

		BHV4DOBSERVER(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

		std::vector<float> const& GetCBuffer();

		void RotateObjectX(float deg);

		void RotateObjectY(float deg);

		void RotateObjectZ(float deg);

		void TranslateObjectX(float translate);

		void TranslateObjectY(float translate);

		void TranslateObjectZ(float translate);

		void ScaleObjectX(float scale);

		void ScaleObjectY(float scale);

		void ScaleObjectZ(float scale);

		void RotateCameraX(float deg);

		void RotateCameraY(float deg);

		void RotateCameraZ(float deg);

		void TranslateCameraX(float translate);

		void TranslateCameraY(float translate);

		void TranslateCameraZ(float translate);

	private:
		SysT::CHV4DHASH UUID{ L"" };

		std::vector<float> cBuffer;

		typedef struct View
		{
			GeV::CHV4DFLOAT3 Eye{ 0.0f, 0.0f, 0.0f };

			GeV::CHV4DFLOAT3 At{ 0.0f, 0.0f, 0.0f };

			GeV::CHV4DFLOAT3 Up{ 0.0f, 1.0f, 0.0f };

		} View;

		std::vector<View> Observers;

	};

}