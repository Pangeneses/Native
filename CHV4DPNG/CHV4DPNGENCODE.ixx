module;

#include <string>
#include <vector>

export module CHV4DPNG:CHV4DPNGENCODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace PNG
{
	class CHV4DPNGENCODE
	{
	public:
		CHV4DPNGENCODE() = default;

	public:
		uint32_t Encode32(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h);

		uint32_t Encode24(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h);

		uint32_t FileEncode(const char* filename, const unsigned char* image, uint32_t w, uint32_t h,
			CHV4DTPNG colortype, uint32_t bitdepth);

		uint32_t FileEncode32(const char* filename, const unsigned char* image, uint32_t w, uint32_t h);

		uint32_t FileEncode24(const char* filename, const unsigned char* image, uint32_t w, uint32_t h);

		uint32_t MemoryEncode(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h,
			CHV4DTPNG colortype, uint32_t bitdepth);

		uint32_t Encode(std::vector<unsigned char>& out, const unsigned char* in, uint32_t w, uint32_t h,
			CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

		uint32_t Encode(std::vector<unsigned char>& out, const std::vector<unsigned char>& in, uint32_t w, uint32_t h,
			CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

		uint32_t Encode(const std::string& filename, const unsigned char* in, uint32_t w, uint32_t h,
			CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

		uint32_t Encode(const std::string& filename, const std::vector<unsigned char>& in, uint32_t w, uint32_t h,
			CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8);

		uint32_t Encode(
			unsigned char** out,
			size_t* outsize,
			const unsigned char* image,
			uint32_t w,
			uint32_t h,
			CHV4DPNGSTATE* state);

		uint32_t Encode(
			std::vector<unsigned char>& out,
			const unsigned char* in,
			uint32_t w,
			uint32_t h,
			CHV4DPNGSTATE& state);

		uint32_t Encode(
			std::vector<unsigned char>& out,
			const std::vector<unsigned char>& in,
			uint32_t w,
			uint32_t h,
			CHV4DPNGSTATE& state);

	private:


	};

}