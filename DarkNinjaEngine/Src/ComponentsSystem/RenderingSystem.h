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

		void Flush() const;
		static RenderingSystem* _instance_;
		void UpdateVertix(glm::mat4 Transform, vec2 Size, float TextureID, vec4 Color);



		
		
	};
}
