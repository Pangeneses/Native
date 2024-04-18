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

import :CHV4DBITSTREAM;

export namespace CHV4DARCHIVE
{
	class CHV4DDEFLATE;

	class CHV4DENCLZSS
	{
	public:
		CHV4DENCLZSS() = default;

	public:
		ZIP_ERROR AppendBlockToStream(
			std::shared_ptr<std::vector<unsigned char>> block,
			std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> out,
			int16_t windowSz,
			DEFLATE_COMPRESSION method);

		ZIP_ERROR AppendNoCompression();

	private:
		ZIP_ERROR ResetWindow();

		ZIP_ERROR SlideWindow();

		ZIP_ERROR IndexWindowSearch();

		ZIP_ERROR IndexedWindowSearch();

		ZIP_ERROR PushLiteral();

	private:
		DEFLATE_COMPRESSION Method;

		uint16_t WindowSz{ 32768 };

		std::list<unsigned char> Window;

		std::list<unsigned char> Literal;

		std::shared_ptr<std::vector<unsigned char>> Block;

		std::vector<unsigned char>::const_iterator CItt;

		std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> Out;

		std::list<std::list<unsigned char>::iterator> Index;



		size_t PointerSz;

		size_t PreBufferPosition;

		bool StopPreBuffering{ false };


	};

}