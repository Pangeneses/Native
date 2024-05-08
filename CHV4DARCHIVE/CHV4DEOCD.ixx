module;

#include <string>

#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DEOCD;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DFILE;

export namespace CHV4DARCHIVE
{
	class CHV4DEOCD
	{
	public:
		CHV4DEOCD();

	public:
		typedef struct CEndOfCentralDir {
			std::pair<uint32_t, char*> Field[9]{
				/*0*/ {  0, new char[4] }, /*Central Directory EOF 0x06054b50*/
				/*1*/ {  4, new char[2] }, /*Current Disk*/
				/*2*/ {  6, new char[2] }, /*Central Directory Start Disk*/
				/*3*/ {  8, new char[2] }, /*Central Directory Records on Disk*/
				/*4*/ { 10, new char[2] }, /*Number of Records*/
				/*5*/ { 12, new char[4] }, /*Byte Size Central Directory*/
				/*6*/ { 16, new char[4] }, /*Central Directory Offset*/
				/*7*/ { 20, new char[2] }, /*Comment Length*/
				/*8*/ { 22, nullptr     } };/*Comment*/
		} CEndOfCentralDir;

		std::shared_ptr<CEndOfCentralDir> RefEndOfCentralDir() { return EndOfCentralDir; }

	private:
		std::shared_ptr<CEndOfCentralDir> EndOfCentralDir;

	public:
		ARCHIVE_ERROR ReadEndOfCentralDir(CHV4DFILE const& file);

	};

}