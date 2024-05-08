module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DFLOCAL;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	CHV4DFLOCAL::CHV4DFLOCAL()
	{



	}

	ARCHIVE_ERROR CHV4DFLOCAL::IndexLocalFiles(CHV4DFILE const& archive)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DFLOCAL::DecompressArchive(CHV4DFILE const& archive)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DFLOCAL::CompressArchive(CHV4DFILE const& archive)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}