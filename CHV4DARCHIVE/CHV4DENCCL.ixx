module;

#include <string>

#include <vector>

export module CHV4DARCHIVE:CHV4DENCCL;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DENCCL
	{
	public:
		CHV4DENCCL() = default;

	public:
		ZIP_ERROR ResetStreamInput(CHV4DARCHIVE::CHV4DBITSTREAM& stream_out);


	};

}