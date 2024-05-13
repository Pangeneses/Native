module;

#include <string>
#include <vector>

module CHV4DXML:CHTMLElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CHTMLElement::title() { return {}; }

	std::wstring CHTMLElement::lang() { return {}; }

	bool CHTMLElement::translate() { return false; }

	std::wstring CHTMLElement::dir() { return {}; }

	// user interaction
	void* CHTMLElement::hidden() { return nullptr; }

	bool CHTMLElement::inert() { return false; }

	void CHTMLElement::Click() {}

	std::wstring CHTMLElement::accessKey() { return {}; }

	std::wstring CHTMLElement::accessKeyLabel() { return {}; }

	bool CHTMLElement::draggable() { return false; }

	bool CHTMLElement::spellcheck() { return false; }

	std::wstring CHTMLElement::autocapitalize() { return {}; }

	std::wstring CHTMLElement::innerText() { return {}; }
	std::wstring CHTMLElement::outerText() { return {}; }

	IElementInternals CHTMLElement::attachInternals() { return nullptr; }

	// The popover API
	void CHTMLElement::ShowPopover() {}

	void CHTMLElement::HidePopover() {}

	bool CHTMLElement::TogglePopover() { return false; }
	void CHTMLElement::TogglePopover(bool force) {}

	std::wstring CHTMLElement::popover() { return {}; }

	std::wstring CHTMLElement::nspaceURI() { return {}; }
	std::wstring CHTMLElement::prefix() { return {}; }
	std::wstring CHTMLElement::localName() { return {}; }
	std::wstring CHTMLElement::tagName() { return {}; }

	std::wstring CHTMLElement::eid() { return {}; }

	std::wstring CHTMLElement::className() { return {}; }
	void CHTMLElement::className(std::wstring name) {}

	IDOMTokenList CHTMLElement::classList() { return nullptr; }

	std::wstring CHTMLElement::slot() { return {}; }
	void CHTMLElement::slot(std::wstring in) {}

	bool CHTMLElement::HasAttributes() { return false; }

	INamedNodeMap CHTMLElement::attributes() { return nullptr; }

	std::vector<std::wstring> CHTMLElement::GetAttributeNames() { return std::vector<std::wstring>{}; }

	std::wstring CHTMLElement::GetAttribute(std::wstring qualifiedName) { return {}; }
	std::wstring CHTMLElement::GetAttributeNS(std::wstring nspace, std::wstring localName) { return {}; }

	void CHTMLElement::SetAttribute(std::wstring qualifiedName, std::wstring value) {}
	void CHTMLElement::SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value) {}
	void CHTMLElement::RemoveAttribute(std::wstring qualifiedName) {}
	void CHTMLElement::RemoveAttributeNS(std::wstring nspace, std::wstring localName) {}

	bool CHTMLElement::ToggleAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLElement::ToggleAttribute(std::wstring qualifiedName, bool force) { return false; }

	bool CHTMLElement::HasAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLElement::HasAttributeNS(std::wstring nspace, std::wstring localName) { return false; }

	IAttr CHTMLElement::GetAttributeNode(std::wstring qualifiedName) { return nullptr; }
	IAttr CHTMLElement::GetAttributeNodeNS(std::wstring nspace, std::wstring localName) { return nullptr; }

	IAttr CHTMLElement::SetAttributeNode(IAttr attr) { return nullptr; }
	IAttr CHTMLElement::SetAttributeNodeNS(IAttr attr) { return nullptr; }
	IAttr CHTMLElement::RemoveAttributeNode(IAttr attr) { return nullptr; }

	IShadowRoot CHTMLElement::AttachShadow(ShadowRootInit init) { return nullptr; }

	IShadowRoot CHTMLElement::shadowRoot() { return nullptr; }

	IElement CHTMLElement::Closest(std::wstring selectors) { return nullptr; }

	bool CHTMLElement::Matches(std::wstring selectors) { return false; }
	bool CHTMLElement::WebkitMatchesSelector(std::wstring selectors) { return false; } // legacy alias of .matches

	IHTMLCollection CHTMLElement::GetElementsByTagName(std::wstring qualifiedName) { return nullptr; }
	IHTMLCollection CHTMLElement::GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) { return nullptr; }
	IHTMLCollection CHTMLElement::GetElementsByClassName(std::wstring classNames) { return nullptr; }

	IElement CHTMLElement::InsertAdjacentElement(std::wstring where, IElement element) { return nullptr; } // legacy
	void CHTMLElement::InsertAdjacentText(std::wstring where, std::wstring data) {} // legacy

	XML_DOM_NODE_TYPE CHTMLElement::nodeType() { return XML_DOM_ELEMENT_NODE; }

	std::wstring CHTMLElement::nodeName() { return {}; }

	std::wstring CHTMLElement::baseURI() { return {}; }

	bool CHTMLElement::isConnected() { return false; }

	IDocument CHTMLElement::ownerDocument() { return nullptr; }

	INode CHTMLElement::GetRootNode() { return nullptr; }
	INode CHTMLElement::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CHTMLElement::parentNode() { return nullptr; }

	IElement CHTMLElement::parentElement() { return nullptr; }

	bool CHTMLElement::HasChildNodes() { return false; }

	INodeList CHTMLElement::childNodes() { return nullptr; }

	INode CHTMLElement::firstChild() { return nullptr; }
	INode CHTMLElement::lastChild() { return nullptr; }
	INode CHTMLElement::previousSibling() { return nullptr; }
	INode CHTMLElement::nextSibling() { return nullptr; }

	std::wstring CHTMLElement::nodeValue() { return {}; }
	void CHTMLElement::nodeValue(std::wstring val) {}

	std::wstring CHTMLElement::textContent() { return {}; }
	void CHTMLElement::textContent(std::wstring text) {}

	void CHTMLElement::Normalize() {}

	INode CHTMLElement::CloneNode() { return nullptr; }
	INode CHTMLElement::CloneNode(bool deep) { return nullptr; }

	bool CHTMLElement::isEqualNode(INode otherINode) { return false; }
	bool CHTMLElement::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CHTMLElement::CompareDocumentPosition(INode other) { return 0; }

	bool CHTMLElement::Contains(INode other) { return false; }

	std::wstring CHTMLElement::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CHTMLElement::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CHTMLElement::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CHTMLElement::InsertBefore(INode node, INode child) { return nullptr; }
	INode CHTMLElement::AppendChild(INode node) { return nullptr; }
	INode CHTMLElement::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CHTMLElement::RemoveChild(INode child) { return nullptr; }

	void CHTMLElement::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CHTMLElement::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CHTMLElement::DispatchEvent(IEvent dispathchedEvent) { return false; }

}