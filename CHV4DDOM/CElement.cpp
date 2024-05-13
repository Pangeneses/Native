module;

#include <string>
#include <vector>

module CHV4DXML:CElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CElement::nspaceURI() { return {}; }
	std::wstring CElement::prefix() { return {}; }
	std::wstring CElement::localName() { return {}; }
	std::wstring CElement::tagName() { return {}; }

	std::wstring CElement::eid() { return {}; }

	std::wstring CElement::className() { return {}; }
	void CElement::className(std::wstring name) {}

	IDOMTokenList CElement::classList() { return {}; }

	std::wstring CElement::slot() { return {}; }
	void CElement::slot(std::wstring in) {}

	bool CElement::HasAttributes() { return false; }

	INamedNodeMap CElement::attributes() { return nullptr; }

	std::vector<std::wstring> CElement::GetAttributeNames() { return std::vector<std::wstring>{}; }

	std::wstring CElement::GetAttribute(std::wstring qualifiedName) { return {}; }
	std::wstring CElement::GetAttributeNS(std::wstring nspace, std::wstring localName) { return {}; }

	void CElement::SetAttribute(std::wstring qualifiedName, std::wstring value) {}
	void CElement::SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value) {}
	void CElement::RemoveAttribute(std::wstring qualifiedName) {}
	void CElement::RemoveAttributeNS(std::wstring nspace, std::wstring localName) {}

	bool CElement::ToggleAttribute(std::wstring qualifiedName) { return false; }
	bool CElement::ToggleAttribute(std::wstring qualifiedName, bool force) { return false; }

	bool CElement::HasAttribute(std::wstring qualifiedName) { return false; }
	bool CElement::HasAttributeNS(std::wstring nspace, std::wstring localName) { return false; }

	IAttr CElement::GetAttributeNode(std::wstring qualifiedName) { return nullptr; }
	IAttr CElement::GetAttributeNodeNS(std::wstring nspace, std::wstring localName) { return nullptr; }

	IAttr CElement::SetAttributeNode(IAttr attr) { return nullptr; }
	IAttr CElement::SetAttributeNodeNS(IAttr attr) { return nullptr; }
	IAttr CElement::RemoveAttributeNode(IAttr attr) { return nullptr; }

	IShadowRoot CElement::AttachShadow(ShadowRootInit init) { return nullptr; }

	IShadowRoot CElement::shadowRoot() { return nullptr; }

	IElement CElement::Closest(std::wstring selectors) { return nullptr; }

	bool CElement::Matches(std::wstring selectors) { return false; }
	bool CElement::WebkitMatchesSelector(std::wstring selectors) { return false; } // legacy alias of .matches

	IHTMLCollection CElement::GetElementsByTagName(std::wstring qualifiedName) { return nullptr; }
	IHTMLCollection CElement::GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) { return nullptr; }
	IHTMLCollection CElement::GetElementsByClassName(std::wstring classNames) { return nullptr; }

	IElement CElement::InsertAdjacentElement(std::wstring where, IElement element) { return nullptr; } // legacy
	void CElement::InsertAdjacentText(std::wstring where, std::wstring data) {} // legacy

	XML_DOM_NODE_TYPE CElement::nodeType() { return XML_DOM_ELEMENT_NODE; }

	std::wstring CElement::nodeName() { return {}; }

	std::wstring CElement::baseURI() { return {}; }

	bool CElement::isConnected() { return false; }

	IDocument CElement::ownerDocument() { return nullptr; }

	INode CElement::GetRootNode() { return nullptr; }
	INode CElement::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CElement::parentNode() { return nullptr; }

	IElement CElement::parentElement() { return nullptr; }

	bool CElement::HasChildNodes() { return false; }

	INodeList CElement::childNodes() { return nullptr; }

	INode CElement::firstChild() { return nullptr; }
	INode CElement::lastChild() { return nullptr; }
	INode CElement::previousSibling() { return nullptr; }
	INode CElement::nextSibling() { return nullptr; }

	std::wstring CElement::nodeValue() { return {}; }
	void CElement::nodeValue(std::wstring val) {}

	std::wstring CElement::textContent() { return {}; }
	void CElement::textContent(std::wstring text) {}

	void CElement::Normalize() {}

	INode CElement::CloneNode() { return nullptr; }
	INode CElement::CloneNode(bool deep) { return nullptr; }

	bool CElement::isEqualNode(INode otherINode) { return false; }
	bool CElement::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CElement::CompareDocumentPosition(INode other) { return 0; }

	bool CElement::Contains(INode other) { return false; }

	std::wstring CElement::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CElement::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CElement::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CElement::InsertBefore(INode node, INode child) { return nullptr; }
	INode CElement::AppendChild(INode node) { return nullptr; }
	INode CElement::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CElement::RemoveChild(INode child) { return nullptr; }

	void CElement::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CElement::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CElement::DispatchEvent(IEvent dispathchedEvent) { return false; }

}