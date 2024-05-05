module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DLFH;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DLFH::LoadAndInflateStream(std::vector<uint8_t> const& buffer)
	{
		buffer.empty();

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DLFH::ReturnInflatedStream(std::vector<uint8_t>& buffer)
	{
		buffer.empty();

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DLFH::DeflateAndReturnStream(std::vector<uint8_t>& buffer)
	{
		buffer.empty();

		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}