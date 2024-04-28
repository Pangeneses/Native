module;

#include <string>

#include <functional>
#include <memory>

#include <unordered_map>
#include <vector>
#include <deque>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DDECODER;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DARCHIVE
{
	CHV4DDECODER::CHV4DDECODER()
	{





	}

	ARCHIVE_ERROR CHV4DDECODER::InflateStream(BlockSink bsink)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (bsink == nullptr) throw std::invalid_argument{ "No Sink specified." };

		BitStream->ClearStream();

		ByteStream->clear();

		Sink = bsink;

		EOS = false;

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		LLC = 0b1111111111111111;

		error = ARCHIVE_ERROR_CONSUME_STREAM;

		while (!(EOS && LLC == 0))
		{
			error = Sink(BitStream);

			if (error != ARCHIVE_ERROR_SUCCEEDED || error != ARCHIVE_ERROR_END_OF_STREAM) return error;

			if (BitStream->BitStreamSize() == 0) throw std::invalid_argument{ "Empty BitStream." };

			if (!((BitStream->BitStreamSize() - BitStream->ForwardSentinelPosition()) > 4)) break;

			if (BlockType == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
			{
				if ((BitStream.get())->operator++() == CHV4DBITSTREAM::BIT_ONE) EOS = true;

				BlockType.first = (BitStream.get())->operator++();

				BlockType.second = (BitStream.get())->operator++();

				if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ONE })
				{
					throw std::invalid_argument{ "Dynamic trees not supported." };

				}
				else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
				{
					throw std::invalid_argument{ "Reserved." };

				}

			}

			if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ZERO })
			{
				do
				{
					error = NoCompress();

				} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

			}
			else
			{
				do
				{
					error = DecodeLLC();

				} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::NoCompress()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->ByteAlignNext();

		uint16_t szUncompressed = 0;

		for (size_t i = 0; i < 16; ++i)
		{
			BitStream->operator++() == CHV4DBITSTREAM::BIT_ZERO ? 
				szUncompressed = (szUncompressed >> 1) | 0 : 
				szUncompressed = (szUncompressed >> 1) | 32768;
			
		}

		for (uint16_t count = 0; count < szUncompressed; ++count)
		{
			uint8_t Literal = 0;

			for (size_t i = 0; i < 8; ++i)
			{
				BitStream->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
					Literal = (Literal << 1) | 0 :
					Literal = (Literal << 1) | static_cast<uint8_t>(32768);

			}

			ByteStream->push_back(static_cast<unsigned char>(Literal));

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodeLLC()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;


		return error;

	}

}