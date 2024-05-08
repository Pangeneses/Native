module;

#include <string>

#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DZIP;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFILE;
import :CHV4DFLOCAL;

export namespace CHV4DARCHIVE
{
	class CHV4DZIP
	{
	public:
		CHV4DZIP();

	public:		
		ARCHIVE_ERROR OpenArchive(std::string const& archive);

		ARCHIVE_ERROR CreateArchive(std::string const& archive, std::vector<std::string const&> const& files, bool compressed = true);

		ARCHIVE_ERROR ExtractArchive(std::string const& dir);

		ARCHIVE_ERROR AddFilesToCurrentArchive(std::vector<std::string const&> const& files);

		ARCHIVE_ERROR AddStreamToCurrentArchive(std::shared_ptr<CHV4DFLOCAL> stream);

		ARCHIVE_ERROR ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::string const& dir);

		ARCHIVE_ERROR ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::shared_ptr<std::vector<CHV4DFLOCAL>> streams);

		ARCHIVE_ERROR RenameFileInArchive(std::string const& from, std::string const& to);

		ARCHIVE_ERROR DeleteFileFromArchive(std::string const& file);

	private:
		CHV4DFILE Archive;

		CHV4DFLOCAL LocalFiles;

	private:
		ARCHIVE_ERROR ValidateArchive();

	};

}
