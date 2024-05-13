module;

#include <string>

module CHV4DXML:CDocumentFragment;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	XML_DOM_NODE_TYPE CDocumentFragment::nodeType() { return XML_DOM_DOCUMENT_FRAGMENT_NODE; }

	std::wstring CDocumentFragment::nodeName() { return {}; }

	std::wstring CDocumentFragment::baseURI() { return {}; }

	bool CDocumentFragment::isConnected() { return false; }

	IDocument CDocumentFragment::ownerDocument() { return nullptr; }

	INode CDocumentFragment::GetRootNode() { return nullptr; }
	INode CDocumentFragment::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CDocumentFragment::parentNode() { return nullptr; }

	IElement CDocumentFragment::parentElement() { return nullptr; }

	bool CDocumentFragment::HasChildNodes() { return false; }

	INodeList CDocumentFragment::childNodes() { return nullptr; }

	INode CDocumentFragment::firstChild() { return nullptr; }
	INode CDocumentFragment::lastChild() { return nullptr; }
	INode CDocumentFragment::previousSibling() { return nullptr; }
	INode CDocumentFragment::nextSibling() { return nullptr; }

	std::wstring CDocumentFragment::nodeValue() { return {}; }
	void CDocumentFragment::nodeValue(std::wstring val) {}

	std::wstring CDocumentFragment::textContent() { return {}; }
	void CDocumentFragment::textContent(std::wstring text) {}

	void CDocumentFragment::Normalize() {}

	INode CDocumentFragment::CloneNode() { return nullptr; }
	INode CDocumentFragment::CloneNode(bool deep) { return nullptr; }

	bool CDocumentFragment::isEqualNode(INode otherINode) { return false; }
	bool CDocumentFragment::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CDocumentFragment::CompareDocumentPosition(INode other) { return 0; }

	bool CDocumentFragment::Contains(INode other) { return false; }

	std::wstring CDocumentFragment::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CDocumentFragment::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CDocumentFragment::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CDocumentFragment::InsertBefore(INode node, INode child) { return nullptr; }
	INode CDocumentFragment::AppendChild(INode node) { return nullptr; }
	INode CDocumentFragment::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CDocumentFragment::RemoveChild(INode child) { return nullptr; }

	void CDocumentFragment::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CDocumentFragment::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CDocumentFragment::DispatchEvent(IEvent dispathchedEvent) { return false; }

}