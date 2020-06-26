#pragma once
#include "Engine.h"
#include "Logger.h"

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>




extern  Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	
	{
	//Engine::Application* app = Engine::CreateApplication();
	SmartPointer<Engine::Application> app= Engine::CreateApplication();
	app.GetData()->Run();
#ifdef _LOGGER
	Engine::Logger::GetClientLogger()->error("Client Started");
#endif
	
	
	}

#ifdef _DEBUG

	_CrtDumpMemoryLeaks();
#endif

}

