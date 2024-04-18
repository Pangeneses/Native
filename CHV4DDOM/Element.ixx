module;

#include <string>
#include <vector>

export module CHV4DXML:Element;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	// include: ParentNode, NonDocumentTypeChildNode, ChildNode, Slottable, 

	class Element : public Node
	{
	public:
		Element() = default;

	public:
		virtual std::wstring nspaceURI() = 0;
		virtual std::wstring prefix() = 0;
		virtual std::wstring localName() = 0;
		virtual std::wstring tagName() = 0;
		 
		virtual std::wstring eid() = 0;
		 
		virtual std::wstring className() = 0; 
		virtual void className(std::wstring name) = 0; 
		 
		virtual IDOMTokenList classList() = 0;
		 
		virtual std::wstring slot() = 0; 
		virtual void slot(std::wstring in) = 0; 
		 
		virtual bool HasAttributes() = 0;
		 
		virtual INamedNodeMap attributes() = 0;
		 
		virtual std::vector<std::wstring> GetAttributeNames() = 0;
		 
		virtual std::wstring GetAttribute(std::wstring qualifiedName) = 0;
		virtual std::wstring GetAttributeNS(std::wstring nspace, std::wstring localName) = 0;
		 
		virtual void SetAttribute(std::wstring qualifiedName, std::wstring value) = 0;
		virtual void SetAttributeNS(std::wstring nspace, std::wstring qualifiedName, std::wstring value) = 0;
		virtual void RemoveAttribute(std::wstring qualifiedName) = 0;
		virtual void RemoveAttributeNS(std::wstring nspace, std::wstring localName) = 0;
		 
		virtual bool ToggleAttribute(std::wstring qualifiedName) = 0;
		virtual bool ToggleAttribute(std::wstring qualifiedName, bool force) = 0;
		 
		virtual bool HasAttribute(std::wstring qualifiedName) = 0;
		virtual bool HasAttributeNS(std::wstring nspace, std::wstring localName) = 0;
		 
		virtual IAttr GetAttributeNode(std::wstring qualifiedName) = 0;
		virtual IAttr GetAttributeNodeNS(std::wstring nspace, std::wstring localName) = 0;
		 
		virtual IAttr SetAttributeNode(IAttr attr) = 0;
		virtual IAttr SetAttributeNodeNS(IAttr attr) = 0;
		virtual IAttr RemoveAttributeNode(IAttr attr) = 0;
		 
		virtual IShadowRoot AttachShadow(ShadowRootInit init) = 0;
		 
		virtual IShadowRoot shadowRoot() = 0;
		 
		virtual IElement Closest(std::wstring selectors) = 0;
		 
		virtual bool Matches(std::wstring selectors) = 0;
		virtual bool WebkitMatchesSelector(std::wstring selectors) = 0; // legacy alias of .matches
		 
		virtual IHTMLCollection GetElementsByTagName(std::wstring qualifiedName) = 0;
		virtual IHTMLCollection GetElementsByTagNameNS(std::wstring nspace, std::wstring localName) = 0;
		virtual IHTMLCollection GetElementsByClassName(std::wstring classNames) = 0;
		 
		virtual IElement InsertAdjacentElement(std::wstring where, IElement element) = 0; // legacy
		virtual void InsertAdjacentText(std::wstring where, std::wstring data) = 0; // legacy

	public:
		virtual ~Element() = 0;

	};

}