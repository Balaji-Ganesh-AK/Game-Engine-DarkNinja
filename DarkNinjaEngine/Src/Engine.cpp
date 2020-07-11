// DarkNinjaEngine.cpp : Defines the functions for the static library.


#include "pch.h"
#include "Engine.h"
#include <glad/glad.h>
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
	{
		_instance_ = this;
#ifdef _LOGGER
		Logger::Init();
		DNE_ENGINE_TRACE("Started!");

#endif

		
		_window_ = std::unique_ptr<Window>(Window::Create());
		_window_->SetEventCallBack(std::bind(&Application::OnEvent, this, std::placeholders::_1));
		std::cout << "Dark Ninja Engine Started!" << std::endl;
#ifdef  _IMGUI
		IMGUI::Instance().Init();
#endif
#ifdef _LOGGER
		
		/*DNE_ENGINE_TRACE("Game Object name!", test->GetName());*/

#endif

		glGenVertexArrays(1, &_vertex_array_);
		glBindVertexArray(_vertex_array_);



		float vertices[3 * 3] = {
			-0.5f,-.5f,0.0f,
			0.5f, -0.5f, 0.0f,
			0.0f, 0.5f, 0.0f

		};

		_vertex_buffer_.reset(VertexBuffer::Create(vertices, sizeof(vertices)));


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		//glGenBuffers(1, &_index_buffer_);
		//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _index_buffer_);
		uint32_t indices[3] = { 0,1,2 };


		_index_buffer__test.reset(IndexBuffer::Create(indices,sizeof(indices)/ sizeof(uint32_t)));
	
		//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		std::string vertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		out vec3 v_Position;
		void main()
		{
			v_Position = a_Position;
			gl_Position = vec4(a_Position,1.0);
		}

		)";

		std::string fragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;
		void main()
		{
			o_Color = vec4(v_Position*0.8 +.5,1.0);
		}

		)";
		
		_shader_.reset(new Shader(vertexSrc,fragmentSrc));
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
		IMGUI::Instance().OnEvent(e);
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
			
			
			glClear(GL_COLOR_BUFFER_BIT);
			_shader_->Bind();
			glBindVertexArray(_vertex_array_);
			glDrawElements(GL_TRIANGLES,_index_buffer__test->GetCount(), GL_UNSIGNED_INT, nullptr);



		
			EntityManager::Instance().Update();
			
			if(Input::IsKeyPressed(Key::Space))
#ifdef _LOGGER
			  DNE_ENGINE_TRACE("Space is pressed ");
#endif
			if(Input::IsMousePressed(Mouse::ButtonRight))
			{
#ifdef _LOGGER
				DNE_ENGINE_TRACE("Mouse button is pressed ");
#endif
			}

#ifdef  _IMGUI
			IMGUI::Instance().Update();
#endif
			
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
