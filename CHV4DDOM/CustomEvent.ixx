module;

#include <string>
#include <chrono>

export module CHV4DXML:CustomEvent;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Event;

export namespace CHV4DXML
{
	class CustomEvent : public Event
	{
	public:
		CustomEvent() = default; //CustomEvent(std::wstring type, CustomEventInit eventInitDict);

	public:
		virtual void* detail() = 0;

	public:
		virtual ~CustomEvent() = 0;

	};

}