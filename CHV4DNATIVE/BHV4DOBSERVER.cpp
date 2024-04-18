module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:BHV4DOBSERVER;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& BHV4DOBSERVER::GetUUID() const
	{
		return UUID;

	}

	void BHV4DOBSERVER::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	std::vector<float> const& BHV4DOBSERVER::GetCBuffer()
	{
		cBuffer.resize(64);

		GeV::CHV4DFLOAT4X4 World{ Math::MatrixRotateWorld({ ObjRotX, ObjRotY, ObjRotZ, 1.0f }) };

		GeV::CHV4DFLOAT3 translateWorld{ ObjTranslateX, ObjTranslateY, ObjTranslateZ };

		World = Math::MatrixTranslationWorld(World, translateWorld);

		GeV::CHV4DFLOAT4X4 View{ Math::MatrixRotateWorld({ CamRotX, CamRotY, CamRotZ, 1.0f }) };

		GeV::CHV4DFLOAT3 translateCam{ CamTranslateX, CamTranslateY, CamTranslateZ };

		World = Math::MatrixTranslationWorld(World, translateCam);

		GeV::CHV4DFLOAT4X4 Projection{
			{0.5625f, 0.0f, 0.0f, 0.0f},
			{0.0f, 1.0f, 0.0f, 0.0f},
			{0.0f, 0.0f, 0.5635f, 0.0f},
			{0.0f, 0.0f, 0.0f, 1.0f}
		};

		*(GeV::CHV4DFLOAT4X4*)&cBuffer[0] = World;

		*(GeV::CHV4DFLOAT4X4*)&cBuffer[16] = View;

		*(GeV::CHV4DFLOAT4X4*)&cBuffer[32] = Projection;

		*(GeV::CHV4DFLOAT4*)&cBuffer[48] = lightVector;

		*(GeV::CHV4DFLOAT4*)&cBuffer[52] = ambientColor;

		*(GeV::CHV4DFLOAT4*)&cBuffer[56] = diffuseColor;

		*(GeV::CHV4DFLOAT4*)&cBuffer[60] = specularColor;

		return cBuffer;

	}

	void BHV4DOBSERVER::RotateObjectX(float deg)
	{
		ObjRotX += deg;

		if (ObjRotX > 360.0f) ObjRotX -= 360.0f;

		if (ObjRotX < -360.0f) ObjRotX += 360.0f;

	}

	void BHV4DOBSERVER::RotateObjectY(float deg)
	{
		ObjRotY += deg;

		if (ObjRotY > 360.0f) ObjRotY -= 360.0f;

		if (ObjRotY < -360.0f) ObjRotY += 360.0f;

	}

	void BHV4DOBSERVER::RotateObjectZ(float deg)
	{
		ObjRotZ += deg;

		if (ObjRotZ > 360.0f) ObjRotZ -= 360.0f;

		if (ObjRotZ < -360.0f) ObjRotZ += 360.0f;

	}

	void BHV4DOBSERVER::TranslateObjectX(float translate)
	{
		ObjTranslateX += translate;

	}

	void BHV4DOBSERVER::TranslateObjectY(float translate)
	{
		ObjTranslateY += translate;

	}

	void BHV4DOBSERVER::TranslateObjectZ(float translate)
	{
		ObjTranslateZ += translate;

	}

	void BHV4DOBSERVER::ScaleObjectX(float scale)
	{
		ObjScaleX *= scale;

	}

	void BHV4DOBSERVER::ScaleObjectY(float scale)
	{
		ObjScaleY *= scale;

	}

	void BHV4DOBSERVER::ScaleObjectZ(float scale)
	{
		ObjScaleZ *= scale;

	}

	void BHV4DOBSERVER::RotateCameraX(float deg)
	{
		CamRotX += deg;

		if (CamRotX > 360.0f) CamRotX -= 360.0f;

		if (CamRotX < -360.0f) CamRotX += 360.0f;

	}

	void BHV4DOBSERVER::RotateCameraY(float deg)
	{
		CamRotY += deg;

		if (CamRotY > 360.0f) CamRotY -= 360.0f;

		if (CamRotY < -360.0f) CamRotY += 360.0f;

	}

	void BHV4DOBSERVER::RotateCameraZ(float deg)
	{
		CamRotZ += deg;

		if (CamRotZ > 360.0f) CamRotZ -= 360.0f;

		if (CamRotZ < -360.0f) CamRotZ += 360.0f;

	}

	void BHV4DOBSERVER::TranslateCameraX(float translate)
	{
		CamTranslateX += translate;

	}

	void BHV4DOBSERVER::TranslateCameraY(float translate)
	{
		CamTranslateY += translate;

	}

	void BHV4DOBSERVER::TranslateCameraZ(float translate)
	{
		CamTranslateZ += translate;

	}

}