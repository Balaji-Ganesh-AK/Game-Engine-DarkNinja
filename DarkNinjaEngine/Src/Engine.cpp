// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "Engine.h"
#include "Logger.h"

#include "glfw/include/GLFW/glfw3.h"


namespace Engine
{
	Application::Application()
	{
		
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");

#endif

		_window_ = std::unique_ptr<Window>(Window::Create());
		_window_->SetEventCallBack(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		std::cout << "Dark Ninja Engine Started!" << std::endl;



	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
#ifdef _LOGGER
		DNE_ENGINE_TRACE("{0}",e.ToString());
#endif
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
	}


	void Application::ShutDown()
	{
		std::cout << "Gaming Engine Shutting Down" << std::endl;
	}

	void Application::Run()
	{
	
		while(_is_running_)
		{
			glClearColor(0, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window_->Update();
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{

		_is_running_ = false;
		return true;
	}
}
