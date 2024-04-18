module;

#include <string>

export module CHV4DXML:Attr;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	class Attr : public Node 
	{
	public:
		Attr() = default;

	public:
		virtual std::wstring nspaceURI() = 0;

		virtual std::wstring prefix() = 0;

		virtual std::wstring localName() = 0;

		virtual std::wstring name() = 0;

		virtual std::wstring value() = 0;
		virtual void value(std::wstring val) = 0;

		virtual IElement ownerElement() = 0;
		virtual void ownerElement(IElement owner) = 0;

		virtual bool specified() = 0; // useless; always returns true

	public:
		virtual ~Attr() = 0;

	};

}