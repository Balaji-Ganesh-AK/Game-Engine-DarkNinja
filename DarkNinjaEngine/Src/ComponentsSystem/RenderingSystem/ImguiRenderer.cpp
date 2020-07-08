//
#include "pch.h"
#include "ImguiRenderer.h"

#include <glad/glad.h>

#pragma region IM_GUI_CLASS

#ifdef _IMGUI
Engine::IMGUI Engine::IMGUI::_instance_;

namespace Engine
{

	
	
	void IMGUI::Init()
	{
		
		IMGUI_CHECKVERSION();
		ImGui::CreateContext();
		ImGuiIO& io = ImGui::GetIO();
		(void)io;
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		
		
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


		
		ImGui_ImplOpenGL3_Init("#version 410");
		ImGui::StyleColorsDark();
	}

	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
	void IMGUI::Update()
	{

		ImGuiIO& io = ImGui::GetIO(); 
		Engine::Application& app = Engine::Application::Instance();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

		float time = (float)glfwGetTime();
		io.DeltaTime = _time_ > 0.0f ? (time - _time_) : (1.0f / 60.0f);
		_time_ = time;


	
		ImGui_ImplOpenGL3_NewFrame();
		ImGui::NewFrame();

		if (show_demo_window)
			ImGui::ShowDemoWindow(&show_demo_window);

		{
			static float f = 0.0f;
			static int counter = 0;

			ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

			ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
			ImGui::Checkbox("Demo Window", &show_demo_window);      // Edit bools storing our window open/close state
			ImGui::Checkbox("Another Window", &show_another_window);

			ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
			ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

			if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
				counter++;
			ImGui::SameLine();
			ImGui::Text("counter = %d", counter);

			ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
			ImGui::End();
		}

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());


	}

	void IMGUI::End()
	{
	}

	void IMGUI::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnWindowResizeEvent));
		dispatcher.Dispatch<MouseButtonPressedEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnMouseButtonPressedEvent));
		dispatcher.Dispatch<MouseButtonReleasedEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnMouseButtonReleasedEvent));
		dispatcher.Dispatch<MouseMovedEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnMouseMovedEvent));
		dispatcher.Dispatch<MouseScrollEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnMouseScrollEvent));
		dispatcher.Dispatch<KeyPressedEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnKeyPressedEvent));
		dispatcher.Dispatch<KeyReleasedEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnKeyReleasedEvent));
		dispatcher.Dispatch<WindowResizeEvent>(DNE_BIND_SINGLE_EVENT(IMGUI::OnWindowResizeEvent));
	}

	bool IMGUI::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = true;
	
		
		return false;
	}

	bool IMGUI::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseDown[e.GetMouseButton()] = false;

		return false;
	}

	bool IMGUI::OnMouseMovedEvent(MouseMovedEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MousePos = ImVec2(e.GetMouseX(),e.GetMouseY());

		return false;
	}

	bool IMGUI::OnMouseScrollEvent(MouseScrollEvent& e)
	{
		ImGuiIO& io = ImGui::GetIO();
		io.MouseWheelH += e.GetMouseX();
		io.MouseWheel += e.GetMouseY();
		
		return false;
	}

	bool IMGUI::OnKeyPressedEvent(KeyPressedEvent& e)
	{
		return false;
	}

	bool IMGUI::OnKeyReleasedEvent(KeyReleasedEvent& e)
	{
		return false;
	}

	bool IMGUI::OnWindowResizeEvent(WindowResizeEvent& e)
	{

		ImGuiIO& io = ImGui::GetIO();
		io.DisplaySize = ImVec2(e.GetWidth(),e.GetHeight());
		io.DisplayFramebufferScale = ImVec2(1.0f,1.0f);
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		
		return false;
	}
}
#endif
#pragma endregion 