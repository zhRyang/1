#pragma once

#include <memory>
#include "DAQSysBenchmarkCore/Core/PlatformDetection.h"

#ifdef NMROS_DEBUG
	#if defined(NMROS_PLATFORM_WINDOWS)
		#define NMROS_DEBUGBREAK() __debugbreak()
	#elif defined(NMROS_PLATFORM_LINUX)
		#include <signal.h>
		#define NMROS_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
		#define NMROS_ENABLE_ASSERTS
#else
		#define NMROS_DEBUGBREAK()
#endif

#ifdef NMROS_RELEASE
		#define NMROS_ENABLE_PROFILE
#endif

#define NMROS_EXPAND_MACRO(x) x
#define NMROS_STRINGIFY_MACRO(x) #x

namespace nmros
{

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}


	template<typename T>
	using Ref = std::shared_ptr<T>;

	template <typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}


#include "DAQSysBenchmarkCore/Core/Log.h"
#include "DAQSysBenchmarkCore/Core/Assert.h"
