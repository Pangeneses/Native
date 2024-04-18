module;

#include <string>


export module CHV4DXML:CDOMParser;

import CHV4DENCODE;

import :DOMParser;

export namespace CHV4DXML
{
	class CDOMParser : public DOMParser
	{
	public:
		CDOMParser() = default;

	public:
		IDocument ParseFromString(std::wstring string, XML_DOM_PARSER_SUPPORTED_TYPE type,
			CHV4DENCODE::ENCODING encode = CHV4DENCODE::ENCODING_UNKNOWN);


	};

}