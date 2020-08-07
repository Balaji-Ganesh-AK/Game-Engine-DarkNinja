#include "pch.h"
#include "Renderer2D.h"

#include <glm/glm/ext/matrix_transform.inl>

namespace Engine
{
	
	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::Init()
	{
		
	}

	void Renderer2D::Update()
	{
		
	
	}

	void Renderer2D::End()
	{
		//delete _data_;
	}

	void Renderer2D::SetTexture(const std::string path)
	{
		_path_ = path;
	
	}

	
	void Renderer2D::SetColor(vec4 Color)
	{
		_color_ = Color;
		//Renderer::SubmitColor(_vertex_array_square_, _texture_shader_, _color_);
	}


	void Renderer2D::DrawQuad()
	{
		
		_texture_ = Texture2D::Create(1, 1);
		uint32_t whitetexturedata = 0xffffffff;
		_texture_->SetData(&whitetexturedata, sizeof(uint32_t));
		
	}

	void Renderer2D::DrawQuad(const std::string path)
	{
		_texture_id_ = 1;
		_path_ = path;
		_texture_ = Texture2D::Create(_path_);
	
	}
}

