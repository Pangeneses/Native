module;

#include <string>
#include <vector>

export module CHV4DXML:ParentNode;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class ParentNode 
	{
	public:
		ParentNode() = default;

	public:
		virtual IHTMLCollection children() = 0;

		virtual IElement FirstElementChild() = 0;

		virtual IElement LastElementChild() = 0;

		virtual uint32_t ChildElementCount() = 0;

		virtual void Prepend(INode node) = 0;

		virtual void Prepend(std::vector<INode> nodes) = 0;

		virtual void Append(INode node) = 0;

		virtual void Append(std::vector<INode> nodes) = 0;

		virtual void ReplaceChildren(INode node) = 0;

		virtual void ReplaceChildren(std::vector<INode> nodes) = 0;

		virtual IElement QuerySelector(std::wstring selectors) = 0;

		virtual NodeList QuerySelectorAll(std::wstring selectors) = 0;

	public:
		virtual ~ParentNode() = 0;

	};

}