module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DTEXTMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DTEXTMAP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DTEXTMAP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

    std::vector<std::shared_ptr<CAD::HV4DTEXT>>& CHV4DTEXTMAP::operator ()()
    {
        return textMap;

    }

    void CHV4DTEXTMAP::operator +=(std::shared_ptr<CAD::HV4DTEXT> const text)
    {
        textMap.push_back(text);

    }

    bool CHV4DTEXTMAP::operator -=(size_t at)
    {
        try
        {
            textMap.erase(std::next(textMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    void CHV4DTEXTMAP::InsertText(std::shared_ptr<CAD::HV4DTEXT> const text)
    {
        textMap.push_back(text);

    }

    bool CHV4DTEXTMAP::RemoveText(size_t at)
    {
        try
        {
            textMap.erase(std::next(textMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    std::vector<std::tuple<size_t, size_t, size_t>>& CHV4DTEXTMAP::operator *()
    {
        return indexMap;

    }

    void CHV4DTEXTMAP::operator +=(std::tuple<size_t, size_t, size_t> const face)
    {
        indexMap.push_back(face);

    }

    bool CHV4DTEXTMAP::operator --(int at)
    {
        try
        {
            indexMap.erase(std::next(indexMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    void CHV4DTEXTMAP::InsertFace(std::tuple<size_t, size_t, size_t> const face)
    {
        indexMap.push_back(face);

    }

    bool CHV4DTEXTMAP::RemoveFace(int at)
    {
        try
        {
            indexMap.erase(std::next(indexMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

}