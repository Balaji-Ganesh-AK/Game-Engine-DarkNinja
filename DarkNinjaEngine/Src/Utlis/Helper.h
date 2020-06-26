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

inline bool NaNCheck(float i_val)
{
	return i_val == i_val ? false : true;
}