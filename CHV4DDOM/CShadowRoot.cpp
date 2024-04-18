module;

#include <string>

module CHV4DXML:CShadowRoot;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	XML_DOM_SHADOW_ROOT_MODE CShadowRoot::mode() { return XML_DOM_SHADOW_ROOT_OPEN; }

	bool CShadowRoot::delegatesFocus() { return false; }

	XML_DOM_SLOT_ASSIGNMENT_MODE CShadowRoot::slotAssignment() { return XML_DOM_SLOT_ASSIGNMENT_NAMED; }

	IElement CShadowRoot::host() { return nullptr; }

	EventHandler CShadowRoot::onSlotChanged() { return nullptr; }

	XML_DOM_NODE_TYPE CShadowRoot::nodeType() { return XML_DOM_DOCUMENT_NODE; }

	std::wstring CShadowRoot::nodeName() { return nullptr; }

	std::wstring CShadowRoot::baseURI() { return nullptr; }

	bool CShadowRoot::isConnected() { return false; }

	IDocument CShadowRoot::ownerDocument() { return nullptr; }

	INode CShadowRoot::GetRootNode() { return nullptr; }
	INode CShadowRoot::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CShadowRoot::parentNode() { return nullptr; }

	IElement CShadowRoot::parentElement() { return nullptr; }

	bool CShadowRoot::HasChildNodes() { return false; }

	INodeList CShadowRoot::childNodes() { return nullptr; }

	INode CShadowRoot::firstChild() { return nullptr; }
	INode CShadowRoot::lastChild() { return nullptr; }
	INode CShadowRoot::previousSibling() { return nullptr; }
	INode CShadowRoot::nextSibling() { return nullptr; }

	std::wstring CShadowRoot::nodeValue() { return nullptr; }
	void CShadowRoot::nodeValue(std::wstring val) {}

	std::wstring CShadowRoot::textContent() { return nullptr; }
	void CShadowRoot::textContent(std::wstring text) {}

	void CShadowRoot::Normalize() {}

	INode CShadowRoot::CloneNode() { return nullptr; }
	INode CShadowRoot::CloneNode(bool deep) { return nullptr; }

	bool CShadowRoot::isEqualNode(INode otherINode) { return false; }
	bool CShadowRoot::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CShadowRoot::CompareDocumentPosition(INode other) { return 0; }

	bool CShadowRoot::Contains(INode other) { return false; }

	std::wstring CShadowRoot::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CShadowRoot::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CShadowRoot::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CShadowRoot::InsertBefore(INode node, INode child) { return nullptr; }
	INode CShadowRoot::AppendChild(INode node) { return nullptr; }
	INode CShadowRoot::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CShadowRoot::RemoveChild(INode child) { return nullptr; }

	void CShadowRoot::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CShadowRoot::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CShadowRoot::DispatchEvent(IEvent dispathchedEvent) { return false; }

}