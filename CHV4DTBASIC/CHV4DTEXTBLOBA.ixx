module;

#include <string>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DTEXTBLOBA;

export namespace CHV4DTBASIC
{
	class CHV4DTEXTBLOBA
	{
	public:
		CHV4DTEXTBLOBA();

		CHV4DTEXTBLOBA(std::string const& blobA);

		CHV4DTEXTBLOBA(CHV4DTEXTBLOBA const& blobA);

	private:
		void IsValidTextBlobA(std::string const& blobA) const;

	public:
		void operator = (std::string const& blobA);

		void operator = (CHV4DTEXTBLOBA const& blobA);

		bool operator == (std::string const& blobA) const;

		bool operator == (CHV4DTEXTBLOBA const& blobA) const;

		std::string operator()() const;

		CHV4DTEXTBLOBA operator()(std::uint64_t const& from, std::uint64_t const& to);

	private:
		std::string tagTEXTBLOBA{};

	};

}
