// DarkNinjaEngine.cpp : Defines the functions for the static library.


#include "pch.h"
#include "Engine.h"

#include <imgui.h>
#include <glm/glm/ext/matrix_transform.inl>


#include "Logger.h"
#include "ComponentsSystem/Entity.h"
#include "ComponentsSystem/RenderingSystem/ImguiRenderer.h"
#include "Input.h"
#include "KeyCodes.h"
#include "MouseCodes.h"



namespace Engine
{
	Engine::Entity* Balajitest;
	Application* Application::_instance_ = nullptr;
	
	Application::Application()
		:_camera_(-1.6,1.6,-1.6,1.6),_camera_controller_(_camera_)
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
		
		Renderer::BeginScene(&_camera_);
		
		
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

#pragma region texture stuff
		std::string textureVertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec2 a_TexCord;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;
		
		out vec3 v_Position;
		out vec2 v_TexCord;
		void main()
		{
			v_Position = a_Position;
		v_TexCord = a_TexCord;
			gl_Position = u_ViewProjection*u_Transform*vec4(a_Position,1.0);
		}

		)";

		std::string textureFragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;
		in vec2 v_TexCord;

		uniform sampler2D u_Texture;
		void main()
		{
		
			o_Color = texture(u_Texture, v_TexCord);
		}

		)";

		//_texture_shader_.reset(new Shader(textureVertexSrc, textureFragmentSrc));
		//_texture_test_ = Texture2D::Create("Resources/Assets/Textures/Checkerboard.png");

		//_texture_shader_->Bind();
	//	_texture_shader_->UniformIntUpload("u_Texture", 0);
	//

		Balajitest = new Engine::Entity("");
#pragma endregion 
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

		_camera_controller_.OnEvent(e);

		
	}


	void Application::ShutDown()
	{
		std::cout << "Game Engine Shutting Down" << std::endl;
	}
	
	void Application::Run()
	{
		EntityManager::Instance().Init();
		while(_is_running_)
		{
			TimeStamp::Run();
			//DNE_ENGINE_INFO("FPS {0}", 1/TimeStamp::DeltaTime());
			
			
#pragma region Renderer
			
			Renderer::GetInstance().ClearColor();
			Renderer::GetInstance().SetClearColor(_clear_color_);

		
			
			//if (Input::IsKeyPressed(Key::W))
			//{
			////	pos.x += 1 * TimeStamp::DeltaTime();
			//}
		
			//_texture_test_->Bind();
			//Renderer::Submit(_vertex_array_square_,_texture_shader_);
		//	glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos);
			//Renderer::Submit(_vertex_array_,_shader_, transform);
			
			
			
#pragma endregion  Renderer

			
			m_ImGuiLayer->Begin();
			EntityManager::Instance().UpdateOnGUI();
			m_ImGuiLayer->End();
		    EntityManager::Instance().Update();
			Renderer::EndScene();
			_camera_controller_.Update(TimeStamp::DeltaTime());
			
		
			GameLoop();
			
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
		if(e.GetHeight()==0||e.GetWidth()==0)
		{
			//Write function to handle when the windows is minimised;
			//As of now this is not required in the engine.
		}


		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());
		return false;
	}
}
