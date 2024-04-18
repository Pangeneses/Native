module;

#include <string>

#include <vector>

#include <stdexcept>

export module CHV4DTBASIC:CHV4DTEXTBLOBW;

export namespace CHV4DTBASIC
{
	class CHV4DTEXTBLOBW
	{
	public:
		CHV4DTEXTBLOBW();

		CHV4DTEXTBLOBW(std::wstring const& blobW);

		CHV4DTEXTBLOBW(CHV4DTEXTBLOBW const& blobW);

	private:
		void IsValidTextBlobW(std::wstring const& blobW) const;

	public:
		void operator = (std::wstring const& blobW);

		void operator = (CHV4DTEXTBLOBW const& blobW);

		bool operator == (std::wstring const& blobW) const;

		bool operator == (CHV4DTEXTBLOBW const& blobW) const;

		std::wstring operator()() const;

		CHV4DTEXTBLOBW operator()(std::uint64_t const& from, std::uint64_t const& to);

	private:
		std::wstring tagTEXTBLOBW{};

	};

}
