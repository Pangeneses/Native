module;

#include <string>


export module CHV4DXML:CXPathExpression;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XPathExpression;

export namespace CHV4DXML
{
	class CXPathExpression : public XPathExpression
	{
	public:
		CXPathExpression() = default;

	public:
		// XPathResult.ANY_TYPE = 0
		IXPathResult evaluate(INode contextNode, uint8_t type = 0, IXPathResult result = 0);

	};

}