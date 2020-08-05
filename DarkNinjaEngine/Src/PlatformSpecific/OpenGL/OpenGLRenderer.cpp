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

	void OpenGLRenderer::DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray, uint32_t IndexCount) const
	{
		vertexArray->Bind();
		uint32_t count = IndexCount ? vertexArray->GetIndexBuffers()->GetCount() : IndexCount;
		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffers()->GetCount(), GL_UNSIGNED_INT, nullptr);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void OpenGLRenderer::SetViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) 
	{
		glViewport(x, y, width, height);
	}

	void OpenGLRenderer::Init() const
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
	}
}
