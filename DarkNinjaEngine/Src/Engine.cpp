// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include <iostream>
#include "Engine.h"

#include "Logger.h"
#include "Event/WindowEvent.h"

namespace Engine
{
	Application::Application()
	{
		std::cout << "Dark Ninja Engine Started!" << std::endl;
#ifdef _LOGGER
		Logger::Init();
		Logger::GetEngineLogger()->warn("Started!");
#endif


	}

	Application::~Application()
	{
	}


	void Application::ShutDown()
	{
		std::cout << "Gaming Engine Shutting Down" << std::endl;
	}

	void Application::Run()
	{
		WindowCreateEvent Window(1000, 1000);
		if (Window.IsInEventCategory(EventCategoryWindow))
		{
#ifdef _LOGGER
			Logger::GetEngineLogger()->warn("Window Event");
#endif
		}

		if (Window.IsInEventCategory(EventCategoryKeyboard))
		{
#ifdef _LOGGER
			Logger::GetEngineLogger()->warn("Keyboard Event");
#endif
		}

	}
}
