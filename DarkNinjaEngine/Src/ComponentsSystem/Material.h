#pragma once

#include "Components.h"
#include "RenderingSystem/Shader.h"
#include "RenderingSystem/Texture.h"
#include "RenderingSystem/VertexArray.h"

namespace Engine
{
	class Material:public Components
	{
	public:
		Material(){}
		
		~Material();
		void Init() override;
		void Update() override;
		void End() override;


		void SetTexture(const std::string path){ _path_ = path; }
		//void OnGUI() override;
		
	private:
		std::string _path_ = "Resources/Assets/Textures/Checkerboard.png";

		std::shared_ptr<VertexArray> _vertex_array_square_;
		std::shared_ptr<Texture2D> _texture_;
		std::shared_ptr<Shader> _texture_shader_;
	};
}
