module;

#include <string>

export module CHV4DXML:AbstractRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class AbstractRange
	{
	public:
		AbstractRange() = default;

	public:
		virtual INode startContainer() =  0;

		virtual uint32_t startOffset() = 0;

		virtual INode endContainer() = 0;

		virtual uint32_t endOffset() = 0;

		virtual bool collapsed() = 0;

	public:
		virtual ~AbstractRange() = 0;

	};

}