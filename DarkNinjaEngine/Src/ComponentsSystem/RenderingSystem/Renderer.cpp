#include "pch.h"

#include "Renderer.h"
#include "PlatformSpecific/OpenGL/OpenGLRenderer.h"
namespace Engine
{
	Renderer::API Renderer::_API_ = Renderer::API::OpenGL;
	Renderer* Renderer::_renderer_ = new OpenGLRenderer;
	
	Renderer::SceneData* Renderer::_scene_data_ = new Renderer::SceneData();




	void Renderer::BeginScene(OrthographicCamera* camera)
	{
		_scene_data_->camera = camera;
		_scene_data_->_view_projection_matrix_ = camera->GetViewProjectionMatrix();
	}

	void Renderer::EndScene()
	{
	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData, const glm::mat4& transform)
	{
		ShaderData->Bind();

		//ShaderData->UniformMat4Upload("u_ViewProjection", _scene_data_->_view_projection_matrix_);
		ShaderData->UniformMat4Upload("u_ViewProjection", _scene_data_->camera->GetViewProjectionMatrix());
		ShaderData->UniformMat4Upload("u_Transform", transform);
		_renderer_->DrawIndexed(vertexArray, ShaderData);
	}
}
