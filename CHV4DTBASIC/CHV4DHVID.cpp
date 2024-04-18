module;

#include <guiddef.h>

#include <combaseapi.h>

#include <string>
#include <sstream>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DHVID;

namespace CHV4DTBASIC
{
	CHV4DHVID::CHV4DHVID()
	{

		return;

	}

	CHV4DHVID::CHV4DHVID(std::wstring const& uuid)
	{
		try
		{
			ToHVID(uuid, tagUUID);

		}
		catch (std::domain_error)
		{
			tagUUID = GUID{};

			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DHVID::CHV4DHVID(GUID const& uuid)
	{
		tagUUID = uuid;

		return;

	}

	CHV4DHVID::CHV4DHVID(CHV4DHVID const& uuid)
	{
		tagUUID = uuid.tagUUID;

		return;

	}

	void CHV4DHVID::operator = (std::wstring const& uuid)
	{
		try
		{
			ToHVID(uuid, tagUUID);

		}
		catch (std::domain_error)
		{
			tagUUID = GUID{};

			throw std::invalid_argument("");

		}

		return;

	}

	void CHV4DHVID::operator = (GUID const& uuid)
	{
		tagUUID = uuid;

		return;

	}

	void CHV4DHVID::operator = (CHV4DHVID const& uuid)
	{
		tagUUID = uuid.tagUUID;

		return;

	}

	bool CHV4DHVID::operator == (std::wstring const& uuid) const
	{
		GUID hvid{};

		try
		{
			ToHVID(uuid, hvid);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagUUID == hvid;

	}

	bool CHV4DHVID::operator == (GUID const& uuid) const
	{
		return tagUUID == uuid;

	}

	bool CHV4DHVID::operator == (CHV4DHVID const& uuid) const
	{
		return tagUUID == uuid.tagUUID;

	}

	bool CHV4DHVID::operator != (std::wstring const& uuid) const
	{
		GUID hvid{};

		try
		{
			ToHVID(uuid, hvid);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagUUID != hvid;

	}

	bool CHV4DHVID::operator != (GUID const& uuid) const
	{
		return tagUUID != uuid;

	}

	bool CHV4DHVID::operator != (CHV4DHVID const& uuid) const
	{
		return tagUUID != uuid.tagUUID;

	}

	bool CHV4DHVID::operator < (std::wstring const& uuid) const
	{
		GUID hvid{};

		try
		{
			ToHVID(uuid, hvid);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return *this < CHV4DHVID{ hvid };

	}

	bool CHV4DHVID::operator < (GUID const& uuid) const
	{
		return *this < CHV4DHVID{ uuid };

	}

	bool CHV4DHVID::operator < (CHV4DHVID const& uuid) const
	{
		if (tagUUID.Data1 < uuid.tagUUID.Data1)
		{
			return true;

		}

		if (tagUUID.Data1 > uuid.tagUUID.Data1)
		{
			return false;

		}

		if (tagUUID.Data2 < uuid.tagUUID.Data2)
		{
			return true;

		}

		if (tagUUID.Data2 > uuid.tagUUID.Data2)
		{
			return false;

		}

		if (tagUUID.Data3 < uuid.tagUUID.Data3)
		{
			return true;

		}

		if (tagUUID.Data3 > uuid.tagUUID.Data3)
		{
			return false;

		}

		for (std::uint8_t i = 0; i < 8; i++)
		{
			if (tagUUID.Data4[i] < uuid.tagUUID.Data4[i])
			{
				return true;

			}

			if (tagUUID.Data4[i] > uuid.tagUUID.Data4[i])
			{
				return false;

			}

		}

		return false;

	}

	bool CHV4DHVID::operator > (std::wstring const& uuid) const
	{
		GUID hvid{};

		try
		{
			ToHVID(uuid, hvid);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return *this > CHV4DHVID{ hvid };

	}

	bool CHV4DHVID::operator > (GUID const& uuid) const
	{
		return *this > CHV4DHVID{ uuid };

	}

	bool CHV4DHVID::operator > (CHV4DHVID const& uuid) const
	{
		if (tagUUID.Data1 > uuid.tagUUID.Data1)
		{
			return true;

		}

		if (tagUUID.Data1 < uuid.tagUUID.Data1)
		{
			return false;

		}

		if (tagUUID.Data2 > uuid.tagUUID.Data2)
		{
			return true;

		}

		if (tagUUID.Data2 < uuid.tagUUID.Data2)
		{
			return false;

		}

		if (tagUUID.Data3 > uuid.tagUUID.Data3)
		{
			return true;

		}

		if (tagUUID.Data3 < uuid.tagUUID.Data3)
		{
			return false;

		}

		for (std::uint8_t i = 0; i < 8; i++)
		{
			if (tagUUID.Data4[i] > uuid.tagUUID.Data4[i])
			{
				return true;

			}

			if (tagUUID.Data4[i] < uuid.tagUUID.Data4[i])
			{
				return false;

			}

		}

		return false;

	}

	GUID CHV4DHVID::operator()() const
	{
		return tagUUID;

	}
	
	void CHV4DHVID::Generate()
	{
		HRESULT ret = CoCreateGuid(&tagUUID);

		if (ret != S_OK)
		{
			throw std::underflow_error("Guid creation failure.");

		}

		return;

	}

	void CHV4DHVID::ToString(GUID const& uuid, std::wstring& str) const
	{
		GUID hvid{ uuid };

		std::uint8_t i_array[16]{};

		std::uint8_t* data1 = reinterpret_cast<std::uint8_t*>(&hvid.Data1);
		std::uint8_t* data2 = reinterpret_cast<std::uint8_t*>(&hvid.Data2);
		std::uint8_t* data3 = reinterpret_cast<std::uint8_t*>(&hvid.Data3);

		i_array[0] = data1[3];
		i_array[1] = data1[2];
		i_array[2] = data1[1];
		i_array[3] = data1[0];
		i_array[4] = data2[1];
		i_array[5] = data2[0];
		i_array[6] = data3[1];
		i_array[7] = data3[0];
		i_array[8] = (std::uint8_t)hvid.Data4[0];
		i_array[9] = (std::uint8_t)hvid.Data4[1];
		i_array[10] = (std::uint8_t)hvid.Data4[2];
		i_array[11] = (std::uint8_t)hvid.Data4[3];
		i_array[12] = (std::uint8_t)hvid.Data4[4];
		i_array[13] = (std::uint8_t)hvid.Data4[5];
		i_array[14] = (std::uint8_t)hvid.Data4[6];
		i_array[15] = (std::uint8_t)hvid.Data4[7];

		std::vector<std::wstring> view{};

		std::wostringstream ss{};

		for (std::uint8_t i = 0; i < 16; i++)
		{
			ss << std::hex << i_array[i];
			view.push_back(ss.str());

		}

		std::wstring out{ L"{" };

		for (std::uint8_t i = 0; i < 16; i++)
		{
			out = out + view[i];

			if (i == 3) out = out + L"-";
			if (i == 5) out = out + L"-";
			if (i == 7) out = out + L"-";
			if (i == 9) out = out + L"-";

		}

		out = out + L"}";

		str = out;

		return;


	}

	void CHV4DHVID::ToHVID(std::wstring const& str, GUID& uuid) const
	{
		uuid.Data1 = wcstoul(std::wstring{ &str[1],  & str[9] }.c_str(), nullptr, 16);
		uuid.Data2 = (unsigned short)wcstoul(std::wstring{ &str[10], & str[14] }.c_str(), nullptr, 16);
		uuid.Data3 = (unsigned short)wcstoul(std::wstring{ &str[15], & str[19] }.c_str(), nullptr, 16);
		uuid.Data4[0] = (char)wcstoul(std::wstring{ str[20], str[21] }.c_str(), nullptr, 16);
		uuid.Data4[1] = (char)wcstoul(std::wstring{ str[22], str[23] }.c_str(), nullptr, 16);
		uuid.Data4[2] = (char)wcstoul(std::wstring{ str[25], str[26] }.c_str(), nullptr, 16);
		uuid.Data4[3] = (char)wcstoul(std::wstring{ str[27], str[28] }.c_str(), nullptr, 16);
		uuid.Data4[4] = (char)wcstoul(std::wstring{ str[29], str[30] }.c_str(), nullptr, 16);
		uuid.Data4[5] = (char)wcstoul(std::wstring{ str[31], str[32] }.c_str(), nullptr, 16);
		uuid.Data4[6] = (char)wcstoul(std::wstring{ str[33], str[34] }.c_str(), nullptr, 16);
		uuid.Data4[7] = (char)wcstoul(std::wstring{ str[35], str[36] }.c_str(), nullptr, 16);

	}

}