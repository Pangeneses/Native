module;

#include <string>

module CHV4DXML:CXPathResult;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	uint8_t CXPathResult::resultType() { return 0; }

	double CXPathResult::numberValue() { return 0; }

	std::wstring CXPathResult::stringValue() { return {}; }

	bool CXPathResult::boolValue() { return false; }

	INode CXPathResult::singleNodeValue() { return nullptr; }

	bool CXPathResult::invalidIteratorState() { return false; }

	uint32_t CXPathResult::snapshotLength() { return 0; }

	INode CXPathResult::IterateNext() { return nullptr; }

	INode CXPathResult::SnapshotItem(uint32_t index) { return nullptr; }

}