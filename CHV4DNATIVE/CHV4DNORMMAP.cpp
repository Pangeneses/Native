module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DNORMMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DNORMMAP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DNORMMAP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

    std::vector<std::shared_ptr<CAD::HV4DNORM>>& CHV4DNORMMAP::operator ()()
    {
        return normMap;

    }

    void CHV4DNORMMAP::operator +=(std::shared_ptr<CAD::HV4DNORM> const norm)
    {
        normMap.push_back(norm);

    }

    bool CHV4DNORMMAP::operator -=(size_t at)
    {
        try
        {
            normMap.erase(std::next(normMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    void CHV4DNORMMAP::InsertNorm(std::shared_ptr<CAD::HV4DNORM> const norm)
    {
        normMap.push_back(norm);

    }

    bool CHV4DNORMMAP::RemoveNorm(size_t at)
    {
        try
        {
            normMap.erase(std::next(normMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    std::vector<std::tuple<size_t, size_t, size_t>>& CHV4DNORMMAP::operator *()
    {
        return indexMap;

    }

    void CHV4DNORMMAP::operator +=(std::tuple<size_t, size_t, size_t> const face)
    {
        indexMap.push_back(face);

    }

    bool CHV4DNORMMAP::operator --(int at)
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

    void CHV4DNORMMAP::InsertFace(std::tuple<size_t, size_t, size_t> const face)
    {
        indexMap.push_back(face);

    }

    bool CHV4DNORMMAP::RemoveFace(int at)
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