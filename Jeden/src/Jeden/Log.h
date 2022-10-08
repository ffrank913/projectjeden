#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Jeden
{
	class JEDEN_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; };
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; };

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// core log macros
#define JD_CORE_TRACE(...)     ::Jeden::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define JD_CORE_INFO(...)      ::Jeden::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JD_CORE_WARN(...)      ::Jeden::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JD_CORE_ERROR(...)     ::Jeden::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JD_CORE_FATAL(...)     ::Jeden::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// client log macros
#define JD_TRACE(...)          ::Jeden::Log::GetClientLogger()->trace(__VA_ARGS__)
#define JD_INFO(...)           ::Jeden::Log::GetClientLogger()->info(__VA_ARGS__)
#define JD_WARN(...)           ::Jeden::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JD_ERROR(...)          ::Jeden::Log::GetClientLogger()->error(__VA_ARGS__)
#define JD_FATAL(...)          ::Jeden::Log::GetClientLogger()->fatal(__VA_ARGS__)

// if dist build
#define JD_CORE_TRACE(...)
#define JD_CORE_INFO(...)
#define JD_CORE_WARN(...)
#define JD_CORE_ERROR(...)
#define JD_CORE_FATAL(...)