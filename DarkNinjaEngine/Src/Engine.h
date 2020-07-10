#pragma once



#define _IMGUI

#include "Window.h"
#include "ComponentsSystem/RenderingSystem/Shader.h"
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
		inline static Application& Instance() { return *_instance_; }
		inline Window& GetWindow() { return *_window_; }
	private:

		static Application* _instance_;
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowsResize(WindowResizeEvent& e);
		std::unique_ptr<Window> _window_;
		std::unique_ptr<Shader> _shader_;
	
		bool _is_running_ = true;


		unsigned int _vertex_array_, _vertex_buffer_, _index_buffer_;
	};
    Application* CreateApplication();
}



