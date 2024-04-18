module;



export module CHV4DXML:AbortController;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class AbortController
	{
	public:
		AbortController() = default;

	public:
		virtual IAbortSignal signal() = 0;

		virtual void Abort(void* reason) = 0;

	public:
		virtual ~AbortController() = 0;

	};

}