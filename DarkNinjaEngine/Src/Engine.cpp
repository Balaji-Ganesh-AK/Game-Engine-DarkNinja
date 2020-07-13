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

	static GLenum ShaderDataTypeToOpenGlType(ShaderDataType Type)
	{
		switch (Type)
		{
		
		case ShaderDataType::FVec: return GL_FLOAT;
		case ShaderDataType::FVec2:return GL_FLOAT;
		case ShaderDataType::FVec3:return GL_FLOAT;
		case ShaderDataType::FVec4:return GL_FLOAT;
		case ShaderDataType::Mat3: return GL_FLOAT;
		case ShaderDataType::Mat4: return GL_FLOAT;
		case ShaderDataType::Int:  return GL_INT;
		case ShaderDataType::Bool: return GL_BOOL;
		}


#ifdef _LOGGER
		DNE_SIMPLE_ASSERT(false, "Unknown Data type");
#endif
		return 0;
	}
	
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



		float vertices[3 * 7] = {
			-0.5f,-.5f, 0.0f,    1.0f, 1.0f, 0.0f, 1.0f,
			0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f, 1.0f,
			0.0f, 0.5f, 0.0f,    0.0f, 1.0f, 0.0f, 1.0f

		};

		_vertex_buffer_.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		uint32_t indices[3] = { 0,1,2 };


		_index_buffer_.reset(IndexBuffer::Create(indices,std::size(indices)));

		{
			BufferLayout layout = {
				{ShaderDataType::FVec3, "a_Position"},
				{ShaderDataType::FVec4, "a_Color"}

			};
			_vertex_buffer_->SetLayout(layout);
		}
		
		uint32_t index = 0;
		const auto& layout = _vertex_buffer_->GetLayout();
		for(auto const &element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGlType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				reinterpret_cast<const void*>(element.Offset));
			index++;
		}
	
	
		std::string vertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;
		out vec3 v_Position;
		out vec4 v_Color;
		void main()
		{
			v_Position = a_Position;
		    v_Color =a_Color;
			gl_Position = vec4(a_Position,1.0);
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
			glClearColor(0.1,0.1,0.1,0.1);
			_shader_->Bind();
			//glBindVertexArray(_vertex_array_);
			glDrawElements(GL_TRIANGLES,_index_buffer_->GetCount(), GL_UNSIGNED_INT, nullptr);



		
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
