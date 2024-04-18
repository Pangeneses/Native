module;

#include <string>


export module CHV4DXML:CDOMException;

export namespace CHV4DXML
{
	class CDOMException
	{
	public:
		CDOMException(std::wstring message = L"", std::wstring name = L"Error");

	public:
		std::wstring name();

		std::wstring message();

		uint16_t code();

	};

}
