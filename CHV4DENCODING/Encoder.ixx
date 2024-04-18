module;

#include <string>
#include <vector>

export module CHV4DENCODE:Encoder;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DENCODE
{
	class Encoder
	{
	public:
		Encoder() = default;

	public:
		Buffer FromCodepoints(
			Text const& data,
			ENCODING const& encoding = ENCODING_UNKNOWN,
			ENDIANNESS const& endianness = ENDIANNESS_UNSPECIFIED,
			BOM bom = false);

	private:
		void PostProcessing();

	private:
		void AsciiFromCodepoint();

		void SystemFromCodepoint();

		void UTF8FromCodepoint();

		void UTF16FromCodepoint();

		void UTF32FromCodepoint();

	private:
		std::vector<Codepoint> Codepoints;

		Buffer raw{};

		ENCODING destEncoding{};

		ENDIANNESS byteWise{};

		BOM byteOrderMark{ false };

		Buffer oBuffer{};

		size_t index{ 0 };

		size_t codepoint{ 0 };

		size_t multiByte{ 1 };

	};

}