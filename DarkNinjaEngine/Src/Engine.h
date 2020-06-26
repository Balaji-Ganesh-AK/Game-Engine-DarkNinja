#pragma once



//#define _LOGGER
namespace  Engine
{
	class Application
	{
	public:

		Application();
		virtual  ~Application();


		
		void ShutDown();
		void Run();
	};
    Application* CreateApplication();
}



