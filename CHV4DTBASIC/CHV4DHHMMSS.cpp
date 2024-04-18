module;

#include <string>

#include <vector>

#include <ctime>

#include <stdexcept>

module CHV4DTBASIC:CHV4DHHMMSS;

namespace CHV4DTBASIC
{
	CHV4DHHMMSS::CHV4DHHMMSS()
	{

		return;

	}

	CHV4DHHMMSS::CHV4DHHMMSS(std::wstring const& hhmmss)
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			tagHHMMSS.clear();

			throw std::invalid_argument("");

		}

		tagHHMMSS = hhmmss;

		return;

	}

	CHV4DHHMMSS::CHV4DHHMMSS(CHV4DHHMMSS const& hhmmss)
	{
		tagHHMMSS = hhmmss.tagHHMMSS;

		return;

	}

	void CHV4DHHMMSS::IsValidHHMMSS(std::wstring const& hhmmss) const
	{
		if (hhmmss.size() == 8)
		{
			throw std::domain_error("");

		}

		if (hhmmss[2] != ':' || hhmmss[5] != ':')
		{
			throw std::domain_error("");

		}

		std::vector<std::wstring>::const_iterator citt{};

		citt = std::find(HV4DHourW.begin(), HV4DHourW.end(), std::wstring{ hhmmss[0], hhmmss[1] });

		if (citt == HV4DHourW.end())
		{
			throw std::domain_error("");

		}

		citt = std::find(HV4D59W.begin(), HV4D59W.end(), std::wstring{ hhmmss[3], hhmmss[4] });

		if (citt == HV4D59W.end())
		{
			throw std::domain_error("");

		}

		citt = std::find(HV4D59W.begin(), HV4D59W.end(), std::wstring{ hhmmss[6], hhmmss[7] });

		if (citt == HV4D59W.end())
		{
			throw std::domain_error("");

		}

		return;

	}

	void CHV4DHHMMSS::operator = (std::wstring const& hhmmss)
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			tagHHMMSS.clear();

			throw std::invalid_argument("");

		}

		tagHHMMSS = hhmmss;

		return;

	}

	void CHV4DHHMMSS::operator = (CHV4DHHMMSS const& hhmmss)
	{
		tagHHMMSS = hhmmss.tagHHMMSS;

		return;

	}

	bool CHV4DHHMMSS::operator == (std::wstring const& hhmmss) const
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagHHMMSS.compare(hhmmss) == 0;

	}

	bool CHV4DHHMMSS::operator == (CHV4DHHMMSS const& hhmmss) const
	{
		return tagHHMMSS.compare(hhmmss.tagHHMMSS) == 0;

	}

	bool CHV4DHHMMSS::operator != (std::wstring const& hhmmss) const
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagHHMMSS.compare(hhmmss) != 0;

	}

	bool CHV4DHHMMSS::operator != (CHV4DHHMMSS const& hhmmss) const
	{
		return tagHHMMSS.compare(hhmmss.tagHHMMSS) != 0;

	}

	bool CHV4DHHMMSS::operator > (std::wstring const& hhmmss) const
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagHHMMSS.compare(hhmmss) > 0;

	}

	bool CHV4DHHMMSS::operator > (CHV4DHHMMSS const& hhmmss) const
	{
		return tagHHMMSS.compare(hhmmss.tagHHMMSS) > 0;

	}

	bool CHV4DHHMMSS::operator < (std::wstring const& hhmmss) const
	{
		try
		{
			IsValidHHMMSS(hhmmss);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagHHMMSS.compare(hhmmss) < 0;

	}

	bool CHV4DHHMMSS::operator < (CHV4DHHMMSS const& hhmmss) const
	{
		return tagHHMMSS.compare(hhmmss.tagHHMMSS) > 0;

	}

	std::wstring CHV4DHHMMSS::operator()() const
	{
		return std::wstring{ tagHHMMSS[0], tagHHMMSS[1], ':', tagHHMMSS[2], tagHHMMSS[3], ':', tagHHMMSS[4], tagHHMMSS[5] };

	}

	void CHV4DHHMMSS::AsTuple(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> hhmmss) const
	{
		hhmmss = std::tuple{
			(std::uint8_t)std::stoi(std::wstring{ tagHHMMSS[0] } + tagHHMMSS[1]),
			(std::uint8_t)std::stoi(std::wstring{ tagHHMMSS[2] } + tagHHMMSS[3]),
			(std::uint8_t)std::stoi(std::wstring{ tagHHMMSS[4] } + tagHHMMSS[5]) };

	}

	void CHV4DHHMMSS::Current()
	{
		std::time_t t = std::time(nullptr);

		std::tm* now{};

		int result = ::localtime_s(now, &t);

		if (result == NULL)
		{
			tagHHMMSS.clear();

			throw std::overflow_error("localtime failed.");

		}

		char buffer[128];

		size_t ret = std::strftime(buffer, sizeof(buffer), "%X", now);

		if (ret == 0)
		{
			tagHHMMSS.clear();

			throw std::underflow_error("format time failed.");

		}

		std::wstring str{ &buffer[0], &buffer[std::strlen(buffer)] };

		tagHHMMSS = str;

		try
		{
			IsValidHHMMSS(tagHHMMSS);

		}
		catch (std::domain_error)
		{
			tagHHMMSS.clear();

			throw std::domain_error("");

		}

		return;

	}

}
