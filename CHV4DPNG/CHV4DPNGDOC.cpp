module;

#include <string>
#include <vector>

module CHV4DPNG:CHV4DPNGDOC;




namespace PNG
{
	const char* CHV4DPNGDOC::ErrorText(uint32_t code)
	{




	}
	
	void CHV4DPNGDOC::InitializeColorMode(CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}

	void CHV4DPNGDOC::CleanColorMode(CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CopyColorMode(CHV4DPNGCOLORMODE* dest, const CHV4DPNGCOLORMODE* source)
	{
	
	
	
	}


	CHV4DPNGCOLORMODE CHV4DPNGDOC::MakeColorMode(CHV4DTPNG colortype, uint32_t bitdepth)
	{
	
	
	
	}


	void CHV4DPNGDOC::ClearPalette(CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::AddPalette(CHV4DPNGCOLORMODE* info, unsigned char r, unsigned char g, unsigned char b, unsigned char a)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::GetBpp(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::GetChannels(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::IsGreyscale(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::IsAlpha(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::IsPalette(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::HasPaletteAlpha(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CanHaveAlpha(const CHV4DPNGCOLORMODE* info)
	{
	
	
	
	}


	size_t CHV4DPNGDOC::GetRawSize(uint32_t w, uint32_t h, const CHV4DPNGCOLORMODE* color)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeInfo(CHV4DPNGINFO* info)
	{
	
	
	
	}


	void CHV4DPNGDOC::CleanInfo(CHV4DPNGINFO* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CopyInfo(CHV4DPNGINFO* dest, const CHV4DPNGINFO* source)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::AddText(CHV4DPNGINFO* info, const char* key, const char* str)
	{
	
	
	
	}


	void CHV4DPNGDOC::ClearText(CHV4DPNGINFO* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::AddForeign(CHV4DPNGINFO* info, const char* key, const char* langtag, const char* transkey, const char* str)
	{
	
	
	
	}


	void CHV4DPNGDOC::ClearForeign(CHV4DPNGINFO* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::SetICC(CHV4DPNGINFO* info, const char* name, const unsigned char* profile, uint32_t profile_size)
	{
	
	
	
	}


	void CHV4DPNGDOC::ClearICC(CHV4DPNGINFO* info)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Convert(
		unsigned char* out,
		const unsigned char* in,
		const CHV4DPNGCOLORMODE* mode_out,
		const CHV4DPNGCOLORMODE* mode_in,
		uint32_t w, uint32_t h)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeDecOptions(CHV4DDECOPTIONS* settings)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeCompOptions(CHV4DCOMPOPTIONS* settings)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeDecoderOptions(CHV4DDECOPTIONS* settings)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeColorStats(CHV4DCOLORSTATS* stats)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::ComputeColorStats(
		CHV4DCOLORSTATS* stats,
		const unsigned char* image,
		uint32_t w,
		uint32_t h,
		const CHV4DPNGCOLORMODE* mode_in)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeEncoderOptions(CHV4DCOMPOPTIONS* settings)
	{
	
	
	
	}


	void CHV4DPNGDOC::InitializeState(CHV4DPNGSTATE* state)
	{
	
	
	
	}


	void CHV4DPNGDOC::CleanState(CHV4DPNGSTATE* state)
	{
	
	
	
	}


	void CHV4DPNGDOC::CopyState(CHV4DPNGSTATE* dest, const CHV4DPNGSTATE* source)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Decode(
		unsigned char** out,
		uint32_t* w,
		uint32_t* h,
		CHV4DPNGSTATE* state,
		const unsigned char* in,
		size_t insize)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Inspect(uint32_t* w, uint32_t* h, CHV4DPNGSTATE* state, const unsigned char* in, size_t insize)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::InspectChunk(CHV4DPNGSTATE* state, size_t pos, const unsigned char* in, size_t insize)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Encode(
		unsigned char** out,
		size_t* outsize,
		const unsigned char* image,
		uint32_t w,
		uint32_t h,
		CHV4DPNGSTATE* state)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::ChunkLength(const unsigned char* chunk)
	{
	
	
	
	}


	void CHV4DPNGDOC::ChunkType(char type[5], const unsigned char* chunk)
	{
	
	
	
	}


	unsigned char CHV4DPNGDOC::ChunkTypeEquals(const unsigned char* chunk, const char* type)
	{
	
	
	
	}


	unsigned char CHV4DPNGDOC::AncillaryChunk(const unsigned char* chunk)
	{
	
	
	
	}


	unsigned char CHV4DPNGDOC::PrivateChunk(const unsigned char* chunk)
	{
	
	
	
	}


	unsigned char CHV4DPNGDOC::SafeToCopyChunk(const unsigned char* chunk)
	{
	
	
	
	}


	unsigned char* CHV4DPNGDOC::ChunkData(unsigned char* chunk)
	{
	
	
	
	}


	const unsigned char* CHV4DPNGDOC::ConstChunkData(const unsigned char* chunk)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CheckChunkCRC(const unsigned char* chunk)
	{
	
	
	
	}


	void CHV4DPNGDOC::GenerateChunkCRC(unsigned char* chunk)
	{
	
	
	
	}


	unsigned char* CHV4DPNGDOC::NextChunk(unsigned char* chunk, unsigned char* end)
	{
	
	
	
	}


	const unsigned char* CHV4DPNGDOC::NextConstChunk(const unsigned char* chunk, const unsigned char* end)
	{
	
	
	
	}


	unsigned char* CHV4DPNGDOC::FindChunk(unsigned char* chunk, unsigned char* end, const char type[5])
	{
	
	
	
	}


	const unsigned char* CHV4DPNGDOC::FindConstChunk(const unsigned char* chunk, const unsigned char* end, const char type[5])
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::AppendChunk(unsigned char** out, size_t* outsize, const unsigned char* chunk)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CreateChunk(
		unsigned char** out,
		size_t* outsize,
		uint32_t length,
		const char* type,
		const unsigned char* data)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::CRC32(const unsigned char* buf, size_t len)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Inflate(
		unsigned char** out,
		size_t* outsize,
		const unsigned char* in,
		size_t insize,
		const CHV4DDECOPTIONS* settings)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::ZLibDecompress(
		unsigned char** out,
		size_t* outsize,
		const unsigned char* in,
		size_t insize,
		const CHV4DDECOPTIONS* settings)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::ZLibCompress(
		unsigned char** out,
		size_t* outsize,
		const unsigned char* in,
		size_t insize,
		const CHV4DCOMPOPTIONS* settings)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::HuffmanCodeLengths(uint32_t* lengths, const uint32_t* frequencies, size_t numcodes, uint32_t maxbitlen)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::Deflate(
		unsigned char** out,
		size_t* outsize,
		const unsigned char* in,
		size_t insize,
		const CHV4DCOMPOPTIONS* settings)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::LoadFile(unsigned char** out, size_t* outsize, const char* filename)
	{
	
	
	
	}


	uint32_t CHV4DPNGDOC::SaveFile(const unsigned char* buffer, size_t buffersize, const char* filename)
	{
	
	
	
	}

	uint32_t CHV4DPNGDOC::Decode(
		std::vector<unsigned char>& out,
		uint32_t& w,
		uint32_t& h,
		CHV4DPNGSTATE& state,
		const unsigned char* in,
		size_t insize)
	{




	}

	uint32_t CHV4DPNGDOC::Decode(
		std::vector<unsigned char>& out,
		uint32_t& w,
		uint32_t& h,
		CHV4DPNGSTATE& state,
		const std::vector<unsigned char>& in)
	{




	}

	uint32_t CHV4DPNGDOC::Encode(
		std::vector<unsigned char>& out,
		const unsigned char* in,
		uint32_t w,
		uint32_t h,
		CHV4DPNGSTATE& state)
	{




	}

	uint32_t CHV4DPNGDOC::Encode(
		std::vector<unsigned char>& out,
		const std::vector<unsigned char>& in,
		uint32_t w,
		uint32_t h,
		CHV4DPNGSTATE& state)
	{





	}

	uint32_t CHV4DPNGDOC::SaveFile(const std::vector<unsigned char>& buffer, const std::string& filename)
	{




	}

	uint32_t CHV4DPNGDOC::Decompress(std::vector<unsigned char>& out, const unsigned char* in, size_t insize, const CHV4DDECOPTIONS& settings)
	{




	}

	uint32_t CHV4DPNGDOC::Decompress(std::vector<unsigned char>& out, const std::vector<unsigned char>& in, const CHV4DDECOPTIONS& settings)
	{




	}

	uint32_t CHV4DPNGDOC::Compress(std::vector<unsigned char>& out, const unsigned char* in, size_t insize, const CHV4DCOMPOPTIONS& settings)
	{




	}

	uint32_t CHV4DPNGDOC::Compress(std::vector<unsigned char>& out, const std::vector<unsigned char>& in, const CHV4DCOMPOPTIONS& settings)
	{




	}




}