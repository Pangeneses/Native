module;

#include <string>

export module CHV4DXML:ProcessingInstruction;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

import :CharacterData;

export namespace CHV4DXML
{
	class ProcessingInstruction : public CharacterData
	{
	public:
		ProcessingInstruction() = default;

	public:
		virtual std::wstring target() = 0;

	public:
		virtual ~ProcessingInstruction() = 0;

	};

}