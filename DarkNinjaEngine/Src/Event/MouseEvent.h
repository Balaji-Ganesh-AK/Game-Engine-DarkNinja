#pragma once
#include "Event.h"


namespace Engine
{
	class MouseMovedEvent :public Event
	{
	public:
		MouseMovedEvent(float x, float y) :
			_mouse_x_(x), _mouse_y_(y)
		{}

		float GetMouseX() const { return _mouse_x_; }
		float GetMouseY() const { return _mouse_y_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _mouse_x_ << ", " << _mouse_y_;
			return ss.str();
		}
		
		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse);

	private:
		 float _mouse_x_, _mouse_y_;
	};


	class MouseScrollEvent :public Event
	{
	public:
		MouseScrollEvent(double x, double y) :
			_mouse_offset_x_(x), _mouse_offset_y_(y)
		{}

		double GetMouseX() const { return _mouse_offset_x_; }
		double GetMouseY() const { return _mouse_offset_y_; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Scrolled event: " << _mouse_offset_x_ << ", " << _mouse_offset_y_;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScroll);
		EVENT_CLASS_CATEGORY(EventCategoryMouse);

	private:
		double _mouse_offset_x_, _mouse_offset_y_;
	};


	class MouseButtonPressedEvent :public Event
	{
	public:
		MouseButtonPressedEvent(int mousecode) :_mouse_code_(mousecode)
		{};

		int GetMouseButton() const { return _mouse_code_; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Pressed Event: "<< _mouse_code_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed); EVENT_CLASS_CATEGORY(EventCategoryMouse);

	private:
	
		int _mouse_code_ = 0;
	};
	class MouseButtonReleasedEvent :public Event
	{
	public:
		MouseButtonReleasedEvent(int mousecode) :_mouse_code_(mousecode)
		{};
		int GetMouseButton() const { return _mouse_code_; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse Button Released Event: " << _mouse_code_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonReleased);
		EVENT_CLASS_CATEGORY(EventCategoryMouse);
	private:

		int _mouse_code_ = 0;
	};


}
