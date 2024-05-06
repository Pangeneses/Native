module;

#include <string>

#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DZIP;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DEOCD;
import :CHV4DCDFH;
import :CHV4DLFH;

export namespace CHV4DARCHIVE
{
	class CHV4DARCHIVE
	{
	public:
		CHV4DARCHIVE() = default;

	public:		
		ARCHIVE_ERROR OpenArchive(std::string const& archive);

		ARCHIVE_ERROR CreateArchive(std::string const& archive, std::vector<std::string const&> const& files, bool compressed = true);

		ARCHIVE_ERROR ExtractArchive(std::string const& dir);

		ARCHIVE_ERROR AddFilesToCurrentArchive(std::vector<std::string const&> const& files);

		ARCHIVE_ERROR AddStreamToCurrentArchive(CHV4DLFH const& stream);

		ARCHIVE_ERROR ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::string const& dir);

		ARCHIVE_ERROR ExtractFilesFromArchive(std::vector<std::string const&> const& files, std::vector<CHV4DLFH const&>& streams);

		ARCHIVE_ERROR RenameFileInArchive(std::string const& from, std::string const& to);
		
	private:
		ZARCHIVE Archive;

		CHV4DEOCD EndOfCentralDir;

		CHV4DCDFH CentralDirHeader;

		std::vector<CHV4DLFH> FileStreams;
	
	};

}
