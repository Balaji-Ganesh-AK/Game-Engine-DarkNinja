#pragma once

#include "KeyCodes.h"
#include "MouseCodes.h"
#include "Utlis/Helper.h"
#include "Math/vec2.h"
namespace Engine
{
	class Input
	{
	public:
		
		inline static bool IsKeyPressed(int KeyCode) { return _instance_->IsKeyPressedImp(KeyCode); }
		inline static bool IsKeyPressed(KeyCodes key) { return _instance_->IsKeyPressedImp(static_cast<int>(key)); }
		//inline static bool IsKeyRepeat(int KeyCode) { return _instance_->IsKeyRepeatImp(KeyCode); };
		inline static bool IsMousePressed(int KeyCode) { return _instance_->IsMousePressedImp(KeyCode); }
		inline static bool IsMousePressed(Mouse MouseCode) { return _instance_->IsMousePressedImp(static_cast<int>(MouseCode));
		}

		inline static float GetMouseX() { return _instance_->GetMouseXImp(); }
		inline static float GetMouseY() { return _instance_->GetMouseYImp(); }
		inline static vec2 GetMousePosition() { return _instance_->GetMousePositionImp(); }

	protected:
		virtual bool IsKeyPressedImp(int keycode) =0;
		//virtual bool IsKeyRepeatImp(int keycode) = 0;
		virtual bool IsMousePressedImp(int keycode) = 0;
		virtual vec2 GetMousePositionImp() = 0;
		virtual float GetMouseXImp() = 0;
		virtual float GetMouseYImp() = 0;
		
	private:
		static Input* _instance_;
	};
}
