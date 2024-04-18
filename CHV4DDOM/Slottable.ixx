module;

#include <string>

export module CHV4DXML:Slottable;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class Slottable
	{
	public:
		Slottable() = default;

	public:
		virtual IHTMLSlotElement AssignedSlot() = 0;

	public:
		virtual ~Slottable() = 0;

	};

}