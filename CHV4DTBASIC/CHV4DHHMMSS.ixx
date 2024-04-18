module;

#include <string>

#include <vector>

#include <ctime>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DHHMMSS;

export namespace CHV4DTBASIC
{
	class CHV4DHHMMSS
	{
	public:
		CHV4DHHMMSS();

		CHV4DHHMMSS(std::wstring const& hhmmss);

		CHV4DHHMMSS(CHV4DHHMMSS const& hhmmss);

	private:
		void IsValidHHMMSS(std::wstring const& hhmmss) const;

	public:
		void operator = (std::wstring const& hhmmss);

		void operator = (CHV4DHHMMSS const& hhmmss);

		bool operator == (std::wstring const& hhmmss) const;

		bool operator == (CHV4DHHMMSS const& hhmmss) const;

		bool operator != (std::wstring const& hhmmss) const;

		bool operator != (CHV4DHHMMSS const& hhmmss) const;

		bool operator > (std::wstring const& hhmmss) const;

		bool operator > (CHV4DHHMMSS const& hhmmss) const;

		bool operator < (std::wstring const& hhmmss) const;

		bool operator < (CHV4DHHMMSS const& hhmmss) const;

		std::wstring operator()() const;

		void AsTuple(std::tuple<std::uint8_t, std::uint8_t, std::uint8_t> hhmmss) const;

		void Current();

	private:
		std::wstring tagHHMMSS{};

	private:
		const std::vector<std::wstring> HV4DHourW{ L"00", L"01", L"02", L"03", L"04", L"05", L"06", L"07", L"08", L"09", L"10",
			L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23" };

		const std::vector<std::wstring> HV4D59W{ L"00", L"01", L"02", L"03", L"04", L"05", L"06", L"07", L"08", L"09", L"10",
			L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"26", L"27", L"28",
			L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44",
			L"45", L"46", L"47", L"48", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59" };

	};

}
