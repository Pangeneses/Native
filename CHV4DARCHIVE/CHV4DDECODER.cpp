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
		Segment->ClearStream();

		ByteStream->clear();

		ReadHeader = true; 

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

		std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;

	}

	ARCHIVE_ERROR CHV4DDECODER::InflateStream(BlockSink bsink)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		if (bsink == nullptr) throw std::invalid_argument{ "No Sink specified." };

		NewStream();

		while (error == ARCHIVE_ERROR_CONSUME_STREAM)
		{
			if (Segment->Remain() == 0)
			{
				error = bsink(Segment);

				Segment->BeginningOfStream();

			}

			if (Segment->Remain() == 0 && error == ARCHIVE_ERROR_CONSUME_STREAM) throw std::invalid_argument{ "Empty Segment." };

			if (ReadHeader && error == ARCHIVE_ERROR_CONSUME_STREAM)
			{
				error = Header();

			}
			else if(!ReadHeader && error == ARCHIVE_ERROR_CONSUME_STREAM)
			{
				if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ZERO })
				{
					do
					{
						error = NoCompress();

					} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

				}
				else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ZERO })
				{
					do
					{
						error = DecodeLLC();

					} while (error == ARCHIVE_ERROR_CONSUME_STREAM);

				}

			}

		}

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DDECODER::Header()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		if (Segment->operator++() == CHV4DBITSTREAM::BIT_ONE) EOS = true;

		if (Segment->Remain() == 0) return ARCHIVE_ERROR_CONSUME_STREAM;

		BlockType.first = Segment->operator++();

		if (Segment->Remain() == 0) return ARCHIVE_ERROR_CONSUME_STREAM;

		BlockType.second = Segment->operator++();

		if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ZERO, CHV4DBITSTREAM::BIT_ONE })
		{
			throw std::invalid_argument{ "Dynamic trees not supported." };

		}
		else if (std::pair{ BlockType.first, BlockType.second } == std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE })
		{
			throw std::invalid_argument{ "Reserved." };

		}

		ReadHeader = false;

		if (Segment->Remain() > 8) Segment->ByteAlignNext();

		else Segment->EndOfStream();

		return ARCHIVE_ERROR_CONSUME_STREAM;

	}

	ARCHIVE_ERROR CHV4DDECODER::NoCompress()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_CONSUME_STREAM;

		if (Segment->BitStreamSize() % 8 != 0) throw std::invalid_argument{ "All segments should be mod 8 except last." };

		if (ZeroZeroBlock.second != 4)
		{
			for (size_t i = ZeroZeroBlock.second; i < 4; ++i)
			{
				if (ZeroZeroBlock.second == i)
				{
					for (size_t i = 0; i < 4; ++i)
					{
						Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
							ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 0 :
							ZeroZeroBlock.first = (ZeroZeroBlock.first >> 1) | 32768;

					}

					++ZeroZeroBlock.second;

					if (Segment->Remain() == 0) return ARCHIVE_ERROR_CONSUME_STREAM;

				}

			}

		}
		else if (NotZeroZeroBlock.second != 4)
		{
			for (size_t i = NotZeroZeroBlock.second; i < 4; ++i)
			{
				if (NotZeroZeroBlock.second == i)
				{
					for (size_t i = 0; i < 4; ++i)
					{
						Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
							NotZeroZeroBlock.first = (NotZeroZeroBlock.first >> 1) | 0 :
							NotZeroZeroBlock.first = (NotZeroZeroBlock.first >> 1) | 32768;

					}

					++NotZeroZeroBlock.second;

					if (Segment->Remain() == 0) return ARCHIVE_ERROR_CONSUME_STREAM;

				}

			}

		}
		else if (ZeroZeroBlock.first != 0)
		{
			if (ZeroZeroBlock.second == 4)
			{
				while (ZeroZeroBlock.first != 0)
				{
					for (size_t i = (Segment->Remain() % 8); i != 0; --i)
					{
						uint8_t Literal = 0;

						for (size_t i = 0; i < 8; ++i)
						{
							Segment->operator++() == CHV4DBITSTREAM::BIT_ZERO ?
								Literal = (Literal << 1) | 0 :
								Literal = (Literal << 1) | static_cast<uint8_t>(32768);

						}

						ByteStream->push_back(static_cast<unsigned char>(Literal));

						--ZeroZeroBlock.first;

					}

				}

			}

		}

		if (ZeroZeroBlock.first == 0)
		{
			BlockType = std::pair{ CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

			ReadHeader = true;

			ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DDECODER::DecodeLLC()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if ((Segment->BitStreamSize() % 8 != 0) && !EOS) throw std::invalid_argument{ "All segments should be mod 8 except last." };

		if (BackRef.LPrefixCode.second != 9)
		{
			if (BackRef.LPrefixCode.second != 7)
			{


			}
			else
			{


			}

		}
		else if (BackRef.Length.second != 5)
		{



		}
		else if (BackRef.DPrefixCode.second != 5)
		{



		}
		else if (BackRef.Distance.second != 13)
		{



		}



		return error;

	}

	void CHV4DDECODER::NewStream()
	{
		Segment->ClearStream();

		ByteStream->clear();

		ReadHeader = true;

		BlockType = { CHV4DBITSTREAM::BIT_ONE, CHV4DBITSTREAM::BIT_ONE };

		ZeroZeroBlock.first = 0; ZeroZeroBlock.second = 0;

		std::memcpy((void*)&BackRef, '\0', sizeof(BackRef));

		EOS = false;

	}

}