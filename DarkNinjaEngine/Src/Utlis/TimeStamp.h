#pragma once
#include "windows.h"
#include <ctime>

namespace Engine
{
	class TimeStamp
	{
	public:
		static TimeStamp GetInstance() { return* _time_stamp_; }
		static void Run();
		static float DeltaTime();
		static float GetMilliSeconds() { return _time_stamp_->DeltaTime() * 1000; }
	
	private:
		 float _time_ms_=0;
		 long long _previous_time_=0;
	
		LARGE_INTEGER  _current_time_, _elasped_time_;
		LARGE_INTEGER _frequency_;

		static TimeStamp* _time_stamp_;
		
	};
}
