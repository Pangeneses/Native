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

	ARCHIVE_ERROR CHV4DDECODER::InflateStream(BlockSink bsink = nullptr)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (bsink == nullptr) throw std::invalid_argument{ "No Sink specified." };

		BitStream->ClearStream();

		ByteStream->clear();

		Sink = bsink;

		EOS = false;

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		LLC = 0b1111111111111111;

		CHV4DBITSTREAM::BIT bit1 = CHV4DBITSTREAM::BIT_ONE, bit2 = CHV4DBITSTREAM::BIT_ONE;

		while (!(EOS && LLC == 0))
		{
			while (Sink(BitStream) != ARCHIVE_ERROR_END_OF_STREAM)
			{
				if (BitStream->BitStreamSize() == 0) throw std::invalid_argument{ "Empty BitStream." };

				if (!((BitStream->BitStreamSize() - BitStream->ForwardSentinelPosition()) > 4))
				{
					error = ARCHIVE_ERROR_CONSUME_STREAM;

				}

				while (error != ARCHIVE_ERROR_CONSUME_STREAM)
				{
					if (BlockType == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
					{
						if ((BitStream.get())->operator++() == CHV4DBITSTREAM::BIT_ONE) EOS == true;

						BlockType.first = (BitStream.get())->operator++();

						BlockType.second = (BitStream.get())->operator++();

						if (std::pair{ bit1, bit2 } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ONE })
						{
							throw std::invalid_argument{ "Dynamic trees not supported." };

						}
						else if (std::pair{ bit1, bit2 } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
						{
							throw std::invalid_argument{ "Reserved." };

						}

						if (std::pair{ bit1, bit2 } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ZERO })
						{
							do
							{
								error = NoCompress();

							} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

						}

					}

					error = DecodeLLC();

				}

			}

		}

	}

	ARCHIVE_ERROR CHV4DDECODER::NoCompress()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::ChewStream()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;



		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodeLLC()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;


		return error;

	}

}