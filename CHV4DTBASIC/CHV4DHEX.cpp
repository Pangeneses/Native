module;

#include <string>

#include <cstdint>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DHEX;

namespace CHV4DTBASIC
{
	CHV4DHEX::CHV4DHEX()
	{

		return;

	}

	CHV4DHEX::CHV4DHEX(std::uint64_t const& hex)
	{
		tagHEX = std::to_wstring(hex);

		return;

	}

	CHV4DHEX::CHV4DHEX(std::wstring const& hex)
	{
		try
		{
			IsValidHEX(hex);

		}
		catch (std::domain_error)
		{
			tagHEX.clear();

			throw std::invalid_argument("");

		}

		tagHEX = hex;

		return;

	}

	CHV4DHEX::CHV4DHEX(CHV4DHEX const& hex)
	{
		tagHEX = hex.tagHEX;

		return;

	}

	void CHV4DHEX::IsValidHEX(std::wstring const& hex) const
	{
		if (hex.size() > 16)
		{
			throw std::domain_error("");

		}

		std::vector<wchar_t>::const_iterator citt{};

		for (std::wstring::const_iterator itt = tagHEX.begin(); itt != tagHEX.end(); itt++)
		{
			citt = std::find(HV4DHexW.begin(), HV4DHexW.end(), *itt);

			if (citt == HV4DHexW.end())
			{
				throw std::domain_error("");

			}

		}

		return;

	}

	void CHV4DHEX::operator = (std::uint64_t const& hex)
	{
		tagHEX = std::to_wstring(hex);

		return;

	}

	void CHV4DHEX::operator = (std::wstring const& hex)
	{
		try
		{
			IsValidHEX(hex);

		}
		catch (std::domain_error)
		{
			tagHEX.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	void CHV4DHEX::operator = (CHV4DHEX const& hex)
	{
		tagHEX = hex.tagHEX;

		return;

	}

	bool CHV4DHEX::operator == (std::wstring const& hex) const
	{
		try
		{
			IsValidHEX(hex);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagHEX.compare(hex) == 0;

	}

	bool CHV4DHEX::operator == (CHV4DHEX const& hex) const
	{
		return tagHEX.compare(hex.tagHEX) == 0;

	}

	std::wstring CHV4DHEX::operator()() const
	{
		return tagHEX;

	}

}