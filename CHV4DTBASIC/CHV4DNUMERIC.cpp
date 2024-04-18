module;

#include <string>

#include <cstdint>

#include <vector>

#include <climits>

#include <stdexcept>

module CHV4DTBASIC:CHV4DNUMERIC;

namespace CHV4DTBASIC
{
	CHV4DNUMERIC::CHV4DNUMERIC()
	{


		return;

	}

	CHV4DNUMERIC::CHV4DNUMERIC(std::int64_t const& num)
	{
		tagNUM = num;

		return;

	}

	CHV4DNUMERIC::CHV4DNUMERIC(std::wstring const& num)
	{
		try
		{
			tagNUM = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return;

	}

	CHV4DNUMERIC::CHV4DNUMERIC(CHV4DNUMERIC const& num)
	{
		tagNUM = num.tagNUM;

		return;

	}

	std::int64_t CHV4DNUMERIC::StringToInt(std::wstring const& num) const
	{
		std::int64_t number{};

		std::wstring::const_iterator citt{};

		for (wchar_t itt : num)
		{
			citt = std::find(num.begin(), num.end(), itt);

			if (citt == num.end())
			{
				throw std::domain_error("");

			}

		}

		number = std::wcstoull(&num[0], nullptr, 10);

		if (number == ULLONG_MAX)
		{
			number = 0;

			throw std::invalid_argument("");

		}

		return number;

	}

	void CHV4DNUMERIC::operator = (std::wstring const& num)
	{
		try
		{
			tagNUM = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return;

	}

	void CHV4DNUMERIC::operator = (std::int64_t const& num)
	{
		tagNUM = num;

		return;

	}

	void CHV4DNUMERIC::operator = (CHV4DNUMERIC const& num)
	{
		tagNUM = num.tagNUM;

		return;

	}

	bool CHV4DNUMERIC::operator == (std::wstring const& num) const
	{
		std::int64_t number{};

		try
		{
			number = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagNUM == number;

	}

	bool CHV4DNUMERIC::operator == (std::int64_t const& num) const
	{

		return tagNUM == num;

	}

	bool CHV4DNUMERIC::operator == (CHV4DNUMERIC const& num) const
	{

		return tagNUM == num.tagNUM;

	}

	bool CHV4DNUMERIC::operator != (std::wstring const& num) const
	{
		std::int64_t number{};

		try
		{
			number = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagNUM != number;

	}

	bool CHV4DNUMERIC::operator != (std::int64_t const& num) const
	{

		return tagNUM != num;

	}

	bool CHV4DNUMERIC::operator != (CHV4DNUMERIC const& num) const
	{

		return tagNUM != num.tagNUM;

	}

	bool CHV4DNUMERIC::operator < (std::wstring const& num) const
	{
		std::int64_t number{};

		try
		{
			number = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagNUM < number;

	}

	bool CHV4DNUMERIC::operator < (std::int64_t const& num) const
	{

		return tagNUM < num;

	}

	bool CHV4DNUMERIC::operator < (CHV4DNUMERIC const& num) const
	{

		return tagNUM < num.tagNUM;

	}

	bool CHV4DNUMERIC::operator > (std::wstring const& num) const
	{
		std::int64_t number{};

		try
		{
			number = StringToInt(num);

		}
		catch (std::domain_error)
		{
			throw std::invalid_argument("");

		}

		return tagNUM > number;

	}

	bool CHV4DNUMERIC::operator > (std::int64_t const& num) const
	{

		return tagNUM > num;

	}

	bool CHV4DNUMERIC::operator > (CHV4DNUMERIC const& num) const
	{

		return tagNUM > num.tagNUM;

	}

	std::int64_t CHV4DNUMERIC::operator()() const
	{
		return tagNUM;

	}

}