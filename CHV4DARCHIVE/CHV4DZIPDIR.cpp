module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DZIPDIR;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DZIPEOF;
import :CHV4DZIPSTREAM;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DZIPDIR::LoadAppendixFromHeader(CHV4DARCHIVE::CHV4DZIPEOF const& header)
	{
		/*
		char at[5]{ '\0' };

		for (zip.seekg(0, zip.end); zip.tellg() != -1; zip.seekg(-1, zip.cur))
		{
			zip.read(&at[0], 1);

			CentralDirectoryEOF.append(at, 1);

			if (*at == 0x06054b50) break;

			at[3] = at[2];
			at[2] = at[1];
			at[1] = at[0];
			at[0] = '\0';

		}

		std::reverse(CentralDirectoryEOF.begin(), CentralDirectoryEOF.end());

		for (zip.seekg(0, zip.end); zip.tellg() != -1; zip.seekg(-1, zip.cur))
		{
			zip.read(&at[0], 1);

			CentralDirectoryBOF.append(at, 1);

			if (*at == 0x02014b50) break;

			at[3] = at[2];
			at[2] = at[1];
			at[1] = at[0];
			at[0] = '\0';

		}

		std::reverse(CentralDirectoryBOF.begin(), CentralDirectoryBOF.end());
		*/

		return CHV4DARCHIVE::ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DZIPDIR::LoadAppendixFromHeader(std::vector<CHV4DARCHIVE::CHV4DZIPSTREAM>& streams)
	{



		return CHV4DARCHIVE::ARCHIVE_ERROR_SUCCEEDED;

	}

}