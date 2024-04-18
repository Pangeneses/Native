module;

#include <string>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DMAXPATH;

export namespace CHV4DTBASIC
{
	class CHV4DMAXPATH
	{
	public:
		CHV4DMAXPATH();

		CHV4DMAXPATH(std::wstring const& maxpath);

		CHV4DMAXPATH(CHV4DMAXPATH const& maxpath);

	private:
		void IsValidMAXPATH();

	public:
		void operator = (std::wstring const& maxpath);

		void operator = (CHV4DMAXPATH const& maxpath);

		bool operator == (std::wstring const& maxpath) const;

		bool operator == (CHV4DMAXPATH const& maxpath) const;

		std::wstring operator()() const;

		std::wstring operator()(std::uint64_t const&, std::uint64_t const& maxpath) const;

	private:
		std::wstring tagMAXPATH{ '\0' };

	private:
		std::vector<wchar_t> HV4DMaxPathW = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
			'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F',
			'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
			'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '_', '-', ' ', '.', '\u005C' };

	};

}
