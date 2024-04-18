module;

#include <string>
#include <vector>

#include <stdexcept>

module CHV4DENCODE:Decoder;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DENCODE
{
	Text Decoder::ToCodepoints(
		Data data,
		size_t const& len,
		ENCODING const& encoding,
		ENDIANNESS const& endianness)
	{
		sourceEncoding = encoding;

		byteWise = endianness;

		dataView = { data, data + len };

		codepoint = 0x00;

		multiByte = 1;

		PreProcessing();

		for (index = multiByte - 1; index < dataView.size(); index += multiByte)
		{
			switch (encoding)
			{
			case ENCODING_UNKNOWN: CodepointFromUnknown(); break;

			case ENCODING_ASCII: CodepointFromAscii(); break;

			case ENCODING_SYSTEM: CodepointFromSystem(); break;

			case ENCODING_UTF8: CodepointFromUTF8(); break;

			case ENCODING_UTF16: CodepointFromUTF16(); break;

			case ENCODING_UTF32: CodepointFromUTF32(); break;

			default: throw std::invalid_argument{ "Non valid converter." }; break;
			}

			if (Codepoints.back() > 0x10FFFF) throw std::invalid_argument{"Malformed Unicode."};

		}

		return Codepoints;

	}

	void Decoder::PreProcessing()
	{
		if (sourceEncoding == ENCODING_UNKNOWN) throw std::invalid_argument{ "Unknown encoding presently not supported." };

		if (dataView[0] == 0xEF && dataView[1] == 0xBB && dataView[2] == 0xBF) { multiByte = 3; return; }

		else if (dataView[0] == 0xFF && dataView[1] == 0xFE) { multiByte = 2; return; }

		else if (dataView[0] == 0xFF && dataView[1] == 0xFE && dataView[2] == 0x00 && dataView[3] == 0x00) { multiByte = 4; return; }

		switch (byteWise)
		{
		case ENDIANNESS_UNORDERED:

			if (sourceEncoding == ENCODING_ASCII) break;

			else if (sourceEncoding == ENCODING_UTF8) break;

		case ENDIANNESS_UNSPECIFIED:

			throw std::invalid_argument{ "Unspecified endianness currently not supported." }; break;

		case ENDIANNESS_BIG_ENDIAN:

			break;

		case ENDIANNESS_LITTLE_ENDIAN:

			if (sourceEncoding == ENCODING_SYSTEM) for (size_t i = 0; i < index; i += 2) std::swap<char8_t>(dataView[i], dataView[i+1]);

			else if (sourceEncoding == ENCODING_UTF16) for (size_t i = 0; i < index; i += 2) std::swap<char8_t>(dataView[i], dataView[i + 1]);

			else if (sourceEncoding == ENCODING_UTF32) for (size_t i = 0; i < index; i += 2)
			{
				std::swap<char8_t>(dataView[i], dataView[i + 3]);

				std::swap<char8_t>(dataView[i + 1], dataView[i + 2]);

			}

			break;

		default: break;

		}

	}

	void Decoder::CodepointFromUnknown()
	{
		throw std::invalid_argument{ "Unknown conversion currently not supported." };

	}

	void Decoder::CodepointFromAscii()
	{
		if (dataView[index + 0] > 0x8) throw std::invalid_argument{ "Invalid Ascii" };

		multiByte = 1;

		Codepoints.push_back((Codepoint)dataView[index + 0]);

	}

	void Decoder::CodepointFromSystem()
	{
		if (dataView[index + 0] == 0xD && dataView[index + 1] == 0x8) throw std::invalid_argument{ "Not System encoding." };

		multiByte = 2;

		codepoint =
			(Codepoint)(dataView[index + 0]) << 8 |
			(Codepoint)(dataView[index + 1]);

	}

	void Decoder::CodepointFromUTF8()
	{
		if ((dataView[index + 0] < 0x8))
		{
			multiByte = 1;

			codepoint = dataView[index + 0];

		}
		else if (dataView[index + 0] < 0xE)
		{
			multiByte = 2;

			codepoint =
				((Codepoint)(dataView[index + 0]) - 0x00C0) << 6 |
				((Codepoint)(dataView[index + 1]) - 0x0080);

		}
		else if (dataView[index + 0] < 0xF)
		{
			multiByte = 3;

			codepoint =
				((Codepoint)(dataView[index + 0]) - 0x00E0) << 12 |
				((Codepoint)(dataView[index + 1]) - 0x0080) <<  6 |
				((Codepoint)(dataView[index + 2]) - 0x0080);

		}
		else
		{
			multiByte = 4;

			codepoint =
				((Codepoint)(dataView[index + 0]) - 0x00E0) << 20 |
				((Codepoint)(dataView[index + 1]) - 0x0080) << 14 |
				((Codepoint)(dataView[index + 2]) - 0x0080) <<  6 |
				((Codepoint)(dataView[index + 3]) - 0x0080);

		}

	}

	void Decoder::CodepointFromUTF16()
	{
		if (dataView[index + 0] == 0xD && dataView[index + 1] == 0x8)
		{
			multiByte = 4;

			codepoint =
				((Codepoint)(dataView[index + 0]) - 0xD8) << 18 |
				((Codepoint)(dataView[index + 1]) - 0x00) << 10 |
				((Codepoint)(dataView[index + 2]) - 0xDC) <<  8 |
				((Codepoint)(dataView[index + 3]) - 0x00) | 0b00010000;

		}
		else
		{
			multiByte = 2;

			codepoint =
				(Codepoint)(dataView[index + 0]) << 8 |
				(Codepoint)(dataView[index + 1]);

		}

	}

	void Decoder::CodepointFromUTF32()
	{
		multiByte = 4;

		memcpy(&codepoint, &dataView[index + 0], 4);

		Codepoints.push_back(codepoint);

	}

}