module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

export module CHV4DNATIVE:CHV4DTEXTMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

export namespace CAD
{
    class CHV4DTEXTMAP
    {
    public:
        CHV4DTEXTMAP() = default;

        CHV4DTEXTMAP(SysT::CHV4DHASH const& uid)
        {
            UUID = uid;

        }

    public:
        SysT::CHV4DHASH const& GetUUID() const;

        void UpdateName(SysT::CHV4DMAXPATH const& name);

        bool Empty()
        {


        }

    public:
        std::vector<std::shared_ptr<CAD::HV4DTEXT>>& operator ()();

        void operator +=(std::shared_ptr<CAD::HV4DTEXT> const text);

        bool operator -=(size_t at);

        void InsertText(std::shared_ptr<CAD::HV4DTEXT> const text);

        bool RemoveText(size_t at);

        std::vector<std::tuple<size_t, size_t, size_t>>& operator *();

        void operator +=(std::tuple<size_t, size_t, size_t> const face);

        bool operator --(int at);

        void InsertFace(std::tuple<size_t, size_t, size_t> const face);

        bool RemoveFace(int at);

    private:
        SysT::CHV4DHASH UUID{ L"" };

        std::vector<std::shared_ptr<CAD::HV4DTEXT>> textMap;

        std::vector<std::tuple<size_t, size_t, size_t>> indexMap;

    };

}