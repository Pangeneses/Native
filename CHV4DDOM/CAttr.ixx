module;

#include <string>


export module CHV4DXML:CAttr;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Attr;

export namespace CHV4DXML
{
	class CAttr : public Attr
	{
	public:
		CAttr() = default;

	public:
		std::wstring nspaceURI();

		std::wstring prefix();

		std::wstring localName();

		std::wstring name();

		std::wstring value();
		void value(std::wstring val);

		IElement ownerElement();
		void ownerElement(IElement owner);

		bool specified(); // useless; always returns true

	public:
		XML_DOM_NODE_TYPE nodeType();

		std::wstring nodeName();

		std::wstring baseURI();

		bool isConnected();

		IDocument ownerDocument();

		INode GetRootNode();
		INode GetRootNode(GetRootNodeOptions options);

		INode parentNode();

		IElement parentElement();

		bool HasChildNodes();

		INodeList childNodes();

		INode firstChild();
		INode lastChild();
		INode previousSibling();
		INode nextSibling();

		std::wstring nodeValue();
		void nodeValue(std::wstring val);

		std::wstring textContent();
		void textContent(std::wstring text);

		void Normalize();

		INode CloneNode();
		INode CloneNode(bool deep);

		bool isEqualNode(INode otherINode);
		bool isSameNode(INode otherINode); // legacy alias of ===

		uint8_t CompareDocumentPosition(INode other);

		bool Contains(INode other);

		std::wstring LookupPrefix(std::wstring nspace);

		std::wstring LookupNamespaceURI(std::wstring prefix);

		bool IsDefaultNamespace(std::wstring nspace);

		INode InsertBefore(INode node, INode child);
		INode AppendChild(INode node);
		INode ReplaceChild(INode node, INode child);
		INode RemoveChild(INode child);

		void AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options);

		void RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options);

		bool DispatchEvent(IEvent dispathchedEvent);

	};

}