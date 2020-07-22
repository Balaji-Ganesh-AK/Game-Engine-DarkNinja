#include "pch.h"

#include "OpenGLRenderer.h"
#include "glad/glad.h"
namespace Engine
{
	void OpenGLRenderer::SetClearColor(vec4& color) const
	{
		glClearColor(color.x, color.y, color.z, color.w);
	}

	void OpenGLRenderer::ClearColor() const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, const std::shared_ptr<Shader>& ShaderData) const
	{
		
		vertexArray->Bind();
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffers()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}
