#pragma once
#include "DAQSysBenchmarkCore/Core/Base.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"

//NOTE This ignore all warning raised inside External headers
#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)


namespace nmros
{
	class  Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger();
		static Ref<spdlog::logger>& GetClientLogger();

	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

#ifndef NMROS_RELEASE_VERSION

//Core log macros
#define NMROS_CORE_TRACE(...)		::nmros::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define NMROS_CORE_INFO(...)		::nmros::Log::GetCoreLogger()->info(__VA_ARGS__)
#define NMROS_CORE_DEBUG(...)		::nmros::Log::GetCoreLogger()->debug(__VA_ARGS__)
#define NMROS_CORE_WARN(...)		::nmros::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define NMROS_CORE_ERROR(...)		::nmros::Log::GetCoreLogger()->error(__VA_ARGS__)
#define NMROS_CORE_FATAL(...)		::nmros::Log::GetCoreLogger()->critical(__VA_ARGS__)


//Client log macros
#define NMROS_APP_TRACE(...)		::nmros::Log::GetClientLogger()->trace(__VA_ARGS__)
#define NMROS_APP_INFO(...)			::nmros::Log::GetClientLogger()->info(__VA_ARGS__)
#define NMROS_APP_DEBUG(...)		::nmros::Log::GetClientLogger()->debug(__VA_ARGS__)
#define NMROS_APP_WARN(...)			::nmros::Log::GetClientLogger()->warn(__VA_ARGS__)
#define NMROS_APP_ERROR(...)		::nmros::Log::GetClientLogger()->error(__VA_ARGS__)
#define NMROS_APP_FATAL(...)		::nmros::Log::GetClientLogger()->critical(__VA_ARGS__)
#else
//Core log macros
#define NMROS_CORE_TRACE(...)		
#define NMROS_CORE_INFO(...)		
#define NMROS_CORE_WARN(...)		
#define NMROS_CORE_ERROR(...)		
#define NMROS_CORE_FATAL(...)		

//Client log macros
#define NMROS_APP_TRACE(...)	
#define NMROS_APP_INFO(...)	
#define NMROS_APP_DEBUG(...)	
#define NMROS_APP_WARN(...)	
#define NMROS_APP_ERROR(...)	
#define NMROS_APP_FATAL(...)	

#endif



