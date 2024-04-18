module;

#include <string>

module CHV4DXML:CAbortController;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	IAbortSignal CAbortController::signal() { return nullptr; };

	void CAbortController::Abort(void* reason) {}

}