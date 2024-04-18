module;

#include <string>

export module CHV4DXML:HTMLCollection;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class HTMLCollection
	{
	public:
		HTMLCollection() = default;

	public:
		virtual uint32_t length() = 0;

		virtual IElement Item(uint32_t index) = 0;

		virtual IElement NamedItem(std::wstring name) = 0;

	public:
		virtual ~HTMLCollection() = 0;

	};
	
}