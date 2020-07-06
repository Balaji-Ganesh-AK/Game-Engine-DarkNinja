#pragma once


#include "Event.h"


namespace Engine
{
	class KeyboardEvent : public Event
	{
	protected:
		KeyboardEvent(int keycode):_key_code_(keycode){};
		
		int _key_code_;
	};

	class KeyPressedEvent: public KeyboardEvent
	{
	public:

		KeyPressedEvent(int key, int repeat):KeyboardEvent(key),_repeated_count_(repeat) {};
		int GetRepeatCount() { return _repeated_count_; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Pressed Event: "<<_key_code_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed);
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard);

	private:
		int _repeated_count_=0;
		
		
	};

	class KeyReleasedEvent: public KeyboardEvent
	{

	public:
		KeyReleasedEvent(int keycode) :KeyboardEvent(keycode)
		{};
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Key Released Event: "<<_key_code_;
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyReleased);
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard);
	
		
	};
}