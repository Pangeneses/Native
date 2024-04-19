module;

#include <string>

#include <functional>
#include <memory>

#include <vector>

#include <stdexcept> 

module CHV4DARCHIVE:CHV4DSTREAM;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CHV4DBITSTREAM;

namespace CHV4DARCHIVE
{
	ARCHIVE_ERROR CHV4DSTREAM::DeflateCompression(DEFLATE_COMPRESSION method) 
	{ 
		Method = method; 
	
		return ARCHIVE_ERROR_SUCCEEDED;

	}

	DEFLATE_COMPRESSION CHV4DSTREAM::DeflateCompression() 
	{ 
		
		return Method; 
	
	}

	ARCHIVE_ERROR CHV4DSTREAM::szWindow(size_t sz) 
	{ 
		WindowSize = sz; 

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	size_t CHV4DSTREAM::szWindow() 
	{ 
		
		return WindowSize; 
	
	}

	ARCHIVE_ERROR CHV4DSTREAM::SharedBlock(std::shared_ptr<std::vector<unsigned char>> block)
	{ 
		Block.reset(block.get());

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	std::shared_ptr<std::vector<unsigned char>> CHV4DSTREAM::SharedBlock()
	{ 
		
		return Block;
	
	}

	ARCHIVE_ERROR CHV4DSTREAM::EmptyStream()
	{
		Method = DEFLATE_COMPRESSION_NO;

		WindowSize = 32768;

		Block = nullptr;

		BlockSentinel = Block->begin();

		LiteralSentinel = Block->begin();

		Index.clear();

		BitStream = nullptr;

		Window.clear();

		return ARCHIVE_ERROR_SUCCEEDED;

	}

	std::vector<unsigned char>::const_iterator CHV4DSTREAM::RefBlockSentinel()
	{

		return BlockSentinel;

	}

	std::vector<unsigned char>::const_iterator CHV4DSTREAM::RefLiteralSentinel()
	{

		return LiteralSentinel;

	}

	std::list<std::vector<unsigned char>::const_iterator> CHV4DSTREAM::RefIndex()
	{

		return Index;

	}

	std::shared_ptr<CHV4DARCHIVE::CHV4DBITSTREAM> CHV4DSTREAM::RefBitStream()
	{

		return BitStream;

	}

}