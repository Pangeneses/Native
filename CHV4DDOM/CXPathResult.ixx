module;

#include <string>


export module CHV4DXML:CXPathResult;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XPathResult;

export namespace CHV4DXML
{
	class CXPathResult : public XPathResult
	{
	public:
		CXPathResult() = default;

	public:
		uint8_t resultType();

		double numberValue();

		std::wstring stringValue();

		bool boolValue();

		INode singleNodeValue();

		bool invalidIteratorState();

		uint32_t snapshotLength();

		INode IterateNext();

		INode SnapshotItem(uint32_t index);

	};

}