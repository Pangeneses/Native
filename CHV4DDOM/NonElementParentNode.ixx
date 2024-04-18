module;

#include <string>

export module CHV4DXML:NonElementParentNode;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	//includes: NonElementParentNode

	class NonElementParentNode
	{
	public:
		NonElementParentNode() = default;

	public:
		virtual IElement GetElementById(std::wstring eid) = 0;

	public:
		virtual ~NonElementParentNode() = 0;

	};

}