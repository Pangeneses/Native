module;

#include <string>

#include <cstdint>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DMMM;

export namespace CHV4DTBASIC
{
	class CHV4DMMM
	{
	public:
		CHV4DMMM();

		CHV4DMMM(std::wstring const& mmm);

		CHV4DMMM(std::uint32_t const& mil, std::uint32_t const& maj, std::uint32_t const& min);

		CHV4DMMM(CHV4DMMM const& mmm);

	private:
		void IsValidMMM(std::wstring const& mmm) const;

	public:
		void operator = (std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> mmm);

		void operator = (std::wstring const& mmm);

		void operator = (CHV4DMMM const& mmm);

		bool operator == (std::wstring const& mmm) const;

		bool operator == (CHV4DMMM const& mmm) const;

		bool operator != (std::wstring const& mmm) const;

		bool operator != (CHV4DMMM const& mmm) const;

		bool operator > (std::wstring const& mmm) const;

		bool operator > (CHV4DMMM const& mmm) const;

		bool operator < (std::wstring const& mmm) const;

		bool operator < (CHV4DMMM const& mmm) const;

		std::wstring operator()() const;

		void AsTuple(std::tuple<std::uint32_t, std::uint32_t, std::uint32_t> mmm) const;

	private:
		std::wstring tagMMM{};

	private:
		const std::vector<wchar_t> HV4DNumericW{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	};

}

