module;

#include <string>

module CHV4DXML:CDOMParser;

import CHV4DENCODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CDocument;

namespace CHV4DXML
{
	IDocument CDOMParser::ParseFromString(std::wstring string, XML_DOM_PARSER_SUPPORTED_TYPE type, 
		CHV4DENCODE::ENCODING encode)
	{
		return nullptr;

	}

}