module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:CHV4DPOINTMAP;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& CHV4DPOINTMAP::GetUUID() const
	{
		return UUID;

	}

	void CHV4DPOINTMAP::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

    std::vector<std::shared_ptr<CAD::HV4DPOINT>>& CHV4DPOINTMAP::operator ()()
    { 
        return pointMap; 
    
    }

    void CHV4DPOINTMAP::operator +=(std::shared_ptr<CAD::HV4DPOINT> const vert)
    { 
        pointMap.push_back(vert); 
    
    }

    bool CHV4DPOINTMAP::operator -=(size_t at)
    {
        try
        {
            pointMap.erase(std::next(pointMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    void CHV4DPOINTMAP::InsertPoint(std::shared_ptr<CAD::HV4DPOINT> const vert)
    {
        pointMap.push_back(vert);

    }

    bool CHV4DPOINTMAP::RemovePoint(size_t at)
    {
        try
        {
            pointMap.erase(std::next(pointMap.begin(), at));

            return true;

        }
        catch (std::out_of_range)
        {
            return false;

        }

    }

    std::vector<std::tuple<size_t, size_t, size_t>>& CHV4DPOINTMAP::operator *() 
    { 
        return indexMap; 
    
    }

    void CHV4DPOINTMAP::operator +=(std::tuple<size_t, size_t, size_t> const face) 
    { 
        indexMap.push_back(face); 
    
    }

    bool CHV4DPOINTMAP::operator --(int at)
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

    void CHV4DPOINTMAP::InsertFace(std::tuple<size_t, size_t, size_t> const face)
    {
        indexMap.push_back(face);

    }

    bool CHV4DPOINTMAP::RemoveFace(int at)
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