#include "pch.h"

#include "Renderer.h"
#include "PlatformSpecific/OpenGL/OpenGLRenderer.h"
namespace Engine
{
	Renderer::API Renderer::_API_ = Renderer::API::OpenGL;
	//TODO change it later to be generic 
	Renderer* Renderer::_renderer_ = new OpenGLRenderer;
	
	Renderer::SceneData* Renderer::_scene_data_ = new Renderer::SceneData();


	void Renderer::BeginScene(OrthographicCamera* camera)
	{
		_renderer_->Init();
		_scene_data_->camera = camera;
		_scene_data_->_view_projection_matrix_ = camera->GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData, const glm::mat4& transform,vec4 color)
	{
		ShaderData->Bind();

		//ShaderData->UniformMat4Upload("u_ViewProjection", _scene_data_->_view_projection_matrix_);
		ShaderData->SetMat4("u_ViewProjection", _scene_data_->camera->GetViewProjectionMatrix());
		ShaderData->SetMat4("u_Transform", transform);
		ShaderData->SetFloat4("u_Color", color.x, color.y, color.z, color.w);
		_renderer_->DrawIndexed(vertexArray, ShaderData);
	}


}
