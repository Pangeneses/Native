module;

#include <string>

module CHV4DXML:CAttr;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CAttr::nspaceURI() { return nullptr; }

	std::wstring CAttr::prefix() { return nullptr; }

	std::wstring CAttr::localName() { return nullptr; }

	std::wstring CAttr::name() { return nullptr; }

	std::wstring CAttr::value() { return nullptr; }
	void CAttr::value(std::wstring val) {}

	IElement CAttr::ownerElement() { return nullptr; }
	void CAttr::ownerElement(IElement owner) {}

	bool CAttr::specified() { return false; } // useless; always returns true

	XML_DOM_NODE_TYPE CAttr::nodeType() { return XML_DOM_ATTRIBUTE_NODE; }

	std::wstring CAttr::nodeName() { return nullptr; }

	std::wstring CAttr::baseURI() { return nullptr; }

	bool CAttr::isConnected() { return false; }

	IDocument CAttr::ownerDocument() { return nullptr; }

	INode CAttr::GetRootNode() { return nullptr; }
	INode CAttr::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CAttr::parentNode() { return nullptr; }

	IElement CAttr::parentElement() { return nullptr; }

	bool CAttr::HasChildNodes() { return false; }

	INodeList CAttr::childNodes() { return nullptr; }

	INode CAttr::firstChild() { return nullptr; }
	INode CAttr::lastChild() { return nullptr; }
	INode CAttr::previousSibling() { return nullptr; }
	INode CAttr::nextSibling() { return nullptr; }

	std::wstring CAttr::nodeValue() { return nullptr; }
	void CAttr::nodeValue(std::wstring val) {}

	std::wstring CAttr::textContent() { return nullptr; }
	void CAttr::textContent(std::wstring text) {}

	void CAttr::Normalize() {}

	INode CAttr::CloneNode() { return nullptr; }
	INode CAttr::CloneNode(bool deep) { return nullptr; }

	bool CAttr::isEqualNode(INode otherINode) { return false; }
	bool CAttr::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CAttr::CompareDocumentPosition(INode other) { return 0; }

	bool CAttr::Contains(INode other) { return false; }

	std::wstring CAttr::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CAttr::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CAttr::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CAttr::InsertBefore(INode node, INode child) { return nullptr; }
	INode CAttr::AppendChild(INode node) { return nullptr; }
	INode CAttr::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CAttr::RemoveChild(INode child) { return nullptr; }

	void CAttr::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CAttr::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CAttr::DispatchEvent(IEvent dispathchedEvent) { return false; }

}