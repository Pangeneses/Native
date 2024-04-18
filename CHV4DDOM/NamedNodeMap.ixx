module;

#include <string>

export module CHV4DXML:NamedNodeMap;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class NamedNodeMap
	{
	public:
		NamedNodeMap() = default;

	public:
		virtual uint32_t length() = 0; 
		virtual void length(uint32_t e) = 0; 

		virtual IAttr Item(uint32_t index) = 0;
					
		virtual IAttr GetNamedItem(std::wstring qualifiedName) = 0;
					
		virtual IAttr GetNamedItemNS(std::wstring nspace, std::wstring localName) = 0;
		virtual IAttr SetNamedItem(IAttr attr) = 0;
		virtual IAttr SetNamedItemNS(IAttr attr) = 0;
		virtual IAttr RemoveNamedItem(std::wstring qualifiedName) = 0;
		virtual IAttr RemoveNamedItemNS(std::wstring nspace, std::wstring localName) = 0;

	public:
		virtual ~NamedNodeMap() = 0;

	};

}