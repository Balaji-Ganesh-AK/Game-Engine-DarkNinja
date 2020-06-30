#include "pch.h"
#include "Logger.h"

namespace Engine
{
	std::shared_ptr<spdlog::logger> Logger::s_client_logger;
	std::shared_ptr<spdlog::logger> Logger::s_engine_logger;


	void Logger::Init()
	{
		
		PrintToOutput("Logger Started!");
		spdlog::set_pattern("%^[%T]%n:%v%$");

		s_engine_logger = spdlog::stdout_color_mt("Engine");
		s_engine_logger->set_level(spdlog::level::trace);


		s_client_logger = spdlog::stdout_color_mt("logger");
		s_client_logger->set_level(spdlog::level::trace);
		
	}
}
