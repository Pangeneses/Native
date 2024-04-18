module;

#include <string>

export module CHV4DXML:EventTarget;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class EventTarget
	{
	public:
		EventTarget() = default;

	public:
		virtual void AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) = 0;
		
		virtual void RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) = 0;
		
		virtual bool DispatchEvent(IEvent dispathchedEvent) = 0;

	public:
		virtual ~EventTarget() = 0;

	};

}