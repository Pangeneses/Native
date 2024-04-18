module;

#include <string>
#include <vector>
#include <functional>

export module CHV4DXML:CHV4DRESOURCE;

import :CHV4DFORWARD;

export namespace CHV4DXML
{
	enum XML_DOM_EXCEPTION
	{
		XML_DOM_INDEX_SIZE_ERR					= 1,
		XML_DOM_DOMSTRING_SIZE_ERR				= 2,
		XML_DOM_HIERARCHY_REQUEST_ERR			= 3,
		XML_DOM_WRONG_DOCUMENT_ERR				= 4,
		XML_DOM_INVALID_CHARACTER_ERR			= 5,
		XML_DOM_NO_DATA_ALLOWED_ERR				= 6,
		XML_DOM_NO_MODIFICATION_ALLOWED_ERR		= 7,
		XML_DOM_NOT_FOUND_ERR					= 8,
		XML_DOM_NOT_SUPPORTED_ERR				= 9,
		XML_DOM_INUSE_ATTRIBUTE_ERR				= 10,
		XML_DOM_INVALID_STATE_ERR				= 11,
		XML_DOM_SYNTAX_ERR						= 12,
		XML_DOM_INVALID_MODIFICATION_ERR		= 13,
		XML_DOM_NAMESPACE_ERR					= 14,
		XML_DOM_INVALID_ACCESS_ERR				= 15,
		XML_DOM_VALIDATION_ERR					= 16,
		XML_DOM_TYPE_MISMATCH_ERR				= 17,
		XML_DOM_SECURITY_ERR					= 18,
		XML_DOM_NETWORK_ERR						= 19,
		XML_DOM_ABORT_ERR						= 20,
		XML_DOM_URL_MISMATCH_ERR				= 21,
		XML_DOM_QUOTA_EXCEEDED_ERR				= 22,
		XML_DOM_TIMEOUT_ERR						= 23,
		XML_DOM_INVALID_NODE_TYPE_ERR			= 24,
		XML_DOM_DATA_CLONE_ERR					= 25	
	};

	enum XML_DOM_PARSER_SUPPORTED_TYPE {
		XML_DOM_TEXT_HTML				= 1,
		XML_DOM_TEXT_XML				= 2,
		XML_DOM_APPLICATION_XML			= 3,
		XML_DOM_APPLICATION_XHTML_XML	= 4,
		XML_DOM_IMAGE_SVG_XML			= 5
	};

	class ParserSupportedType
	{
	public:
		ParserSupportedType() = default;

	public:
		std::wstring operator ()(XML_DOM_PARSER_SUPPORTED_TYPE e)
		{
			switch (e)
			{
			case XML_DOM_TEXT_HTML: return L"text/html";

			case XML_DOM_TEXT_XML: return L"text/xml";

			case XML_DOM_APPLICATION_XML: return L"application/xml";

			case XML_DOM_APPLICATION_XHTML_XML: return L"application/xhtml+xml";

			case XML_DOM_IMAGE_SVG_XML: return L"image/svg+xml";

			default: return L"";

			}

		}

	};

	enum XML_DOM_EVENT_PHASE
	{
		XML_DOM_NONE				= 0,
		XML_DOM_CAPTURING_PHASE		= 1,
		XML_DOM_AT_TARGET			= 2,
		XML_DOM_BUBBLING_PHASE		= 3
	};

	struct EventInit
	{
		bool bubbles;

		bool cancelable;

		bool composed;

	};

	typedef class EventListener
	{
	public:
		EventListener() = default;

	public:
		virtual void HandleEvent(IEvent handleEvent) = 0;

	public:
		virtual ~EventListener() = default;

	}* IEventListener;

	struct EventListenerOptions
	{
		bool capture{ false };

	};

	struct AddEventListenerOptions : public EventListenerOptions
	{
		bool passive;

		bool once{ false };

		IAbortSignal signal;

	};

	struct CustomEventInit
	{
		void* detail;

		bool bubbles;

		bool cancelable;

		bool composed;

	};

	using EventHandlerNonNull = auto(*)(IEvent) -> void;

	using EventHandler = EventHandlerNonNull;

	struct MutationObserverInit
	{
		bool childList{ false };

		bool attributes;

		bool characterData;

		bool subtree{ false };

		bool attributeOldValue;

		bool characterDataOldValue;

		std::function<void()> attributeFilter;

	};

	using MutationCallback = auto(*)(std::function<void()>  sequenceMutations, IMutationObserver observer) -> void;

	enum XML_DOM_NODE_TYPE
	{
		XML_DOM_ELEMENT_NODE				= 1,
		XML_DOM_ATTRIBUTE_NODE				= 2,
		XML_DOM_TEXT_NODE					= 3,
		XML_DOM_CDATA_SECTION_NODE			= 4,
		XML_DOM_ENTITY_REFERENCE_NODE		= 5, //legacy
		XML_DOM_ENTITY_NODE					= 6, //legacy
		XML_DOM_PROCESSING_INSTRUCTION_NODE = 7,
		XML_DOM_COMMENT_NODE				= 8,
		XML_DOM_DOCUMENT_NODE				= 9,
		XML_DOM_DOCUMENT_TYPE_NODE			= 10,
		XML_DOM_DOCUMENT_FRAGMENT_NODE		= 11,
		XML_DOM_NOTATION_NODE				= 12 //legacy
	};

	enum XML_DOM_DOCUMENT_POSITION
	{
		XML_DOM_DOCUMENT_POSITION_DISCONNECTED				= 0x01,
		XML_DOM_DOCUMENT_POSITION_PRECEDING					= 0x02,
		XML_DOM_DOCUMENT_POSITION_FOLLOWING					= 0x04,
		XML_DOM_DOCUMENT_POSITION_CONTAINS					= 0x08,
		XML_DOM_DOCUMENT_POSITION_CONTAINED_BY				= 0x10,
		XML_DOM_DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC	= 0x20
	};

	struct GetRootNodeOptions
	{
		bool composed;

	};

	struct ElementCreationOptions
	{
		std::wstring is;

	};

	enum XML_DOM_SHADOW_ROOT_MODE
	{
		XML_DOM_SHADOW_ROOT_OPEN	= 0x00,
		XML_DOM_SHADOW_ROOT_CLOSED	= 0x01
	};

	enum XML_DOM_SLOT_ASSIGNMENT_MODE
	{
		XML_DOM_SLOT_ASSIGNMENT_MANUAL = 0x00,
		XML_DOM_SLOT_ASSIGNMENT_NAMED = 0x01
	};

	struct ShadowRootInit
	{
		XML_DOM_SHADOW_ROOT_MODE mode;

		bool delegatesFocus;

		XML_DOM_SLOT_ASSIGNMENT_MODE slotAssignment{ XML_DOM_SLOT_ASSIGNMENT_NAMED };

	};

	enum XML_DOM_BOUNDARY_POINTS
	{
		XML_DOM_START_TO_START		= 0,
		XML_DOM_START_TO_END		= 1,
		XML_DOM_END_TO_END			= 2,
		XML_DOM_END_TO_START		= 3
	};

	struct StaticRangeInit
	{
		INode startContainer;

		uint32_t startOffset;

		INode endContainer;

		uint32_t endOffset;

	};

	enum XML_DOM_FILTER_ACCEPT
	{
		XML_DOM_FILTER_ACCEPT	= 1,
		XML_DOM_FILTER_REJECT	= 2,
		XML_DOM_FILTER_SKIP		= 3
	};

	enum XML_DOM_WHAT_TO_SHOW
	{
		XML_DOM_SHOW_ALL					= 0xFFFFFFFF,
		XML_DOM_SHOW_ELEMENT				= 0x1,
		XML_DOM_SHOW_ATTRIBUTE				= 0x2,
		XML_DOM_SHOW_TEXT					= 0x4,
		XML_DOM_SHOW_CDATA_SECTION			= 0x8,
		XML_DOM_SHOW_ENTITY_REFERENCE		= 0x10, // legacy
		XML_DOM_SHOW_ENTITY					= 0x20, // legacy
		XML_DOM_SHOW_PROCESSING_INSTRUCTION = 0x40,
		XML_DOM_SHOW_COMMENT				= 0x80,
		XML_DOM_SHOW_DOCUMENT				= 0x100,
		XML_DOM_SHOW_DOCUMENT_TYPE			= 0x200,
		XML_DOM_SHOW_DOCUMENT_FRAGMENT		= 0x400,
		XML_DOM_SHOW_NOTATION				= 0x800 // legacy
	};

	struct AssignedNodesOptions
	{
		bool flatten;

	};

	struct ValidityStateFlags
	{
		bool valueMissing;
		bool typeMismatch;
		bool patternMismatch;
		bool tooLong;
		bool tooShort;
		bool rangeUnderflow;
		bool rangeOverflow;
		bool stepMismatch;
		bool badInput;
		bool customError;
	};

	enum XML_DOM_XPATH_RESULT
	{
		XML_DOM_ANY_TYPE						= 0,
		XML_DOM_NUMBER_TYPE						= 1,
		XML_DOM_STRING_TYPE						= 2,
		XML_DOM_BOOLEAN_TYPE					= 3,
		XML_DOM_UNORDERED_NODE_ITERATOR_TYPE	= 4,
		XML_DOM_ORDERED_NODE_ITERATOR_TYPE		= 5,
		XML_DOM_UNORDERED_NODE_SNAPSHOT_TYPE	= 6,
		XML_DOM_ORDERED_NODE_SNAPSHOT_TYPE		= 7,
		XML_DOM_ANY_UNORDERED_NODE_TYPE			= 8,
		XML_DOM_FIRST_ORDERED_NODE_TYPE			= 9
	};

}