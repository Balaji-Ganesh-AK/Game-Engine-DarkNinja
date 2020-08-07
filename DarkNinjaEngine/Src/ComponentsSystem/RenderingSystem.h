#pragma once
#include "Entity.h"


namespace Engine
{
	class RenderingSystem
	{
		
	public:
		static RenderingSystem* Instance() { return _instance_; }
		void Init();
		void Run();
		void Shutdown();

	private:

		void Flush();
		static RenderingSystem* _instance_;
		void UpdateVertix(vec3 tempPos, vec2 tempSize, float tempTextureID, vec4 Color);



		
		
	};
}
