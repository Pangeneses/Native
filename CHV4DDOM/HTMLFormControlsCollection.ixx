module;

#include <string>

export module CHV4DXML:HTMLFormControlsCollection;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :NodeList;
import :HTMLCollection;

export namespace CHV4DXML
{
	class HTMLFormControlsCollection : public HTMLCollection 
	{
	public:
		HTMLFormControlsCollection() = default;

	public:
		// inherits length and item()
		virtual IElement NamedItem(std::wstring name) = 0; // shadows inherited namedItem()

	public:
		virtual ~HTMLFormControlsCollection() = 0;

	};
	
	class RadioNodeList : public NodeList 
	{
	public:
		RadioNodeList() = default;

	public:
		virtual std::wstring value() = 0; 
		virtual void value(std::wstring val) = 0; 

	public:
		virtual ~RadioNodeList() = 0;

	};

}