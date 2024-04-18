module;

#include <string>
#include <vector>
#include <chrono>

module CHV4DXML:CEvent;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	CEvent::CEvent(std::wstring type, EventInit eventInitDict){}

	std::wstring CEvent::type() { return L""; }

	IEventTarget CEvent::target() { return nullptr; }

	IEventTarget CEvent::srcElement(){ return nullptr; }

	IEventTarget CEvent::currentTarget(){ return nullptr; }

	std::vector<IEventTarget> CEvent::ComposedPath() { return std::vector<IEventTarget>{}; }

	char CEvent::eventPhase() { return '\0'; }

	void CEvent::StopPropagation(){}

	void CEvent::StopImmediatePropagation(){}

	bool CEvent::bubbles(){ return '\0'; }
	bool CEvent::cancelable(){ return '\0'; }

	void CEvent::preventDefault(){}

	bool CEvent::defaultPrevented(){ return '\0'; }
	bool CEvent::composed(){ return '\0'; }

	bool CEvent::isTrusted() { return false; }

	std::chrono::time_point<std::chrono::system_clock> CEvent::TimeStamp() { return std::chrono::system_clock::now(); }

	void CEvent::initEvent(std::wstring type, bool bubbles, bool cancelable){}

}