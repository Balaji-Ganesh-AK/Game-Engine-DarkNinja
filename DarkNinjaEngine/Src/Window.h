#pragma once
#include "../pch.h"

#include "Event/Event.h"



namespace Engine
{
	struct WindowProperties
	{
		std::string Title;
		uint32_t width;
		uint32_t height;

		WindowProperties(const std::string& Title = " Dark Ninja Engine", uint32_t i_width = 1280, uint32_t i_height = 720) :
			Title(Title), width(i_width), height(i_height)
		{

		}
	};

	class Window
	{
	public:
		
		using EventCallBackFn = std::function<void(Event&)>;
		virtual ~Window()=default;
		virtual void Update();

#pragma region Getterfunciton
		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;
#pragma endregion 

#pragma region WindowsAttributes
		virtual void SetEventCallBack(const EventCallBackFn& callback) = 0;
		virtual void* GetNativeWindow() const = 0;
		virtual void SetVSync(bool enabled)= 0;
		virtual bool IsVSync() const = 0;
#pragma endregion 



		static Window* Create(const WindowProperties& prop = WindowProperties());
		
	};
}
