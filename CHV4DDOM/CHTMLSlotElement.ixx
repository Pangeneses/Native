module;

#include <string>


export module CHV4DXML:CHTMLSlotElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :HTMLSlotElement;

export namespace CHV4DXML
{
	class CHTMLSlotElement : public HTMLSlotElement
	{
	public:
		CHTMLSlotElement() = default;

	public:
		std::wstring name();
		void name(std::wstring e);

		std::vector<INode> assignedNodes();
		std::vector<INode> assignedNodes(AssignedNodesOptions options);

		std::vector<IElement> assignedElements();
		std::vector<IElement> assignedElements(AssignedNodesOptions options);

		void Assign(std::vector<INode> nodes);

	public:
		std::wstring nspaceURI();
		std::wstring prefix();
		std::wstring localName();
		std::wstring tagName();

		std::wstring eid();

		std::wstring className();
		void className(std::wstring name);

		IDOMTokenList classList();

		std::wstring slot();
		void slot(std::wstring in);

		bool HasAttributes();

		INamedNodeMap attributes();

		std::vector<std::wstring> GetAttributeNames();

		std::wstring GetAttribute(std::wstring qualifiedName);
		std::wstring GetAttributeNS(std::wstring nspace, std::wstring localName);

		void SetAttribute(std::wstring qualifiedName, std::wstring value);
		void SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value);
		void RemoveAttribute(std::wstring qualifiedName);
		void RemoveAttributeNS(std::wstring nspace, std::wstring localName);

		bool ToggleAttribute(std::wstring qualifiedName);
		bool ToggleAttribute(std::wstring qualifiedName, bool force);

		bool HasAttribute(std::wstring qualifiedName);
		bool HasAttributeNS(std::wstring nspace, std::wstring localName);

		IAttr GetAttributeNode(std::wstring qualifiedName);
		IAttr GetAttributeNodeNS(std::wstring nspace, std::wstring localName);

		IAttr SetAttributeNode(IAttr attr);
		IAttr SetAttributeNodeNS(IAttr attr);
		IAttr RemoveAttributeNode(IAttr attr);

		IShadowRoot AttachShadow(ShadowRootInit init);

		IShadowRoot shadowRoot();

		IElement Closest(std::wstring selectors);

		bool Matches(std::wstring selectors);
		bool WebkitMatchesSelector(std::wstring selectors); // legacy alias of .matches

		IHTMLCollection GetElementsByTagName(std::wstring qualifiedName);
		IHTMLCollection GetElementsByTagNameNS(std::wstring nspace, std::wstring localName);
		IHTMLCollection GetElementsByClassName(std::wstring classNames);

		IElement InsertAdjacentElement(std::wstring where, IElement element); // legacy
		void InsertAdjacentText(std::wstring where, std::wstring data); // legacy

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