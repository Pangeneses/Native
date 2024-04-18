module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>

export module CHV4DNATIVE:CHV4DPOINTMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
    class CHV4DPOINTMAP
    {
    public:
        CHV4DPOINTMAP() = default;

        CHV4DPOINTMAP(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

        bool IsEmpty() { return pointMap.size() != 0; }

    public:
        std::vector<std::shared_ptr<CAD::HV4DPOINT>>& operator ()();

        void operator +=(std::shared_ptr<CAD::HV4DPOINT> const vert);

        bool operator -=(size_t at);

        void InsertPoint(std::shared_ptr<CAD::HV4DPOINT> const vert);

        bool RemovePoint(size_t at);

        std::vector<std::tuple<size_t, size_t, size_t>>& operator *();

        void operator +=(std::tuple<size_t, size_t, size_t> const face);

        bool operator --(int at);

        void InsertFace(std::tuple<size_t, size_t, size_t> const face);

        bool RemoveFace(int at);

    private:
        SysT::CHV4DHASH UUID{ L"" };

        std::vector<std::shared_ptr<CAD::HV4DPOINT>> pointMap;

        std::vector<std::tuple<size_t, size_t, size_t>> indexMap;

    };

}