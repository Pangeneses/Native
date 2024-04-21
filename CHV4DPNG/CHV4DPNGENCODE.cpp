module;

#include <string>
#include <vector>

module CHV4DPNG:CHV4DPNGENCODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace PNG
{
	uint32_t CHV4DPNGENCODE::Encode32(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h)
	{




	}

	uint32_t CHV4DPNGENCODE::Encode24(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h)
	{




	}

	uint32_t CHV4DPNGENCODE::FileEncode(const char* filename, const unsigned char* image, uint32_t w, uint32_t h,
		CHV4DTPNG colortype, uint32_t bitdepth)
	{




	}

	uint32_t CHV4DPNGENCODE::FileEncode32(const char* filename, const unsigned char* image, uint32_t w, uint32_t h)
	{




	}

	uint32_t CHV4DPNGENCODE::FileEncode24(const char* filename, const unsigned char* image, uint32_t w, uint32_t h)
	{




	}

	uint32_t CHV4DPNGENCODE::MemoryEncode(unsigned char** out, size_t* outsize, const unsigned char* image, uint32_t w, uint32_t h,
		CHV4DTPNG colortype, uint32_t bitdepth)
	{




	}

	uint32_t CHV4DPNGENCODE::Encode(std::vector<unsigned char>& out, const unsigned char* in, uint32_t w, uint32_t h,
		CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
	{




	}

	uint32_t CHV4DPNGENCODE::Encode(std::vector<unsigned char>& out, const std::vector<unsigned char>& in, uint32_t w, uint32_t h,
		CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
	{




	}

	uint32_t CHV4DPNGENCODE::Encode(const std::string& filename, const unsigned char* in, uint32_t w, uint32_t h,
		CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
	{




	}

	uint32_t CHV4DPNGENCODE::Encode(const std::string& filename, const std::vector<unsigned char>& in, uint32_t w, uint32_t h,
		CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
	{




	}

}