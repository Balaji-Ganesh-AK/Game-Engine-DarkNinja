// DarkNinjaEngine.cpp : Defines the functions for the static library.


#include "pch.h"
#include "Engine.h"

#include <imgui.h>
#include <glm/glm/ext/matrix_transform.inl>


#include "Logger.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseCodes.h"
#include "ComponentsSystem/RenderingSystem.h"



namespace Engine
{
	Engine::Entity* Balajitest;
	Application* Application::_instance_ = nullptr;
	
	Application::Application()
		:_camera_(-1.888, 1.888, -1, 1),_camera_controller_(_camera_)
	{
		_instance_ = this;
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");

#endif

		
		_window_ = std::unique_ptr<Window>(Window::Create());
		_window_->SetVSync(true);
		_window_->SetEventCallBack(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		std::cout << "Dark Ninja Engine Started!" << std::endl;
		
		Renderer::BeginScene(&_camera_);
		
		
		m_ImGuiLayer = new IMGUI;
		m_ImGuiLayer->Init();
		
		Balajitest = new Engine::Entity("");
#pragma endregion 
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

		_camera_controller_.OnEvent(e);

		
	}


	void Application::ShutDown()
	{
		EntityManager::Instance().End();
		RenderingSystem::Instance()->Shutdown();
		std::cout << "Game Engine Shutting Down" << std::endl;
	}
	
	void Application::Run()
	{
		EntityManager::Instance().Init();
		RenderingSystem::Instance()->Init();
		while(_is_running_)
		{
			TimeStamp::Run();
			//DNE_ENGINE_INFO("FPS {0}", 1/TimeStamp::DeltaTime());
			
			

#pragma region Renderer			
			Renderer::GetInstance().ClearColor();
			Renderer::GetInstance().SetClearColor(_clear_color_);

			
			
#pragma region IMGUILayer
			
			m_ImGuiLayer->Begin();
			EntityManager::Instance().UpdateOnGUI();
			m_ImGuiLayer->End();

#pragma endregion IMGUILayer

			
			//Todo Enable only editor window. 
			_camera_controller_.Update(TimeStamp::DeltaTime());
			DNE_ENGINE_TRACE("Game object count {0}", EntityManager::Instance().GetGameObjectCount());
		    EntityManager::Instance().Update();

		
			
			RenderingSystem::Instance()->Run();
			

			
			
			Renderer::EndScene();
		
			GameLoop();
			
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
		if(e.GetHeight()==0||e.GetWidth()==0)
		{
			//Write function to handle when the windows is minimised;
			//As of now this is not required in the engine.
		}


		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return false;
	}
}
