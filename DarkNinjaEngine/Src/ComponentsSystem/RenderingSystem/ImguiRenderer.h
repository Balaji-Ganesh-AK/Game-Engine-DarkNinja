#pragma once
#pragma region IM_GUI_CLASS

#include <imgui.h>
#include "PlatformSpecific/OpenGL/imguiOpenGLRenderer.h"

#include "Engine.h"
#include "Logger.h"
#include "glfw/glfw3.h"


namespace Engine
{
	class IMGUI
	{
	public:

		static IMGUI& Instance() { return _instance_; }
		void Update();


		void Init();


		void End();
	private:
		static IMGUI _instance_;
		float _time_ = 0.0f;
	};
}

#pragma endregion 