module;

#include <string>
#include <vector>

module CHV4DXML:CHTMLSlotElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring name() { return {}; }
	void name(std::wstring e) {}

	std::vector<INode> assignedNodes() { return std::vector<INode>{}; }
	std::vector<INode> assignedNodes(AssignedNodesOptions options) { return std::vector<INode>{}; }

	std::vector<IElement> assignedElements() { return std::vector<IElement>{}; }
	std::vector<IElement> assignedElements(AssignedNodesOptions options) { return std::vector<IElement>{}; }

	void Assign(std::vector<INode> nodes) {}

	std::wstring CHTMLSlotElement::nspaceURI() { return {}; }
	std::wstring CHTMLSlotElement::prefix() { return {}; }
	std::wstring CHTMLSlotElement::localName() { return {}; }
	std::wstring CHTMLSlotElement::tagName() { return {}; }

	std::wstring CHTMLSlotElement::eid() { return {}; }

	std::wstring CHTMLSlotElement::className() { return {}; }
	void CHTMLSlotElement::className(std::wstring name) {}

	IDOMTokenList CHTMLSlotElement::classList() { return nullptr; }

	std::wstring CHTMLSlotElement::slot() { return {}; }
	void CHTMLSlotElement::slot(std::wstring in) {}

	bool CHTMLSlotElement::HasAttributes() { return false; }

	INamedNodeMap CHTMLSlotElement::attributes() { return nullptr; }

	std::vector<std::wstring> CHTMLSlotElement::GetAttributeNames() { return std::vector<std::wstring>{}; }

	std::wstring CHTMLSlotElement::GetAttribute(std::wstring qualifiedName) { return {}; }
	std::wstring CHTMLSlotElement::GetAttributeNS(std::wstring nspace, std::wstring localName) { return {}; }

	void CHTMLSlotElement::SetAttribute(std::wstring qualifiedName, std::wstring value) {}
	void CHTMLSlotElement::SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value) {}
	void CHTMLSlotElement::RemoveAttribute(std::wstring qualifiedName) {}
	void CHTMLSlotElement::RemoveAttributeNS(std::wstring nspace, std::wstring localName) {}

	bool CHTMLSlotElement::ToggleAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLSlotElement::ToggleAttribute(std::wstring qualifiedName, bool force) { return false; }

	bool CHTMLSlotElement::HasAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLSlotElement::HasAttributeNS(std::wstring nspace, std::wstring localName) { return false; }

	IAttr CHTMLSlotElement::GetAttributeNode(std::wstring qualifiedName) { return nullptr; }
	IAttr CHTMLSlotElement::GetAttributeNodeNS(std::wstring nspace, std::wstring localName) { return nullptr; }

	IAttr CHTMLSlotElement::SetAttributeNode(IAttr attr) { return nullptr; }
	IAttr CHTMLSlotElement::SetAttributeNodeNS(IAttr attr) { return nullptr; }
	IAttr CHTMLSlotElement::RemoveAttributeNode(IAttr attr) { return nullptr; }

	IShadowRoot CHTMLSlotElement::AttachShadow(ShadowRootInit init) { return nullptr; }

	IShadowRoot CHTMLSlotElement::shadowRoot() { return nullptr; }

	IElement CHTMLSlotElement::Closest(std::wstring selectors) { return nullptr; }

	bool CHTMLSlotElement::Matches(std::wstring selectors) { return false; }
	bool CHTMLSlotElement::WebkitMatchesSelector(std::wstring selectors) { return false; } // legacy alias of .matches

	IHTMLCollection CHTMLSlotElement::GetElementsByTagName(std::wstring qualifiedName) { return nullptr; }
	IHTMLCollection CHTMLSlotElement::GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) { return nullptr; }
	IHTMLCollection CHTMLSlotElement::GetElementsByClassName(std::wstring classNames) { return nullptr; }

	IElement CHTMLSlotElement::InsertAdjacentElement(std::wstring where, IElement element) { return nullptr; } // legacy
	void CHTMLSlotElement::InsertAdjacentText(std::wstring where, std::wstring data) {} // legacy

	XML_DOM_NODE_TYPE CHTMLSlotElement::nodeType() { return XML_DOM_ELEMENT_NODE; }

	std::wstring CHTMLSlotElement::nodeName() { return {}; }

	std::wstring CHTMLSlotElement::baseURI() { return {}; }

	bool CHTMLSlotElement::isConnected() { return false; }

	IDocument CHTMLSlotElement::ownerDocument() { return nullptr; }

	INode CHTMLSlotElement::GetRootNode() { return nullptr; }
	INode CHTMLSlotElement::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CHTMLSlotElement::parentNode() { return nullptr; }

	IElement CHTMLSlotElement::parentElement() { return nullptr; }

	bool CHTMLSlotElement::HasChildNodes() { return false; }

	INodeList CHTMLSlotElement::childNodes() { return nullptr; }

	INode CHTMLSlotElement::firstChild() { return nullptr; }
	INode CHTMLSlotElement::lastChild() { return nullptr; }
	INode CHTMLSlotElement::previousSibling() { return nullptr; }
	INode CHTMLSlotElement::nextSibling() { return nullptr; }

	std::wstring CHTMLSlotElement::nodeValue() { return {}; }
	void CHTMLSlotElement::nodeValue(std::wstring val) {}

	std::wstring CHTMLSlotElement::textContent() { return {}; }
	void CHTMLSlotElement::textContent(std::wstring text) {}

	void CHTMLSlotElement::Normalize() {}

	INode CHTMLSlotElement::CloneNode() { return nullptr; }
	INode CHTMLSlotElement::CloneNode(bool deep) { return nullptr; }

	bool CHTMLSlotElement::isEqualNode(INode otherINode) { return false; }
	bool CHTMLSlotElement::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CHTMLSlotElement::CompareDocumentPosition(INode other) { return 0; }

	bool CHTMLSlotElement::Contains(INode other) { return false; }

	std::wstring CHTMLSlotElement::LookupPrefix(std::wstring nspace) { return {}; }

	std::wstring CHTMLSlotElement::LookupNamespaceURI(std::wstring prefix) { return {}; }

	bool CHTMLSlotElement::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CHTMLSlotElement::InsertBefore(INode node, INode child) { return nullptr; }
	INode CHTMLSlotElement::AppendChild(INode node) { return nullptr; }
	INode CHTMLSlotElement::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CHTMLSlotElement::RemoveChild(INode child) { return nullptr; }

	void CHTMLSlotElement::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CHTMLSlotElement::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CHTMLSlotElement::DispatchEvent(IEvent dispathchedEvent) { return false; }

}