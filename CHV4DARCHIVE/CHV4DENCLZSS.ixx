module;

#include <fstream>
#include <string>

#include <memory>

#include <vector>
#include <list>
#include <map>

export module CHV4DARCHIVE:CHV4DENCLZSS;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DDEFLATE;

	class CHV4DENCLZSS
	{
	public:
		CHV4DENCLZSS() = default;

	public:
		ARCHIVE_ERROR AppendBlockToStream(std::shared_ptr<CHV4DARCHIVE::CHV4DSTREAM> stream);

		ARCHIVE_ERROR AppendNoCompression();

	private:
		ARCHIVE_ERROR IndexWindowSearch();

		ARCHIVE_ERROR IndexedWindowSearch();

		ARCHIVE_ERROR SlideWindow();

		ARCHIVE_ERROR CodePair(size_t& dist, size_t& len);

		ARCHIVE_ERROR PushLiteral();

	private:
		std::shared_ptr<CHV4DARCHIVE::CHV4DSTREAM> Stream;

	};

}