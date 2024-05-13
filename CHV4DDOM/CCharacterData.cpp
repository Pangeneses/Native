module;

#include <string>

module CHV4DXML:CCharacterData;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CCharacterData::data() { return {}; }
	void CCharacterData::data(std::wstring e) {}

	uint32_t CCharacterData::length() { return 0; }
	void CCharacterData::length(uint32_t len) {}

	std::wstring CCharacterData::SubstringData(uint32_t offset, uint32_t count) { return {}; }

	void CCharacterData::AppendData(std::wstring data) {}
	void CCharacterData::InsertData(uint32_t offset, std::wstring data) {}
	void CCharacterData::DeleteData(uint32_t offset, uint32_t count) {}
	void CCharacterData::ReplaceData(uint32_t offset, uint32_t count, std::wstring data) {}

	XML_DOM_NODE_TYPE CCharacterData::nodeType() { return XML_DOM_TEXT_NODE; }

	std::wstring CCharacterData::nodeName() { return {}; }

	std::wstring CCharacterData::baseURI() { return {}; }

	bool CCharacterData::isConnected() { return false; }

	IDocument CCharacterData::ownerDocument() { return nullptr; }

	INode CCharacterData::GetRootNode() { return nullptr; }
	INode CCharacterData::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CCharacterData::parentNode() { return nullptr; }

	IElement CCharacterData::parentElement() { return nullptr; }

	bool CCharacterData::HasChildNodes() { return false; }

	INodeList CCharacterData::childNodes() { return nullptr; }

	INode CCharacterData::firstChild() { return nullptr; }
	INode CCharacterData::lastChild() { return nullptr; }
	INode CCharacterData::previousSibling() { return nullptr; }
	INode CCharacterData::nextSibling() { return nullptr; }

	std::wstring CCharacterData::nodeValue() { return {}; }
	void CCharacterData::nodeValue(std::wstring val) {}

	std::wstring CCharacterData::textContent() { return {}; }
	void CCharacterData::textContent(std::wstring text) {}

	void CCharacterData::Normalize() {}

	INode CCharacterData::CloneNode() { return nullptr; }
	INode CCharacterData::CloneNode(bool deep) { return nullptr; }

	bool CCharacterData::isEqualNode(INode otherINode) { return false; }
	bool CCharacterData::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CCharacterData::CompareDocumentPosition(INode other) { return 0; }

	bool CCharacterData::Contains(INode other) { return false; }

	std::wstring CCharacterData::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CCharacterData::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CCharacterData::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CCharacterData::InsertBefore(INode node, INode child) { return nullptr; }
	INode CCharacterData::AppendChild(INode node) { return nullptr; }
	INode CCharacterData::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CCharacterData::RemoveChild(INode child) { return nullptr; }

	void CCharacterData::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CCharacterData::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CCharacterData::DispatchEvent(IEvent dispathchedEvent) { return false; }

}