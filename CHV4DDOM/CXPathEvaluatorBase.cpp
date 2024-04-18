module;

#include <string>

module CHV4DXML:CXPathEvaluatorBase;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IXPathExpression CXPathEvaluatorBase::CreateExpression(std::wstring expression) { return nullptr; }
	IXPathExpression CXPathEvaluatorBase::CreateExpression(std::wstring expression, IXPathNSResolver* resolver) { return nullptr; }

	INode CXPathEvaluatorBase::CreateNSResolver(INode nodeResolver) { return nullptr; } // legacy

	// XPathResult.ANY_TYPE
	IXPathResult CXPathEvaluatorBase::Evaluate(std::wstring expression, INode contextNode, IXPathNSResolver resolver, uint8_t type, IXPathResult result)
	{


		return nullptr;

	}

}