module;

#include <string>


export module CHV4DXML:CAbortController;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :AbortController;

export namespace CHV4DXML
{
	class CAbortController : public AbortController
	{
	public:
		CAbortController() = default;

	public:
		IAbortSignal signal();

		void Abort(void* reason);

	};

}