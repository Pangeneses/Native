module;

#include <string>

export module CHV4DXML:XPathEvaluatorBase;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class XPathNSResolver
	{
	public:
		XPathNSResolver() = default; 
		
	public:
		virtual std::wstring lookupNamespaceURI(std::wstring prefix) = 0;

	public:
		virtual ~XPathNSResolver() = 0;

	};

	// include: XPathExpression

	class XPathEvaluatorBase
	{
	public:
		XPathEvaluatorBase() = default;

	public:
		virtual IXPathExpression CreateExpression(std::wstring expression) = 0;
		virtual IXPathExpression CreateExpression(std::wstring expression, IXPathNSResolver* resolver) = 0;
		
		virtual INode CreateNSResolver(INode nodeResolver) = 0; // legacy
		
		// XPathResult.ANY_TYPE
		virtual IXPathResult Evaluate(
			std::wstring expression, 
			INode contextNode, 
			IXPathNSResolver resolver, 
			uint8_t type, 
			IXPathResult result) = 0;

	public:
		virtual ~XPathEvaluatorBase() = 0;

	};

}