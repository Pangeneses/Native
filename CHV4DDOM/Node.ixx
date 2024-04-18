module;

#include <string>

export module CHV4DXML:Node;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :EventTarget;

export namespace CHV4DXML
{
	class Node : public EventTarget
	{
	public:
		Node() = default;

	public:
		virtual XML_DOM_NODE_TYPE nodeType() = 0;
		 
		virtual std::wstring nodeName() = 0;
		 
		virtual std::wstring baseURI() = 0;
		 
		virtual bool isConnected() = 0;
		 
		virtual IDocument ownerDocument() = 0;
		 
		virtual INode GetRootNode() = 0;
		virtual INode GetRootNode(GetRootNodeOptions options) = 0;
		 
		virtual INode parentNode() = 0;
		 
		virtual IElement parentElement() = 0;
		 
		virtual bool HasChildNodes() = 0;

		virtual INodeList childNodes() = 0;

		virtual INode firstChild() = 0;
		virtual INode lastChild() = 0;
		virtual INode previousSibling() = 0;
		virtual INode nextSibling() = 0;

		virtual std::wstring nodeValue() = 0; 
		virtual void nodeValue(std::wstring val) = 0; 

		virtual std::wstring textContent() = 0; 
		virtual void textContent(std::wstring text) = 0; 

		virtual void Normalize() = 0;

		virtual INode CloneNode() = 0;
		virtual INode CloneNode(bool deep) = 0;

		virtual bool isEqualNode(INode otherNode) = 0;
		virtual bool isSameNode(INode otherNode) = 0; // legacy alias of ===
		
		virtual uint8_t CompareDocumentPosition(INode other) = 0;

		virtual bool Contains(INode other) = 0;

		virtual std::wstring LookupPrefix(std::wstring nspace) = 0;

		virtual std::wstring LookupNamespaceURI(std::wstring prefix) = 0;

		virtual bool IsDefaultNamespace(std::wstring nspace) = 0;

		virtual INode InsertBefore(INode node, INode child) = 0;
		virtual INode AppendChild(INode node) = 0;
		virtual INode ReplaceChild(INode node, INode child) = 0;
		virtual INode RemoveChild(INode child) = 0;

	public:
		virtual ~Node() = 0;

	};

}