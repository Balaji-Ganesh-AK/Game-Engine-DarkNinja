#pragma once

#include "Engine.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include "Utlis/SmartPointer.h"
#include "Utlis/Helper.h"


namespace Engine
{
	
class Logger
{
public:
	static void Init();

	inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_engine_logger; }
	inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_client_logger; }

	
private :
	static std::shared_ptr<spdlog::logger> s_engine_logger;
	static std::shared_ptr<spdlog::logger> s_client_logger;

};
}

#define DNE_ENGINE_TRACE(...) ::Engine::Logger::GetEngineLogger()->trace(__VA_ARGS__)
#define DNE_ENGINE_ERROR(...) ::Engine::Logger::GetEngineLogger()->error(__VA_ARGS__)
#define DNE_ENGINE_WARN(...) ::Engine::Logger::GetEngineLogger()->warn(__VA_ARGS__)
#define DNE_ENGINE_INFO(...) ::Engine::Logger::GetEngineLogger()->info(__VA_ARGS__)
#define DNE_ENGINE_CRITICAL(...) ::Engine::Logger::GetEngineLogger()->critical(__VA_ARGS__)


#define DNE_CLIENT_TRACE(...) ::Engine::Logger::GetClientLogger()->trace(__VA_ARGS__)
#define DNE_CLIENT_ERROR(...) ::Engine::Logger::GetClientLogger()->error(__VA_ARGS__)
#define DNE_CLIENT_WARN(...) ::Engine::Logger::GetClientLogger()->warn(__VA_ARGS__)
#define DNE_CLIENT_INFO(...) ::Engine::Logger::GetClientLogger()->info(__VA_ARGS__)
#define DNE_CLIENT_CRITICAL(...) ::Engine::Logger::GetClientLogger()->critical(__VA_ARGS__)


