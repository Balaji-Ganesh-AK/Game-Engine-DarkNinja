#pragma once
#include "Logger.h"


#include <cstdlib>
#include <crtdbg.h>
#include <stdlib.h> 
#include "Engine.h"



extern  Engine::Application* Engine::CreateApplication();

int main(int argc, char** argv)
{
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld);
	
	{
	//Engine::Application* app = Engine::CreateApplication();
	SmartPointer<Engine::Application> app= Engine::CreateApplication();
#ifdef _LOGGER
	Engine::Logger::GetClientLogger()->error("Client Started");
#endif
	app.GetData()->Run();
	_CrtMemCheckpoint(&sNew);
	
	}

#ifdef _DEBUG

	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		
		_CrtMemDumpStatistics(&sDiff);
		
		_CrtMemDumpAllObjectsSince(&sOld);
	
		_CrtDumpMemoryLeaks();
	}
#endif

}

