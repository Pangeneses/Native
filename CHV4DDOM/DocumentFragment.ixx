module;

#include <string>

export module CHV4DXML:DocumentFragment;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	// include: NonElementParentNode, ParentNode, 

	class DocumentFragment : public Node
	{
	public:
		DocumentFragment() = default;

	public:
		virtual ~DocumentFragment() = 0;

	};

}