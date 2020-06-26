#pragma once


#include "Event.h"


namespace Engine
{
	class WindowCreateEvent:public Event
	{
	public:
		WindowCreateEvent(unsigned int width, unsigned int height):
		_width_(width),_height_(height)
		{}

		unsigned int GetWidth() const { return _width_; }
		unsigned int GetHeight() const { return _height_; }

		EVENT_CLASS_TYPE(WindowCreate);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);
		
	private:
		unsigned int _width_, _height_;
	};


	class WindowResizeEvent :public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) :
			_width_(width), _height_(height)
		{}

		unsigned int GetWidth() const { return _width_; }
		unsigned int GetHeight() const { return _height_; }

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);

	private:
		unsigned int _width_, _height_;
	};


	class WindowCloseEvent :public Event
	{
	public:
		WindowCloseEvent() = default;

		
		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryWindow);

	private:
		unsigned int _width_, _height_;
	};

	
}
