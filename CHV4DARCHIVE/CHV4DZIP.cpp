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
	ARCHIVE_ERROR CHV4DARCHIVE::OpenArchive(std::string const& archive)
	{
		if (archive.empty()) throw std::invalid_argument{ "No archive specified" };

		std::filesystem::path directory{ archive };

		if (!std::filesystem::is_directory(directory.parent_path())) return ARCHIVE_ERROR_DIR_DNE;

		if (!std::filesystem::exists(directory)) return ARCHIVE_ERROR_ARCHIVE_DNE;

		Archive.directory = directory.parent_path();

		Archive.file = directory.filename();

		if (EndOfCentralDir.ReadEndOfCentralDir(Archive) != ARCHIVE_ERROR_SUCCEEDED) throw std::runtime_error{ "Malformed archive." };

		if (CentralDirHeader.LoadCentralDirHeader(EndOfCentralDir) != ARCHIVE_ERROR_SUCCEEDED) throw std::runtime_error{ "Malformed archive." };

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::CreateArchive(std::string const& archive, std::vector<std::string const&> const& files, bool compressed)
	{
		std::vector<std::string const&>::const_iterator FileItt;



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ExtractArchive(std::string const& dir)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::AddFilesToCurrentArchive(std::vector<std::string const&> const& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::AddStreamToCurrentArchive(CHV4DLFH const& stream)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::string const& dir)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::vector<CHV4DLFH const&>& streams)
	{




		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DARCHIVE::RenameFileInArchive(std::string const& from, std::string const& to)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}