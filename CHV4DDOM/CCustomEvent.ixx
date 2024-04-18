module;

#include <string>


export module CHV4DXML:CCustomEvent;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CustomEvent;

export namespace CHV4DXML
{
	class CCustomEvent : public CustomEvent
	{
	public:
		CCustomEvent(std::wstring type, CustomEventInit eventInitDict);

	public:
		void* detail();

		std::wstring type();

		IEventTarget target();

		IEventTarget srcElement();

		IEventTarget currentTarget();

		std::vector<IEventTarget> ComposedPath();

		char eventPhase();

		void StopPropagation();

		void StopImmediatePropagation();

		bool bubbles();
		bool cancelable();

		void preventDefault();

		bool defaultPrevented();
		bool composed();

		bool isTrusted();

		std::chrono::time_point<std::chrono::system_clock> TimeStamp();

		void initEvent(std::wstring type, bool bubbles, bool cancelable);

	};

}