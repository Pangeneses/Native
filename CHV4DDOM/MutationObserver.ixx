module;

#include <string>
#include <vector>
#include <functional>

export module CHV4DXML:MutationObserver;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class MutationObserver 
	{
	public:
		MutationObserver() = default; // (MutationCallback callback);

	public:
		virtual void Observe(INode target) = 0;

		virtual void Observe(INode target, MutationObserverInit options) = 0;

		virtual void Disconnect() = 0;

		virtual void takeRecords(std::function<void()> sequenceOperator) = 0;

	public:
		virtual ~MutationObserver() = 0;

	};

}