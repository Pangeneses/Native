module;

#include <string>


export module CHV4DXML:CDocument;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Document;
import :DOMImplementation;
import :CDocumentType;

export namespace CHV4DXML
{
	//includes: NonElementParentNode, DocumentOrShadowRoot, ParentNode, XPathEvaluatorBase, 

	//template<class MetaData>
	class CDocument : public Document //, public MetaData
	{
	public:
		CDocument() = default;

	public:
		IDOMImplementation implementation();

		std::wstring URL();
		std::wstring documentURI();
		std::wstring compatMode();
		std::wstring characterSet();
		std::wstring charset(); // legacy alias of .characterSet
		std::wstring inputEncoding(); // legacy alias of .characterSet
		std::wstring contentType();

		IDocumentType doctype();

		IElement documentElement();

		IHTMLCollection GetElementsByTagName(std::wstring qualifiedName);
		IHTMLCollection GetElementsByTagNameNS(std::wstring nspace, std::wstring localName);
		IHTMLCollection GetElementsByClassName(std::wstring classNames);

		IElement CreateElement(std::wstring localName);
		IElement CreateElement(std::wstring localName, std::wstring options);

		IElement CreateElementNS(std::wstring nspace, std::wstring qualifiedName);
		IElement CreateElementNS(std::wstring nspace, std::wstring qualifiedName, std::wstring options);

		IDocumentFragment CreateDocumentFragment();

		IText CreateTextNode(std::wstring data);

		ICDATASection CreateCDATASection(std::wstring data);

		IComment CreateComment(std::wstring data);

		IProcessingInstruction CreateProcessingInstruction(std::wstring target, std::wstring data);

		INode ImportNode(INode node);
		INode ImportNode(INode node, bool deep);

		INode AdoptNode(INode node);

		IAttr CreateAttribute(std::wstring localName);
		IAttr CreateAttributeNS(std::wstring nspace, std::wstring qualifiedName);

		IEvent CreateEvent(std::wstring contract); // legacy

		IRange CreateRange();

		// INodeFilter.SHOW_ALLxFFFFFFFF
		INodeIterator CreateNodeIterator(INode root, uint32_t whatToShow, INodeFilter filter);

		ITreeWalker CreateTreeWalker(INode root, uint32_t whatToShow, INodeFilter filter);

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
		class CDocumentDOMImplementation : public DOMImplementation
		{
		public:
			CDocumentDOMImplementation() = default;

		public:
			IDocumentType CreateDocumentType(std::wstring qualifiedName, std::wstring publicId, std::wstring systemId);

			IXMLDocument CreateDocument(std::wstring nspace, std::wstring qualifiedName, IDocumentType doctype);

			IDocument CreateHTMLDocument(std::wstring title);

			bool HasFeature(); // useless; always returns true

		};

	private:
		IDOMImplementation DOMImplementationObject{ new CDocumentDOMImplementation{} };

		std::wstring DocumentEncoding{ L"UTF-8" };

		std::wstring DocumentContentType{ L"application/xml" };

		std::wstring DocumentURL{ L"about:blank" };

		std::wstring DocumentOrigin{ L"" };

		std::wstring DocumentMode{ L"no-quirks" };

	};

	class XMLDocumentMetaData
	{
	public:
		XMLDocumentMetaData() = default;

	private:
		inline static const std::wstring DocumentTypePublicId = L"";

		inline static const std::wstring DocumentTypeSystemId = L"";

	};

	typedef class XMLDocument : public CDocument //<XMLDocumentMetaData>
	{
	public:
		XMLDocument() = default;

	}* IXMLDocument;

	class HTMLDocumentMetaData
	{
	public:
		HTMLDocumentMetaData() = default;

	private:
		inline static const std::wstring DocumentTypePublicId = L"";

		inline static const std::wstring DocumentTypeSystemId = L"";

	};

	class CHTMLDocument : public CDocument //<HTMLDocumentMetaData>
	{
	public:
		CHTMLDocument() = default;

	};

}