module;

#include <string>

export module CHV4DXML:Range;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :AbstractRange;

export namespace CHV4DXML
{
	class Range : public AbstractRange
	{
	public:
		Range() = default;

	public:
		virtual INode commonAncestorContainer() = 0;
		 
		virtual void SetStart(INode node, uint32_t offset) = 0;
		virtual void SetEnd(INode node, uint32_t offset) = 0;
		virtual void SetStartBefore(INode node) = 0;
		virtual void SetStartAfter(INode node) = 0;
		virtual void SetEndBefore(INode node) = 0;
		virtual void SetEndAfter(INode node) = 0;
		 
		virtual void Collapse() = 0;
		virtual void Collapse(bool toStart) = 0;
		 
		virtual void SelectNode(INode node) = 0;
		virtual void SelectNodeContents(INode node) = 0;
		
		virtual int8_t CompareBoundaryPoints(uint8_t how, IRange sourceRange) = 0;
		 
		virtual void DeleteContents() = 0;
		 
		virtual IDocumentFragment ExtractContents() = 0;
		virtual IDocumentFragment CloneContents() = 0;
		 
		virtual void InsertNode(INode node) = 0;
		virtual void SurroundContents(INode newParent) = 0;
		 
		virtual IRange CloneRange() = 0;
		 
		virtual void Detach() = 0;
		 
		virtual bool IsPointInRange(INode node, uint32_t offset) = 0;
		 
		virtual int8_t ComparePoint(INode node, uint32_t offset) = 0;
		 
		virtual bool IntersectsNode(INode node) = 0;
		 
		virtual std::wstring stringifier() = 0;

	public:
		virtual ~Range() = 0;

	};

}