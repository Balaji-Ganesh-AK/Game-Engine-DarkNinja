#pragma once
#include "Logger.h"


#include <cstdlib>
#include <crtdbg.h>
#include <stdlib.h> 
#include "Engine.h"



extern  Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	
	
	{
	//Engine::Application* app = Engine::CreateApplication();
	SmartPointer<Engine::Application> app= Engine::CreateApplication();
#ifdef _LOGGER
	Engine::Logger::GetClientLogger()->error("Client Started");
#endif
	app.GetData()->Run();
	app.GetData()->ShutDown();
	
	}


}

