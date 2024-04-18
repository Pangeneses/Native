module;

#include <string>
#include <chrono>

module CHV4DXML:CCustomEvent;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Event;

namespace CHV4DXML
{
	CCustomEvent::CCustomEvent(std::wstring type, CustomEventInit eventInitDict) {}

	void* CCustomEvent::detail() { return nullptr; }

	std::wstring CCustomEvent::type() { return L""; }

	IEventTarget CCustomEvent::target() { return nullptr; }

	IEventTarget CCustomEvent::srcElement() { return nullptr; }

	IEventTarget CCustomEvent::currentTarget() { return nullptr; }

	std::vector<IEventTarget> CCustomEvent::ComposedPath() { return std::vector<IEventTarget>{}; }

	char CCustomEvent::eventPhase() { return '\0'; }

	void CCustomEvent::StopPropagation() {}

	void CCustomEvent::StopImmediatePropagation() {}

	bool CCustomEvent::bubbles() { return '\0'; }
	bool CCustomEvent::cancelable() { return '\0'; }

	void CCustomEvent::preventDefault() {}

	bool CCustomEvent::defaultPrevented() { return '\0'; }
	bool CCustomEvent::composed() { return '\0'; }

	bool CCustomEvent::isTrusted() { return false; }

	std::chrono::time_point<std::chrono::system_clock> CCustomEvent::TimeStamp() { return std::chrono::system_clock::now(); }

	void CCustomEvent::initEvent(std::wstring type, bool bubbles, bool cancelable) {}

}