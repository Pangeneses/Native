module;

#include <string>

export module CHV4DXML:NonElementParentNode;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class Window
	{
	public:
		Window() = default;

	public:
		virtual IEvent legacyEvent() = 0;

	public:
		virtual ~Window() = 0;

	};

}