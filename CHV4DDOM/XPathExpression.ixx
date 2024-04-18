module;

#include <string>

export module CHV4DXML:XPathExpression;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class XPathExpression
	{
	public:
		XPathExpression() = default;

	public:
		// XPathResult.ANY_TYPE = 0
		virtual IXPathResult evaluate(INode contextNode, uint8_t type = 0, IXPathResult result = 0) = 0;

	public:
		virtual ~XPathExpression() = 0;

	};

}