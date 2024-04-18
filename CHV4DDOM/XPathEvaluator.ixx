module;

#include <string>

export module CHV4DXML:XPathEvaluator;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XPathEvaluatorBase;

export namespace CHV4DXML
{
	class XPathEvaluator : public XPathEvaluatorBase
	{
	public:
		XPathEvaluator() = default;


	public:
		virtual ~XPathEvaluator() = 0;

	};

}