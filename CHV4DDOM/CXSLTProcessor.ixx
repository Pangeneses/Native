module;

#include <string>


export module CHV4DXML:CXSLTProcessor;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :XSLTProcessor;

export namespace CHV4DXML
{
	class CXSLTProcessor : public XSLTProcessor
	{
	public:
		CXSLTProcessor();

	public:
		void ImportStylesheet(INode style);

		IDocumentFragment TransformToFragment(INode source, IDocument output);

		IDocument TransformToDocument(INode source);

		void SetParameter(std::wstring nspaceURI, std::wstring localName, void* value);

		void* GetParameter(std::wstring nspaceURI, std::wstring localName);

		void RemoveParameter(std::wstring nspaceURI, std::wstring localName);

		void ClearParameters();

		void Reset();

	};

}
