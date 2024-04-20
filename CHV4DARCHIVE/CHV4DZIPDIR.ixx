module;

#include <string>

#include <vector>

export module CHV4DARCHIVE:CHV4DZIPDIR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DZIPEOF;
import :CHV4DZIPSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DZIPDIR
	{
	public:
		CHV4DZIPDIR() = default;

	public:
		ARCHIVE_ERROR LoadAppendixFromHeader(CHV4DZIPEOF const& header);

		ARCHIVE_ERROR LoadAppendixFromHeader(std::vector<CHV4DZIPSTREAM>& streams);

	private:
		typedef struct Entry {
			std::pair<uint32_t, char*> Field[18]{
			/*00*/{  0, new char[4] }, /*Central Directory 0x02014b50*/
			/*01*/{  4, new char[2] }, /*Version*/
			/*02*/{  6, new char[2] }, /*Minimum*/
			/*03*/{  8, new char[2] }, /*GPBit*/
			/*04*/{ 10, new char[2] }, /*Compression*/
			/*05*/{ 12, new char[2] }, /*Modified Time*/
			/*06*/{ 14, new char[2] }, /*Modified Date*/
			/*07*/{ 16, new char[4] }, /*CRC-32*/
			/*08*/{ 20, new char[4] }, /*Compressed Sz*/
			/*09*/{ 24, new char[4] }, /*Uncompressed Sz*/
			/*10*/{ 28, new char[2] }, /*Name Length*/
			/*11*/{ 30, new char[2] }, /*Field Length*/
			/*12*/{ 32, new char[2] }, /*Comment Length*/
			/*13*/{ 34, new char[2] }, /*Disk Start*/
			/*14*/{ 36, new char[2] }, /*Internal Attributes*/
			/*15*/{ 38, new char[4] }, /*External Attributes*/
			/*16*/{ 42, new char[4] }, /*Relative Offset*/
			/*17*/{ 46, nullptr		} };/*Filename*/
			std::pair<uint32_t, char*> ExtraField;
			std::pair<uint32_t, char*> FileComment;
		} Entry;

	private:
		std::vector<Entry> CentralDirectoryHeaders;

	};

}