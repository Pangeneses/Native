module;

#include <string>

export module CHV4DXML:XSLTProcessor;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class XSLTProcessor 
	{
	public:
		XSLTProcessor() = default;

	public:
		virtual void ImportStylesheet(INode style) = 0;

		virtual IDocumentFragment TransformToFragment(INode source, IDocument output) = 0;

		virtual IDocument TransformToDocument(INode source) = 0;

		virtual void SetParameter(std::wstring nspaceURI, std::wstring localName, void* value) = 0;

		virtual void* GetParameter(std::wstring nspaceURI, std::wstring localName) = 0;

		virtual void RemoveParameter(std::wstring nspaceURI, std::wstring localName) = 0;

		virtual void ClearParameters() = 0;

		virtual void Reset() = 0;

	public:
		virtual ~XSLTProcessor() = 0;

	};

}