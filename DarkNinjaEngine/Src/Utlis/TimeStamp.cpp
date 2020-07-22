#include "pch.h"
#include "TimeStamp.h"




namespace Engine
{
	TimeStamp* TimeStamp::_time_stamp_ = new TimeStamp();


	void TimeStamp::Run()
	{
		QueryPerformanceCounter(&_time_stamp_->_current_time_);
		QueryPerformanceFrequency(&_time_stamp_->_frequency_);


		_time_stamp_->_elasped_time_.QuadPart = _time_stamp_->_current_time_.QuadPart - _time_stamp_->_previous_time_;
		_time_stamp_->_elasped_time_.QuadPart *= 100000;
		_time_stamp_->_elasped_time_.QuadPart /= _time_stamp_->_frequency_.QuadPart;
		_time_stamp_->_time_ms_ = static_cast<float>(_time_stamp_->_elasped_time_.QuadPart) / 100000;

		_time_stamp_->_previous_time_ = _time_stamp_->_current_time_.QuadPart;

		
	}

	float TimeStamp::DeltaTime()
	{
		return _time_stamp_->_time_ms_;
	}
}
