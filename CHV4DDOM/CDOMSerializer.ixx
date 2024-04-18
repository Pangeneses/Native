module;

#include <string>


export module CHV4DXML:CDOMSerializer;

import :DOMSerializer;

export namespace CHV4DXML
{
	class CDOMSerializer : public DOMSerializer
	{
	public:
		CDOMSerializer() = default;

	public:
		std::wstring SerializeToString(INode root);

	};

}