module;

#include <vector>


export module CHV4DXML:ChildNode;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class ChildNode
	{
	public:
		ChildNode() = default;

	public:
		virtual void Before(INode node) = 0;

		virtual void Before(std::vector<INode> nodes) = 0;

		virtual void After(INode node) = 0;

		virtual void After(std::vector<INode> nodes) = 0;

		virtual void ReplaceWith(INode node) = 0;

		virtual void ReplaceWith(std::vector<INode> nodes) = 0;

		virtual void Remove() = 0;

	public:
		virtual ~ChildNode() = 0;

	};

}