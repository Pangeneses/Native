module;

#include "windows.h"

#include "fileapi.h"
#include "io.h"
#include "fcntl.h"

#include <string>
#include <vector>

#include <stdexcept>

module CHV4DENCODE:FileView;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :StreamView;

namespace CHV4DENCODE
{
	void FileView::LoadDocument(
		File file,
		ENCODING const& encode,
		ENDIANNESS const& endianness)
	{
		if (std::strcmp(file, "")) throw std::invalid_argument{ "No file specified." };

		currentPath = file;

		if (encode == ENCODING_UNKNOWN || endianness == ENDIANNESS_UNSPECIFIED)
			throw std::invalid_argument{ "Unspecified currently not supported" };

		int hFile{ -1 };

		errno_t error = _sopen_s(&hFile, file, _O_BINARY | _O_RDONLY | _O_SEQUENTIAL, _SH_DENYWR, _S_IREAD);

		if (hFile == -1 || error == ENOENT) throw std::invalid_argument{ "Malformed file or path." };

		uint64_t fileLength = 0;

		if (!GetFileSizeEx(&hFile, (PLARGE_INTEGER)fileLength)) throw std::invalid_argument{ "Malformed file." };

		char8_t* buffer = new char8_t[fileLength];

		int bytesRead = _read(hFile, buffer, (UINT)fileLength);

		if (bytesRead <= 0) throw std::invalid_argument{ "Malformed file." };

		bytesRead = streamView.SetSream({ buffer, buffer + fileLength }, encode, endianness);

		delete buffer;

		_close(hFile);

	}

	void FileView::OverwriteDocument(
		ENCODING const& encode,
		ENDIANNESS const& endianness,
		bool BOM)
	{
		if (encode == ENCODING_UNKNOWN || endianness == ENDIANNESS_UNSPECIFIED)
			throw std::invalid_argument{ "Unspecified currently not supported" };

		int hFile{ -1 };

		errno_t error = _sopen_s(&hFile, currentPath.c_str(), _O_BINARY | _O_RANDOM | _O_TRUNC, _SH_DENYRW, _S_IREAD | _S_IWRITE);

		if (hFile == -1 || error == ENOENT) throw std::invalid_argument{ "Malformed file or path." };



	}

	void FileView::WriteDocument(
		File file,
		ENCODING const& encode,
		ENDIANNESS const& endianness,
		bool BOM)
	{
		if (encode == ENCODING_UNKNOWN || endianness == ENDIANNESS_UNSPECIFIED)
			throw std::invalid_argument{ "Unspecified currently not supported" };

		int hFile{ -1 };

		errno_t error = _sopen_s(&hFile, currentPath.c_str(), _O_BINARY | _O_RANDOM | _O_TRUNC, _SH_DENYRW, _S_IREAD | _S_IWRITE);

		if (hFile == -1 || error == ENOENT) throw std::invalid_argument{ "Malformed file or path." };

	}

	StreamView& FileView::operator()() { return streamView; }

}