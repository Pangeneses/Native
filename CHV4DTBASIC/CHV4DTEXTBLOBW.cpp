module;

#include <string>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DTEXTBLOBW;

namespace CHV4DTBASIC
{
	CHV4DTEXTBLOBW::CHV4DTEXTBLOBW()
	{

		return;

	}

	CHV4DTEXTBLOBW::CHV4DTEXTBLOBW(std::wstring const& blobW)
	{
		tagTEXTBLOBW = blobW;

		return;

	}

	CHV4DTEXTBLOBW::CHV4DTEXTBLOBW(CHV4DTEXTBLOBW const& blobW)
	{
		tagTEXTBLOBW = blobW.tagTEXTBLOBW;

		return;

	}

	void CHV4DTEXTBLOBW::operator = (std::wstring const& blobW)
	{
		tagTEXTBLOBW = blobW;

		return;

	}

	void CHV4DTEXTBLOBW::operator = (CHV4DTEXTBLOBW const& blobW)
	{
		tagTEXTBLOBW = blobW.tagTEXTBLOBW;

		return;

	}

	bool CHV4DTEXTBLOBW::operator == (std::wstring const& blobW) const
	{
		return tagTEXTBLOBW.compare(blobW) == 0;

	}

	bool CHV4DTEXTBLOBW::operator == (CHV4DTEXTBLOBW const& blobW) const
	{
		return tagTEXTBLOBW.compare(blobW.tagTEXTBLOBW) == 0;

	}

	std::wstring CHV4DTEXTBLOBW::operator()() const
	{
		return tagTEXTBLOBW;

	}

	CHV4DTEXTBLOBW CHV4DTEXTBLOBW::operator()(std::uint64_t const& from, std::uint64_t const& to)
	{
		return tagTEXTBLOBW.substr(from, to);

	}

}