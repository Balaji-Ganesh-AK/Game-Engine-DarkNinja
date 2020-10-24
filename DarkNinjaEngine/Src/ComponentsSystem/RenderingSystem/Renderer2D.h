#pragma once

#include "../Components.h"
#include "../RenderingSystem.h"
#include "../RenderingSystem/Shader.h"
#include "../RenderingSystem/Texture.h"
#include "../RenderingSystem/VertexArray.h"
#include "glm/glm/glm.hpp"
#include "Math/Vec3.h"
#include "Math/vec2.h"
namespace Engine
{

	class Renderer2D:public Components
	{
		friend RenderingSystem;
	public:
		Renderer2D(){}
		
		~Renderer2D();
		void Init() override;
		void Update() override;
		void End() override;


		void SetTexture(const std::string path = "Resources/Assets/Textures/Checkerboard.png");
	
		void SetColor(vec4 Color);

	

		//Just a Quad with Color
		void DrawQuad();

		//Draw a quad with a texture;
		void DrawQuad(const std::string path);

		
		
	private:

		
		std::string _path_;
		//this is used to check if we need to use the default white texture on this sprite.
		int _texture_id_ =-1;

		vec3 _position_;
		vec2 _size_;
		vec4 _color_ = vec4(1,1,1,1);
		std::shared_ptr<VertexArray> _vertex_array_square_;
		std::shared_ptr<VertexBuffer> _vertex_buffer_square;
		std::shared_ptr<Texture2D> _texture_;
		std::shared_ptr<Shader> _texture_shader_;
	};
}
