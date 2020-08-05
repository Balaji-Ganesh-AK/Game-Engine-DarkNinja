#include "pch.h"
#include "RenderingSystem.h"

#include "RenderingSystem/Renderer2D.h"
#include "Transform/Transform.h"


namespace Engine
{
	RenderingSystem* RenderingSystem::_instance_ = new RenderingSystem();

#pragma region 2D Rendering Data.


	struct QuadVertex2D
	{
		vec3 _position_;
		vec4 _color_;
		vec2 _texture_coord_;

	};
	struct Render2DData
	{

		static const uint32_t MaxQuad = 10000;
		static const uint32_t MaxVertices = MaxQuad * 4;
		static const uint32_t MaxIndices = MaxQuad * 6;
		//Todo add texture slots;


		std::shared_ptr<VertexArray> _vertex_array_;
		std::shared_ptr<VertexBuffer> _vertex_buffer_;
		std::shared_ptr<Texture2D> _texture_;
		std::shared_ptr<Shader> _texture_shader_;


		uint32_t IndexCount = 0;

		//Pointer to the current memory block.

		QuadVertex2D* _vertex_buffer_base_ = nullptr;
		QuadVertex2D* _vertex_buffer_ptr_ = nullptr;

	};


	static Render2DData _data_2D_;

#pragma  endregion

	
	void RenderingSystem::Init()
	{

		// this is for batch rendering. 
		_data_2D_._vertex_array_.reset(VertexArray::Create());

		_data_2D_._vertex_buffer_.reset(VertexBuffer::Create(_data_2D_.MaxVertices * sizeof(QuadVertex2D)));

		{
			BufferLayout layout = {
				{ShaderDataType::FVec3, "a_Position"},
				{ShaderDataType::FVec4, "a_Color"},
				{ShaderDataType::FVec2, "a_TexCord"}

			};
			_data_2D_._vertex_buffer_->SetLayout(layout);
		}
		
		_data_2D_._vertex_array_->AddVertexBuffer(_data_2D_._vertex_buffer_);

		_data_2D_._vertex_buffer_base_ = new QuadVertex2D[_data_2D_.MaxIndices];

	


		//This is a bad way of writing a code, but since i know this works using it.
		uint32_t* indices = new uint32_t[_data_2D_.MaxIndices];


		uint32_t offset = 0;

		for (uint32_t i = 0; i < _data_2D_.MaxIndices; i += 6)
		{
			indices[i + 0] = offset + 0;
			indices[i + 1] = offset + 1;
			indices[i + 2] = offset + 2;
			
			indices[i + 3] = offset + 2;
			indices[i + 4] = offset + 3;
			indices[i + 5] = offset + 0;

			offset += 4;
		}

		
		std::shared_ptr<IndexBuffer> _index_buffer_;
		_index_buffer_.reset(IndexBuffer::Create(indices, _data_2D_.MaxIndices));
		_data_2D_._vertex_array_->SetIndexBuffer(_index_buffer_);
		//this set is done because the data is uploaded to the gpu.
		delete[] indices;

		//Just now for white texture.

		_data_2D_._texture_ = Texture2D::Create(1, 1);
		uint32_t whitetexturedata = 0xffffffff;
		_data_2D_._texture_->SetData(&whitetexturedata,sizeof(uint32_t));

#pragma region  shaderData
		std::string textureVertexSrc = R"(
				#version 430 core

		layout(location = 0) in vec3 a_Position;
		layout(location = 1) in vec4 a_Color;
		layout(location = 2) in vec2 a_TexCord;

		uniform mat4 u_ViewProjection;
		
		
		
	
		out vec4 v_Color;
		out vec2 v_TexCord;
		
		void main()
		{
			
		
			v_TexCord = a_TexCord;
			v_Color = a_Color;
			gl_Position = u_ViewProjection * vec4(a_Position,1.0);
		}

		)";

		std::string textureFragmentSrc = R"(
				#version 430 core

		layout(location = 0) out vec4 o_Color;


		in vec4 v_Color;
		in vec2 v_TexCord;

		uniform vec4 u_Color;
		uniform sampler2D u_Texture;
		
		void main()
		{
		
			//o_Color = texture(u_Texture, v_TexCord ) * u_Color;
			o_Color = v_Color;
		}

		)";

#pragma endregion 

		
		_data_2D_._texture_shader_.reset(Shader::Create(textureVertexSrc, textureFragmentSrc));
		_data_2D_._texture_shader_->Bind();
		_data_2D_._texture_shader_->SetInt("u_Texture", 0);



		_data_2D_._texture_shader_->SetMat4("u_ViewProjection", Renderer::GetCameraViewProjection());
		_data_2D_.IndexCount = 0;
		_data_2D_._vertex_buffer_ptr_ = _data_2D_._vertex_buffer_base_;
		
		for (auto it = EntityManager::Instance()._entity_list_stack_.begin(); it != EntityManager::Instance()._entity_list_stack_.end(); ++it)
		{


			if (it->second->GetComponent<Renderer2D>())
			{
				const vec3 tempPos = it->second->GetComponent<Transform>()->GetPosition();
				const vec2 tempSize = it->second->GetComponent<Transform>()->GetSize();
				
				_data_2D_._vertex_buffer_ptr_->_position_ = tempPos;
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 0.0f,0.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x + tempSize.x, tempPos.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 1.0f,0.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x + tempSize.x, tempPos.y + tempSize.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 1.0f,1.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x , tempPos.y + tempSize.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 0.0f,1.0f };
				_data_2D_._vertex_buffer_ptr_++;

				//6 index per quad.
				_data_2D_.IndexCount += 6;
				
			}

		}
	}

	void RenderingSystem::Run()
	{
		
		_data_2D_._texture_shader_->SetMat4("u_ViewProjection", Renderer::GetCameraViewProjection());
		_data_2D_.IndexCount = 0;
		_data_2D_._vertex_buffer_ptr_ = _data_2D_._vertex_buffer_base_;


		
		for (auto it = EntityManager::Instance()._entity_list_stack_.begin(); it != EntityManager::Instance()._entity_list_stack_.end(); ++it)
		{


			if (it->second->GetComponent<Renderer2D>())
			{

				vec3 tempPos = it->second->GetComponent<Transform>()->GetPosition();
				vec2 tempSize = it->second->GetComponent<Transform>()->GetSize();

				_data_2D_._vertex_buffer_ptr_->_position_ = tempPos;
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 0.0f,0.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x + tempSize.x, tempPos.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 1.0f,0.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x + tempSize.x, tempPos.y + tempSize.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 1.0f,1.0f };
				_data_2D_._vertex_buffer_ptr_++;

				_data_2D_._vertex_buffer_ptr_->_position_ = { tempPos.x , tempPos.y + tempSize.y, 0.0f };
				_data_2D_._vertex_buffer_ptr_->_color_ = it->second->GetComponent<Renderer2D>()->_color_;
				_data_2D_._vertex_buffer_ptr_->_texture_coord_ = { 0.0f,1.0f };
				_data_2D_._vertex_buffer_ptr_++;

				//6 index per quad.
				_data_2D_.IndexCount += 6;

			}

		}


		uint32_t dataSize = (uint8_t*)_data_2D_._vertex_buffer_ptr_-(uint8_t*)_data_2D_._vertex_buffer_base_;
		_data_2D_._vertex_buffer_->SetData(_data_2D_._vertex_buffer_base_,dataSize);
		Flush();
		
	}

	void RenderingSystem::Shutdown()
	{
		delete _instance_;
		
	}

	void RenderingSystem::Flush()
	{
		Renderer::Submit(_data_2D_._vertex_array_, _data_2D_.IndexCount);
	}
}
