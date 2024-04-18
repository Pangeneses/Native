module;

#include <string>

module CHV4DXML:CDOMException;

import :CHV4DFORWARD;
import :CHV4DRESOURCE;

namespace CHV4DXML
{
	CDOMException::CDOMException(std::wstring message, std::wstring name) {}

	std::wstring CDOMException::name() { return nullptr; }

	std::wstring CDOMException::message() { return nullptr; }

	uint16_t CDOMException::code() { return 0; }

}