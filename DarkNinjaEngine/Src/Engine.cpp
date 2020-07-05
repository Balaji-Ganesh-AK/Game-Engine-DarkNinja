// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"

#include "Engine.h"


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
		dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::OnWindowClose, this, std::placeholders::_1));
	}


	void Application::ShutDown()
	{
		std::cout << "Game Engine Shutting Down" << std::endl;
	}

	void Application::Run()
	{
		IMGUI::Instance().Init();
		while(_is_running_)
		{

			
			//EntityManager::Instance().Update();
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
