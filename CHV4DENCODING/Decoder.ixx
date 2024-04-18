module;

#include <string>
#include <vector>

export module CHV4DENCODE:Decoder;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DENCODE
{
	class Decoder
	{
	public:
		Decoder() = default;

	public:
		Text ToCodepoints(
			Data data,
			size_t const& len, 
			ENCODING const& encoding = ENCODING_UNKNOWN,
			ENDIANNESS const& endianness = ENDIANNESS_UNSPECIFIED);

	private:
		void PreProcessing();

	private:
		void CodepointFromUnknown();

		void CodepointFromAscii();

		void CodepointFromSystem();

		void CodepointFromUTF8();

		void CodepointFromUTF16();

		void CodepointFromUTF32();

	private:
		ENCODING sourceEncoding;

		ENDIANNESS byteWise;

		Buffer dataView;

		Text Codepoints;

		size_t index{ 0 };

		Codepoint codepoint{ 0 };

		size_t multiByte{ 1 };

	};

}