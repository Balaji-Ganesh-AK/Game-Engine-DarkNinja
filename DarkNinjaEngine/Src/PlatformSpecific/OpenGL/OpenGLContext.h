#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "ComponentsSystem/RenderingSystem/RenderingContext.h"
namespace Engine
{
	class OpenGLContext : public RenderingContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandler);
		
		void Init() override;
		void SwapBuffers() override;

	private:
		GLFWwindow* _glfw_window_handler_;
	};

	
}
