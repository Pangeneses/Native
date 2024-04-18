module;

#include <string>
#include <vector>
#include <list>
#include <map>

export module CHV4DENCODE:CHV4DRESOURCE;

import :CHV4DFORWARD;

export namespace CHV4DENCODE
{
	typedef const char* File;

	typedef bool BOM;

	typedef const char8_t* Data;

	typedef std::vector<char8_t> Buffer;

	typedef uint32_t Codepoint;

	typedef std::list<Codepoint> Text;

	typedef Text::iterator Scan;

	typedef std::list<Scan*> ScanPoints;

	typedef std::vector<std::map<Codepoint, ScanPoints>> StreamViewHash;

	typedef std::vector<std::u8string> Watchword;

	typedef std::map<const char8_t*, ScanPoints> IndexedWatchwords;

	enum ENCODING
	{
		ENCODING_UNKNOWN	= 0,
		ENCODING_ASCII		= 1,
		ENCODING_SYSTEM		= 2,
		ENCODING_UTF8		= 3,
		ENCODING_UTF16		= 4,
		ENCODING_UTF32		= 5
	};

	enum ENDIANNESS
	{
		ENDIANNESS_UNORDERED		= 0,
		ENDIANNESS_UNSPECIFIED		= 1,
		ENDIANNESS_BIG_ENDIAN		= 2,
		ENDIANNESS_LITTLE_ENDIAN    = 3
	};

	enum SACCADE
	{
		SACCADE_BEGIN_RIGHT		= 0,
		SACCADE_END_LEFT		= 1,
		SACCADE_FROM_LEFT		= 2,
		SACCADE_FROM_RIGHT		= 3
	};

	const size_t EOS{ 0xFFFFFFFFFFFFFFFF };

}