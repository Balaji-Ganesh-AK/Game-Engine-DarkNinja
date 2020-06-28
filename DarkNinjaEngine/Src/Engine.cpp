// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "Engine.h"
#include "Logger.h"
#include "Event/WindowEvent.h"
#include "glfw/include/GLFW/glfw3.h"


namespace Engine
{
	Application::Application()
	{

		/*_window_ = Window::Create();*/
		std::cout << "Dark Ninja Engine Started!" << std::endl;
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");
		
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
	/*	
		while(_is_running_)
		{
			
			_window_->Update();
		}*/

	}
}
