#pragma once


#define _LOGGER
#define _IMGUI

#include "Window.h"
#include "ComponentsSystem/RenderingSystem/Buffer.h"
#include "ComponentsSystem/RenderingSystem/Shader.h"
#include "ComponentsSystem/RenderingSystem/VertexArray.h"
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
		std::shared_ptr<Shader> _shader_;
		
		std::shared_ptr<VertexArray> _vertex_array_;
		std::shared_ptr<VertexBuffer> _vertex_buffer_;
		std::shared_ptr<IndexBuffer> _index_buffer_;
	
		bool _is_running_ = true;



	};
    Application* CreateApplication();
}



