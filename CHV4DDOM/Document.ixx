module;

#include <string>

export module CHV4DXML:Document;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	//includes: NonElementParentNode, DocumentOrShadowRoot, ParentNode, XPathEvaluatorBase, 

	class Document : public Node
	{
	public:
		Document() = default;

	public:
		virtual IDOMImplementation implementation() = 0;

		virtual std::wstring URL() = 0;
		virtual std::wstring documentURI() = 0;
		virtual std::wstring compatMode() = 0;
		virtual std::wstring characterSet() = 0;
		virtual std::wstring charset() = 0; // legacy alias of .characterSet
		virtual std::wstring inputEncoding() = 0; // legacy alias of .characterSet
		virtual std::wstring contentType() = 0;

		virtual IDocumentType doctype() = 0;

		virtual IElement documentElement() = 0;

		virtual IHTMLCollection GetElementsByTagName(std::wstring qualifiedName) = 0;
		virtual IHTMLCollection GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) = 0;
		virtual IHTMLCollection GetElementsByClassName(std::wstring classNames) = 0;

		virtual IElement CreateElement(std::wstring localName) = 0;
		virtual IElement CreateElement(std::wstring localName, std::wstring options) = 0;

		virtual IElement CreateElementNS(std::wstring nspace, std::wstring qualifiedName) = 0;
		virtual IElement CreateElementNS(std::wstring nspace, std::wstring qualifiedName, std::wstring options) = 0;

		virtual IDocumentFragment CreateDocumentFragment() = 0;

		virtual IText CreateTextNode(std::wstring data) = 0;

		virtual ICDATASection CreateCDATASection(std::wstring data) = 0;

		virtual IComment CreateComment(std::wstring data) = 0;

		virtual IProcessingInstruction CreateProcessingInstruction(std::wstring target, std::wstring data) = 0;

		virtual INode ImportNode(INode node) = 0;
		virtual INode ImportNode(INode node, bool deep) = 0;

		virtual INode AdoptNode(INode node) = 0;

		virtual IAttr CreateAttribute(std::wstring localName) = 0;
		virtual IAttr CreateAttributeNS(std::wstring nspace, std::wstring qualifiedName) = 0;

		virtual IEvent CreateEvent(std::wstring contract) = 0; // legacy

		virtual IRange CreateRange() = 0;

		// INodeFilter.SHOW_ALL = 0xFFFFFFFF
		virtual INodeIterator CreateNodeIterator(INode root, uint32_t whatToShow, INodeFilter filter) = 0;
		
		virtual ITreeWalker CreateTreeWalker(INode root, uint32_t whatToShow, INodeFilter filter) = 0;

	public:
		virtual ~Document() = 0;

	};

}