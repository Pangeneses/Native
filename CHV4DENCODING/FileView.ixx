module;

#include <string>
#include <vector>

export module CHV4DENCODE:FileView;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :StreamView;

export namespace CHV4DENCODE
{
	class FileView
	{
	public:
		FileView() = default;

	public:
		void LoadDocument(
			File file,
			ENCODING const& encode = ENCODING_UNKNOWN,
			ENDIANNESS const& endianness = ENDIANNESS_UNSPECIFIED);

		void IndexWatchwords(Watchword const& keyWords);

		void OverwriteDocument(
			ENCODING const& encode = ENCODING_UNKNOWN,
			ENDIANNESS const& endianness = ENDIANNESS_UNSPECIFIED,
			BOM bom = false);

		void WriteDocument(
			File file,
			ENCODING const& encode = ENCODING_UNKNOWN,
			ENDIANNESS const& endianness = ENDIANNESS_UNSPECIFIED,
			BOM bom = false);

	public:
		StreamView& operator()();

	private:
		std::string currentPath;

		StreamView streamView;

	};

}