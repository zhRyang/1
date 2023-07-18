#include "Instrumentor.h"
#include "Timer.h"

#if defined(NMROS_PROFILE_ON)
// Resolve which function signature macro will be used. Note that this only
// is resolved when the (pre)compiler starts, so the syntax highlighting
// could mark the wrong one in your editor!
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) ||    \
    (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#define NMROS_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
#define NMROS_FUNC_SIG __PRETTY_FUNCTION__
#elif (defined(__FUNCSIG__) || (_MSC_VER))
#define NMROS_FUNC_SIG __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) ||              \
    (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#define NMROS_FUNC_SIG __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define NMROS_FUNC_SIG __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define NMROS_FUNC_SIG __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define NMROS_FUNC_SIG __func__
#else
#define NMROS_FUNC_SIG "NMROS_FUNC_SIG unknown!"
#endif

#define NMROS_PROFILE_BEGIN_SESSION(name, filePath)                            \
  ::nmros::Instrumentor::Get().BeginSession(name, filePath)
#define NMROS_PROFILE_END_SESSION() ::nmros::Instrumentor::Get().EndSession()
#define NMROS_PROFILE_SCOPE(name)                                              \
  constexpr auto fixedName =                                                   \
      ::nmros::InstrumentorUtils::CleanupOutputString(name, "__cdecl ");       \
  ::nmros::InstrumentationTimer timer##__LINE__(fixedName.Data)
#define NMROS_PROFILE_FUNCTION() NMROS_PROFILE_SCOPE(NMROS_FUNC_SIG)
#else
#define NMROS_PROFILE_BEGIN_SESSION(name, filePath)
#define NMROS_PROFILE_END_SESSION()
#define NMROS_PROFILE_SCOPE(name)
#define NMROS_PROFILE_FUNCTION()
#endif
