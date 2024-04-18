module;

#include <string>
#include <vector>

module CHV4DXML:CHTMLFormElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	std::wstring CHTMLFormElement::acceptcharset() { return nullptr; }
	void CHTMLFormElement::acceptcharset(std::wstring set) {}

	std::wstring CHTMLFormElement::action() { return nullptr; }
	void CHTMLFormElement::action(std::wstring doActtion) {}

	std::wstring CHTMLFormElement::autocomplete() { return nullptr; }
	void CHTMLFormElement::autocomplete(std::wstring fill) {}

	std::wstring CHTMLFormElement::enctype() { return nullptr; }
	void CHTMLFormElement::enctype(std::wstring enc) {}

	std::wstring CHTMLFormElement::encoding() { return nullptr; }
	void CHTMLFormElement::encoding(std::wstring coding) {}

	std::wstring CHTMLFormElement::method() { return nullptr; }
	void CHTMLFormElement::method(std::wstring way) {}

	std::wstring CHTMLFormElement::name() { return nullptr; }
	void CHTMLFormElement::name(std::wstring n) {}

	bool CHTMLFormElement::noValidate() { return false; }
	void CHTMLFormElement::noValidate(bool validity) {}

	std::wstring CHTMLFormElement::target() { return nullptr; }
	void CHTMLFormElement::target(std::wstring name) {}

	std::wstring CHTMLFormElement::rel() { return nullptr; }
	void CHTMLFormElement::rel(std::wstring name) {}

	INodeList CHTMLFormElement::relList() { return nullptr; }
	void CHTMLFormElement::relList(INodeList list) {}

	IHTMLFormControlsCollection CHTMLFormElement::elements() { return nullptr; }

	uint32_t CHTMLFormElement::length() { return 0; }

	IElement CHTMLFormElement::ByIndex(uint32_t index) { return nullptr; }

	IElement CHTMLFormElement::ByName(std::wstring name) { return nullptr; }

	void CHTMLFormElement::Submit() {}

	void CHTMLFormElement::RequestSubmit(IElement submitter) {}

	void CHTMLFormElement::Reset() {}

	bool CHTMLFormElement::CheckValidity() { return false; }

	bool CHTMLFormElement::ReportValidity() { return false; }

	std::wstring CHTMLFormElement::title() { return nullptr; }

	std::wstring CHTMLFormElement::lang() { return nullptr; }

	bool CHTMLFormElement::translate() { return false; }

	std::wstring CHTMLFormElement::dir() { return nullptr; }

	// user interaction
	void* CHTMLFormElement::hidden() { return nullptr; }

	bool CHTMLFormElement::inert() { return false; }

	void CHTMLFormElement::Click() {}

	std::wstring CHTMLFormElement::accessKey() { return nullptr; }

	std::wstring CHTMLFormElement::accessKeyLabel() { return nullptr; }

	bool CHTMLFormElement::draggable() { return false; }

	bool CHTMLFormElement::spellcheck() { return false; }

	std::wstring CHTMLFormElement::autocapitalize() { return nullptr; }

	std::wstring CHTMLFormElement::innerText() { return nullptr; }
	std::wstring CHTMLFormElement::outerText() { return nullptr; }

	IElementInternals CHTMLFormElement::attachInternals() { return nullptr; }

	// The popover API
	void CHTMLFormElement::ShowPopover() {}

	void CHTMLFormElement::HidePopover() {}

	bool CHTMLFormElement::TogglePopover() { return false; }
	void CHTMLFormElement::TogglePopover(bool force) {}

	std::wstring CHTMLFormElement::popover() { return nullptr; }

	std::wstring CHTMLFormElement::nspaceURI() { return nullptr; }
	std::wstring CHTMLFormElement::prefix() { return nullptr; }
	std::wstring CHTMLFormElement::localName() { return nullptr; }
	std::wstring CHTMLFormElement::tagName() { return nullptr; }

	std::wstring CHTMLFormElement::eid() { return nullptr; }

	std::wstring CHTMLFormElement::className() { return nullptr; }
	void CHTMLFormElement::className(std::wstring name) {}

	IDOMTokenList CHTMLFormElement::classList() { return nullptr; }

	std::wstring CHTMLFormElement::slot() { return nullptr; }
	void CHTMLFormElement::slot(std::wstring in) {}

	bool CHTMLFormElement::HasAttributes() { return false; }

	INamedNodeMap CHTMLFormElement::attributes() { return nullptr; }

	std::vector<std::wstring> CHTMLFormElement::GetAttributeNames() { return std::vector<std::wstring>{}; }

	std::wstring CHTMLFormElement::GetAttribute(std::wstring qualifiedName) { return nullptr; }
	std::wstring CHTMLFormElement::GetAttributeNS(std::wstring nspace, std::wstring localName) { return nullptr; }

	void CHTMLFormElement::SetAttribute(std::wstring qualifiedName, std::wstring value) {}
	void CHTMLFormElement::SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value) {}
	void CHTMLFormElement::RemoveAttribute(std::wstring qualifiedName) {}
	void CHTMLFormElement::RemoveAttributeNS(std::wstring nspace, std::wstring localName) {}

	bool CHTMLFormElement::ToggleAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLFormElement::ToggleAttribute(std::wstring qualifiedName, bool force) { return false; }

	bool CHTMLFormElement::HasAttribute(std::wstring qualifiedName) { return false; }
	bool CHTMLFormElement::HasAttributeNS(std::wstring nspace, std::wstring localName) { return false; }

	IAttr CHTMLFormElement::GetAttributeNode(std::wstring qualifiedName) { return nullptr; }
	IAttr CHTMLFormElement::GetAttributeNodeNS(std::wstring nspace, std::wstring localName) { return nullptr; }

	IAttr CHTMLFormElement::SetAttributeNode(IAttr attr) { return nullptr; }
	IAttr CHTMLFormElement::SetAttributeNodeNS(IAttr attr) { return nullptr; }
	IAttr CHTMLFormElement::RemoveAttributeNode(IAttr attr) { return nullptr; }

	IShadowRoot CHTMLFormElement::AttachShadow(ShadowRootInit init) { return nullptr; }

	IShadowRoot CHTMLFormElement::shadowRoot() { return nullptr; }

	IElement CHTMLFormElement::Closest(std::wstring selectors) { return nullptr; }

	bool CHTMLFormElement::Matches(std::wstring selectors) { return false; }
	bool CHTMLFormElement::WebkitMatchesSelector(std::wstring selectors) { return false; } // legacy alias of .matches

	IHTMLCollection CHTMLFormElement::GetElementsByTagName(std::wstring qualifiedName) { return nullptr; }
	IHTMLCollection CHTMLFormElement::GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) { return nullptr; }
	IHTMLCollection CHTMLFormElement::GetElementsByClassName(std::wstring classNames) { return nullptr; }

	IElement CHTMLFormElement::InsertAdjacentElement(std::wstring where, IElement element) { return nullptr; } // legacy
	void CHTMLFormElement::InsertAdjacentText(std::wstring where, std::wstring data) {} // legacy

	XML_DOM_NODE_TYPE CHTMLFormElement::nodeType() { return XML_DOM_ELEMENT_NODE; }

	std::wstring CHTMLFormElement::nodeName() { return nullptr; }

	std::wstring CHTMLFormElement::baseURI() { return nullptr; }

	bool CHTMLFormElement::isConnected() { return false; }

	IDocument CHTMLFormElement::ownerDocument() { return nullptr; }

	INode CHTMLFormElement::GetRootNode() { return nullptr; }
	INode CHTMLFormElement::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	INode CHTMLFormElement::parentNode() { return nullptr; }

	IElement CHTMLFormElement::parentElement() { return nullptr; }

	bool CHTMLFormElement::HasChildNodes() { return false; }

	INodeList CHTMLFormElement::childNodes() { return nullptr; }

	INode CHTMLFormElement::firstChild() { return nullptr; }
	INode CHTMLFormElement::lastChild() { return nullptr; }
	INode CHTMLFormElement::previousSibling() { return nullptr; }
	INode CHTMLFormElement::nextSibling() { return nullptr; }

	std::wstring CHTMLFormElement::nodeValue() { return nullptr; }
	void CHTMLFormElement::nodeValue(std::wstring val) {}

	std::wstring CHTMLFormElement::textContent() { return nullptr; }
	void CHTMLFormElement::textContent(std::wstring text) {}

	void CHTMLFormElement::Normalize() {}

	INode CHTMLFormElement::CloneNode() { return nullptr; }
	INode CHTMLFormElement::CloneNode(bool deep) { return nullptr; }

	bool CHTMLFormElement::isEqualNode(INode otherINode) { return false; }
	bool CHTMLFormElement::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	uint8_t CHTMLFormElement::CompareDocumentPosition(INode other) { return 0; }

	bool CHTMLFormElement::Contains(INode other) { return false; }

	std::wstring CHTMLFormElement::LookupPrefix(std::wstring nspace) { return nullptr; }

	std::wstring CHTMLFormElement::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	bool CHTMLFormElement::IsDefaultNamespace(std::wstring nspace) { return false; }

	INode CHTMLFormElement::InsertBefore(INode node, INode child) { return nullptr; }
	INode CHTMLFormElement::AppendChild(INode node) { return nullptr; }
	INode CHTMLFormElement::ReplaceChild(INode node, INode child) { return nullptr; }
	INode CHTMLFormElement::RemoveChild(INode child) { return nullptr; }

	void CHTMLFormElement::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CHTMLFormElement::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CHTMLFormElement::DispatchEvent(IEvent dispathchedEvent) { return false; }

}