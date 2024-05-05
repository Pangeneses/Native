module;

#include <string>

#include <vector>

module CHV4DARCHIVE:CHV4DCDFH;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DEOCD;
import :CHV4DLFH;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DCDFH::LoadCentralDirHeader(CHV4DEOCD const& EOCD)
	{
		CHV4DEOCD Header = EOCD;
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
		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DCDFH::IndexStreams(std::vector<CHV4DLFH>& streams)
	{
		streams.clear();


		return ARCHIVE_ERROR_SUCCEEDED;

	}
	
}