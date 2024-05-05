module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DEOCD;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DLFH;

namespace CHV4DARCHIVE
{	
	ARCHIVE_ERROR CHV4DEOCD::ReadEndOfCentralDir(std::shared_ptr<ZARCHIVE> archive)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DEOCD::AppendToArchive(std::shared_ptr<std::vector<CHV4DLFH>> streams)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}