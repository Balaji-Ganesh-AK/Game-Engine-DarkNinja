#include "pch.h"
#include "WindowsWindow.h"

#include "../../Logger.h"


namespace Engine
{

	static bool _GLFW_Initialized = false;

	Window* Window::Create(const WindowProperties& prop)
	{
		return new WindowsWindow(prop);
	}
	WindowsWindow::WindowsWindow(const WindowProperties& prop)
	{
		Init(prop);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}


	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);
	}

	bool WindowsWindow::IsVSync() const
	{
		return _windows_data_.VSync;
	}


	void WindowsWindow::Init(const WindowProperties& properties)
	{
		_windows_data_.Title = properties.Title;
		_windows_data_.Width = properties.width;
		_windows_data_.Height = properties.height;

#ifdef  _LOGGER
		DNE_ENGINE_INFO("Creating Window {0} ({1},{2})", properties.Title, properties.width, properties.height);
#endif

		if (!_GLFW_Initialized)
		{
			int success = glfwInit();
#ifdef  _LOGGER
			DNE_CLIENT_ASSERT(success, " GLFW Window Created!");
#endif
			_GLFW_Initialized = true;
		}

		_glfw_window_ = glfwCreateWindow((int)properties.width, (int)properties.height, _windows_data_.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(_glfw_window_);
		glfwSetWindowUserPointer(_glfw_window_, &_windows_data_);
		SetVSync(true);

	}
		

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(_glfw_window_);
	}

	void WindowsWindow::Update()
	{
		glfwPollEvents();
		glfwSwapBuffers(_glfw_window_);
	}

	
}

