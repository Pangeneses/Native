module;

#include <string>

export module CHV4DXML:ShadowRoot;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :DocumentFragment;

export namespace CHV4DXML
{
	// include: DocumentOrShadowRoot,

	class ShadowRoot : public DocumentFragment
	{
	public:
		ShadowRoot() = default;

	public:
		virtual XML_DOM_SHADOW_ROOT_MODE mode() = 0;
	
		virtual bool delegatesFocus() = 0;
		
		virtual XML_DOM_SLOT_ASSIGNMENT_MODE slotAssignment() = 0;
		
		virtual IElement host() = 0;

		virtual EventHandler onSlotChanged() = 0;

	public:
		virtual ~ShadowRoot() = 0;

	};

}