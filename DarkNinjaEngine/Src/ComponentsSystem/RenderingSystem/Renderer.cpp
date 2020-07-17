#include "pch.h"

#include "Renderer.h"
#include "PlatformSpecific/OpenGL/OpenGLRenderer.h"
namespace Engine
{
	Renderer::API Renderer::_API_ = Renderer::API::OpenGL;
	Renderer* Renderer::_renderer_ = new OpenGLRenderer;

	void Renderer::BeginScene()
	{
	}

	void Renderer::EndScene()
	{
	}
}
