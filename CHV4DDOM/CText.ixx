module;

#include <string>


export module CHV4DXML:CText;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Text;

export namespace CHV4DXML
{
	// include: Slottable, 

	class CText : public Text
	{
	public:
		CText(std::wstring data = L"");

	public:
		IText splitText(uint32_t offset);

		std::wstring wholeText();

	public:
		std::wstring data();
		void data(std::wstring e);

		uint32_t length();
		void length(uint32_t len);

		std::wstring SubstringData(uint32_t offset, uint32_t count);

		void AppendData(std::wstring data);
		void InsertData(uint32_t offset, std::wstring data);
		void DeleteData(uint32_t offset, uint32_t count);
		void ReplaceData(uint32_t offset, uint32_t count, std::wstring data);

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