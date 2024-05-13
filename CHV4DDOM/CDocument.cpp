module;

#include <string>

module CHV4DXML:CDocument;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IDOMImplementation CDocument::implementation() { return DOMImplementationObject; }

	std::wstring CDocument::URL() 
	{ 
		auto v = ParserSupportedType{}(XML_DOM_TEXT_XML);

		return DocumentURL; 
	
	}

	std::wstring CDocument::documentURI() { return {}; }
	std::wstring CDocument::compatMode() { return {}; }
	std::wstring CDocument::characterSet() { return {}; }
	std::wstring CDocument::charset() { return characterSet(); } // legacy alias of .characterSet
	std::wstring CDocument::inputEncoding() { return characterSet(); } // legacy alias of .characterSet
	std::wstring CDocument::contentType() { return {}; }

	IDocumentType CDocument::doctype() { return nullptr; }

	IElement CDocument::documentElement() { return nullptr; }

	IHTMLCollection CDocument::GetElementsByTagName(std::wstring qualifiedName) { return nullptr; }
	IHTMLCollection CDocument::GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) { return nullptr; }
	IHTMLCollection CDocument::GetElementsByClassName(std::wstring classNames) { return nullptr; }

	IElement CDocument::CreateElement(std::wstring localName) { return nullptr; }
	IElement CDocument::CreateElement(std::wstring localName, std::wstring options) { return nullptr; }
			 
	IElement CDocument::CreateElementNS(std::wstring nspace, std::wstring qualifiedName) { return nullptr; }
	IElement CDocument::CreateElementNS(std::wstring nspace, std::wstring qualifiedName, std::wstring options) { return nullptr; }

	IDocumentFragment CDocument::CreateDocumentFragment() { return nullptr; }

	IText CDocument::CreateTextNode(std::wstring data) { return nullptr; }

	ICDATASection CDocument::CreateCDATASection(std::wstring data) { return nullptr; }

	IComment CDocument::CreateComment(std::wstring data) { return nullptr; }

	IProcessingInstruction CDocument::CreateProcessingInstruction(std::wstring target, std::wstring data) { return nullptr; }

	INode CDocument::ImportNode(INode node) { return nullptr; }
	INode CDocument::ImportNode(INode node, bool deep) { return nullptr; }
		 
	INode CDocument::AdoptNode(INode node) { return nullptr; }
		 
	IAttr CDocument::CreateAttribute(std::wstring localName) { return nullptr; }
	IAttr CDocument::CreateAttributeNS(std::wstring nspace, std::wstring qualifiedName) { return nullptr; }

	IEvent CDocument::CreateEvent(std::wstring contract) { return nullptr; } // legacy

	IRange CDocument::CreateRange() { return nullptr; }

	// INodeFilter.SHOW_ALLxFFFFFFFF
	INodeIterator CDocument::CreateNodeIterator(INode root, uint32_t whatToShow, INodeFilter filter) { return nullptr; }

	ITreeWalker CDocument::CreateTreeWalker(INode root, uint32_t whatToShow, INodeFilter filter) { return nullptr; }

	XML_DOM_NODE_TYPE CDocument::nodeType() { return XML_DOM_DOCUMENT_TYPE_NODE; }

	std::wstring CDocument::nodeName() { return {}; }

	std::wstring CDocument::baseURI() { return {}; }

	bool CDocument::isConnected() { return false; }

	IDocument CDocument::ownerDocument() { return nullptr; }

	INode CDocument::GetRootNode() { return nullptr; }
	INode CDocument::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CDocument::parentNode() { return nullptr; }

	IElement CDocument::parentElement() { return nullptr; }

	bool CDocument::HasChildNodes() { return false; }

	INodeList CDocument::childNodes() { return nullptr; }

	INode CDocument::firstChild() {  return nullptr; }
	INode CDocument::lastChild() { return nullptr; }
	INode CDocument::previousSibling() { return nullptr; }
	INode CDocument::nextSibling() { return nullptr; }

	std::wstring CDocument::nodeValue() { return {}; }
	void CDocument::nodeValue(std::wstring val) {}

	std::wstring CDocument::textContent() { return {}; }
	void CDocument::textContent(std::wstring text) {}

	void CDocument::Normalize() {}

	INode CDocument::CloneNode() { return nullptr; }
	INode CDocument::CloneNode(bool deep) { return nullptr; }

	bool CDocument::isEqualNode(INode otherINode) { return false; }
	bool CDocument::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CDocument::CompareDocumentPosition(INode other) { return 0; }

	bool CDocument::Contains(INode other) { return false; }

	std::wstring CDocument::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CDocument::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CDocument::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CDocument::InsertBefore(INode node, INode child) { return nullptr; }
	INode CDocument::AppendChild(INode node) { return nullptr; }
	INode CDocument::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CDocument::RemoveChild(INode child) { return nullptr; }

	void CDocument::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CDocument::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CDocument::DispatchEvent(IEvent dispathchedEvent) { return false; }


	IDocumentType CDocument::CDocumentDOMImplementation::CreateDocumentType(std::wstring qualifiedName, std::wstring publicId, std::wstring systemId)
	{

		return nullptr;

	}

	IXMLDocument CDocument::CDocumentDOMImplementation::CreateDocument(std::wstring nspace, std::wstring qualifiedName, IDocumentType doctype)
	{

		return nullptr;

	}

	IDocument CDocument::CDocumentDOMImplementation::CreateHTMLDocument(std::wstring title)
	{

		return nullptr;

	}

	bool CDocument::CDocumentDOMImplementation::HasFeature() { return true; } // useless; always returns true


}