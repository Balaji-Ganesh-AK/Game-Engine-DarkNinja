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


		struct Render2DData
		{
			std::shared_ptr<VertexArray> _vertex_array_square_;
			std::shared_ptr<Texture2D> _texture_;
			std::shared_ptr<Shader> _texture_shader_;
		};


		static Render2DData* _data_;

		
		
		
	};
}
