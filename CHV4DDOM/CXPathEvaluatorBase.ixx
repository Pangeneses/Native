module;

#include <string>


export module CHV4DXML:CXPathEvaluatorBase;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XPathEvaluatorBase;

export namespace CHV4DXML
{
	// include: XPathExpression

	class CXPathEvaluatorBase : public XPathEvaluatorBase
	{
	public:
		CXPathEvaluatorBase() = default;

	public:
		IXPathExpression CreateExpression(std::wstring expression);
		IXPathExpression CreateExpression(std::wstring expression, IXPathNSResolver* resolver);

		INode CreateNSResolver(INode nodeResolver); // legacy

		// XPathResult.ANY_TYPE
		IXPathResult Evaluate(
			std::wstring expression,
			INode contextNode,
			IXPathNSResolver resolver,
			uint8_t type,
			IXPathResult result);

	};

}