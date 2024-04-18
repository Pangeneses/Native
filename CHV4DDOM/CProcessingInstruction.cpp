module;

#include <string>

module CHV4DXML:CProcessingInstruction;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CProcessingInstruction::target() { return nullptr; }

	std::wstring CProcessingInstruction::data() { return nullptr; }
	void CProcessingInstruction::data(std::wstring e) {}

	uint32_t CProcessingInstruction::length() { return 0; }
	void CProcessingInstruction::length(uint32_t len) {}

	std::wstring CProcessingInstruction::SubstringData(uint32_t offset, uint32_t count) { return nullptr; }

	void CProcessingInstruction::AppendData(std::wstring data) {}
	void CProcessingInstruction::InsertData(uint32_t offset, std::wstring data) {}
	void CProcessingInstruction::DeleteData(uint32_t offset, uint32_t count) {}
	void CProcessingInstruction::ReplaceData(uint32_t offset, uint32_t count, std::wstring data) {}

	XML_DOM_NODE_TYPE CProcessingInstruction::nodeType() { return XML_DOM_PROCESSING_INSTRUCTION_NODE; }

	std::wstring CProcessingInstruction::nodeName() { return nullptr; }

	std::wstring CProcessingInstruction::baseURI() { return nullptr; }

	bool CProcessingInstruction::isConnected() { return false; }

	IDocument CProcessingInstruction::ownerDocument() { return nullptr; }

	INode CProcessingInstruction::GetRootNode() { return nullptr; }
	INode CProcessingInstruction::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CProcessingInstruction::parentNode() { return nullptr; }

	IElement CProcessingInstruction::parentElement() { return nullptr; }

	bool CProcessingInstruction::HasChildNodes() { return false; }

	INodeList CProcessingInstruction::childNodes() { return nullptr; }

	INode CProcessingInstruction::firstChild() { return nullptr; }
	INode CProcessingInstruction::lastChild() { return nullptr; }
	INode CProcessingInstruction::previousSibling() { return nullptr; }
	INode CProcessingInstruction::nextSibling() { return nullptr; }

	std::wstring CProcessingInstruction::nodeValue() { return nullptr; }
	void CProcessingInstruction::nodeValue(std::wstring val) {}

	std::wstring CProcessingInstruction::textContent() { return nullptr; }
	void CProcessingInstruction::textContent(std::wstring text) {}

	void CProcessingInstruction::Normalize() {}

	INode CProcessingInstruction::CloneNode() { return nullptr; }
	INode CProcessingInstruction::CloneNode(bool deep) { return nullptr; }

	bool CProcessingInstruction::isEqualNode(INode otherINode) { return false; }
	bool CProcessingInstruction::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CProcessingInstruction::CompareDocumentPosition(INode other) { return 0; }

	bool CProcessingInstruction::Contains(INode other) { return false; }

	std::wstring CProcessingInstruction::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CProcessingInstruction::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CProcessingInstruction::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CProcessingInstruction::InsertBefore(INode node, INode child) { return nullptr; }
	INode CProcessingInstruction::AppendChild(INode node) { return nullptr; }
	INode CProcessingInstruction::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CProcessingInstruction::RemoveChild(INode child) { return nullptr; }

	void CProcessingInstruction::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CProcessingInstruction::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CProcessingInstruction::DispatchEvent(IEvent dispathchedEvent) { return false; }

}