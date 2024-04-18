module;

#include <memory>
#include <stdexcept>

#include <string>
#include <vector>
#include <map>

module CHV4DNATIVE:BHV4DSTATICBUF;

import CHV4DTBASIC;
import CHV4DTENSOR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace SysT = CHV4DTBASIC;

namespace CAD
{
	SysT::CHV4DHASH const& BHV4DSTATICBUF::GetUUID() const
	{
		return UUID;

	}

	void BHV4DSTATICBUF::UpdateName(SysT::CHV4DMAXPATH const& name)
	{
		UUID = { UUID().first, name() };

	}

	void BHV4DSTATICBUF::LoadObj()
	{
		Deck::CHV4DOBJ const& ref = Obj.LoadMeshFromFile("C:\\Users\\rebek\\Source\\tire.obj");

		buffer.reserve(67108864);

		size_t index = 0;

		for (Deck::CHV4DGROUP grp : ref.Groups)
		{
			buffer.resize(buffer.size() + grp.second.size() * 36);

			for (Deck::CHV4DFACE face : grp.second)
			{
				*(Deck::CHV4DFACE*)&buffer[index] = face;

				index += 36;

			}

		}

	}

	std::vector<float> const& BHV4DSTATICBUF::GetObj()
	{
		return buffer;

	}

}