module;

#include <string>

export module CHV4DXML:CharacterData;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :Node;

export namespace CHV4DXML
{
	// include: NonDocumentTypeChildNode,

	class CharacterData : public Node
	{
	public:
		CharacterData() = default;

	public:
		virtual std::wstring data() = 0; 
		virtual void data(std::wstring e) = 0;

		virtual uint32_t length() = 0;
		virtual void length(uint32_t len) = 0;

		virtual std::wstring SubstringData(uint32_t offset, uint32_t count) = 0;

		virtual void AppendData(std::wstring data) = 0;
		virtual void InsertData(uint32_t offset, std::wstring data) = 0;
		virtual void DeleteData(uint32_t offset, uint32_t count) = 0;
		virtual void ReplaceData(uint32_t offset, uint32_t count, std::wstring data) = 0;

	public:
		virtual ~CharacterData() = 0;

	};

}