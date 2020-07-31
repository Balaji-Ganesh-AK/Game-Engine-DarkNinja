#pragma once




#include "../Src/Window.h"
#include "ComponentsSystem/RenderingSystem/RenderingContext.h"
#include "PlatformSpecific/OpenGL/OpenGLContext.h"



namespace Engine
{
	class WindowsWindow: public Window
	{
	public:
		WindowsWindow(const WindowProperties& properties);
		virtual ~WindowsWindow();

		void Update() override;

		unsigned int GetWidth() const override { return _windows_data_.Width; }
		unsigned int GetHeight() const override { return _windows_data_.Height; }

		void SetEventCallBack(const EventCallBackFn& callback) override { _windows_data_.EventCallBack = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
		void* GetNativeWindow() const override { return _glfw_window_; };




	private:
		virtual void Init(const WindowProperties& properties);
		virtual void ShutDown();
		GLFWwindow* _glfw_window_;

		RenderingContext* _rendering_context_;

		struct WindowsData
		{
			std::string Title="";
			unsigned int Width=0, Height=0;
			bool VSync=true;
			EventCallBackFn EventCallBack;
		};

		WindowsData _windows_data_;
	};
}

