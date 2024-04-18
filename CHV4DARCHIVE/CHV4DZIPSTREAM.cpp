module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIPSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ZIP_ERROR CHV4DZIPSTREAM::LoadAndInflateStream(std::vector<uint8_t> const& buffer)
	{


		return CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

	}

	ZIP_ERROR CHV4DZIPSTREAM::ReturnInflatedStream(std::vector<uint8_t>& buffer)
	{


		return CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

	}

	ZIP_ERROR CHV4DZIPSTREAM::DeflateAndReturnStream(std::vector<uint8_t>& buffer)
	{


		return CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

	}

}