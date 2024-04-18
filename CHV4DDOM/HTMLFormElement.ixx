module;

#include <string>

export module CHV4DXML:HTMLFormElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :HTMLElement;

export namespace CHV4DXML
{
	class HTMLFormElement : public HTMLElement
	{
	public:
		HTMLFormElement() = default;

	public:
		virtual std::wstring acceptcharset() = 0; 
		virtual void acceptcharset(std::wstring set) = 0;

		virtual std::wstring action() = 0;
		virtual void action(std::wstring doActtion) = 0;

		virtual std::wstring autocomplete() = 0;
		virtual void autocomplete(std::wstring fill) = 0;

		virtual std::wstring enctype() = 0;
		virtual void enctype(std::wstring enc) = 0;

		virtual std::wstring encoding() = 0;
		virtual void encoding(std::wstring coding) = 0;

		virtual std::wstring method() = 0;
		virtual void method(std::wstring way) = 0;

		virtual std::wstring name() = 0;
		virtual void name(std::wstring n) = 0;

		virtual bool noValidate() = 0;
		virtual void noValidate(bool validity) = 0;

		virtual std::wstring target() = 0;
		virtual void target(std::wstring name) = 0;

		virtual std::wstring rel() = 0;
		virtual void rel(std::wstring name) = 0;

		virtual INodeList relList() = 0;
		virtual void relList(INodeList list) = 0;

		virtual IHTMLFormControlsCollection elements() = 0;

		virtual uint32_t length() = 0;

		virtual IElement ByIndex(uint32_t index) = 0;

		virtual IElement ByName(std::wstring name) = 0;

		virtual void Submit() = 0;

		virtual void RequestSubmit(IElement submitter) = 0;

		virtual void Reset() = 0;

		virtual bool CheckValidity() = 0;

		virtual bool ReportValidity() = 0;

	public:
		virtual ~HTMLFormElement() = 0;

	};

}