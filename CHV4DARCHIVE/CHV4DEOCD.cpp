module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DEOCD;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DLFH;

namespace CHV4DARCHIVE
{	
	ARCHIVE_ERROR CHV4DEOCD::ReadArchiveHeader(FileStream stream)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

}