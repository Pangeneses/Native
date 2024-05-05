module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DLFH;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DLFH::LoadAndInflateStream()
	{
		StreamBuffer.clear();

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DLFH::ReturnInflatedStream(std::shared_ptr<std::vector<unsigned char>>)
	{
		StreamBuffer.clear();

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DLFH::DeflateAndReturnStream(std::shared_ptr<std::vector<unsigned char>>)
	{
		StreamBuffer.clear();

		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}