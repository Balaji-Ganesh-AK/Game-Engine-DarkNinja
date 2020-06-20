// DarkNinjaEngine.cpp : Defines the functions for the static library.
//

#include <iostream>
#include "Engine.h"

namespace Engine
{
	Application::Application()
	{
		std::cout << "Gaming Engine Started!" << std::endl;
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
		while(true)
		{}
	}
}
