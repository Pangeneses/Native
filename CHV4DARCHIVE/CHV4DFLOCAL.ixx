module;

#include <string>

#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DFLOCAL;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFILE;

export namespace CHV4DARCHIVE
{
	class CHV4DFLOCAL
	{
	public:
		CHV4DFLOCAL();

	public:
		typedef struct CLocalFileHeader {
			std::pair<uint32_t, char*> Field[12]{
				/*00*/ {  0, new char[4] },	//Local file header signature = 0x04034b50 (PK\3\4)
				/*01*/ {  4, new char[2] },	//Version needed to extract(minimum)
				/*02*/ {  6, new char[2] },	//General purpose bit flag
				/*03*/ {  8, new char[2] },	//Compression method; e.g.none = 0, DEFLATE = 8
				/*04*/ { 10, new char[2] },	//File last modification time
				/*05*/ { 12, new char[2] },	//File last modification date
				/*06*/ { 14, new char[4] },	//CRC - 32 of uncompressed data
				/*07*/ { 18, new char[4] },	//Compressed size(or 0xffffffff for ZIP64)
				/*08*/ { 22, new char[4] },	//Uncompressed size(or 0xffffffff for ZIP64)
				/*09*/ { 26, new char[2] },	//File name length(n)
				/*10*/ { 28, new char[2] },	//Extra field length(m)
				/*11*/ { 30, nullptr 	 } };//File name
			std::pair<uint32_t, char*> ExtraField;
		} CLocalFileHeader;

		typedef struct FileStream {
			DEFLATE_COMPRESSION deflate;
			CLocalFileHeader LocalFileHeader;
			std::vector<unsigned char> stream;
		} FileStream;

		typedef std::shared_ptr<std::vector<FileStream>> FLocalIndex;

	public:
		FLocalIndex RefFLocalIndex() { return Index; }

	private:
		FLocalIndex Index;

	public:
		ARCHIVE_ERROR IndexLocalFiles(CHV4DFILE const& archive);

		ARCHIVE_ERROR DecompressArchive(CHV4DFILE const& archive);

		ARCHIVE_ERROR CompressArchive(CHV4DFILE const& archive);

	private:
		CHV4DFILE Archive;

	};

}