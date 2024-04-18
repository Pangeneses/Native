module;

#include <string>

#include <cstdint>

#include <vector>

#include <climits>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DNUMERIC;

export namespace CHV4DTBASIC
{
	class CHV4DNUMERIC
	{
	public:
		CHV4DNUMERIC();

		CHV4DNUMERIC(std::int64_t const& num);

		CHV4DNUMERIC(std::wstring const& num);

		CHV4DNUMERIC(CHV4DNUMERIC const& num);

	private:
		std::int64_t StringToInt(std::wstring const& num) const;

	public:
		void operator = (std::wstring const& num);

		void operator = (std::int64_t const& num);

		void operator = (CHV4DNUMERIC const& num);

		bool operator == (std::wstring const& num) const;

		bool operator == (std::int64_t const& num) const;

		bool operator == (CHV4DNUMERIC const& num) const;

		bool operator != (std::wstring const& num) const;

		bool operator != (std::int64_t const& num) const;

		bool operator != (CHV4DNUMERIC const& num) const;

		bool operator < (std::wstring const& num) const;

		bool operator < (std::int64_t const& num) const;

		bool operator < (CHV4DNUMERIC const& num) const;

		bool operator > (std::wstring const& num) const;

		bool operator > (std::int64_t const& num) const;

		bool operator > (CHV4DNUMERIC const& num) const;

		std::int64_t operator()() const;

	private:
		std::int64_t tagNUM;

	private:
		const std::vector<wchar_t> HV4DNumericW{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	};

}

