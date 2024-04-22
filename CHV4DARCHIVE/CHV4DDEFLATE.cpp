module;

#include <string>

#include <functional>
#include <memory>

#include <deque>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DSTREAM::DeflateStream(BlockSink bsink, size_t const& powWindow)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (powWindow < 8 || powWindow > 15) throw std::out_of_range{ "Window size out of range." };

		BitStream->ClearStream();

		Stream.clear();

		Sink = bsink;

		do
		{
			error = NewBlock();

			if (error != ARCHIVE_ERROR_END_OF_STREAM)
			{
				do
				{
					if (std::next(BlockSentinel, 3) == Block->end())
					{
						PushLiteral();

					}
					else if (std::next(BlockSentinel, 2) == Block->end())
					{


					}
					else
					{
						if (IndexWindow() != ARCHIVE_ERROR_SUCCEEDED) return error;

						if (Index.size() == 0)
						{
							PushLiteral();

						}
						else
						{
							if (Encode() != ARCHIVE_ERROR_SUCCEEDED) return error;

						}

					}

				} while (BlockSentinel != Block->end());

			}

		} while (!FinalBlock);

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	ARCHIVE_ERROR CHV4DSTREAM::SetDeflateCompression(DEFLATE_COMPRESSION method = DEFLATE_COMPRESSION_NO)
	{
		Method = method;

		if (Method == DEFLATE_COMPRESSION_RESERVED) throw std::invalid_argument{ "Reserved." };

		else return ARCHIVE_ERROR_SUCCEEDED;

	}

	DEFLATE_COMPRESSION CHV4DSTREAM::GetDeflateCompression()
	{

		return Method;

	}

	ARCHIVE_ERROR CHV4DSTREAM::NewBlock()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		Block->clear();

		FinalBlock = false;

		if (Sink(Block, FinalBlock) != ARCHIVE_ERROR_SUCCEEDED) return error;

		if (Block->size() == 0) throw std::out_of_range{ "Empty Block." };

		Stream.insert(Stream.end(),
			std::make_move_iterator(Block->begin()),
			std::make_move_iterator(Block->end()));

		BlockSentinel = std::next(Stream.begin(), Stream.size() - Block->size());

		LiteralSentinel = std::next(BlockSentinel, 1);

		Index.clear();

		if (!FinalBlock) *BitStream << CHV4DBITSTREAM::BIT_ZERO;

		else *BitStream << CHV4DBITSTREAM::BIT_ONE;

		if (Method == DEFLATE_COMPRESSION_NO || Block->size() < 258)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			BitStream->ByteAlignNext();

			size_t sz = Block->size();

			unsigned char* ptr = reinterpret_cast<unsigned char*>(&sz);

			BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

			BitStream->PushBits(ptr[7], 8);
			BitStream->PushBits(ptr[6], 8);
			BitStream->PushBits(ptr[5], 8);
			BitStream->PushBits(ptr[4], 8);

			sz = ~sz;

			BitStream->PushBits(ptr[7], 8);
			BitStream->PushBits(ptr[6], 8);
			BitStream->PushBits(ptr[5], 8);
			BitStream->PushBits(ptr[4], 8);

			if (AppendNoCompression() != ARCHIVE_ERROR_SUCCEEDED) return error;

			if (FinalBlock) return ARCHIVE_ERROR_EMPTY_STREAM;

		}
		else if (Method == DEFLATE_COMPRESSION_FIXED)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ONE;

			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

		}
		if (Method == DEFLATE_COMPRESSION_DYNAMIC)
		{
			*BitStream << CHV4DBITSTREAM::BIT_ZERO;

			*BitStream << CHV4DBITSTREAM::BIT_ONE;

		}
		else
		{

			throw std::invalid_argument{ "Reserved." };

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::AppendNoCompression()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		BitStream->SetConsumption(CHV4DBITSTREAM::BIT_CONSUMPTION_LEFT_RIGHT);

		BitStream->InsertBits(BitStream->BitStreamSize(), BlockSentinel, std::distance(BlockSentinel, Stream.cend()) * 8);

		SlideWindow(std::distance(BlockSentinel, Stream.cend()));

		return ARCHIVE_ERROR_END_OF_STREAM;

	}

	ARCHIVE_ERROR CHV4DSTREAM::IndexWindow()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		std::deque<unsigned char>::iterator WindowSentinel;

		for (WindowSentinel = Stream.begin(); WindowSentinel != BlockSentinel; ++WindowSentinel)
		{
			if (std::equal(WindowSentinel, std::next(WindowSentinel, 3), BlockSentinel, std::next(BlockSentinel, 3)))
			{
				Index.push_back(WindowSentinel);

			}

		}

		return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::PushLiteral()
	{
		Buffer.push_back(0);
		Buffer.push_back(*BlockSentinel);
		Buffer.push_back(0);
		Buffer.push_back(*std::next(BlockSentinel, 1));

		if (SlideWindow(2) != ARCHIVE_ERROR_SUCCEEDED) return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::Encode()
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		std::deque<std::deque<unsigned char>::const_iterator>::const_iterator test;

		size_t LongestLength = 3;

		for (test = std::next(Index.begin(), 1); test != Index.end(); ++test)
		{
			size_t CurrentLength = 3;

			while (CurrentLength <= 258)
			{
				if (*std::next(*test, CurrentLength) == *std::next(BlockSentinel, CurrentLength))
				{
					if (CurrentLength > LongestLength) Index.pop_front();

					++CurrentLength;

				}
				else
				{
					if (CurrentLength <= LongestLength) Index.erase(std::next(Index.begin(), 1));

				}

			}

		}

		PushLength(LongestLength);

		PushDistance(std::distance(Index.front(), BlockSentinel));

		error = SlideWindow(std::distance(BlockSentinel, LiteralSentinel));

		if (error != ARCHIVE_ERROR_SUCCEEDED) return error;

		return error;

	}

	ARCHIVE_ERROR CHV4DSTREAM::PushLength(size_t const& len)
	{
		Buffer.push_back(0b00000001);

		switch (len)
		{
		case 3:  Buffer.push_back(1); Buffer.push_back(0); break;
		case 4:  Buffer.push_back(2); Buffer.push_back(0); break;
		case 5:  Buffer.push_back(3); Buffer.push_back(0); break;
		case 6:  Buffer.push_back(4); Buffer.push_back(0); break;
		case 7:  Buffer.push_back(5); Buffer.push_back(0); break;
		case 8:  Buffer.push_back(6); Buffer.push_back(0); break;
		case 9:  Buffer.push_back(7); Buffer.push_back(0); break;
		case 10: Buffer.push_back(8); Buffer.push_back(0); break;

		case 11: Buffer.push_back(9); Buffer.push_back(0);  break;
		case 12: Buffer.push_back(9); Buffer.push_back(1);  break;
		case 13: Buffer.push_back(10); Buffer.push_back(0); break;
		case 14: Buffer.push_back(10); Buffer.push_back(1); break;
		case 15: Buffer.push_back(11); Buffer.push_back(0); break;
		case 16: Buffer.push_back(11); Buffer.push_back(1); break;
		case 17: Buffer.push_back(12); Buffer.push_back(0); break;
		case 18: Buffer.push_back(12); Buffer.push_back(1); break;

		case 19: Buffer.push_back(13); Buffer.push_back(0); break;
		case 20: Buffer.push_back(13); Buffer.push_back(1); break;
		case 21: Buffer.push_back(13); Buffer.push_back(2); break;
		case 22: Buffer.push_back(13); Buffer.push_back(3); break;
		case 23: Buffer.push_back(14); Buffer.push_back(0); break;
		case 24: Buffer.push_back(14); Buffer.push_back(1); break;
		case 25: Buffer.push_back(14); Buffer.push_back(2); break;
		case 26: Buffer.push_back(14); Buffer.push_back(3); break;
		case 27: Buffer.push_back(15); Buffer.push_back(0); break;
		case 28: Buffer.push_back(15); Buffer.push_back(1); break;
		case 29: Buffer.push_back(15); Buffer.push_back(2); break;
		case 30: Buffer.push_back(15); Buffer.push_back(3); break;
		case 31: Buffer.push_back(16); Buffer.push_back(0); break;
		case 32: Buffer.push_back(16); Buffer.push_back(1); break;
		case 33: Buffer.push_back(16); Buffer.push_back(2); break;
		case 34: Buffer.push_back(16); Buffer.push_back(3); break;

		case 35: Buffer.push_back(17); Buffer.push_back(0); break;
		case 36: Buffer.push_back(17); Buffer.push_back(1); break;
		case 37: Buffer.push_back(17); Buffer.push_back(2); break;
		case 38: Buffer.push_back(17); Buffer.push_back(3); break;
		case 39: Buffer.push_back(17); Buffer.push_back(4); break;
		case 40: Buffer.push_back(17); Buffer.push_back(5); break;
		case 41: Buffer.push_back(17); Buffer.push_back(6); break;
		case 42: Buffer.push_back(17); Buffer.push_back(7); break;
		case 43: Buffer.push_back(18); Buffer.push_back(0); break;
		case 44: Buffer.push_back(18); Buffer.push_back(1); break;
		case 45: Buffer.push_back(18); Buffer.push_back(2); break;
		case 46: Buffer.push_back(18); Buffer.push_back(3); break;
		case 47: Buffer.push_back(18); Buffer.push_back(4); break;
		case 48: Buffer.push_back(18); Buffer.push_back(5); break;
		case 49: Buffer.push_back(18); Buffer.push_back(6); break;
		case 50: Buffer.push_back(18); Buffer.push_back(7); break;
		case 51: Buffer.push_back(19); Buffer.push_back(0); break;
		case 52: Buffer.push_back(19); Buffer.push_back(1); break;
		case 53: Buffer.push_back(19); Buffer.push_back(2); break;
		case 54: Buffer.push_back(19); Buffer.push_back(3); break;
		case 55: Buffer.push_back(19); Buffer.push_back(4); break;
		case 56: Buffer.push_back(19); Buffer.push_back(5); break;
		case 57: Buffer.push_back(19); Buffer.push_back(6); break;
		case 58: Buffer.push_back(19); Buffer.push_back(7); break;
		case 59: Buffer.push_back(20); Buffer.push_back(0); break;
		case 60: Buffer.push_back(20); Buffer.push_back(1); break;
		case 61: Buffer.push_back(20); Buffer.push_back(2); break;
		case 62: Buffer.push_back(20); Buffer.push_back(3); break;
		case 63: Buffer.push_back(20); Buffer.push_back(4); break;
		case 64: Buffer.push_back(20); Buffer.push_back(5); break;
		case 65: Buffer.push_back(20); Buffer.push_back(6); break;
		case 66: Buffer.push_back(20); Buffer.push_back(7); break;

		case 67: Buffer.push_back(21); Buffer.push_back(0); break;
		case 68: Buffer.push_back(21); Buffer.push_back(1); break;
		case 69: Buffer.push_back(21); Buffer.push_back(2); break;
		case 70: Buffer.push_back(21); Buffer.push_back(3); break;
		case 71: Buffer.push_back(21); Buffer.push_back(4); break;
		case 72: Buffer.push_back(21); Buffer.push_back(5); break;
		case 73: Buffer.push_back(21); Buffer.push_back(6); break;
		case 74: Buffer.push_back(21); Buffer.push_back(7); break;
		case 75: Buffer.push_back(21); Buffer.push_back(8); break;
		case 76: Buffer.push_back(21); Buffer.push_back(9); break;
		case 77: Buffer.push_back(21); Buffer.push_back(10); break;
		case 78: Buffer.push_back(21); Buffer.push_back(11); break;
		case 79: Buffer.push_back(21); Buffer.push_back(12); break;
		case 80: Buffer.push_back(21); Buffer.push_back(13); break;
		case 81: Buffer.push_back(21); Buffer.push_back(14); break;
		case 82: Buffer.push_back(21); Buffer.push_back(15); break;
		case 83: Buffer.push_back(22); Buffer.push_back(0); break;
		case 84: Buffer.push_back(22); Buffer.push_back(1); break;
		case 85: Buffer.push_back(22); Buffer.push_back(2); break;
		case 86: Buffer.push_back(22); Buffer.push_back(3); break;
		case 87: Buffer.push_back(22); Buffer.push_back(4); break;
		case 88: Buffer.push_back(22); Buffer.push_back(5); break;
		case 89: Buffer.push_back(22); Buffer.push_back(6); break;
		case 90: Buffer.push_back(22); Buffer.push_back(7); break;
		case 91: Buffer.push_back(22); Buffer.push_back(8); break;
		case 92: Buffer.push_back(22); Buffer.push_back(9); break;
		case 93: Buffer.push_back(22); Buffer.push_back(10); break;
		case 94: Buffer.push_back(22); Buffer.push_back(11); break;
		case 95: Buffer.push_back(22); Buffer.push_back(12); break;
		case 96: Buffer.push_back(22); Buffer.push_back(13); break;
		case 97: Buffer.push_back(22); Buffer.push_back(14); break;
		case 98: Buffer.push_back(22); Buffer.push_back(15); break;
		case 99: Buffer.push_back(23); Buffer.push_back(0); break;
		case 100: Buffer.push_back(23); Buffer.push_back(1); break;
		case 101: Buffer.push_back(23); Buffer.push_back(2); break;
		case 102: Buffer.push_back(23); Buffer.push_back(3); break;
		case 103: Buffer.push_back(23); Buffer.push_back(4); break;
		case 104: Buffer.push_back(23); Buffer.push_back(5); break;
		case 105: Buffer.push_back(23); Buffer.push_back(6); break;
		case 106: Buffer.push_back(23); Buffer.push_back(7); break;
		case 107: Buffer.push_back(23); Buffer.push_back(8); break;
		case 108: Buffer.push_back(23); Buffer.push_back(9); break;
		case 109: Buffer.push_back(23); Buffer.push_back(10); break;
		case 110: Buffer.push_back(23); Buffer.push_back(11); break;
		case 111: Buffer.push_back(23); Buffer.push_back(12); break;
		case 112: Buffer.push_back(23); Buffer.push_back(13); break;
		case 113: Buffer.push_back(23); Buffer.push_back(14); break;
		case 114: Buffer.push_back(23); Buffer.push_back(15); break;
		case 115: Buffer.push_back(24); Buffer.push_back(0); break;
		case 116: Buffer.push_back(24); Buffer.push_back(1); break;
		case 117: Buffer.push_back(24); Buffer.push_back(2); break;
		case 118: Buffer.push_back(24); Buffer.push_back(3); break;
		case 119: Buffer.push_back(24); Buffer.push_back(4); break;
		case 120: Buffer.push_back(24); Buffer.push_back(5); break;
		case 121: Buffer.push_back(24); Buffer.push_back(6); break;
		case 122: Buffer.push_back(24); Buffer.push_back(7); break;
		case 123: Buffer.push_back(24); Buffer.push_back(8); break;
		case 124: Buffer.push_back(24); Buffer.push_back(9); break;
		case 125: Buffer.push_back(24); Buffer.push_back(10); break;
		case 126: Buffer.push_back(24); Buffer.push_back(11); break;
		case 127: Buffer.push_back(24); Buffer.push_back(12); break;
		case 128: Buffer.push_back(24); Buffer.push_back(13); break;
		case 129: Buffer.push_back(24); Buffer.push_back(14); break;
		case 130: Buffer.push_back(24); Buffer.push_back(15); break;

		case 131: Buffer.push_back(25); Buffer.push_back(0); break;
		case 132: Buffer.push_back(25); Buffer.push_back(1); break;
		case 133: Buffer.push_back(25); Buffer.push_back(2); break;
		case 134: Buffer.push_back(25); Buffer.push_back(3); break;
		case 135: Buffer.push_back(25); Buffer.push_back(4); break;
		case 136: Buffer.push_back(25); Buffer.push_back(5); break;
		case 137: Buffer.push_back(25); Buffer.push_back(6); break;
		case 138: Buffer.push_back(25); Buffer.push_back(7); break;
		case 139: Buffer.push_back(25); Buffer.push_back(8); break;
		case 140: Buffer.push_back(25); Buffer.push_back(9); break;
		case 141: Buffer.push_back(25); Buffer.push_back(10); break;
		case 142: Buffer.push_back(25); Buffer.push_back(11); break;
		case 143: Buffer.push_back(25); Buffer.push_back(12); break;
		case 144: Buffer.push_back(25); Buffer.push_back(13); break;
		case 145: Buffer.push_back(25); Buffer.push_back(14); break;
		case 146: Buffer.push_back(25); Buffer.push_back(15); break;
		case 147: Buffer.push_back(25); Buffer.push_back(16); break;
		case 148: Buffer.push_back(25); Buffer.push_back(17); break;
		case 149: Buffer.push_back(25); Buffer.push_back(18); break;
		case 150: Buffer.push_back(25); Buffer.push_back(19); break;
		case 151: Buffer.push_back(25); Buffer.push_back(20); break;
		case 152: Buffer.push_back(25); Buffer.push_back(21); break;
		case 153: Buffer.push_back(25); Buffer.push_back(22); break;
		case 154: Buffer.push_back(25); Buffer.push_back(23); break;
		case 155: Buffer.push_back(25); Buffer.push_back(24); break;
		case 156: Buffer.push_back(25); Buffer.push_back(25); break;
		case 157: Buffer.push_back(25); Buffer.push_back(26); break;
		case 158: Buffer.push_back(25); Buffer.push_back(27); break;
		case 159: Buffer.push_back(25); Buffer.push_back(28); break;
		case 160: Buffer.push_back(25); Buffer.push_back(29); break;
		case 161: Buffer.push_back(25); Buffer.push_back(30); break;
		case 162: Buffer.push_back(25); Buffer.push_back(31); break;
		case 163: Buffer.push_back(26); Buffer.push_back(0); break;
		case 164: Buffer.push_back(26); Buffer.push_back(1); break;
		case 165: Buffer.push_back(26); Buffer.push_back(2); break;
		case 166: Buffer.push_back(26); Buffer.push_back(3); break;
		case 167: Buffer.push_back(26); Buffer.push_back(4); break;
		case 168: Buffer.push_back(26); Buffer.push_back(5); break;
		case 169: Buffer.push_back(26); Buffer.push_back(6); break;
		case 170: Buffer.push_back(26); Buffer.push_back(7); break;
		case 171: Buffer.push_back(26); Buffer.push_back(8); break;
		case 172: Buffer.push_back(26); Buffer.push_back(9); break;
		case 173: Buffer.push_back(26); Buffer.push_back(10); break;
		case 174: Buffer.push_back(26); Buffer.push_back(11); break;
		case 175: Buffer.push_back(26); Buffer.push_back(12); break;
		case 176: Buffer.push_back(26); Buffer.push_back(13); break;
		case 177: Buffer.push_back(26); Buffer.push_back(14); break;
		case 178: Buffer.push_back(26); Buffer.push_back(15); break;
		case 179: Buffer.push_back(26); Buffer.push_back(16); break;
		case 180: Buffer.push_back(26); Buffer.push_back(17); break;
		case 181: Buffer.push_back(26); Buffer.push_back(18); break;
		case 182: Buffer.push_back(26); Buffer.push_back(19); break;
		case 183: Buffer.push_back(26); Buffer.push_back(20); break;
		case 184: Buffer.push_back(26); Buffer.push_back(21); break;
		case 185: Buffer.push_back(26); Buffer.push_back(22); break;
		case 186: Buffer.push_back(26); Buffer.push_back(23); break;
		case 187: Buffer.push_back(26); Buffer.push_back(24); break;
		case 188: Buffer.push_back(26); Buffer.push_back(25); break;
		case 189: Buffer.push_back(26); Buffer.push_back(26); break;
		case 190: Buffer.push_back(26); Buffer.push_back(27); break;
		case 191: Buffer.push_back(26); Buffer.push_back(28); break;
		case 192: Buffer.push_back(26); Buffer.push_back(29); break;
		case 193: Buffer.push_back(26); Buffer.push_back(30); break;
		case 194: Buffer.push_back(26); Buffer.push_back(31); break;
		case 195: Buffer.push_back(27); Buffer.push_back(0); break;
		case 196: Buffer.push_back(27); Buffer.push_back(1); break;
		case 197: Buffer.push_back(27); Buffer.push_back(2); break;
		case 198: Buffer.push_back(27); Buffer.push_back(3); break;
		case 199: Buffer.push_back(27); Buffer.push_back(4); break;
		case 200: Buffer.push_back(27); Buffer.push_back(5); break;
		case 201: Buffer.push_back(27); Buffer.push_back(6); break;
		case 202: Buffer.push_back(27); Buffer.push_back(7); break;
		case 203: Buffer.push_back(27); Buffer.push_back(8); break;
		case 204: Buffer.push_back(27); Buffer.push_back(9); break;
		case 205: Buffer.push_back(27); Buffer.push_back(10); break;
		case 206: Buffer.push_back(27); Buffer.push_back(11); break;
		case 207: Buffer.push_back(27); Buffer.push_back(12); break;
		case 208: Buffer.push_back(27); Buffer.push_back(13); break;
		case 209: Buffer.push_back(27); Buffer.push_back(14); break;
		case 210: Buffer.push_back(27); Buffer.push_back(15); break;
		case 211: Buffer.push_back(27); Buffer.push_back(16); break;
		case 212: Buffer.push_back(27); Buffer.push_back(17); break;
		case 213: Buffer.push_back(27); Buffer.push_back(18); break;
		case 214: Buffer.push_back(27); Buffer.push_back(19); break;
		case 215: Buffer.push_back(27); Buffer.push_back(20); break;
		case 216: Buffer.push_back(27); Buffer.push_back(21); break;
		case 217: Buffer.push_back(27); Buffer.push_back(22); break;
		case 218: Buffer.push_back(27); Buffer.push_back(23); break;
		case 219: Buffer.push_back(27); Buffer.push_back(24); break;
		case 220: Buffer.push_back(27); Buffer.push_back(25); break;
		case 221: Buffer.push_back(27); Buffer.push_back(26); break;
		case 222: Buffer.push_back(27); Buffer.push_back(27); break;
		case 223: Buffer.push_back(27); Buffer.push_back(28); break;
		case 224: Buffer.push_back(27); Buffer.push_back(29); break;
		case 225: Buffer.push_back(27); Buffer.push_back(30); break;
		case 226: Buffer.push_back(27); Buffer.push_back(31); break;
		case 227: Buffer.push_back(28); Buffer.push_back(0); break;
		case 228: Buffer.push_back(28); Buffer.push_back(1); break;
		case 229: Buffer.push_back(28); Buffer.push_back(2); break;
		case 230: Buffer.push_back(28); Buffer.push_back(3); break;
		case 231: Buffer.push_back(28); Buffer.push_back(4); break;
		case 232: Buffer.push_back(28); Buffer.push_back(5); break;
		case 233: Buffer.push_back(28); Buffer.push_back(6); break;
		case 234: Buffer.push_back(28); Buffer.push_back(7); break;
		case 235: Buffer.push_back(28); Buffer.push_back(8); break;
		case 236: Buffer.push_back(28); Buffer.push_back(9); break;
		case 237: Buffer.push_back(28); Buffer.push_back(10); break;
		case 238: Buffer.push_back(28); Buffer.push_back(11); break;
		case 239: Buffer.push_back(28); Buffer.push_back(12); break;
		case 240: Buffer.push_back(28); Buffer.push_back(13); break;
		case 241: Buffer.push_back(28); Buffer.push_back(14); break;
		case 242: Buffer.push_back(28); Buffer.push_back(15); break;
		case 243: Buffer.push_back(28); Buffer.push_back(16); break;
		case 244: Buffer.push_back(28); Buffer.push_back(17); break;
		case 245: Buffer.push_back(28); Buffer.push_back(18); break;
		case 246: Buffer.push_back(28); Buffer.push_back(19); break;
		case 247: Buffer.push_back(28); Buffer.push_back(20); break;
		case 248: Buffer.push_back(28); Buffer.push_back(21); break;
		case 249: Buffer.push_back(28); Buffer.push_back(22); break;
		case 250: Buffer.push_back(28); Buffer.push_back(23); break;
		case 251: Buffer.push_back(28); Buffer.push_back(24); break;
		case 252: Buffer.push_back(28); Buffer.push_back(25); break;
		case 253: Buffer.push_back(28); Buffer.push_back(26); break;
		case 254: Buffer.push_back(28); Buffer.push_back(27); break;
		case 255: Buffer.push_back(28); Buffer.push_back(28); break;
		case 256: Buffer.push_back(28); Buffer.push_back(29); break;
		case 257: Buffer.push_back(28); Buffer.push_back(30); break;

		case 258:  Buffer.push_back(29); Buffer.push_back(0); break;

		}

	}

	ARCHIVE_ERROR CHV4DSTREAM::PushDistance(size_t const& dist)
	{
		if		(dist == 1)						 { Buffer.push_back( 0); Buffer.push_back(0);	  Buffer.push_back(0);            }
		else if (dist == 2)						 { Buffer.push_back( 1); Buffer.push_back(0);	  Buffer.push_back(0);            }
		else if (dist == 3)						 { Buffer.push_back( 2); Buffer.push_back(0);	  Buffer.push_back(0);            }
		else if (dist == 4)						 { Buffer.push_back( 3); Buffer.push_back(0);	  Buffer.push_back(0);            }
		else if (dist == 5 || dist == 6)		 { Buffer.push_back( 4); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 5));     }
		else if (dist == 7 || dist == 8)		 { Buffer.push_back( 5); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 7));     }
		else if (dist >= 9 || dist <= 12)		 { Buffer.push_back( 6); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 9));     }
		else if (dist >= 13 || dist <= 16)		 { Buffer.push_back( 7); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 13));    }
		else if (dist >= 17 || dist <= 24)		 { Buffer.push_back( 8); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 17));    }
		else if (dist >= 25 || dist <= 32)		 { Buffer.push_back( 9); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 25));    }
		else if (dist >= 33 || dist <= 48)		 { Buffer.push_back(10); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 33));    }
		else if (dist >= 49 || dist <= 64)		 { Buffer.push_back(11); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 49));    }
		else if (dist >= 65 || dist <= 96)		 { Buffer.push_back(12); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 65));    }
		else if (dist >= 97 || dist <= 128)		 { Buffer.push_back(13); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 97));    }
		else if (dist >= 129 || dist <= 192)	 { Buffer.push_back(14); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 129));   }
		else if (dist >= 193 || dist <= 256)	 { Buffer.push_back(15); Buffer.push_back(0);	  Buffer.push_back(static_cast<unsigned char>(dist - 193));   }
		else if (dist >= 257 || dist <= 384)	 { Buffer.push_back(16); Buffer.push_back(0);     Buffer.push_back(static_cast<unsigned char>(dist - 257));   }
		else if (dist >= 385 || dist <= 512)	 { Buffer.push_back(17); Buffer.push_back(0);     Buffer.push_back(static_cast<unsigned char>(dist - 385));   }
		else if (dist >= 513 || dist <= 768)	 { Buffer.push_back(18); Buffer.push_back(0);     Buffer.push_back(static_cast<unsigned char>(dist - 513));   }
		else if (dist >= 769 || dist <= 1024)	 { Buffer.push_back(19); Buffer.push_back(0);     Buffer.push_back(static_cast<unsigned char>(dist - 769));   }
		else if (dist >= 1025 || dist <= 1536)   { Buffer.push_back(20); Buffer.push_back(static_cast<unsigned char>((dist - 1025) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 1025) >> 8) << 8)); }
		else if (dist >= 1537 || dist <= 2048)	 { Buffer.push_back(21); Buffer.push_back(static_cast<unsigned char>((dist - 1537) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 1537) >> 8) << 8));  }
		else if (dist >= 2049 || dist <= 3072)	 { Buffer.push_back(22); Buffer.push_back(static_cast<unsigned char>((dist - 2049) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 2049) >> 8) << 8));  }
		else if (dist >= 3073 || dist <= 4096)	 { Buffer.push_back(23); Buffer.push_back(static_cast<unsigned char>((dist - 3073) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 3073) >> 8) << 8));  }
		else if (dist >= 4097 || dist <= 6144)	 { Buffer.push_back(24); Buffer.push_back(static_cast<unsigned char>((dist - 4097) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 4097) >> 8) << 8));  }
		else if (dist >= 6145 || dist <= 8192)	 { Buffer.push_back(25); Buffer.push_back(static_cast<unsigned char>((dist - 6145) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 6145) >> 8) << 8));  }
		else if (dist >= 8193 || dist <= 12288)  { Buffer.push_back(26); Buffer.push_back(static_cast<unsigned char>((dist - 8193) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 8193) >> 8) << 8));  }
		else if (dist >= 12289 || dist <= 16384) { Buffer.push_back(27); Buffer.push_back(static_cast<unsigned char>((dist - 12289) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 12289) >> 8) << 8)); }
		else if (dist >= 16385 || dist <= 24576) { Buffer.push_back(28); Buffer.push_back(static_cast<unsigned char>((dist - 16385) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 16385) >> 8) << 8)); }
		else if (dist >= 24577 || dist <= 32768) { Buffer.push_back(29); Buffer.push_back(static_cast<unsigned char>((dist - 24577) >> 8)); Buffer.push_back(static_cast<unsigned char>(((dist - 24577) >> 8) << 8)); }
		  
	}

	ARCHIVE_ERROR CHV4DSTREAM::SlideWindow(size_t const& shift)
	{
		ARCHIVE_ERROR error = ARCHIVE_ERROR_SUCCEEDED;

		if (std::distance(BlockSentinel, Block->cend()) < shift) return ARCHIVE_ERROR_OUT_OF_RANGE;

		BlockSentinel = std::next(BlockSentinel, shift);

		LiteralSentinel = std::next(BlockSentinel, 1);

		return error;

	}

}