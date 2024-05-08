module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DCDFH;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFILE;
import :CHV4DEOCD;

namespace CHV4DARCHIVE
{
	CHV4DCDFH::CHV4DCDFH()
	{



	}

	ARCHIVE_ERROR CHV4DCDFH::ReadCentralDirHeader(CHV4DFILE const& file)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}