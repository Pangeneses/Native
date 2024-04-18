module;

#include <string>

#include <cstdint>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DHEX;

export namespace CHV4DTBASIC
{
	class CHV4DHEX
	{
	public:
		CHV4DHEX();

		CHV4DHEX(std::uint64_t const& hex);

		CHV4DHEX(std::wstring const& hex);

		CHV4DHEX(CHV4DHEX const& hex);

	private:
		void IsValidHEX(std::wstring const& hex) const;

	public:
		void operator = (std::uint64_t const& hex);

		void operator = (std::wstring const& hex);

		void operator = (CHV4DHEX const& hex);

		bool operator == (std::wstring const& hex) const;

		bool operator == (CHV4DHEX const& hex) const;

		std::wstring operator()() const;

	private:
		std::wstring tagHEX{};

	private:
		const std::vector<wchar_t> HV4DHexW{ '0', '1', '2', '3', '4', '5', '6', '7', '8',
			'9', 'A', 'a', 'B', 'b', 'C', 'c', 'D', 'd', 'E', 'e', 'F', 'f' };

	};

}
