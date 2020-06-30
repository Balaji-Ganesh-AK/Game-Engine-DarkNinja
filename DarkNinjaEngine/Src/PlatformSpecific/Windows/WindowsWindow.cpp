#include "pch.h"
#include "WindowsWindow.h"
#include "../Src/Event/WindowEvent.h"
#include "../Src/Event/KeyboardEvent.h"
#include "../Src/Event/MouseEvent.h"
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

//#ifdef  _LOGGER
//		DNE_ENGINE_INFO("Creating Window {0} ({1},{2})", properties.Title, properties.width, properties.height);
//#endif

		if (!_GLFW_Initialized)
		{
			int success = glfwInit();
#ifdef  _LOGGER
			DNE_ENGINE_ASSERT(success, " GLFW Window Created!");
#endif
			_GLFW_Initialized = true;
		}

		_glfw_window_ = glfwCreateWindow((int)properties.width, (int)properties.height, _windows_data_.Title.c_str(), nullptr, nullptr);

		glfwMakeContextCurrent(_glfw_window_);
		glfwSetWindowUserPointer(_glfw_window_, &_windows_data_);
		SetVSync(true);

		glfwSetWindowSizeCallback(_glfw_window_, [](GLFWwindow* window, int width, int height)
			{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;
			
				WindowResizeEvent event(width, height);
				data.EventCallBack(event);
				
			});
		glfwSetWindowCloseCallback(_glfw_window_, [](GLFWwindow* window)
		{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				WindowCloseEvent event;
				
				data.EventCallBack(event);
			
		});


		glfwSetKeyCallback(_glfw_window_, [](GLFWwindow* window, int key, int scancode, int action , int mods)
		{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);
				switch (action)
				{
				case GLFW_PRESS:
					{
					
						KeyPressedEvent event(key,0);
						
						data.EventCallBack(event);
						break;
						
					}
				case GLFW_RELEASE:
					{
					KeyReleasedEvent event(key);
					data.EventCallBack(event);
					break;
					}
				case GLFW_REPEAT:
					{
					KeyReleasedEvent event(key);
					data.EventCallBack(event);
					break;
					}
					
					
				}
		});
		glfwSetMouseButtonCallback(_glfw_window_, [](GLFWwindow* window, int button, int action ,int mods)
		{
			WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);
			switch (action)
			{
			case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);

					data.EventCallBack(event);
					break;
				}
			case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.EventCallBack(event);
					break;
				}
			}
		});

		glfwSetScrollCallback(_glfw_window_, [](GLFWwindow* window, double xOffset, double yOffset)
		{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				MouseScrollEvent event(xOffset, yOffset);
				data.EventCallBack(event);
			
			
		});
		glfwSetCursorPosCallback(_glfw_window_, [](GLFWwindow* window, double xpos, double ypos)
		{
				WindowsData& data = *(WindowsData*)glfwGetWindowUserPointer(window);

				MouseMovedEvent event(xpos, ypos);
				data.EventCallBack(event);
		});

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

