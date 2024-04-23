module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

export module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DDEFLATE
	{
	public:
		CHV4DDEFLATE() = default;

	public:




	private:
		std::shared_ptr<CHV4DBITSTREAM> BitStream;


	};

}