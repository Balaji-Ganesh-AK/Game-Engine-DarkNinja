#pragma once


#include "Engine.h"
#include "Logger.h"
#include "glfw/glfw3.h"


#include "imgui.h"
#include "ImGui/examples/imgui_impl_glfw.h"
#include "ImGui/examples/imgui_impl_opengl3.h"
#include <stdio.h>


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
		
		
	private:

		static IMGUI _instance_;
		float _time_ = 0.0f;
	};
#endif
}

#pragma endregion 