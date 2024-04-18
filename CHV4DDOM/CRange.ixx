module;

#include <string>


export module CHV4DXML:CRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Range;

export namespace CHV4DXML
{
	class CRange : public Range
	{
	public:
		CRange() = default;

	public:
		INode commonAncestorContainer();

		void SetStart(INode node, uint32_t offset);
		void SetEnd(INode node, uint32_t offset);
		void SetStartBefore(INode node);
		void SetStartAfter(INode node);
		void SetEndBefore(INode node);
		void SetEndAfter(INode node);

		void Collapse();
		void Collapse(bool toStart);

		void SelectNode(INode node);
		void SelectNodeContents(INode node);

		int8_t CompareBoundaryPoints(uint8_t how, IRange sourceRange);

		void DeleteContents();

		IDocumentFragment ExtractContents();
		IDocumentFragment CloneContents();

		void InsertNode(INode node);
		void SurroundContents(INode newParent);

		IRange CloneRange();

		void Detach();

		bool IsPointInRange(INode node, uint32_t offset);

		int8_t ComparePoint(INode node, uint32_t offset);

		bool IntersectsNode(INode node);

		std::wstring stringifier();

	public:
		INode startContainer();

		uint32_t startOffset();

		INode endContainer();

		uint32_t endOffset();

		bool collapsed();

	};

}