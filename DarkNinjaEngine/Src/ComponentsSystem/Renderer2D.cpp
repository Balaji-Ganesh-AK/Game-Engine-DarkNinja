#include "pch.h"
#include "Renderer2D.h"

#include <glm/glm/ext/matrix_transform.inl>


#include "RenderingSystem/Renderer.h"

namespace Engine
{
	Renderer2D::~Renderer2D()
	{
	}

	void Renderer2D::Init()
	{
		float verticessq[5 * 4] = {
			-0.5f, -.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f, 0.5f, 0.0f, 0.0f, 1.0f

		};

		_vertex_array_square_.reset(VertexArray::Create());

		std::shared_ptr<VertexBuffer> _vertex_buffer_square;
		_vertex_buffer_square.reset(VertexBuffer::Create(verticessq, sizeof(verticessq)));

		{
			BufferLayout layoutsquare = {
				{ShaderDataType::FVec3, "a_Position"},
				{ShaderDataType::FVec2, "a_TexCord"}

			};
			_vertex_buffer_square->SetLayout(layoutsquare);
		}
		_vertex_array_square_->AddVertexBuffer(_vertex_buffer_square);

		uint32_t indicessquare[6] = { 0,1,2 ,2,3,0 };


		std::shared_ptr<IndexBuffer> _index_buffer_square;
		_index_buffer_square.reset(IndexBuffer::Create(indicessquare, std::size(indicessquare)));
		_vertex_array_square_->SetIndexBuffer(_index_buffer_square);







		std::string textureVertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec2 a_TexCord;

		uniform mat4 u_ViewProjection;
		uniform mat4 u_Transform;
		
		
		out vec3 v_Position;
		out vec2 v_TexCord;
		
		void main()
		{
			v_Position = a_Position;
		
			v_TexCord = a_TexCord;
			
			gl_Position = u_ViewProjection * u_Transform * vec4(a_Position,1.0);
		}

		)";

		std::string textureFragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;
		in vec2 v_TexCord;

		uniform vec4 u_Color;
		uniform sampler2D u_Texture;
		
		void main()
		{
		
			o_Color = texture(u_Texture, v_TexCord ) * u_Color;
		}

		)";

		
		_texture_shader_.reset(Shader::Create(textureVertexSrc,textureFragmentSrc));
      
		
		
		_texture_shader_->Bind();
		_texture_shader_->SetInt("u_Texture", 0);
		_texture_shader_->SetFloat4("u_Color", _color_.x, _color_.y, _color_.z, _color_.w);
		
	}

	void Renderer2D::Update()
	{
		
	
	}

	void Renderer2D::End()
	{
	}

	void Renderer2D::SetTexture(const std::string path)
	{
		_path_ = path;
	
	
	}

	void Renderer2D::SetPosition(const vec3 Position)
	{
		_position_ = Position;
		_transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
			* glm::scale(glm::mat4(1.0f), { _size_.x, _size_.y,1.0f });
		
	}

	void Renderer2D::SetColor(vec4 Color)
	{
		_color_ = Color;
		//Renderer::SubmitColor(_vertex_array_square_, _texture_shader_, _color_);
	}

	void Renderer2D::SetScale(const vec2 Size)
	{
		_size_ = Size;

		_transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
		*glm::scale(glm::mat4(1.0f), {_size_.x, _size_.y,1.0f});
		
	}

	void Renderer2D::DrawQuad(const vec4 Color, vec2 Size)
	{
		_texture_ = Texture2D::Create(1,1);
		 uint32_t whitetexturedata = 0xffffffff;
		 _texture_->SetData(&whitetexturedata,sizeof(uint32_t));
		 
		 _size_ = Size;
		 _color_ = Color;
		
		 _transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
			 * glm::scale(glm::mat4(1.0f), { _size_.x, _size_.y,1.0f });

	}

	void Renderer2D::DrawQuad(const std::string path, const vec2 Size)
	{
		_path_ = path;
		_texture_ = Texture2D::Create(_path_);
		_size_ = Size;

		_transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
			* glm::scale(glm::mat4(1.0f), { _size_.x, _size_.y,1.0f });
	}
}
