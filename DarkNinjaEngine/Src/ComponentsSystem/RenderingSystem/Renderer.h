#pragma once

#include "VertexArray.h"
#include "Math/Vec4.h"

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


		static void BeginScene();
		static void EndScene();
		inline static void Submit(const std::shared_ptr<VertexArray>& vertexArray)
		{
			_renderer_->DrawIndexed(vertexArray);
		}
		inline static Renderer& GetInstance() { return  *_renderer_; }
		inline static API GetAPI() { return _API_; }

		
	private:
		
		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) const = 0;
		static API _API_;
		static Renderer* _renderer_;
		
	};
}