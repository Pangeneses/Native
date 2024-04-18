module;

#include <string>

module CHV4DXML:CText;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	CText::CText(std::wstring data) {}

	IText CText::splitText(uint32_t offset) { return nullptr; }

	std::wstring CText::wholeText() { return nullptr; }

	std::wstring CText::data() { return nullptr; }
	void CText::data(std::wstring e) {}

	uint32_t CText::length() { return 0; }
	void CText::length(uint32_t len) {}

	std::wstring CText::SubstringData(uint32_t offset, uint32_t count) { return nullptr; }

	void CText::AppendData(std::wstring data) {}
	void CText::InsertData(uint32_t offset, std::wstring data) {}
	void CText::DeleteData(uint32_t offset, uint32_t count) {}
	void CText::ReplaceData(uint32_t offset, uint32_t count, std::wstring data) {}

	XML_DOM_NODE_TYPE CText::nodeType() { return XML_DOM_TEXT_NODE; }

	std::wstring CText::nodeName() { return nullptr; }

	std::wstring CText::baseURI() { return nullptr; }

	bool CText::isConnected() { return false; }

	IDocument CText::ownerDocument() { return nullptr; }

	INode CText::GetRootNode() { return nullptr; }
	INode CText::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CText::parentNode() { return nullptr; }

	IElement CText::parentElement() { return nullptr; }

	bool CText::HasChildNodes() { return false; }

	INodeList CText::childNodes() { return nullptr; }

	INode CText::firstChild() { return nullptr; }
	INode CText::lastChild() { return nullptr; }
	INode CText::previousSibling() { return nullptr; }
	INode CText::nextSibling() { return nullptr; }

	std::wstring CText::nodeValue() { return nullptr; }
	void CText::nodeValue(std::wstring val) {}

	std::wstring CText::textContent() { return nullptr; }
	void CText::textContent(std::wstring text) {}

	void CText::Normalize() {}

	INode CText::CloneNode() { return nullptr; }
	INode CText::CloneNode(bool deep) { return nullptr; }

	bool CText::isEqualNode(INode otherINode) { return false; }
	bool CText::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CText::CompareDocumentPosition(INode other) { return 0; }

	bool CText::Contains(INode other) { return false; }

	std::wstring CText::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CText::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CText::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CText::InsertBefore(INode node, INode child) { return nullptr; }
	INode CText::AppendChild(INode node) { return nullptr; }
	INode CText::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CText::RemoveChild(INode child) { return nullptr; }

	void CText::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CText::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CText::DispatchEvent(IEvent dispathchedEvent) { return false; }

}