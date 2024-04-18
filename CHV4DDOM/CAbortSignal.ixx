module;

#include <string>
#include <vector>

export module CHV4DXML:CAbortSignal;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :AbortSignal;

export namespace CHV4DXML
{
	class CAbortSignal : public AbortSignal
	{
	public:
		CAbortSignal() = default;

	public:
		IAbortSignal Abort(void* reason);

		IAbortSignal Timeout(uint64_t milliseconds);

		IAbortSignal Any(std::vector<IAbortSignal> signals);

		bool aborted();

		void* reason();

		void ThrowIfAborted();

		EventHandler onAbort();

		void onAbort(EventHandler handler);

		void AddEventListener(std::wstring type, IEventListener callback, AddEventListenerOptions options);

		void RemoveEventListener(std::wstring type, IEventListener callback, EventListenerOptions options);

		bool DispatchEvent(IEvent dispathchedEvent);

	};

}