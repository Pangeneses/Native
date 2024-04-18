module;

#include <string>

export module CHV4DXML:NonDocumentTypeChildNode;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class NonDocumentTypeChildNode
	{
	public:
		NonDocumentTypeChildNode() = default;

	public:
		virtual IElement PreviousElementSibling() = 0;

		virtual IElement NextElementSibling() = 0;

	public:
		virtual ~NonDocumentTypeChildNode() = 0;

	};

}