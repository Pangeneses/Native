module;

#include <string>


export module CHV4DXML:CStaticRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :StaticRange;

export namespace CHV4DXML
{
	class CStaticRange : public StaticRange
	{
	public:
		CStaticRange(StaticRangeInit init);

	public:
		INode startContainer();

		uint32_t startOffset();

		INode endContainer();

		uint32_t endOffset();

		bool collapsed();

	};

}