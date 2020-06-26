#pragma once

#include "Engine.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
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

