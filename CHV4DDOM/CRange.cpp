module;

#include <string>

module CHV4DXML:CRange;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	INode CRange::commonAncestorContainer() { return nullptr; }

	void CRange::SetStart(INode node, uint32_t offset) {}
	void CRange::SetEnd(INode node, uint32_t offset) {}
	void CRange::SetStartBefore(INode node) {}
	void CRange::SetStartAfter(INode node) {}
	void CRange::SetEndBefore(INode node) {}
	void CRange::SetEndAfter(INode node) {}

	void CRange::Collapse() {}
	void CRange::Collapse(bool toStart) {}

	void CRange::SelectNode(INode node) {}
	void CRange::SelectNodeContents(INode node) {}

	int8_t CRange::CompareBoundaryPoints(uint8_t how, IRange sourceRange) { return 0; }

	void CRange::DeleteContents() {}

	IDocumentFragment CRange::ExtractContents() { return nullptr; }
	IDocumentFragment CRange::CloneContents() { return nullptr; }

	void CRange::InsertNode(INode node) {}
	void CRange::SurroundContents(INode newParent) {}

	IRange CRange::CloneRange() { return nullptr; }

	void CRange::Detach() {}

	bool CRange::IsPointInRange(INode node, uint32_t offset) { return false; }

	int8_t CRange::ComparePoint(INode node, uint32_t offset) { return 0; }

	bool CRange::IntersectsNode(INode node) { return false; }

	std::wstring CRange::stringifier() { return {}; }

	INode CRange::startContainer() { return nullptr; }

	uint32_t CRange::startOffset() { return 0; }

	INode CRange::endContainer() { return nullptr; }

	uint32_t CRange::endOffset() { return 0; }

	bool CRange::collapsed() { return true; }

}