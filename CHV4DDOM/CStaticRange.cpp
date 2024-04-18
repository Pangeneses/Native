module;

#include <string>

module CHV4DXML:CStaticRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	CStaticRange::CStaticRange(StaticRangeInit init) {}

	INode CStaticRange::startContainer() { return nullptr; }

	uint32_t CStaticRange::startOffset() { return 0; }

	INode CStaticRange::endContainer() { return nullptr; }

	uint32_t CStaticRange::endOffset() { return 0; }

	bool CStaticRange::collapsed() { return true; }

}