
#include "pch.h"
#include "OpenGLContext.h"

#include "Logger.h"
#include "Utlis/Helper.h"

namespace Engine
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandler):_glfw_window_handler_(windowHandler)
	{
#ifdef  _LOGGER
		DNE_ENGINE_ASSERT(windowHandler, "Window Handle is null");
#endif
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(_glfw_window_handler_);

		int success = gladLoadGLLoader(GLADloadproc(glfwGetProcAddress));
#ifdef  _LOGGER
		DNE_ENGINE_ASSERT(success, " GLAD Window Failed to Create!");


		DNE_ENGINE_INFO("OpenGL Info:");
		DNE_ENGINE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		DNE_ENGINE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		DNE_ENGINE_INFO("  Version: {0}", glGetString(GL_VERSION));
#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwPollEvents();

		glfwSwapBuffers(_glfw_window_handler_);
	}
}
