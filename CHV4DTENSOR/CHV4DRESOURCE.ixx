module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DRESOURCE;

import :CHV4DFORWARD;

export namespace CHV4DTENSOR
{
	template<typename T> void assert_char() { static_assert(false, "Non Float type."); }

	template<> void assert_char<const char>() {}
	template<> void assert_char<const unsigned char>() {}
	template<> void assert_char<const char*>() {}
	template<> void assert_char<const unsigned char*>() {}

	template<typename T> void assert_array() { static_assert(false, "Non Float type."); }

	template<> void assert_array<const char* const>() {}

	template<typename T> void assert_precision() { static_assert(false, "Non Float type."); }

	template<> void assert_precision<float>() {}
	template<> void assert_precision<double>() {}
	template<> void assert_precision<long double>() {}

	template<typename T> void assert_integer() { static_assert(false, "Non Integer type."); }

	template<> void assert_integer <CHV4DINTEGER>() {}

	template<> void assert_integer <std::uint8_t>() {}
	template<> void assert_integer <std::uint16_t>() {}
	template<> void assert_integer <std::uint32_t>() {}
	template<> void assert_integer <std::uint64_t>() {}

	template<> void assert_integer <std::int8_t>() {}
	template<> void assert_integer <std::int16_t>() {}
	template<> void assert_integer <std::int32_t>() {}
	template<> void assert_integer <std::int64_t>() {}

}