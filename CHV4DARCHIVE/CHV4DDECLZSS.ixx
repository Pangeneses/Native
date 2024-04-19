module;

#include <fstream>
#include <string>

#include <vector>
#include <list>
#include <map>

export module CHV4DARCHIVE:CHV4DDECLZSS;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DARCHIVE
{
	class CHV4DDECLZSS
	{
	public:
		CHV4DDECLZSS() = default;

	public:
		ARCHIVE_ERROR DecompressStreamLZSS(
			std::vector<uint8_t> const& in,
			std::vector<uint8_t>& out,
			size_t const& window = 15);

		ARCHIVE_ERROR DecompressOnDiskLZSS(
			std::string const& in,
			std::string& out,
			size_t const& window = 15);

	};

}