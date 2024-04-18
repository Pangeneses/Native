module;

#include <string>

module CHV4DXML:CXPathEvaluator;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IXPathExpression CXPathEvaluator::CreateExpression(std::wstring expression) { return nullptr; }
	IXPathExpression CXPathEvaluator::CreateExpression(std::wstring expression, IXPathNSResolver* resolver) { return nullptr; }

	INode CXPathEvaluator::CreateNSResolver(INode nodeResolver) { return nullptr; } // legacy

	// XPathResult.ANY_TYPE
	IXPathResult CXPathEvaluator::Evaluate(std::wstring expression, INode contextNode, IXPathNSResolver resolver, uint8_t type, IXPathResult result)
	{


		return nullptr;

	}

}