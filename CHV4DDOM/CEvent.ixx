module;

#include <string>
#include <vector>
#include <chrono>

export module CHV4DXML:CEvent;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Event;

export namespace CHV4DXML
{
	class CEvent : public Event
	{
	public:
		CEvent(std::wstring type, EventInit eventInitDict);

	public:
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

	public:
		~CEvent() = default;

	};

}