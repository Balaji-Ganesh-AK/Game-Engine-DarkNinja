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
		
	};
}
