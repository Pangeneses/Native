module;

#include <string>

export module CHV4DXML:MutationRecord;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class MutationRecord
	{
	public:
		MutationRecord() = default;

	public:
		virtual std::wstring type() = 0;
		
		virtual INode target() = 0;
		
		virtual INodeList addedNodes() = 0;
		
		virtual INodeList removedNodes() = 0;
		
		virtual INode previousSibling() = 0;
		
		virtual INode nextSibling() = 0;
		
		virtual std::wstring attributeName() = 0;
		
		virtual std::wstring attributeNamespace() = 0;
		
		virtual std::wstring oldValue() = 0;

	public:
		virtual ~MutationRecord() = 0;

	};

}