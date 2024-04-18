module;

#include <string>
#include <vector>

#include <stdexcept>

module CHV4DENCODE:Encoder;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DENCODE
{
	Buffer Encoder::FromCodepoints(
		Text const& data,
		ENCODING const& encoding,
		ENDIANNESS const& endianness,
		BOM BOM)
	{		
		Codepoints = { data.begin(), data.end() };

		destEncoding = encoding;

		byteWise = endianness;

		byteOrderMark = BOM;

		oBuffer.clear();

		codepoint = 0;

		multiByte = 1;
		
		for (index = multiByte - 1; index < raw.size(); index += 4)
		{
			if (raw[index] > 0x10FFFF) throw std::invalid_argument{ "Malformed Unicode." };
		
			switch (encoding)
			{
			case ENCODING_UNKNOWN: throw std::invalid_argument{ "Cannot encode to unknown encoding." }; break;

			case ENCODING_ASCII: AsciiFromCodepoint(); break;

			case ENCODING_SYSTEM: SystemFromCodepoint(); break;

			case ENCODING_UTF8: UTF8FromCodepoint(); break;

			case ENCODING_UTF16: UTF16FromCodepoint(); break;

			case ENCODING_UTF32: UTF32FromCodepoint(); break;

			default: throw std::invalid_argument{ "Non valid converter." }; break;
			}

		}

		PostProcessing();
		
		return oBuffer;

	}

	void Encoder::PostProcessing()
	{
		if (destEncoding == ENCODING_UNKNOWN) throw std::invalid_argument{ "Unknown encoding presently not supported." };

		if (byteOrderMark && (destEncoding == ENCODING_ASCII || destEncoding == ENCODING_UTF8))
		{
			multiByte = 3;

			oBuffer.push_back(0xEF);
			oBuffer.push_back(0xBB);
			oBuffer.push_back(0xBF);

		}
		else if (byteOrderMark && (destEncoding == ENCODING_SYSTEM || destEncoding == ENCODING_UTF16))
		{
			multiByte = 2;

			oBuffer.push_back(0xFF);
			oBuffer.push_back(0xFE);

		}
		else if (byteOrderMark && destEncoding == ENCODING_UTF32)
		{
			multiByte = 4;

			oBuffer.push_back(0xFF);
			oBuffer.push_back(0xFE);
			oBuffer.push_back(0x00);
			oBuffer.push_back(0x00);

		}

		switch (byteWise)
		{
		case ENDIANNESS_UNORDERED:

			if (destEncoding == ENCODING_ASCII) break;

			else if (destEncoding == ENCODING_UTF8) break;

		case ENDIANNESS_UNSPECIFIED:

			throw std::invalid_argument{ "Unspecified endianness currently not supported." }; break;

		case ENDIANNESS_BIG_ENDIAN:

			break;

		case ENDIANNESS_LITTLE_ENDIAN:

			if (destEncoding == ENCODING_SYSTEM) for (size_t i = 0; i < oBuffer.size(); i += 2) std::swap<char8_t>(oBuffer[i], oBuffer[i + 1]);

			else if (destEncoding == ENCODING_UTF16) for (size_t i = 0; i < oBuffer.size(); i += 2) std::swap<char8_t>(oBuffer[i], oBuffer[i + 1]);

			else if (destEncoding == ENCODING_UTF32) for (size_t i = 0; i < oBuffer.size(); i += 2)
			{
				std::swap<char8_t>(oBuffer[i], oBuffer[i + 3]);

				std::swap<char8_t>(oBuffer[i + 1], oBuffer[i + 2]);

			}

			break;

		default: break;

		}
		
	}

	void Encoder::AsciiFromCodepoint()
	{
		if (raw[index + 3] >= 0x80) throw std::invalid_argument{ "Improperly coded ASCII." };

		oBuffer.push_back(raw[index + 3]);

	}

	void Encoder::SystemFromCodepoint()
	{
		if (Codepoints[codepoint] > 0x0000FFFF) throw std::invalid_argument{ "Improperly encoded System encoding." };

		oBuffer.push_back(raw[index + 2]);

		oBuffer.push_back(raw[index + 3]);
	
	}

	void Encoder::UTF8FromCodepoint()
	{
		if (Codepoints[codepoint] < 0x80) oBuffer.push_back(raw[index + 3]);

		else if (Codepoints[codepoint] < 0x0800)
		{
			oBuffer.push_back(((raw[index + 2] << 2) | (raw[index + 3] >> 6)) + 0xC0);

			oBuffer.push_back((raw[index + 3] & ~0xC0) + 0x80);

		}
		else if (Codepoints[codepoint] < 0x10000)
		{
			oBuffer.push_back((raw[index + 2] >> 4) + 0xE0);

			oBuffer.push_back(((raw[index + 2] & ~0xF0 << 2) | (raw[index + 3] >> 6)) + 0x80);

			oBuffer.push_back((raw[index + 3] & ~0xC0) + 0x80);

		}

		else if (Codepoints[codepoint] > 0x10FFFF) throw std::invalid_argument{ "Malformed Unicode." };

		else
		{
			oBuffer.push_back((raw[index + 1] >> 2) + 0xF0);

			oBuffer.push_back(((raw[index + 1] & 0x03 << 4) | (raw[index + 2] >> 4)) + 0x80);

			oBuffer.push_back(((raw[index + 2] & ~0xF0) << 2 | (raw[index + 3] & 0xC0) >> 6) + 0x80);

			oBuffer.push_back((raw[index + 3] & ~0xC0) + 0x80);

		}
		
	}

	void Encoder::UTF16FromCodepoint()
	{
		if (Codepoints[codepoint] < 0x00010000)
		{
			oBuffer.push_back(raw[index + 2]);

			oBuffer.push_back(raw[index + 3]);

		}

		else if (Codepoints[codepoint] > 0x10FFFF) throw std::invalid_argument{ "Malformed Unicode." };

		else
		{
			raw[index + 1] = raw[index + 1] - 0x01;

			oBuffer.push_back(0xD8);

			oBuffer.push_back((raw[index + 1] << 6) | (raw[index + 2] >> 2));

			oBuffer.push_back((raw[index + 2] & 0x03) + 0xDC);

			oBuffer.push_back(raw[index + 3]);

		}
		
	}

	void Encoder::UTF32FromCodepoint()
	{
		if (Codepoints[codepoint] > 0x10FFFF) throw std::invalid_argument{ "Malformed Unicode." };

		oBuffer.push_back(raw[index + 0]);
		oBuffer.push_back(raw[index + 1]);
		oBuffer.push_back(raw[index + 2]);
		oBuffer.push_back(raw[index + 3]);
		
	}

}