#pragma once



#include "PlatformSpecific/OpenGL/ImGui/imguiOpenGLRenderer.h"

#include "Engine.h"
#include "Logger.h"
#include "glfw/glfw3.h"

#include "Event/WindowEvent.h"
#include "Event/KeyboardEvent.h"
#include "Event/MouseEvent.h"

#pragma region IM_GUI_CLASS
namespace Engine
{

#ifdef _IMGUI
	class IMGUI
	{
	public:

		static IMGUI& Instance() { return _instance_; }
		void Update();


		void Init();


		void End();
		void OnEvent(Event& e);
	private:


#pragma region Events


		
		
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent& e );
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(MouseMovedEvent& e);
		bool OnMouseScrollEvent(MouseScrollEvent& e);
		bool OnKeyPressedEvent(KeyPressedEvent& e);
		bool OnKeyReleasedEvent(KeyReleasedEvent& e);
		bool OnWindowResizeEvent(WindowResizeEvent&e );
	
		
#pragma endregion 
		static IMGUI _instance_;
		float _time_ = 0.0f;
	};
#endif
}

#pragma endregion 