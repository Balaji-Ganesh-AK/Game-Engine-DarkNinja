#pragma once


#define _LOGGER


#include "Window.h"

namespace  Engine
{
	class Application
	{
	public:

		Application();
		virtual  ~Application();


		
		void ShutDown();
		void Run();
	private:
		std::unique_ptr<Window> _window_;
		bool _is_running_ = true;
	};
    Application* CreateApplication();
}



