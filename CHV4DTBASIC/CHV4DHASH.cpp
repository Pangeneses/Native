module;

#include <combaseapi.h>

#include <string>

#include <stdexcept>

module CHV4DTBASIC:CHV4DHASH;

import :CHV4DTEXTBLOBW;

namespace CHV4DTBASIC
{
	CHV4DHASH::CHV4DHASH(std::wstring const& hash)
	{
		GUID uid;

		HRESULT hr = CoCreateGuid(&uid);

		if (SUCCEEDED(hr))
		{
			tagHVID = uid;

		}
		else
		{
			throw std::runtime_error("Failed to generate Uuid.");

		}

		tagMAXPATH = hash;

		return;

	}

	CHV4DHASH::CHV4DHASH(std::wstring const& hvid, std::wstring const& mp)
	{
		try
		{
			tagHVID = hvid;

		}
		catch (std::invalid_argument)
		{
			tagHVID = CHV4DHVID{};

			tagMAXPATH = CHV4DTEXTBLOBW{};

			throw std::invalid_argument("");

		}

		try
		{
			tagMAXPATH = mp;

		}
		catch (std::domain_error)
		{
			tagHVID = CHV4DHVID{};

			tagMAXPATH = CHV4DTEXTBLOBW{};

			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DHASH::CHV4DHASH(GUID const& hvid, std::wstring const& mp)
	{
		try
		{
			tagHVID = hvid;

		}
		catch (std::invalid_argument)
		{
			tagHVID = CHV4DHVID{};

			tagMAXPATH = CHV4DTEXTBLOBW{};

			throw std::invalid_argument("");

		}

		try
		{
			tagMAXPATH = mp;

		}
		catch (std::domain_error)
		{
			tagHVID = CHV4DHVID{};

			tagMAXPATH = CHV4DTEXTBLOBW{};

			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DHASH::CHV4DHASH(CHV4DHASH const& hash)
	{
		tagHVID = hash.tagHVID;

		tagMAXPATH = hash.tagMAXPATH;

		return;

	}

	bool CHV4DHASH::operator == (std::pair<GUID, std::wstring> const& hash) const
	{
		try
		{
			auto var = hash.first;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		try
		{
			auto var = hash.second;

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return ((tagHVID == hash.first) && (tagMAXPATH == hash.second));

	}

	bool CHV4DHASH::operator == (CHV4DHASH const& hash) const
	{
		return ((tagHVID == hash.tagHVID) && (tagMAXPATH == hash.tagMAXPATH));

	}

	bool CHV4DHASH::operator != (std::pair<GUID, std::wstring> const& hash) const
	{
		try
		{
			auto var = hash.first;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		try
		{
			auto var = hash.second;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		return !(tagHVID == hash.first && tagMAXPATH == hash.second);

	}

	bool CHV4DHASH::operator != (CHV4DHASH const& hash) const
	{
		return !(tagHVID == hash.tagHVID && tagMAXPATH == hash.tagMAXPATH);

	}

	bool CHV4DHASH::operator < (std::pair<GUID, std::wstring> const& hash) const
	{
		try
		{
			auto var = hash.first;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		try
		{
			auto var = hash.second;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		return tagHVID < hash.first;

	}

	bool CHV4DHASH::operator < (CHV4DHASH const& e) const
	{
		return tagHVID < e.tagHVID;

	}

	bool CHV4DHASH::operator > (std::pair<GUID, std::wstring> const& hash) const
	{
		try
		{
			auto var = hash.first;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		try
		{
			auto var = hash.second;

		}
		catch (std::invalid_argument)
		{
			throw std::invalid_argument("");

		}

		return tagHVID > hash.first;

	}

	bool CHV4DHASH::operator > (CHV4DHASH const& hash) const
	{
		return tagHVID > hash.tagHVID;

	}

	std::pair<GUID, std::wstring> CHV4DHASH::operator()() const
	{
		return std::pair{ tagHVID(), tagMAXPATH() };

	}

}