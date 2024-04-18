module;

#include <string>

export module CHV4DXML:DOMImplementation;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class DOMImplementation
	{
	public:
		DOMImplementation() = default;

	public:
		virtual IDocumentType CreateDocumentType(std::wstring qualifiedName, std::wstring publicId, std::wstring systemId) = 0;

		virtual IXMLDocument CreateDocument(std::wstring nspace, std::wstring qualifiedName, IDocumentType doctype) = 0;

		virtual IDocument CreateHTMLDocument(std::wstring title) = 0;

		virtual bool HasFeature() = 0; // useless; always returns true

	public:
		virtual ~DOMImplementation() = 0;

	};

}