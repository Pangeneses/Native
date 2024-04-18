module;

#include <string>
#include <functional>

module CHV4DXML:CMutationObserver;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	void CMutationObserver::Observe(INode target) {}

	void CMutationObserver::Observe(INode target, MutationObserverInit options) {}

	void CMutationObserver::Disconnect() {}

	void CMutationObserver::takeRecords(std::function<void()> sequenceOperator) {}

}