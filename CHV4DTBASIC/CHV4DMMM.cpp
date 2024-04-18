module;

#include <string>

#include <cstdint>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DMMM;

namespace CHV4DTBASIC
{
	CHV4DMMM::CHV4DMMM()
	{

		return;

	}

	CHV4DMMM::CHV4DMMM(std::wstring const& mmm)
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		tagMMM = mmm;

		return;

	}

	CHV4DMMM::CHV4DMMM(std::uint32_t const& mil, std::uint32_t const& maj, std::uint32_t const& min)
	{
		if (mil > 10 || maj > 999 || min > 999)
		{
			throw std::invalid_argument("");

		}

		tagMMM = std::wstring{ std::to_wstring(mil) + L"." + std::to_wstring(maj) + L"." + std::to_wstring(min) };

	}

	CHV4DMMM::CHV4DMMM(CHV4DMMM const& mmm)
	{
		tagMMM = mmm.tagMMM;

		return;

	}

	void CHV4DMMM::IsValidMMM(std::wstring const& mmm) const
	{
		if (mmm.size() != 9)
		{
			throw std::domain_error("");

		}

		if (!(mmm[1] == '.' && mmm[5] == '.'))
		{
			throw std::domain_error("");

		}

		std::vector<wchar_t>::const_iterator citt{};

		for (wchar_t itt : mmm)
		{
			citt = std::find(HV4DNumericW.begin(), HV4DNumericW.end(), itt);

			if (citt == HV4DNumericW.end())
			{
				throw std::domain_error("");

			}

		}

		return;

	}

	void CHV4DMMM::operator = (std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> e)
	{
		if (std::get<0>(e) > 10 || std::get<1>(e) > 999 || std::get<2>(e) > 999)
		{
			throw std::invalid_argument("");

		}

		tagMMM = std::wstring{
			std::to_wstring(std::get<0>(e)) + L"." +
			std::to_wstring(std::get<1>(e)) + L"." +
			std::to_wstring(std::get<2>(e)) };

	}

	void CHV4DMMM::operator = (std::wstring const& mmm)
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		tagMMM = mmm;

		return;

	}

	void CHV4DMMM::operator = (CHV4DMMM const& mmm)
	{
		tagMMM = mmm.tagMMM;

		return;

	}

	bool CHV4DMMM::operator == (std::wstring const& mmm) const
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagMMM.compare(mmm) == 0;

	}

	bool CHV4DMMM::operator == (CHV4DMMM const& mmm) const
	{
		return tagMMM.compare(mmm.tagMMM) == 0;

	}

	bool CHV4DMMM::operator != (std::wstring const& mmm) const
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagMMM.compare(mmm) != 0;

	}

	bool CHV4DMMM::operator != (CHV4DMMM const& mmm) const
	{
		return tagMMM.compare(mmm.tagMMM) != 0;

	}

	bool CHV4DMMM::operator > (std::wstring const& mmm) const
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagMMM.compare(mmm) > 0;

	}

	bool CHV4DMMM::operator > (CHV4DMMM const& mmm) const
	{
		return tagMMM.compare(mmm.tagMMM) > 0;

	}

	bool CHV4DMMM::operator < (std::wstring const& mmm) const
	{
		try
		{
			IsValidMMM(mmm);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagMMM.compare(mmm) < 0;

	}

	bool CHV4DMMM::operator < (CHV4DMMM const& mmm) const
	{
		return tagMMM.compare(mmm.tagMMM) < 0;

	}

	std::wstring CHV4DMMM::operator()() const
	{
		return tagMMM;

	}

	void CHV4DMMM::AsTuple(std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> val) const
	{
		std::uint32_t mil{}, maj{}, min{};

		std::wstring str_mil{ tagMMM[0] };

		std::wstring str_maj{ &tagMMM[1], &tagMMM[3] };

		std::wstring str_min{ &tagMMM[4], &tagMMM[6] };

		mil = std::wcstoul(str_mil.c_str(), nullptr, 10);

		maj = std::wcstoul(str_maj.c_str(), nullptr, 10);

		min = std::wcstoul(str_min.c_str(), nullptr, 10);

		val = std::tuple{ mil, maj, min };

	}

}