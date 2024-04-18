module;

#include <string>
#include <vector>

export module CHV4DXML:DOMTokenList;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

export namespace CHV4DXML
{
	class DOMTokenList
	{
	public:
		DOMTokenList() = default;

	public:
		virtual uint32_t Length() = 0;

		virtual std::wstring Item(uint32_t index) = 0;

		virtual bool Contains(std::wstring token) = 0;

		virtual void Add(std::vector<std::wstring> tokens) = 0;

		virtual void Remove(std::vector<std::wstring> tokens) = 0;

		virtual bool Toggle(std::wstring token) = 0;
		virtual bool Toggle(std::wstring token, bool force) = 0;

		virtual bool Replace(std::wstring token, std::wstring newToken) = 0;

		virtual bool Supports(std::wstring token) = 0;

		virtual std::wstring Value() = 0;

		virtual std::vector<std::wstring>::iterator Tokens() = 0;

		virtual std::vector<std::wstring>::iterator Begin() = 0;

		virtual std::vector<std::wstring>::iterator End() = 0;

	public:
		virtual ~DOMTokenList() = 0;

	};

}