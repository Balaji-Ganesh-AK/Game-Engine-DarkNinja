
#include "pch.h"
#include "ImguiRenderer.h"

#include <glad/glad.h>

#pragma region IM_GUI_CLASS


Engine::IMGUI Engine::IMGUI::_instance_;
namespace Engine
{

	
	
	void IMGUI::Init()
	{
		
		ImGui::CreateContext();
		

		ImGuiIO& io = ImGui::GetIO();
		(void)io;
	/*	io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;*/

		ImGui::StyleColorsDark();
		
		
		//KeyMap.
		io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
		io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
		io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
		io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
		io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
		io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
		io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
		io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
		io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
		io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
		io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
		io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
		io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
		io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
		io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
		io.KeyMap[ImGuiKey_KeyPadEnter] = GLFW_KEY_KP_ENTER;
		io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
		io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
		io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
		io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
		io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
		io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;


		ImGui_ImplOpenGL3_Init("#version 150");
		
	}


	void IMGUI::Update()
	{

		ImGuiIO& io = ImGui::GetIO(); (void)io;
		Engine::Application& app = Engine::Application::Instance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = _time_ > 0.0f ? (time - _time_) : (1.0f / 60.0f);
		_time_ = time;


		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();
		DNE_ENGINE_INFO("working!");
		//demo window
		static bool show = true;
		ImGui::ShowDemoWindow(&show);

		{
			
		ImGui::Begin("Another Window", &show);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
		ImGui::Text("Hello from another window!");
		ImGui::End();
		}
		ImGui::Render();

		glClearColor(0, 1, 1,1);
		glClear(GL_COLOR_BUFFER_BIT);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


	}

	void IMGUI::End()
	{
	}
}
#pragma endregion 