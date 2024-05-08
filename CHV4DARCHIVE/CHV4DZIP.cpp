module;

//#include <iostream>
//#include <fstream>

#include <filesystem>

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIP;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{	
	CHV4DZIP::CHV4DZIP()
	{



	}

	ARCHIVE_ERROR CHV4DZIP::OpenArchive(std::string const& archive)
	{
		if (archive.empty()) throw std::invalid_argument{ "No archive specified" };

		std::filesystem::path directory{ archive };

		if (!std::filesystem::is_directory(directory.parent_path())) return ARCHIVE_ERROR_DIR_DNE;

		if (!std::filesystem::exists(directory)) return ARCHIVE_ERROR_ARCHIVE_DNE;

		//Archive.directory = directory.parent_path();

		//Archive.file = directory.filename();

		if (LocalFiles.IndexLocalFiles(Archive) != ARCHIVE_ERROR_SUCCEEDED) throw std::runtime_error{ "Malformed archive." };

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::CreateArchive(std::string const& archive, std::vector<std::string const&> const& files, bool compressed)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::ExtractArchive(std::string const& dir)
	{


		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::AddFilesToCurrentArchive(std::vector<std::string const&> const& files)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::AddStreamToCurrentArchive(std::shared_ptr<CHV4DFLOCAL> stream)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::string const& dir)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::shared_ptr<std::vector<CHV4DFLOCAL>> streams)
	{




		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::RenameFileInArchive(std::string const& from, std::string const& to)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::ValidateArchive()
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIP::DeleteFileFromArchive(std::string const& file)
	{



		return ARCHIVE_ERROR_SUCCEEDED;

	}

}