module;

#include <type_traits>

#include <stdexcept>

export module CHV4DTENSOR:CHV4DRESOURCE;

import :CHV4DFORWARD;

export namespace CHV4DTENSOR
{
	template<typename T> 
	void assert_char() 
	{ 
		static_assert (
			std::is_same<T, const char>::value ||
			std::is_same<T, const unsigned char>::value ||
			std::is_same<T, const char*>::value ||
			std::is_same<T, const unsigned char*>::value,
			"Non Character Type.");
	}

	template<typename T> 
	void assert_array() 
	{ 
		static_assert(std::is_same<T, const char* const>::value, "Non Array Type.");
	}

	template<typename T> void assert_precision() 
	{ 
		static_assert(
			std::is_same<T, float>::value || 
			std::is_same<T, double>::value || 
			std::is_same<T, long double>::value, 
			"Non Float type.");
	}

	template<typename T> void assert_integer() 
	{ 
		static_assert(
			std::is_same<T, std::uint8_t>::value ||
			std::is_same<T, std::uint16_t>::value ||
			std::is_same<T, std::uint32_t>::value ||
			std::is_same<T, std::uint64_t>::value ||
			std::is_same<T, std::int8_t>::value ||
			std::is_same<T, std::int16_t>::value ||
			std::is_same<T, std::int32_t>::value ||
			std::is_same<T, std::int64_t>::value,
			"Non Integer type.");
	}	
}