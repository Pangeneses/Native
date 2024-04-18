module;

#include <string>
#include <stdexcept>

export module CHV4DXML:CDocumentType;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :DocumentType;

export namespace CHV4DXML
{
	// include: ChildNodeChildNode, 

	template<class T>
	class CDocumentType : public DocumentType, public T
	{
	public:
		CDocumentType(std::wstring name) : DocumentTypeName(name) { if (name == L"") throw std::invalid_argument(L""); }

	public:
		std::wstring name();

		std::wstring publicId();

		std::wstring systemId();

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

	public:
		void AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options);

		void RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options);

		bool DispatchEvent(IEvent dispathchedEvent);

	private:
		std::wstring DocumentTypeName{ L"" };

	};

}