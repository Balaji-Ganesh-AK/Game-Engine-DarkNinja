#include "pch.h"
#include "WindowInput.h"

#include "Engine.h"
#include "GLFW/glfw3.h"


namespace Engine
{
	Input* Input::_instance_ = new WindowInput();
	
	bool WindowInput::IsKeyPressedImp(int keycode)
	{

		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());

		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
		
	}

	bool WindowInput::IsMousePressedImp(int button)
	{

		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());

		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}


	float WindowInput::GetMouseXImp()
	{
		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());

		double xpos, ypos;
	    glfwGetCursorPos(window, &xpos, &ypos);
		return static_cast<float>(xpos);
	}

	float WindowInput::GetMouseYImp()
	{
		auto window = static_cast<GLFWwindow*>(Application::Instance().GetWindow().GetNativeWindow());

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		return static_cast<float>(ypos);
	}
}
