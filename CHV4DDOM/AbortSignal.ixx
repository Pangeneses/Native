module;

#include <string>
#include <vector>

export module CHV4DXML:AbortSignal;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :EventTarget;

export namespace CHV4DXML
{
	class AbortSignal : public EventTarget
	{
	public:
		AbortSignal() = default;

	public:
		virtual IAbortSignal Abort(void* reason) = 0;

		virtual IAbortSignal Timeout(uint64_t milliseconds) = 0;
		
		virtual IAbortSignal Any(std::vector<IAbortSignal> signals) = 0;

		virtual bool aborted() = 0;

		virtual void* reason() = 0;

		virtual void ThrowIfAborted() = 0;

		virtual EventHandler onAbort() = 0;

		virtual void onAbort(EventHandler handler) = 0;

	public:
		virtual ~AbortSignal() = 0;

	};

}