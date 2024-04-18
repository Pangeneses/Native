module;

#include <string>

export module CHV4DXML:HTMLElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Element;

export namespace CHV4DXML
{
	// includes GlobalEventHandlers, ElementContentEditable, HTMLOrSVGElement

	class HTMLElement : public Element 
	{
	public:
		HTMLElement() = default;
	
	public:
		virtual std::wstring title() = 0;

		virtual std::wstring lang() = 0;

		virtual bool translate() = 0;

		virtual std::wstring dir() = 0;
	
		// user interaction
		virtual void* hidden() = 0;

		virtual bool inert() = 0;

		virtual void Click() = 0;

		virtual std::wstring accessKey() = 0;

		virtual std::wstring accessKeyLabel() = 0;

		virtual bool draggable() = 0;

		virtual bool spellcheck() = 0;

		virtual std::wstring autocapitalize() = 0;
	
		virtual std::wstring innerText() = 0;
		virtual std::wstring outerText() = 0;
	
		virtual IElementInternals attachInternals() = 0;
	
		// The popover API
		virtual void ShowPopover() = 0;

		virtual void HidePopover() = 0;

		virtual bool TogglePopover() = 0;
		virtual void TogglePopover(bool force) = 0;

		virtual std::wstring popover() = 0;

	public:
		virtual ~HTMLElement() = 0;

	};

	class HTMLUnknownElement : public HTMLElement 
	{
	public:
		HTMLUnknownElement() = default;


	public:
		virtual ~HTMLUnknownElement() = 0;

	};

}