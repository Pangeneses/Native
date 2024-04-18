module;

#include <string>
#include <fstream>
#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DALPHANUMERIC;

namespace CHV4DTBASIC
{
	CHV4DALPHANUMERIC::CHV4DALPHANUMERIC()
	{
		std::fstream traits;

		return;

	}

	CHV4DALPHANUMERIC::CHV4DALPHANUMERIC(std::wstring const& reduced)
	{
		try
		{
			IsValidAlphaNumeric(reduced);

		}
		catch (std::domain_error)
		{
			tagTEXT.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DALPHANUMERIC::CHV4DALPHANUMERIC(CHV4DALPHANUMERIC const& reduced)
	{
		tagTEXT = reduced.tagTEXT;

		return;

	}

	void CHV4DALPHANUMERIC::IsValidAlphaNumeric(std::wstring const& reduced) const
	{
		std::vector<wchar_t>::const_iterator citt{};

		for (std::wstring::const_iterator itt = reduced.begin(); itt != reduced.end(); itt++)
		{
			citt = std::find(HV4DAlphaNumericW.begin(), HV4DAlphaNumericW.end(), *itt);

			if (citt == HV4DAlphaNumericW.end())
			{
				throw std::domain_error("");

			}

		}

		return;

	}

	void CHV4DALPHANUMERIC::operator = (std::wstring const& reduced)
	{
		try
		{
			IsValidAlphaNumeric(reduced);

		}
		catch (std::domain_error)
		{
			tagTEXT.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	void CHV4DALPHANUMERIC::operator = (CHV4DALPHANUMERIC const& reduced)
	{
		tagTEXT = reduced.tagTEXT;

		return;

	}

	bool CHV4DALPHANUMERIC::operator == (std::wstring const& reduced) const
	{
		try
		{
			IsValidAlphaNumeric(reduced);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagTEXT.compare(reduced) == 0;

	}

	bool CHV4DALPHANUMERIC::operator == (CHV4DALPHANUMERIC const& reduced) const
	{
		return tagTEXT.compare(reduced.tagTEXT) == 0;

	}

	std::wstring CHV4DALPHANUMERIC::operator()() const
	{
		return tagTEXT;

	}

}