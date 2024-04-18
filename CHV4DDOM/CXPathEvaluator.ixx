module;

#include <string>


export module CHV4DXML:CXPathEvaluator;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XPathEvaluator;

export namespace CHV4DXML
{
	// include: XPathEvaluatorBase

	class CXPathEvaluator : public XPathEvaluator
	{
	public:
		CXPathEvaluator() = default;

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