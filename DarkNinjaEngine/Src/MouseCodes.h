#pragma once


namespace Engine
{

	//FROM glfw3.h
	typedef enum class MouseCode
	{
		Button1 = 0,
		Button2 = 1,
		Button3 = 2,
		Button4 = 3,
		Button5 = 4,
		Button6 = 5,
		Button7 = 6,
		Button8 = 7,
		ButtonLeft = Button1,
		ButtonLast = Button8,
		ButtonRight = Button2,
		ButtonMiddle = Button3


	}Mouse;
}


#define DNE_MOUSE_BUTTON_1      0,
#define DNE_MOUSE_BUTTON_2      1,
#define DNE_MOUSE_BUTTON_3      2,
#define DNE_MOUSE_BUTTON_4      3,
#define DNE_MOUSE_BUTTON_5      4,
#define DNE_MOUSE_BUTTON_6      5,
#define DNE_MOUSE_BUTTON_7      6,
#define DNE_MOUSE_BUTTON_8      7,
#define DNE_MOUSE_BUTTON_LAST   DNE_MOUSE_BUTTON_8
#define DNE_MOUSE_BUTTON_LEFT   DNE_MOUSE_BUTTON_1
#define DNE_MOUSE_BUTTON_RIGHT  DNE_MOUSE_BUTTON_2
#define DNE_MOUSE_BUTTON_MIDDLE DNE_MOUSE_BUTTON_3