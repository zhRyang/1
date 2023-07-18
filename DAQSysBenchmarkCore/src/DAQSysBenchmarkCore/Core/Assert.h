#include "DAQSysBenchmarkCore/Core/Base.h"
#include "DAQSysBenchmarkCore/Core/Log.h"
#include <filesystem>

#ifdef NMROS_ENABLE_ASSERTS

	// Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
	// provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
	#define NMROS_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { NMROS##type##ERROR(msg, __VA_ARGS__); NMROS_DEBUGBREAK(); } }
	#define NMROS_INTERNAL_ASSERT_WITH_MSG(type, check, ...) NMROS_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
	#define NMROS_INTERNAL_ASSERT_NO_MSG(type, check) NMROS_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", NMROS_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)


	#define NMROS_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
	#define NMROS_INTERNAL_ASSERT_GET_MACRO(...) NMROS_EXPAND_MACRO( NMROS_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, NMROS_INTERNAL_ASSERT_WITH_MSG, NMROS_INTERNAL_ASSERT_NO_MSG) )

	//Currently accepts at least the condition one additional parameter being optional
	#define NMROS_ASSERT(...) NMROS_EXPAND_MACRO(NMROS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_APP_, __VA_ARGS__))
	#define NMROS_CORE_ASSERT(...)  NMROS_EXPAND_MACRO(NMROS_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__))
#else
	#define NMROS_ASSERT(x, ...) x
	#define NMROS_CORE_ASSERT(x, ...) x
#endif
