module;

#include <string>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DMAXPATH;

namespace CHV4DTBASIC
{
	CHV4DMAXPATH::CHV4DMAXPATH()
	{

		return;

	}

	CHV4DMAXPATH::CHV4DMAXPATH(std::wstring const& maxpath)
	{
		tagMAXPATH = maxpath;

		try
		{
			IsValidMAXPATH();

		}
		catch (std::domain_error)
		{
			tagMAXPATH.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DMAXPATH::CHV4DMAXPATH(CHV4DMAXPATH const& maxpath)
	{
		tagMAXPATH = maxpath.tagMAXPATH;

		return;

	}

	void CHV4DMAXPATH::IsValidMAXPATH()
	{
		if (tagMAXPATH.size() > 255)
		{
			throw std::domain_error("");

		}

		std::vector<wchar_t>::const_iterator citt{};

		for (std::wstring::const_iterator itt = tagMAXPATH.begin(); itt != tagMAXPATH.end(); itt++)
		{
			citt = std::find(HV4DMaxPathW.begin(), HV4DMaxPathW.end(), *itt);

			if (citt == HV4DMaxPathW.end())
			{
				throw std::domain_error("");

			}

		}

		return;

	}

	void CHV4DMAXPATH::operator = (std::wstring const& maxpath)
	{
		tagMAXPATH = maxpath;

		try
		{
			IsValidMAXPATH();

		}
		catch (std::domain_error)
		{
			tagMAXPATH.clear();

			throw std::invalid_argument("");

		}

		return;

	}

	void CHV4DMAXPATH::operator = (CHV4DMAXPATH const& maxpath)
	{
		tagMAXPATH = maxpath.tagMAXPATH;

		return;

	}

	bool CHV4DMAXPATH::operator == (std::wstring const& maxpath) const
	{
		CHV4DMAXPATH var{};

		try
		{
			var = maxpath;

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return *this == var;

	}

	bool CHV4DMAXPATH::operator == (CHV4DMAXPATH const& maxpath) const
	{
		return tagMAXPATH.compare(maxpath.tagMAXPATH) == 0;

	}

	std::wstring CHV4DMAXPATH::operator()() const
	{
		return tagMAXPATH;

	}

	std::wstring CHV4DMAXPATH::operator()(std::uint64_t const& i, std::uint64_t const& l) const
	{

		return tagMAXPATH.substr(i, l);

	}

}