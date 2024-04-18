module;

#include <string>
#include <vector>

module CHV4DXML:CAbortSignal;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IAbortSignal CAbortSignal::Abort(void* reason) { return nullptr; }

	IAbortSignal CAbortSignal::Timeout(uint64_t milliseconds) { return nullptr; }

	IAbortSignal CAbortSignal::Any(std::vector<IAbortSignal> signals) { return nullptr; }

	bool CAbortSignal::aborted() { return false; }

	void* CAbortSignal::reason() { return nullptr; }

	void CAbortSignal::ThrowIfAborted() {}

	EventHandler CAbortSignal::onAbort() { return nullptr; }

	void CAbortSignal::onAbort(EventHandler handler) {}

	void CAbortSignal::AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options) {}

	void CAbortSignal::RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options) {}

	bool CAbortSignal::DispatchEvent(IEvent dispathchedEvent) { return false; }

}