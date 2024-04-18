module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DSTATICBUF;

import CHV4DTBASIC;
import CHV4DTENSOR;

import ObjDecoder;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DSTATICBUF
	{
	public:
		BHV4DSTATICBUF() = default;

        BHV4DSTATICBUF(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

        void LoadObj();

        std::vector<float> const& GetObj();

    private:
        SysT::CHV4DHASH UUID{ L"" };

        typedef struct World 
        {
            GeV::CHV4DFLOAT ObjRotX{ 0.0f };

            GeV::CHV4DFLOAT ObjRotY{ 0.0f };

            GeV::CHV4DFLOAT ObjRotZ{ 0.0f };

            GeV::CHV4DFLOAT ObjTranslateX{ 0.0f };

            GeV::CHV4DFLOAT ObjTranslateY{ 0.0f };

            GeV::CHV4DFLOAT ObjTranslateZ{ 0.0f };

            GeV::CHV4DFLOAT ObjScaleX{ 1.0f };

            GeV::CHV4DFLOAT ObjScaleY{ 1.0f };

            GeV::CHV4DFLOAT ObjScaleZ{ 1.0f };

        } World;

        typedef struct Mesh
        {
            typedef struct PerVertex
            {
                float Position[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

                float TextUV[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

                float Normal[4]{ 0.0f, 0.0f, 0.0f, 0.0f };

            } PerVertex;

            std::vector<PerVertex> Vertices;

        } Mesh;

        std::map<CHV4DTBASIC::CHV4DHASH, std::pair<World, Mesh>> StaticBuffer; 

	};

}