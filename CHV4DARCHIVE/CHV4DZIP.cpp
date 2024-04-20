module;

#include <iostream>
#include <fstream>

#include <filesystem>

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIP;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DARCHIVE::OpenArchive(std::string const& archive, size_t const& sz)
	{
		std::filesystem::path directory{ archive };

		if (!std::filesystem::is_directory(directory.parent_path())) return ARCHIVE_ERROR_DIR_DNE;

		if (!std::filesystem::exists(directory)) return ARCHIVE_ERROR_ARCHIVE_DNE;

		File.directory = directory.parent_path();

		File.file = directory.filename();

		File.window = sz;

		Header.OpenArchive(File);

		Appendix.LoadAppendixFromHeader(Header);



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::CreateArchive(std::string const& archive, std::vector<std::string> const& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ExtractArchive(std::vector<std::string>& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::AddFilesToCurrentArchive(std::vector<std::string> const& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::AddStreamToCurrentArchive(std::vector<uint8_t> const& buffer)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ReleaseFilesFromArchive(std::vector<std::string> const& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ReleaseStreamFromArchive(std::string const& file, std::vector<uint8_t> const& buffer)
	{




		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::RenameFileInArchive(std::string const& from, std::string const& to)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

}