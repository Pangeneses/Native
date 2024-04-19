module;

#include <string>

#include <vector>

export module CHV4DARCHIVE:CHV4DENCLL;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DENCLL
	{
	public:
		CHV4DENCLL() = default;

	public:
		ARCHIVE_ERROR ResetStreamInput(CHV4DARCHIVE::CHV4DBITSTREAM& stream_out);


	};

}