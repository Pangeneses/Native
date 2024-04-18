module;

#include <string>

module CHV4DXML:CDocumentType;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	template<class T>
	std::wstring CDocumentType<T>::name() { return DocumentTypeName; }

	template<class T>
	std::wstring CDocumentType<T>::publicId() { return T.DocumentTypePublicId; }

	template<class T>
	std::wstring CDocumentType<T>::systemId() { return T.DocumentTypeSystemId; }

	template<class T>
	XML_DOM_NODE_TYPE CDocumentType<T>::nodeType() { return XML_DOM_DOCUMENT_TYPE_NODE; }

	template<class T>
	std::wstring CDocumentType<T>::nodeName() { return nullptr; }

	template<class T>
	std::wstring CDocumentType<T>::baseURI() { return nullptr; }

	template<class T>
	bool CDocumentType<T>::isConnected() { return false; }

	template<class T>
	IDocument CDocumentType<T>::ownerDocument() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::GetRootNode() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::GetRootNode(GetRootNodeOptions options) { return nullptr; }

	template<class T>
	INode CDocumentType<T>::parentNode() { return nullptr; }

	template<class T>
	IElement CDocumentType<T>::parentElement() { return nullptr; }

	template<class T>
	bool CDocumentType<T>::HasChildNodes() { return false; }

	template<class T>
	INodeList CDocumentType<T>::childNodes() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::firstChild() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::lastChild() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::previousSibling() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::nextSibling() { return nullptr; }

	template<class T>
	std::wstring CDocumentType<T>::nodeValue() { return nullptr; }

	template<class T>
	void CDocumentType<T>::nodeValue(std::wstring val) {}

	template<class T>
	std::wstring CDocumentType<T>::textContent() { return nullptr; }

	template<class T>
	void CDocumentType<T>::textContent(std::wstring text) {}

	template<class T>
	void CDocumentType<T>::Normalize() {}

	template<class T>
	INode CDocumentType<T>::CloneNode() { return nullptr; }

	template<class T>
	INode CDocumentType<T>::CloneNode(bool deep) { return nullptr; }

	template<class T>
	bool CDocumentType<T>::isEqualNode(INode otherINode) { return false; }

	template<class T>
	bool CDocumentType<T>::isSameNode(INode otherINode) { return false; } // legacy alias of ===

	template<class T>
	uint8_t CDocumentType<T>::CompareDocumentPosition(INode other) { return 0; }

	template<class T>
	bool CDocumentType<T>::Contains(INode other) { return false; }

	template<class T>
	std::wstring CDocumentType<T>::LookupPrefix(std::wstring nspace) { return nullptr; }

	template<class T>
	std::wstring CDocumentType<T>::LookupNamespaceURI(std::wstring prefix) { return nullptr; }

	template<class T>
	bool CDocumentType<T>::IsDefaultNamespace(std::wstring nspace) { return false; }

	template<class T>
	INode CDocumentType<T>::InsertBefore(INode node, INode child) { return nullptr; }

	template<class T>
	INode CDocumentType<T>::AppendChild(INode node) { return nullptr; }

	template<class T>
	INode CDocumentType<T>::ReplaceChild(INode node, INode child) { return nullptr; }

	template<class T>
	INode CDocumentType<T>::RemoveChild(INode child) { return nullptr; }

	template<class T>
	void CDocumentType<T>::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	template<class T>
	void CDocumentType<T>::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	template<class T>
	bool CDocumentType<T>::DispatchEvent(IEvent dispathchedEvent) { return false; }

}