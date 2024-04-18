module;

#include <string>

module CHV4DXML:CComment;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CComment::data() { return nullptr; }
	void CComment::data(std::wstring e) {}

	uint32_t CComment::length() { return 0; }
	void CComment::length(uint32_t len) {}

	std::wstring CComment::SubstringData(uint32_t offset, uint32_t count) { return nullptr; }

	void CComment::AppendData(std::wstring data) {}
	void CComment::InsertData(uint32_t offset, std::wstring data) {}
	void CComment::DeleteData(uint32_t offset, uint32_t count) {}
	void CComment::ReplaceData(uint32_t offset, uint32_t count, std::wstring data) {}

	XML_DOM_NODE_TYPE CComment::nodeType() { return XML_DOM_COMMENT_NODE; }

	std::wstring CComment::nodeName() { return nullptr; }

	std::wstring CComment::baseURI() { return nullptr; }

	bool CComment::isConnected() { return false; }

	IDocument CComment::ownerDocument() { return nullptr; }

	INode CComment::GetRootNode() { return nullptr; }
	INode CComment::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CComment::parentNode() { return nullptr; }

	IElement CComment::parentElement() { return nullptr; }

	bool CComment::HasChildNodes() { return false; }

	INodeList CComment::childNodes() { return nullptr; }

	INode CComment::firstChild() { return nullptr; }
	INode CComment::lastChild() { return nullptr; }
	INode CComment::previousSibling() { return nullptr; }
	INode CComment::nextSibling() { return nullptr; }

	std::wstring CComment::nodeValue() { return nullptr; }
	void CComment::nodeValue(std::wstring val) {}

	std::wstring CComment::textContent() { return nullptr; }
	void CComment::textContent(std::wstring text) {}

	void CComment::Normalize() {}

	INode CComment::CloneNode() { return nullptr; }
	INode CComment::CloneNode(bool deep) { return nullptr; }

	bool CComment::isEqualNode(INode otherINode) { return false; }
	bool CComment::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CComment::CompareDocumentPosition(INode other) { return 0; }

	bool CComment::Contains(INode other) { return false; }

	std::wstring CComment::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CComment::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CComment::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CComment::InsertBefore(INode node, INode child) { return nullptr; }
	INode CComment::AppendChild(INode node) { return nullptr; }
	INode CComment::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CComment::RemoveChild(INode child) { return nullptr; }

	void CComment::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CComment::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CComment::DispatchEvent(IEvent dispathchedEvent) { return false; }

}