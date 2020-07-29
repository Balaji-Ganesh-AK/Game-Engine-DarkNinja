#pragma once

#include "Input.h"

namespace Engine
{
	class WindowInput : public Input
	{
	protected:
		bool IsKeyPressedImp(int keycode) override;
		bool IsMousePressedImp(int button) override;
		float GetMouseXImp() override;
		float GetMouseYImp() override;
		vec2 GetMousePositionImp() override;
	};
}
