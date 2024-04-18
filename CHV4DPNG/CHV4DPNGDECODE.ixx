module;

#include <string>
#include <vector>

export module CHV4DPNG:CHV4DPNGDECODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace PNG
{
	class CHV4DPNGDECODE
	{
	public:
		CHV4DPNGDECODE() = default;

	public:
        uint32_t MemoryDecode(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize,
            CHV4DTPNG colortype, uint32_t bitdepth);

        uint32_t Decode32(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize);

        uint32_t Decode24(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize);

        uint32_t FileDecode(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename,
            CHV4DTPNG colortype, uint32_t bitdepth);

        uint32_t FileDecode32(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename);

        uint32_t FileDecode24(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename);

        uint32_t Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const unsigned char* in, size_t insize,
            CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

        uint32_t Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const std::vector<unsigned char>& in,
            CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

        uint32_t Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const std::string& filename,
            CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

		uint32_t Decode(
			unsigned char** out,
			uint32_t* w,
			uint32_t* h,
			CHV4DPNGSTATE* state,
			const unsigned char* in,
			size_t insize);

		uint32_t Decode(
			std::vector<unsigned char>& out,
			uint32_t& w,
			uint32_t& h,
			CHV4DPNGSTATE& state,
			const unsigned char* in,
			size_t insize);

		uint32_t Decode(
			std::vector<unsigned char>& out,
			uint32_t& w,
			uint32_t& h,
			CHV4DPNGSTATE& state,
			const std::vector<unsigned char>& in);

	private:


	};

}