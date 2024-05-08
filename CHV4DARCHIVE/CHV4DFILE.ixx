module;

#include <string>

#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DFILE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import CHV4DTBASIC;

export namespace CHV4DARCHIVE
{
	class CHV4DFILE
	{
	public:
		CHV4DFILE();

	public:
		CHV4DTBASIC::CHV4DHVID& FileUUID;

		CHV4DTBASIC::CHV4DMAXPATH directory;

		CHV4DTBASIC::CHV4DMAXPATH file;

		CHV4DTBASIC::CHV4DMMDDYYYY date;

		CHV4DTBASIC::CHV4DHHMMSS time;

	private:
		CHV4DTBASIC::CHV4DHVID uuid;

		CHV4DTBASIC::CHV4DMAXPATH directory;

		CHV4DTBASIC::CHV4DMAXPATH file;

		CHV4DTBASIC::CHV4DMMDDYYYY date;

		CHV4DTBASIC::CHV4DHHMMSS time;

	};

}