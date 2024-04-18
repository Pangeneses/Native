module;

#include <string>

export module CHV4DXML:NodeFilter;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class NodeFilter
	{
	public:
		NodeFilter() = default;

	public:
		virtual uint8_t AcceptNode(INode node) = 0;

	public:
		virtual ~NodeFilter() = 0;

	};

}