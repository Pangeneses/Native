module;

#include <string>

export module CHV4DXML:XPathResult;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class XPathResult
	{
	public:
		XPathResult() = default;

	public:
		virtual uint8_t resultType() = 0;

		virtual double numberValue() = 0;

		virtual std::wstring stringValue() = 0;

		virtual bool boolValue() = 0;

		virtual INode singleNodeValue() = 0;

		virtual bool invalidIteratorState() = 0;

		virtual uint32_t snapshotLength() = 0;

		virtual INode IterateNext() = 0;

		virtual INode SnapshotItem(uint32_t index) = 0;

	public:
		virtual ~XPathResult() = 0;

	};

}