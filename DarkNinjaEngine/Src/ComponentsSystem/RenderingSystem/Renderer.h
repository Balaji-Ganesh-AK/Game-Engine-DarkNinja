#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "Math/Vec4.h"
#include "glm/glm/glm.hpp"
#include "Camera.h"
namespace Engine
{
	

	class Renderer
	{
	public:

		enum  class API
		{
			None,
			OpenGL,
			DirectX,
			Vulkan
		};

		virtual void SetClearColor(vec4& color) const = 0;
		virtual void ClearColor() const = 0;


		static void BeginScene(OrthographicCamera* camera);
		static void EndScene();
		static void Submit(const std::shared_ptr<VertexArray>& vertexArray,
		                          const std::shared_ptr<Shader>& ShaderData,
			const glm::mat4& transform = glm::mat4(1.0f));

	
		inline static Renderer& GetInstance() { return  *_renderer_; }
		inline static API GetAPI() { return _API_; }

		
	private:
		
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData) const = 0;

		
		static API _API_;
		static Renderer* _renderer_;

		
		
		
		
	protected:

		
		//Sub class needs to access this data.
		struct SceneData
		{
			glm::mat4 _view_projection_matrix_;
			OrthographicCamera* camera;
			
		};
		static SceneData* _scene_data_;
	};
}