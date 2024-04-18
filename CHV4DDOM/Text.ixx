module;

#include <string>

export module CHV4DXML:Text;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CharacterData;

export namespace CHV4DXML
{
	// include: Slottable, 

	class Text : public CharacterData
	{
	public:
		Text() = default; // Text(std::wstring data = L"");

	public:
		virtual IText splitText(uint32_t offset) = 0;

		virtual std::wstring wholeText() = 0;

	public:
		virtual ~Text() = 0;

	};

}