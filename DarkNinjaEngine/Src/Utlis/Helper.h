#pragma once
#include <cmath>
#include <sstream>


//This file contains all helper functions and macros for the game engine.




#define BIT(x) (1<<x)

#define  PrintToOutput(value)\
{\
	std::ostringstream os_;\
	os_ << value;\
	OutputDebugStringA(os_.str().c_str());\
}\

//Custom assertions, enabled only for debug mode.
#ifdef DNE_ENABLE_ASSERTS
	#define DNE_CLIENT_ASSERT(x, ...) {if(!(x)) { DNE_CLIENT_ERROR("Assertion Failed! :{0}",__VA_ARGS__); __debugbreak(); } }
	#define DNE_ENGINE_ASSERT(x, ...) {if(!(x)) { DNE_CLIENT_ERROR("Assertion Failed! :{0}",__VA_ARGS__); __debugbreak(); } }
	#define DNE_SIMPLE_ASSERT(x, ...) {if(!(x)) { __debugbreak(); }}
#else
#define DNE_CLIENT_ASSERT(x, ...) 
#define DNE_ENGINE_ASSERT(x, ...)
#define DNE_SIMPLE_ASSERT(x, ...)

#endif


#define DNE_BIND_SINGLE_EVENT(fn) std::bind(&fn, this, std::placeholders::_1)

inline bool NaNCheck(float i_val)
{
	return i_val == i_val ? false : true;
}