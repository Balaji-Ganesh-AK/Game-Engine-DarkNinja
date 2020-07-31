#pragma once


#define _LOGGER
#define _IMGUI

#include "Window.h"
#include "ComponentsSystem/CameraController.h"
#include "ComponentsSystem/RenderingSystem/Buffer.h"
#include "ComponentsSystem/RenderingSystem/Camera.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"
#include "ComponentsSystem/RenderingSystem/Shader.h"
#include "ComponentsSystem/RenderingSystem/VertexArray.h"
#include "ComponentsSystem/RenderingSystem/Renderer.h"
#include "ComponentsSystem/RenderingSystem/Texture.h"
#include "Event/WindowEvent.h"
#include "Utlis/TimeStamp.h"
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
		//Override this function to handle the client's game loop code.
		virtual void GameLoop() =0;
		inline static Application& Instance() { return *_instance_; }
		inline Window& GetWindow() { return *_window_; }
	private:

		static Application* _instance_;
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowsResize(WindowResizeEvent& e);

		vec4 _clear_color_ = vec4(0.1, 0.1, 0.1, 0.1);
		
		std::unique_ptr<Window> _window_;
		std::shared_ptr<Shader> _shader_;
		std::shared_ptr<Shader> _shader_square_;
		std::shared_ptr<Shader> _texture_shader_;
		
		std::shared_ptr<VertexArray> _vertex_array_;

		std::shared_ptr<VertexArray> _vertex_array_square_;

		std::shared_ptr<Texture2D> _texture_test_;

		glm::vec3 pos;


		
		IMGUI* m_ImGuiLayer;
		
		bool _is_running_ = true;

		OrthographicCamera _camera_;
	
		vec4 _camera_position_ = vec4(-1,1,-1,1);

		CameraController _camera_controller_;
	};
    Application* CreateApplication();
}



