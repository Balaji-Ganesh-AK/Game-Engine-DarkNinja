#pragma once

#include "Components.h"
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
	public:
		Renderer2D(){}
		
		~Renderer2D();
		void Init() override;
		void Update() override;
		void End() override;


		void SetTexture(const std::string path= "Resources/Assets/Textures/Checkerboard.png"){ _path_ = path; }
		void SetPosition(const vec3 Position);

		void SetScale(const vec2 Size);


		void DrawQuad();
		//void OnGUI() override;
		
	private:
		std::string _path_;
		glm::mat4 _transform_ = glm::mat4(1.0f);

		vec3 _position_;
		vec2 _size_;
		vec3 _color_;
		std::shared_ptr<VertexArray> _vertex_array_square_;
		std::shared_ptr<Texture2D> _texture_;
		std::shared_ptr<Shader> _texture_shader_;
	};
}
