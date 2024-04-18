module;

#include <string>
#include <vector>

export module CHV4DXML:HTMLSlotElement;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :HTMLElement;

export namespace CHV4DXML
{
	class HTMLSlotElement : public HTMLElement
	{
	public:
		HTMLSlotElement() = default;

	public:
		virtual std::wstring name() = 0; 
		virtual void name(std::wstring e) = 0; 
		 
		virtual std::vector<INode> assignedNodes() = 0;
		virtual std::vector<INode> assignedNodes(AssignedNodesOptions options) = 0;
		 
		virtual std::vector<IElement> assignedElements() = 0;
		virtual std::vector<IElement> assignedElements(AssignedNodesOptions options) = 0;
		 
		virtual void Assign(std::vector<INode> nodes) = 0;

	public:
		virtual ~HTMLSlotElement() = 0;

	};
	
};