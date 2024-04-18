module;

#include <string>

module CHV4DXML:CXSLTProcessor;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	void CXSLTProcessor::ImportStylesheet(INode style) {}

	IDocumentFragment CXSLTProcessor::TransformToFragment(INode source, IDocument output) { return nullptr; }

	IDocument CXSLTProcessor::TransformToDocument(INode source) { return nullptr; }

	void CXSLTProcessor::SetParameter(std::wstring nspaceURI, std::wstring localName, void* value) {}

	void* CXSLTProcessor::GetParameter(std::wstring nspaceURI, std::wstring localName) { return nullptr; }

	void CXSLTProcessor::RemoveParameter(std::wstring nspaceURI, std::wstring localName) {}

	void CXSLTProcessor::ClearParameters() {}

	void CXSLTProcessor::Reset() {}

}