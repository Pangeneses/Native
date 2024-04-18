module;

#include <string>
#include <vector>

module CHV4DPNG:CHV4DPNGDECODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace PNG
{
    uint32_t CHV4DPNGDECODE::MemoryDecode(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize,
        CHV4DTPNG colortype, uint32_t bitdepth)
    {



    }

    uint32_t CHV4DPNGDECODE::Decode32(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize)
    {



    }

    uint32_t CHV4DPNGDECODE::Decode24(unsigned char** out, uint32_t* w, uint32_t* h, const unsigned char* in, size_t insize)
    {



    }

    uint32_t CHV4DPNGDECODE::FileDecode(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename,
        CHV4DTPNG colortype, uint32_t bitdepth)
    {



    }

    uint32_t CHV4DPNGDECODE::FileDecode32(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename)
    {



    }

    uint32_t CHV4DPNGDECODE::FileDecode24(unsigned char** out, uint32_t* w, uint32_t* h, const char* filename)
    {



    }

    uint32_t CHV4DPNGDECODE::Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const unsigned char* in, size_t insize,
        CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
    {



    }

    uint32_t CHV4DPNGDECODE::Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const std::vector<unsigned char>& in,
        CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
    {



    }

    uint32_t CHV4DPNGDECODE::Decode(std::vector<unsigned char>& out, uint32_t& w, uint32_t& h, const std::string& filename,
        CHV4DTPNG colortype /*= LCT_RGBA*/, uint32_t bitdepth = 8)
    {



    }

}