module;

#include <string>
#include <vector>

export module CHV4DPNG:CHV4DPNGDOC;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace PNG
{
	class CHV4DPNGDOC
	{
	public:
		CHV4DPNGDOC() = default;

	public:
		uint32_t LoadFile(const std::string& filename);

		uint32_t SaveFile(const std::string& filename);

	public:
		void InitializeColorMode(CHV4DPNGCOLORMODE* info);

		void CleanColorMode(CHV4DPNGCOLORMODE* info);

		uint32_t CopyColorMode(CHV4DPNGCOLORMODE* dest, const CHV4DPNGCOLORMODE* source);

		CHV4DPNGCOLORMODE MakeColorMode(CHV4DTPNG colortype, uint32_t bitdepth);


		void ClearPalette(CHV4DPNGCOLORMODE* info);

		uint32_t AddPalette(CHV4DPNGCOLORMODE* info, unsigned char r, unsigned char g, unsigned char b, unsigned char a);


		uint32_t GetBpp(const CHV4DPNGCOLORMODE* info);


		uint32_t GetChannels(const CHV4DPNGCOLORMODE* info);


		uint32_t IsGreyscale(const CHV4DPNGCOLORMODE* info);

		uint32_t IsAlpha(const CHV4DPNGCOLORMODE* info);

		uint32_t IsPalette(const CHV4DPNGCOLORMODE* info);

		uint32_t HasPaletteAlpha(const CHV4DPNGCOLORMODE* info);

		uint32_t CanHaveAlpha(const CHV4DPNGCOLORMODE* info);


		size_t GetRawSize(uint32_t w, uint32_t h, const CHV4DPNGCOLORMODE* color);


		void InitializeInfo(CHV4DPNGINFO* info);

		void CleanInfo(CHV4DPNGINFO* info);

		uint32_t CopyInfo(CHV4DPNGINFO* dest, const CHV4DPNGINFO* source);


		uint32_t AddText(CHV4DPNGINFO* info, const char* key, const char* str);

		void ClearText(CHV4DPNGINFO* info);


		uint32_t AddForeign(CHV4DPNGINFO* info, const char* key, const char* langtag, const char* transkey, const char* str);

		void ClearForeign(CHV4DPNGINFO* info);


		uint32_t SetICC(CHV4DPNGINFO* info, const char* name, const unsigned char* profile, uint32_t profile_size);

		void ClearICC(CHV4DPNGINFO* info);


		uint32_t Convert(
			unsigned char* out, 
			const unsigned char* in, 
			const CHV4DPNGCOLORMODE* mode_out, 
			const CHV4DPNGCOLORMODE* mode_in,
			uint32_t w, uint32_t h);


		void InitializeDecOptions(CHV4DDECOPTIONS* settings);

		void InitializeCompOptions(CHV4DCOMPOPTIONS* settings);

		void InitializeDecoderOptions(CHV4DDECOPTIONS* settings);

		void InitializeEncoderOptions(CHV4DCOMPOPTIONS* settings);


		void InitializeColorStats(CHV4DCOLORSTATS* stats);

		uint32_t ComputeColorStats(
			CHV4DCOLORSTATS* stats,
			const unsigned char* image, 
			uint32_t w, 
			uint32_t h,
			const CHV4DPNGCOLORMODE* mode_in);


		void InitializeState(CHV4DPNGSTATE* state);

		void CleanState(CHV4DPNGSTATE* state);

		void CopyState(CHV4DPNGSTATE* dest, const CHV4DPNGSTATE* source);


		uint32_t Inspect(uint32_t* w, uint32_t* h, CHV4DPNGSTATE* state, const unsigned char* in, size_t insize);

		uint32_t InspectChunk(CHV4DPNGSTATE* state, size_t pos, const unsigned char* in, size_t insize);

		uint32_t ChunkLength(const unsigned char* chunk);

		void ChunkType(char type[5], const unsigned char* chunk);

		unsigned char ChunkTypeEquals(const unsigned char* chunk, const char* type);

		unsigned char AncillaryChunk(const unsigned char* chunk);

		unsigned char PrivateChunk(const unsigned char* chunk);

		unsigned char SafeToCopyChunk(const unsigned char* chunk);

		unsigned char* ChunkData(unsigned char* chunk);

		const unsigned char* ConstChunkData(const unsigned char* chunk);

		uint32_t CheckChunkCRC(const unsigned char* chunk);

		void GenerateChunkCRC(unsigned char* chunk);

		unsigned char* NextChunk(unsigned char* chunk, unsigned char* end);

		const unsigned char* NextConstChunk(const unsigned char* chunk, const unsigned char* end);

		unsigned char* FindChunk(unsigned char* chunk, unsigned char* end, const char type[5]);

		const unsigned char* FindConstChunk(const unsigned char* chunk, const unsigned char* end, const char type[5]);

		uint32_t AppendChunk(unsigned char** out, size_t* outsize, const unsigned char* chunk);

		uint32_t CreateChunk(
			unsigned char** out, 
			size_t* outsize, 
			uint32_t length,
			const char* type, 
			const unsigned char* data);


		uint32_t CRC32(const unsigned char* buf, size_t len);


		const char* ErrorText(uint32_t code);


		public:
			uint32_t Decompress(std::vector<unsigned char>& out, const unsigned char* in, size_t insize,
				const CHV4DDECOPTIONS& settings = DefaultDecOptions);

			uint32_t Decompress(std::vector<unsigned char>& out, const std::vector<unsigned char>& in,
				const CHV4DDECOPTIONS& settings = DefaultDecOptions);

			uint32_t Compress(std::vector<unsigned char>& out, const unsigned char* in, size_t insize,
				const CHV4DCOMPOPTIONS& settings = DefaultCompOptions);

			uint32_t Compress(std::vector<unsigned char>& out, const std::vector<unsigned char>& in,
				const CHV4DCOMPOPTIONS& settings = DefaultCompOptions);

			uint32_t Inflate(
				unsigned char** out,
				size_t* outsize,
				const unsigned char* in,
				size_t insize,
				const CHV4DDECOPTIONS* settings);

			uint32_t ZLibDecompress(
				unsigned char** out,
				size_t* outsize,
				const unsigned char* in,
				size_t insize,
				const CHV4DDECOPTIONS* settings);

			uint32_t ZLibCompress(
				unsigned char** out,
				size_t* outsize,
				const unsigned char* in,
				size_t insize,
				const CHV4DCOMPOPTIONS* settings);

			uint32_t HuffmanCodeLengths(uint32_t* lengths, const uint32_t* frequencies, size_t numcodes, uint32_t maxbitlen);

			uint32_t Deflate(
				unsigned char** out,
				size_t* outsize,
				const unsigned char* in,
				size_t insize,
				const CHV4DCOMPOPTIONS* settings);

	private:
		std::string Name;

		CHV4DPNGINFO Info;

		std::vector<char8_t> buffer;

	private:
		static const CHV4DDECOPTIONS DefaultDecOptions;

		static const CHV4DCOMPOPTIONS DefaultCompOptions;

	};




}