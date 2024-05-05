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

		ARCHIVE_ERROR ExtractArchive(std::vector<std::string const&>& files);

		ARCHIVE_ERROR AddFilesToCurrentArchive(std::vector<std::string const&> const& files);

		ARCHIVE_ERROR AddStreamToCurrentArchive(std::vector<unsigned char> const& buffer);

		ARCHIVE_ERROR ReleaseFilesFromArchive(std::vector<std::string const&>& files);

		ARCHIVE_ERROR ReleaseStreamFromArchive(std::string const& file, std::vector<unsigned char>& buffer);

		ARCHIVE_ERROR RenameFileInArchive(std::string const& from, std::string const& to);
		
	private:
		std::shared_ptr<ZARCHIVE> Archive;

		CHV4DEOCD EndOfCentralDir;

		CHV4DCDFH CentralDirHeader;

		std::shared_ptr<std::vector<CHV4DLFH>> FileHeaders;
	
	};

}
