#pragma once



#include <stdio.h>
#include "Event/KeyboardEvent.h"
#include "Event/WindowEvent.h"
#include "Event/MouseEvent.h"



namespace Engine
{


	class IMGUI
	{
	public:

		//static IMGUI& Instance() { return _instance_; }
		
		void Init();
		void Shutdown();

		void Begin();
		void End();

		void OnEvent(Event& e);

		
	private:

		//static IMGUI _instance_;
		float _time_ = 0.0f;
	};

}

