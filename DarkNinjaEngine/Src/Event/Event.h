#pragma once

#include "../Utlis/Helper.h"

namespace Engine
{
	enum class EventType
	{
		None=0,
		//----------WindowEvents----------//
		WindowClose, WindowCreate, WindowResize,
		//----------WindowEvents----------//


		//----------MouseEvents----------//
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScroll,
		//----------MouseEvents----------//

		//----------KeyBoardEvent----------//
		KeyPressed, KeyReleased
		//----------KeyBoardEvent----------//
		
	};


	enum EventCategory
	{
		None = 0,
		EventCategoryWindow = BIT(0),
		EventCategoryKeyboard = BIT(1),
		EventCategoryMouse = BIT(2)
	};



	
	
	class Event
	{
	public:
		bool handled = false;

		virtual EventType GetEventType() const =0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryValue() const = 0;
		virtual std::string ToString() const { return GetName(); }


		bool IsInEventCategory(EventCategory category) const
		{
			return GetCategoryValue()&category;
		}
		
	};
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::type;}\
	virtual EventType GetEventType() const override{return GetStaticType();}\
	virtual const char* GetName() const override{return #type;}


#define EVENT_CLASS_CATEGORY(cat) virtual int GetCategoryValue() const override{return cat;};
	
	/*class EventDispatcher
	{
	public:
		EventDispatcher(Event& event)
			:_event_(event)
		{
			
		}
		template<typename T, typename F>
		bool Dispatch(const F& func)
		{
			if(_event_.GetEventType() == T::GetStaticType())
			{
				_event_.handled = func(static_cast<T&>(_event_));
				return true;
			}
			return false;
		}

	private:
		Event& _event_;
	};*/
	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;
		
	public:
		EventDispatcher(Event& event)
			:_event_(event)
		{

		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (_event_.GetEventType() == T::GetStaticType())
			{
				_event_.handled = func(*(T*)&_event_);
				return true;
			}
			return false;
		}

	private:
		Event& _event_;
	};
}

