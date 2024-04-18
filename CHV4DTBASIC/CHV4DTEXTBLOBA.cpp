module;

#include <string>

#include <vector>

#include <stdexcept>

module CHV4DTBASIC:CHV4DTEXTBLOBA;

namespace CHV4DTBASIC
{
	CHV4DTEXTBLOBA::CHV4DTEXTBLOBA()
	{

		return;

	}

	CHV4DTEXTBLOBA::CHV4DTEXTBLOBA(std::string const& blobA)
	{
		tagTEXTBLOBA = blobA;

		return;

	}

	CHV4DTEXTBLOBA::CHV4DTEXTBLOBA(CHV4DTEXTBLOBA const& blobA)
	{
		tagTEXTBLOBA = blobA.tagTEXTBLOBA;

		return;

	}

	void CHV4DTEXTBLOBA::operator = (std::string const& blobA)
	{
		tagTEXTBLOBA = blobA;

		return;

	}

	void CHV4DTEXTBLOBA::operator = (CHV4DTEXTBLOBA const& blobA)
	{
		tagTEXTBLOBA = blobA.tagTEXTBLOBA;

		return;

	}

	bool CHV4DTEXTBLOBA::operator == (std::string const& blobA) const
	{
		return tagTEXTBLOBA.compare(blobA) == 0;

	}

	bool CHV4DTEXTBLOBA::operator == (CHV4DTEXTBLOBA const& blobA) const
	{
		return tagTEXTBLOBA.compare(blobA.tagTEXTBLOBA) == 0;

	}

	std::string CHV4DTEXTBLOBA::operator()() const
	{
		return tagTEXTBLOBA;

	}

	CHV4DTEXTBLOBA CHV4DTEXTBLOBA::operator()(std::uint64_t const& from, std::uint64_t const& to)
	{
		return tagTEXTBLOBA.substr(from, to);

	}

}