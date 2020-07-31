#pragma once
#include "Entity.h"


namespace Engine
{
	class RenderingSystem
	{
		
	public:
		static RenderingSystem* Instance() { return _instance_; }
		void Run();
		void Shutdown();

	private:

		static RenderingSystem* _instance_;
		
		
	};
}
