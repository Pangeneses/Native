module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DEOCD;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFILE;

namespace CHV4DARCHIVE
{	
	CHV4DEOCD::CHV4DEOCD()
	{



	}

	ARCHIVE_ERROR CHV4DEOCD::ReadEndOfCentralDir(CHV4DFILE const& file)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

}