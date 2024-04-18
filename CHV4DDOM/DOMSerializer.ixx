module;

#include <string>

export module CHV4DXML:DOMSerializer;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class DOMSerializer
	{
	public:
		DOMSerializer() = default;

	public:
		virtual std::wstring SerializeToString(INode root) = 0;

	public:
		virtual ~DOMSerializer() = 0;

	};

}