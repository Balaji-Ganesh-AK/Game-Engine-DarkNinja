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

		//this needs to be reworked in future to handle more viewports. 
		static void OnWindowResize( uint32_t width, uint32_t height) { _renderer_->SetViewPort(0, 0, width, height); }
		static void BeginScene(OrthographicCamera* camera);
		static void EndScene();
		static void Submit(const std::shared_ptr<VertexArray>& vertexArray,
		                          const std::shared_ptr<Shader>& ShaderData,
			const glm::mat4& transform = glm::mat4(1.0f),
			vec4 color = vec4(1,1,1,1));


		static void Submit(const std::shared_ptr<VertexArray>& vertexArray, uint32_t IndexCount =0);

		static glm::mat4 GetCameraViewProjection();
		static void SubmitColor(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData , vec4 color);

	
		inline static Renderer& GetInstance() { return  *_renderer_; }
		inline static API GetAPI() { return _API_; }
		
	private:
		
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData) const = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray,uint32_t IndexCount = 0)const =0;
		virtual void Init()const =0;
		//x and y is the from value and width and height are the new values.
		virtual void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
		
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