module;

#include <stdexcept>

export module CHV4DTENSOR:CHV4DRESOURCE;

import :CHV4DFORWARD;

export namespace CHV4DTENSOR
{
	template<typename T> void assert_float() { static_assert(false, "Non Float type."); }

	template<> void assert_float<float>() {}
	template<> void assert_float<double>() {}
	template<> void assert_float<long double>() {}

	template<typename T> void assert_integer() { static_assert(false, "Non Integer type."); }

	template<> void assert_integer <MaxInteger>() {}

	template<> void assert_integer <std::uint8_t>() {}
	template<> void assert_integer <std::uint16_t>() {}
	template<> void assert_integer <std::uint32_t>() {}
	template<> void assert_integer <std::uint64_t>() {}

	template<> void assert_integer <std::int8_t>() {}
	template<> void assert_integer <std::int16_t>() {}
	template<> void assert_integer <std::int32_t>() {}
	template<> void assert_integer <std::int64_t>() {}

}