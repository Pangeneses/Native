module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:BHV4DKNOWN;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
	class BHV4DKNOWN
	{
	public:
		BHV4DKNOWN() = default;

        BHV4DKNOWN(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

        void GetBigWorld(float& bigX, float& bigY, float& bigZ);

        size_t GetVertexBufferAllocSz();

    private:
        SysT::CHV4DHASH UUID{ L"" };

        float BigX, BigY, BigZ;

        const size_t VertexReserved{ 250000 };

        size_t VertexBufferAllocSz{ VertexReserved };

    };

}