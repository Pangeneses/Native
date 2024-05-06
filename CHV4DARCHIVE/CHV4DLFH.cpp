module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DLFH;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	CHV4DLFH::CHV4DLFH()
	{



	}

	ARCHIVE_ERROR CHV4DLFH::InflateStream()
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DLFH::DeflateStream()
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}