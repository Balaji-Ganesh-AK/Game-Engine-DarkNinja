#pragma once

#include <iostream>
#include <string>
#include <sstream>


class RefrenceCounter
{
private:
	int smart_pointer_counter_;
	

public:

	void AddSmartPointerReference()
	{
		smart_pointer_counter_++;
	}

	int RemoveSmartPointerReference()
	{
		return --smart_pointer_counter_;
	}

	int SmartPointerCount() const
	{
		return smart_pointer_counter_;
	}
};

template<typename  T>
class SmartPointer
{
private:
	T* p_data_;
	RefrenceCounter* p_refrence_counter_;
public:
	explicit SmartPointer():p_data_(0), p_refrence_counter_(0)
	{
		p_refrence_counter_ = new RefrenceCounter();
		p_refrence_counter_->AddSmartPointerReference();
	}

	  SmartPointer(T* p_value) : p_data_(p_value), p_refrence_counter_(0)
	{
		p_refrence_counter_ = new RefrenceCounter();
		p_refrence_counter_->AddSmartPointerReference();
	}

	SmartPointer (const SmartPointer& i_smart_pointer):p_data_(i_smart_pointer.GetData()),p_refrence_counter_(i_smart_pointer.GetReference())
	{
		if(p_refrence_counter_)
		{
			p_refrence_counter_->AddSmartPointerReference();
		}
	}

	~SmartPointer()
	{
		
		if(p_refrence_counter_->RemoveSmartPointerReference()==0)
		{
			
			delete p_data_;
			delete p_refrence_counter_;
		}
	}


	//Smart Pointer operations

	int GetReferenceCount() const
	{
		return p_refrence_counter_->SmartPointerCount();
	}

	RefrenceCounter* GetReference() const 
	{
		return p_refrence_counter_;
	}
	T* GetData()
	{
		return p_data_;
	}
	
	operator bool()
	{
		return  p_data_ != nullptr;
	}


	T& operator->()
	{
		return p_data_;
	}
	T* operator*()
	{
		return *p_data_;
	}
};
