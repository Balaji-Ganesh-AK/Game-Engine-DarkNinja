// DarkNinjaEngine.cpp : Defines the functions for the static library.


#include "pch.h"
#include "Engine.h"
#include <glad/glad.h>
#include "Logger.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseCodes.h"


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
#ifdef  _IMGUI
		IMGUI::Instance().Init();
#endif
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
		dispatcher.Dispatch<WindowResizeEvent>(DNE_BIND_SINGLE_EVENT(Application::OnWindowsResize));
#ifdef _IMGUI
		IMGUI::Instance().OnEvent(e);
#endif
	}


	void Application::ShutDown()
	{
		std::cout << "Game Engine Shutting Down" << std::endl;
	}
	
	void Application::Run()
	{
		
		while(_is_running_)
		{
			
			EntityManager::Instance().Update();
			
			glClear(GL_COLOR_BUFFER_BIT);
			
			if(Input::IsKeyPressed(Key::Space))
#ifdef _LOGGER
			  DNE_ENGINE_TRACE("Space is pressed ");
#endif
			if(Input::IsMousePressed(Mouse::ButtonRight))
			{
#ifdef _LOGGER
				DNE_ENGINE_TRACE("Mouse button is pressed ");
#endif
			}

#ifdef  _IMGUI
			IMGUI::Instance().Update();
#endif
			
			_window_->Update();
		
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{

		_is_running_ = false;
		return true;
	}

	bool Application::OnWindowsResize(WindowResizeEvent& e)
	{
#ifdef _LOGGER
		DNE_ENGINE_INFO("Windows Resize Event");
#endif
		return true;
	}
}
