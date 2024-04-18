module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIPEOF;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ZIP_ERROR CHV4DZIPEOF::OpenArchive(CHV4DARCHIVE::Archive& archive)
	{



		return ZIP_ERROR_SUCCEEDED;

	}

	ZIP_ERROR CHV4DZIPEOF::AppendNewHeaderToArchive(CHV4DARCHIVE::Archive& archive)
	{



		return ZIP_ERROR_SUCCEEDED;

	}

}