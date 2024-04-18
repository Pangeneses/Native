module;

#include <string>

export module CHV4DXML:ElementInternals;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :HTMLFormElement;
import :HTMLElement;

export namespace CHV4DXML
{
	class ValidityState
	{
	public:
		ValidityState() = default;

	public:
		virtual bool valueMissing() = 0;
		virtual bool typeMismatch() = 0;
		virtual bool patternMismatch() = 0;
		virtual bool tooLong() = 0;
		virtual bool tooShort() = 0;
		virtual bool rangeUnderflow() = 0;
		virtual bool rangeOverflow() = 0;
		virtual bool stepMismatch() = 0;
		virtual bool badInput() = 0;
		virtual bool customError() = 0;
		virtual bool valid() = 0;

	public:
		virtual ~ValidityState() = 0;

	};

	class ElementInternals
	{
	public:
		ElementInternals() = default;

	public:
		virtual IShadowRoot shadowRoot() = 0;

		virtual void SetFormValue(void* value) = 0;
		virtual void SetFormValue(void* value, void* state) = 0;

		virtual HTMLFormElement form() = 0;

		virtual void SetValidity(ValidityState flags, std::wstring message, IHTMLElement anchor) = 0;

		virtual bool willValidate() = 0;

		virtual ValidityState validity() = 0;

		virtual std::wstring validationMessage() = 0;

		virtual bool CheckValidity() = 0;

		virtual bool ReportValidity() = 0;

		virtual NodeList labels() = 0;

	public:
		virtual ~ElementInternals() = 0;

	};

}