#pragma once

#include "ComponentsSystem/RenderingSystem/Renderer.h"

namespace Engine
{
	class OpenGLRenderer:public Renderer
	{
		void SetClearColor(vec4& color) const override;
		void ClearColor() const override;

	private:
		void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData) const override;
		void SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		void Init() const override;
	};
}
