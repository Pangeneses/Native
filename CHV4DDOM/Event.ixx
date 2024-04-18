module;

#include <string>
#include <vector>
#include <chrono>

export module CHV4DXML:Event;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class Event
	{
	public:
		Event() = default; // Event(std::wstring type, EventInit eventInitDict);

	public:
		virtual std::wstring type() = 0;

		virtual IEventTarget target() = 0;

		virtual IEventTarget srcElement() = 0;

		virtual IEventTarget currentTarget() = 0;

		virtual std::vector<IEventTarget> ComposedPath() = 0;

		virtual char eventPhase() = 0;

		virtual void StopPropagation() = 0;

		virtual void StopImmediatePropagation() = 0;

		virtual bool bubbles() = 0;
		virtual bool cancelable() = 0;

		virtual void preventDefault() = 0;

		virtual bool defaultPrevented() = 0;
		virtual bool composed() = 0;

		virtual bool isTrusted() = 0;

		virtual std::chrono::time_point<std::chrono::system_clock> TimeStamp() = 0;

		virtual void initEvent(std::wstring type, bool bubbles, bool cancelable) = 0;

	public:
		virtual ~Event() = 0;

	};

}