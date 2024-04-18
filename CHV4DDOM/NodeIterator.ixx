module;

#include <string>

export module CHV4DXML:NodeIterator;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class NodeIterator
	{
	public:
		NodeIterator() = default;

	public:
		virtual INode root() = 0;

		virtual INode referenceNode() = 0;

		virtual bool pointerBeforeReferenceNode() = 0;

		virtual uint32_t whatToShow() = 0;

		virtual INodeFilter filter() = 0;

		virtual INode NextNode() = 0;
		virtual INode PreviousNode() = 0;

		virtual void Detach() = 0;

	public:
		virtual ~NodeIterator() = 0;

	};

}