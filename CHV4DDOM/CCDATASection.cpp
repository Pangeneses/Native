module;

#include <string>

module CHV4DXML:CCDATASection;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IText CCDATASection::splitText(uint32_t offset) { return nullptr; }

	std::wstring CCDATASection::wholeText() { return {}; }

	std::wstring CCDATASection::data() { return {}; }
	void CCDATASection::data(std::wstring e) {}

	uint32_t CCDATASection::length() { return 0; }
	void CCDATASection::length(uint32_t len) {}

	std::wstring CCDATASection::SubstringData(uint32_t offset, uint32_t count) { return {}; }

	void CCDATASection::AppendData(std::wstring data) {}
	void CCDATASection::InsertData(uint32_t offset, std::wstring data) {}
	void CCDATASection::DeleteData(uint32_t offset, uint32_t count) {}
	void CCDATASection::ReplaceData(uint32_t offset, uint32_t count, std::wstring data) {}

	XML_DOM_NODE_TYPE CCDATASection::nodeType() { return XML_DOM_CDATA_SECTION_NODE; }

	std::wstring CCDATASection::nodeName() { return {}; }

	std::wstring CCDATASection::baseURI() { return {}; }

	bool CCDATASection::isConnected() { return false; }

	IDocument CCDATASection::ownerDocument() { return nullptr; }

	INode CCDATASection::GetRootNode() { return nullptr; }
	INode CCDATASection::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CCDATASection::parentNode() { return nullptr; }

	IElement CCDATASection::parentElement() { return nullptr; }

	bool CCDATASection::HasChildNodes() { return false; }

	INodeList CCDATASection::childNodes() { return nullptr; }

	INode CCDATASection::firstChild() { return nullptr; }
	INode CCDATASection::lastChild() { return nullptr; }
	INode CCDATASection::previousSibling() { return nullptr; }
	INode CCDATASection::nextSibling() { return nullptr; }

	std::wstring CCDATASection::nodeValue() { return {}; }
	void CCDATASection::nodeValue(std::wstring val) {}

	std::wstring CCDATASection::textContent() { return {}; }
	void CCDATASection::textContent(std::wstring text) {}

	void CCDATASection::Normalize() {}

	INode CCDATASection::CloneNode() { return nullptr; }
	INode CCDATASection::CloneNode(bool deep) { return nullptr; }

	bool CCDATASection::isEqualNode(INode otherINode) { return false; }
	bool CCDATASection::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CCDATASection::CompareDocumentPosition(INode other) { return 0; }

	bool CCDATASection::Contains(INode other) { return false; }

	std::wstring CCDATASection::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CCDATASection::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CCDATASection::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CCDATASection::InsertBefore(INode node, INode child) { return nullptr; }
	INode CCDATASection::AppendChild(INode node) { return nullptr; }
	INode CCDATASection::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CCDATASection::RemoveChild(INode child) { return nullptr; }

	void CCDATASection::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CCDATASection::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CCDATASection::DispatchEvent(IEvent dispathchedEvent) { return false; }

}