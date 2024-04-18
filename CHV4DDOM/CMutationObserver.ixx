module;

#include <string>


export module CHV4DXML:CMutationObserver;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :MutationObserver;

export namespace CHV4DXML
{
	class CMutationObserver : public MutationObserver
	{
	public:
		CMutationObserver() = default; // (MutationCallback callback);

	public:
		void Observe(INode target);

		void Observe(INode target, MutationObserverInit options);

		void Disconnect();

		void takeRecords(std::function<void()> sequenceOperator);

	};

}