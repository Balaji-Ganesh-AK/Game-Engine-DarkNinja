#pragma once


#define _LOGGER


#include "Window.h"
#include "Event/WindowEvent.h"
namespace  Engine
{
	

	class Application
	{
	public:

		Application();
		virtual  ~Application();

		void OnEvent(Event& e);
		
		void ShutDown();
		void Run();
	private:

		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> _window_;
		bool _is_running_ = true;
	};
    Application* CreateApplication();
}



