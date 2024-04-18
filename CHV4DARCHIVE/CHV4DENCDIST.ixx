module;

#include <string>

#include <vector>

export module CHV4DARCHIVE:CHV4DENCDIST;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DENCDIST
	{
	public:
		CHV4DENCDIST() = default;

	public:
		ZIP_ERROR ResetStreamInput(CHV4DARCHIVE::CHV4DBITSTREAM& stream_out);


	};

}