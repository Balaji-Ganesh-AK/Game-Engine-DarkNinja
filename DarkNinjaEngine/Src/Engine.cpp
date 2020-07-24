// DarkNinjaEngine.cpp : Defines the functions for the static library.


#include "pch.h"
#include "Engine.h"

#include <imgui.h>

#include "Logger.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseCodes.h"



namespace Engine
{

	Application* Application::_instance_ = nullptr;
	
	Application::Application()
		:_camera_(-1,1,-1,1)
	{
		_instance_ = this;
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");

#endif

		
		_window_ = std::unique_ptr<Window>(Window::Create());
		_window_->SetVSync(true);
		_window_->SetEventCallBack(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		std::cout << "Dark Ninja Engine Started!" << std::endl;
		m_ImGuiLayer = new IMGUI;
		m_ImGuiLayer->Init();
#ifdef  _IMGUI
	
#endif


		_vertex_array_.reset(VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f,-.5f, 0.0f,    1.0f, 1.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f,    0.0f, 1.0f, 0.0f, 1.0f

		};
		std::shared_ptr<VertexBuffer> _vertex_buffer_;
		_vertex_buffer_.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		{
			BufferLayout layout = {
				{ShaderDataType::FVec3, "a_Position"},
				{ShaderDataType::FVec4, "a_Color"}

			};
			_vertex_buffer_->SetLayout(layout);
		}

		_vertex_array_->AddVertexBuffer(_vertex_buffer_);


		uint32_t indices[3] = { 0,1,2 };


		std::shared_ptr<IndexBuffer> _index_buffer_;
		_index_buffer_.reset(IndexBuffer::Create(indices, std::size(indices)));
		_vertex_array_->SetIndexBuffer(_index_buffer_);

		std::string vertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;
		
		out vec3 v_Position;
		out vec4 v_Color;
		void main()
		{
			v_Position = a_Position;
		    v_Color =a_Color;
			gl_Position = u_ViewProjection*u_Transform*vec4(a_Position,1.0);
		}

		)";

		std::string fragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;
		in vec4 v_Color;
		void main()
		{
			o_Color = vec4(v_Position*0.8 +.5,1.0);
		    o_Color = v_Color;
		}

		)";
		
		_shader_.reset(new Shader(vertexSrc,fragmentSrc));



		//square
		float verticessq[3 * 4] = {
		-0.5f,-.5f, 0.0f,    
		0.5f, -0.5f, 0.0f,   
		0.5f, 0.5f, 0.0f,    
		-0.5f, 0.5f, 0.0f

		};
		
		_vertex_array_square_.reset(VertexArray::Create());

		std::shared_ptr<VertexBuffer> _vertex_buffer_square;
		_vertex_buffer_square.reset(VertexBuffer::Create(verticessq, sizeof(verticessq)));

		{
			BufferLayout layoutsquare = {
				{ShaderDataType::FVec3, "a_Position"},

			};
			_vertex_buffer_square->SetLayout(layoutsquare);
		}
		_vertex_array_square_->AddVertexBuffer(_vertex_buffer_square);

		uint32_t indicessquare[6] = { 0,1,2 ,2,3,0};


		std::shared_ptr<IndexBuffer> _index_buffer_square;
		_index_buffer_square.reset(IndexBuffer::Create(indicessquare, std::size(indicessquare)));
		_vertex_array_square_->SetIndexBuffer(_index_buffer_square);


		std::string vertexSrcSquare = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;
		
		out vec3 v_Position;

		void main()
		{
			v_Position = a_Position;
			gl_Position = u_ViewProjection*u_Transform*vec4(a_Position,1.0);
		}

		)";

		std::string fragmentSrcSquare = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;

		void main()
		{
			o_Color = vec4(0.2,0.3,0.8,1.0);

		}

		)";

		_shader_square_.reset(new Shader(vertexSrcSquare, fragmentSrcSquare));


		
	}

	Application::~Application()
	{
	}

	void Application::OnEvent(Event& e)
	{
#ifdef _LOGGER
		//DNE_ENGINE_TRACE("{0}",e.ToString());
#endif
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(DNE_BIND_SINGLE_EVENT(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(DNE_BIND_SINGLE_EVENT(Application::OnWindowsResize));
#ifdef _IMGUI
		
	
#endif
	}


	void Application::ShutDown()
	{
		std::cout << "Game Engine Shutting Down" << std::endl;
	}
	
	void Application::Run()
	{
		
		while(_is_running_)
		{
			TimeStamp::Run();
			//DNE_ENGINE_INFO("FPS {0}", 1/TimeStamp::DeltaTime());
			
			
#pragma region Renderer
			Renderer::BeginScene(_camera_);
			Renderer::GetInstance().ClearColor();
			Renderer::GetInstance().SetClearColor(_clear_color_);


		
			
			Renderer::Submit(_vertex_array_square_,_shader_square_);
	
			Renderer::Submit(_vertex_array_,_shader_);
			
			
			Renderer::EndScene();
#pragma endregion  Renderer


			m_ImGuiLayer->Begin();
			EntityManager::Instance().UpdateOnGUI();
			m_ImGuiLayer->End();
		    EntityManager::Instance().Update();
			
			if(Input::IsKeyPressed(Key::Space))
			{
				
#ifdef _LOGGER
			  DNE_ENGINE_TRACE("Space is pressed ");
			  _camera_position_.x -= .004f;
			  _camera_position_.y += .004f;
			  _camera_position_.z -= .004f;
			  _camera_position_.w += .004f;
			
    			 _camera_.CameraMove(_camera_position_.x, _camera_position_.y, 
				  _camera_position_.z, _camera_position_.w);
				
#endif
			}
			if(Input::IsMousePressed(Mouse::ButtonRight))
			{
#ifdef _LOGGER
				DNE_ENGINE_TRACE("Mouse button is pressed ");
				
#endif
			}
			
			_window_->Update();
		
		}

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{

		_is_running_ = false;
		return true;
	}

	bool Application::OnWindowsResize(WindowResizeEvent& e)
	{
#ifdef _LOGGER
		//DNE_ENGINE_INFO("Windows Resize Event");
#endif
		return true;
	}
}
