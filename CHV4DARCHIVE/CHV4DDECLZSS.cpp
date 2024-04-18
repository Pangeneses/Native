module;

#include <fstream>
#include <string>

#include <iterator>
#include <map>
#include <vector>
#include <list>

#include <cmath>

module CHV4DARCHIVE:CHV4DDECLZSS;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	ZIP_ERROR CHV4DENCLZSS::DecompressStreamLZSS(
		std::vector<uint8_t> const& in,
		std::vector<uint8_t>& out,
		size_t const& window)
	{
		ZIP_ERROR error = CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

		if (!(8 <= window) && !(window <= 15)) return ZIP_ERROR_OUT_OF_RANGE;

		WindowSz = static_cast<uint16_t>(std::pow(2, window));

		size_t WindowOffset = 0;

		PreBufferPosition = 0;

		BitFlagPos = 0;

		Window.clear();

		PreBuffer.clear();

		std::copy(in.begin(), std::next(in.begin(), 2048), std::back_inserter(PreBuffer));

		PreBufferPosition = 2047;

		while (PreBuffer.size() > 0)
		{
			if (((*PreBuffer.begin() << (BitFlagPos - 1)) & 0b10000000) == 0b00000000)
			{
				if (BitFlagPos == 8)
				{
					out.push_back(*std::next(PreBuffer.begin()));

					out.push_back(*std::next(PreBuffer.begin(), 1));

					WindowOffset += 2;

					PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), 2));

					if (PreBuffer.size() < 1024)
					{
						std::copy(
							std::next(in.begin(), PreBufferPosition),
							std::next(in.begin(), PreBufferPosition + 1024),
							std::back_inserter(PreBuffer));

						PreBufferPosition += 1024;

					}

				}
				else
				{
					out.push_back(*PreBuffer.begin() << BitFlagPos);

					out.back() = out.back() & (*std::next(PreBuffer.begin()) >> (8 - BitFlagPos));

					out.push_back(*std::next(PreBuffer.begin()) << BitFlagPos);

					out.back() = out.back() & (*std::next(PreBuffer.begin(), 2) >> (8 - BitFlagPos));

					WindowOffset += 2;

					PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), 2));

					if (PreBuffer.size() < 1024)
					{
						std::copy(
							std::next(in.begin(), PreBufferPosition),
							std::next(in.begin(), PreBufferPosition + 1024),
							std::back_inserter(PreBuffer));

						PreBufferPosition += 1024;

					}

				}

			}
			else
			{
				uint32_t InPlace;

				uint8_t* Buffer = (uint8_t*)&InPlace;

				std::move(PreBuffer.begin(), std::next(PreBuffer.begin(), 4), Buffer);

				InPlace = InPlace << BitFlagPos;

				InPlace = InPlace >> (16 - PointerSz);

				uint16_t Position = *(uint16_t*)&InPlace;

				uint8_t Length = Buffer[3];

				out.insert(
					out.end(),
					std::next(out.begin(), WindowOffset + (WindowSz - Position)),
					std::next(out.begin(), WindowOffset + (WindowSz - Position + Length)));

				WindowOffset += Length;

				PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), Length));

				if (PreBuffer.size() < 1024)
				{
					std::copy(
						std::next(in.begin(), PreBufferPosition),
						std::next(in.begin(), PreBufferPosition + 1024),
						std::back_inserter(PreBuffer));

					PreBufferPosition += 1024;

				}

			}

		}

		out = Output;

		return CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

	}

	ZIP_ERROR CHV4DENCLZSS::DecompressOnDiskLZSS(
		std::string const& in,
		std::string& out,
		size_t const& window)
	{
		ZIP_ERROR error = CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

		if (!(8 <= window) && !(window <= 15)) return ZIP_ERROR_OUT_OF_RANGE;

		WindowSz = static_cast<uint16_t>(std::pow(2, window));

		size_t WindowOffset = 0;

		PreBufferPosition = 0;

		BitFlagPos = 0;

		Window.clear();

		PreBuffer.clear();

		std::fstream IStream;

		IStream.open(in, std::ios::in | std::ios::binary);

		IStream.seekg(0, std::ios::end);

		FileSz = IStream.tellg();

		IStream.seekg(0, std::ios::beg);

		Move.resize(2048);

		IStream.get(&Move[0], 2048);

		PreBuffer.insert(PreBuffer.begin(), Move.begin(), Move.end());

		Move.clear(); Move.resize(1024);

		std::fstream OStream;

		OStream.open(out, std::ios::in | std::ios::binary);

		while (PreBuffer.size() > 0)
		{
			if (((*PreBuffer.begin() << (BitFlagPos - 1)) & 0b10000000) == 0b00000000)
			{
				if (BitFlagPos == 8)
				{
					Output.push_back(*std::next(PreBuffer.begin()));

					Output.push_back(*std::next(PreBuffer.begin(), 1));

					WindowOffset += 2;

					PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), 2));

					if (PreBuffer.size() < 1024)
					{
						IStream.get(&Move[0], 1024);

						PreBuffer.insert(PreBuffer.begin(), Move.begin(), Move.end());

						Move.clear();

					}

				}
				else
				{
					Output.push_back(*PreBuffer.begin() << BitFlagPos);

					Output.back() = Output.back() & (*std::next(PreBuffer.begin()) >> (8 - BitFlagPos));

					Output.push_back(*std::next(PreBuffer.begin()) << BitFlagPos);

					Output.back() = Output.back() & (*std::next(PreBuffer.begin(), 2) >> (8 - BitFlagPos));

					WindowOffset += 2;

					PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), 2));

					if (PreBuffer.size() < 1024)
					{
						IStream.get(&Move[0], 1024);

						PreBuffer.insert(PreBuffer.begin(), Move.begin(), Move.end());

						Move.clear();

					}

				}

			}
			else
			{
				uint32_t InPlace;

				uint8_t* Buffer = (uint8_t*)&InPlace;

				std::move(PreBuffer.begin(), std::next(PreBuffer.begin(), 4), Buffer);

				InPlace = InPlace << BitFlagPos;

				InPlace = InPlace >> (16 - PointerSz);

				uint16_t Position = *(uint16_t*)&InPlace;

				uint8_t Length = Buffer[3];

				Output.insert(
					Output.end(),
					std::next(Output.begin(), WindowOffset + (WindowSz - Position)),
					std::next(Output.begin(), WindowOffset + (WindowSz - Position + Length)));

				WindowOffset += Length;

				PreBuffer.erase(PreBuffer.begin(), std::next(PreBuffer.begin(), Length));

				if (PreBuffer.size() < 1024)
				{
					IStream.get(&Move[0], 1024);

					PreBuffer.insert(PreBuffer.begin(), Move.begin(), Move.end());

					Move.clear();

				}

			}

			if (Output.size() > 4096)
			{
				OStream.seekg(0, std::ios::end);

				OStream.write(reinterpret_cast<char*>(Output.data()), 2048);

				Output.erase(Output.begin(), std::next(Output.begin(), 2048));

				WindowOffset -= 2048;

			}

		}

		OStream.seekg(0, std::ios::end);

		OStream.write(reinterpret_cast<char*>(Output.data()), Output.size());

		Output.clear();

		return CHV4DARCHIVE::ZIP_ERROR_SUCCEEDED;

	}

}