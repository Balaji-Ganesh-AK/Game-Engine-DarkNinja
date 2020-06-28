#pragma once


#define _LOGGER


#include "PlatformSpecific/Windows/WindowsWindow.h"

namespace  Engine
{
	class Application
	{
	public:

		Application();
		virtual  ~Application();

		WindowProperties* pror;

		
		void ShutDown();
		void Run();
	private:
	};
    Application* CreateApplication();
}



