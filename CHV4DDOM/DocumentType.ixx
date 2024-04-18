module;

#include <string>

export module CHV4DXML:DocumentType;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	// include: ChildNodeChildNode, 

	class DocumentType : public Node
	{
	public:
		DocumentType() = default;

	public:
		virtual std::wstring name() = 0;

		virtual std::wstring publicId() = 0;

		virtual std::wstring systemId() = 0;

	public:
		virtual ~DocumentType() = 0;

	};

}