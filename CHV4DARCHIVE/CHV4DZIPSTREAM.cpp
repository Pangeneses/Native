module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIPSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DZIPSTREAM::LoadAndInflateStream(std::vector<uint8_t> const& buffer)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIPSTREAM::ReturnInflatedStream(std::vector<uint8_t>& buffer)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIPSTREAM::DeflateAndReturnStream(std::vector<uint8_t>& buffer)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

}