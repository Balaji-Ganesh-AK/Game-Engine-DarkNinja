#pragma once

#include "Utlis/Helper.h"

namespace Engine
{
	class Input
	{
	public:
		inline static bool IsKeyPressed(int KeyCode) { return _instance_->IsKeyPressedImp(KeyCode); };

		//inline static bool IsKeyRepeat(int KeyCode) { return _instance_->IsKeyRepeatImp(KeyCode); };
		inline static bool IsMousePressed(int KeyCode) { return _instance_->IsMousePressedImp(KeyCode); };

		inline static float GetMouseX() { return _instance_->GetMouseXImp(); }
		inline static float GetMouseY() { return _instance_->GetMouseYImp(); }

	protected:
		virtual bool IsKeyPressedImp(int keycode) =0;
		//virtual bool IsKeyRepeatImp(int keycode) = 0;
		virtual bool IsMousePressedImp(int keycode) = 0;
		virtual float GetMouseXImp() = 0;
		virtual float GetMouseYImp() = 0;
		
	private:
		static Input* _instance_;
	};
}
