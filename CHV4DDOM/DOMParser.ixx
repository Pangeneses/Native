module;

#include <string>

export module CHV4DXML:DOMParser;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class DOMParser
	{
	public:
		DOMParser() = default;

	public:
		virtual IDocument ParseFromString(std::wstring string, XML_DOM_PARSER_SUPPORTED_TYPE type) = 0;

	public:
		virtual ~DOMParser() = 0;

	};

}