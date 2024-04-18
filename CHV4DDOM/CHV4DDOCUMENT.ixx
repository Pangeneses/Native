module;

#include <string>

export module CHV4DXML:CHV4DDOCUMENT;

import CHV4DENCODE;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CDOMParser;

export namespace CHV4DXML
{
	template<class charT, class Tr = std::char_traits<charT>>
	IDocument OpenDocument(std::wstring file, XML_DOM_PARSER_SUPPORTED_TYPE type = XML_DOM_APPLICATION_XML)
	{
		//CHV4DENCODE::IFileView doc = new CHV4DENCODE::CFileView<charT>{};

		//CDOMParser{}.ParseFromString(string, type);

		return nullptr;

	}

	bool CommitDocument(IDocument doc, std::wstring file)
	{

		//CDOMParser{}.ParseFromString(string, type);

		return false;

	}

	


}