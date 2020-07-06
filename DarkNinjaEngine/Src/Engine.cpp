// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "Engine.h"

#include <glad/glad.h>



#include "Logger.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"


namespace Engine
{

	Application* Application::_instance_ = nullptr;
	
	Application::Application()
	{
		_instance_ = this;
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");

#endif

		
		_window_ = std::unique_ptr<Window>(Window::Create());
		_window_->SetEventCallBack(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		std::cout << "Dark Ninja Engine Started!" << std::endl;

		IMGUI::Instance().Init();
		
#ifdef _LOGGER
		
		/*DNE_ENGINE_TRACE("Game Object name!", test->GetName());*/

#endif


	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
#ifdef _LOGGER
		//DNE_ENGINE_TRACE("{0}",e.ToString());
#endif
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(DNE_BIND_SINGLE_EVENT(Application::OnWindowClose));

		IMGUI::Instance().OnEvent(e);
	}


	void Application::ShutDown()
	{
		std::cout << "Game Engine Shutting Down" << std::endl;
	}
	
	void Application::Run()
	{
		
		while(_is_running_)
		{
			
			//EntityManager::Instance().Update();
			
			glClear(GL_COLOR_BUFFER_BIT);
			IMGUI::Instance().Update();
			_window_->Update();
		
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{

		_is_running_ = false;
		return true;
	}
}
