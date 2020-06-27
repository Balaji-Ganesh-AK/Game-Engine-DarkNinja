#pragma once


#include "Event.h"


namespace Engine
{
	class KeyboardEvent : public Event
	{
	protected:
		KeyboardEvent();
	};

	class KeyPressedEvent: public KeyboardEvent
	{
	public:

		KeyPressedEvent()
		{};
		int GetRepeatCount() { return _repeated_count_; }
		EVENT_CLASS_TYPE(KeyPressed);

	private:
		int _repeated_count_;
		
	};
	class KeyReleasedEvent: public KeyPressedEvent
	{

	public:
		KeyReleasedEvent(){};
		EVENT_CLASS_TYPE(KeyReleased);
		
	};
}