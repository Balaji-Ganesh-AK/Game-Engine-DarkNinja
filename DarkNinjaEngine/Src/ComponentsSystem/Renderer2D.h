#pragma once

#include "Components.h"
#include "RenderingSystem.h"
#include "RenderingSystem/Shader.h"
#include "RenderingSystem/Texture.h"
#include "RenderingSystem/VertexArray.h"
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
		void SetPosition(const vec3 Position);
		void SetColor(vec4 Color);

		void SetScale(const vec2 Size);

		//Just a Quad with Color
		void DrawQuad(const vec3 Position = vec3(0,0,0), const vec4 Color = vec4(0,0,0,0),vec2 size=vec2(1,1));

		//Draw a quad with a texture;
		void DrawQuad(const std::string path, const vec2 Size = vec2(1,1));

		
		
	private:
		std::string _path_;
		glm::mat4 _transform_ = glm::mat4(1.0f);

		vec3 _position_;
		vec2 _size_;
		vec4 _color_ = vec4(1,1,1,1);
		std::shared_ptr<VertexArray> _vertex_array_square_;
		std::shared_ptr<Texture2D> _texture_;
		std::shared_ptr<Shader> _texture_shader_;
	};
}
