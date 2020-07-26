#include "pch.h"
#include "Material.h"

#include "RenderingSystem/Renderer.h"

namespace Engine
{
	Material::~Material()
	{
	}

	void Material::Init()
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
			gl_Position = u_ViewProjection*u_Transform*vec4(a_Position,1.0);
		}

		)";

		std::string textureFragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;

		in vec3 v_Position;
		in vec2 v_TexCord;

		uniform sampler2D u_Texture;
		void main()
		{
		
			o_Color = texture(u_Texture, v_TexCord);
		}

		)";

		_texture_shader_.reset(new Shader(textureVertexSrc, textureFragmentSrc));
        _texture_ = Texture2D::Create(_path_);
		
		
		_texture_shader_->Bind();
		_texture_shader_->UniformIntUpload("u_Texture", 0);
	}

	void Material::Update()
	{
		_texture_->Bind();
		Renderer::Submit(_vertex_array_square_,_texture_shader_);
	}

	void Material::End()
	{
	}


}
