module;

#include <string>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DALPHANUMERIC;

export namespace CHV4DTBASIC
{
	class CHV4DALPHANUMERIC
	{
	public:
		CHV4DALPHANUMERIC();

		CHV4DALPHANUMERIC(std::wstring const& reduced);

		CHV4DALPHANUMERIC(CHV4DALPHANUMERIC const& reduced);

	private:
		void IsValidAlphaNumeric(std::wstring const& reduced) const;

	public:
		void operator = (std::wstring const& reduced);

		void operator = (CHV4DALPHANUMERIC const& reduced);

		bool operator == (std::wstring const& reduced) const;

		bool operator == (CHV4DALPHANUMERIC const& reduced) const;

		std::wstring operator()() const;

	private:
		std::wstring tagTEXT{};

	private:
		const std::vector<wchar_t> HV4DAlphaNumericW{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
			'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y',
			'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	};

}
