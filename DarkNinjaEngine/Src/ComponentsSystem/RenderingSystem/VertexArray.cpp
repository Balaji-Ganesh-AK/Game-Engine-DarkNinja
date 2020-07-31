#include "pch.h"
#include "VertexArray.h"

#include "PlatformSpecific/OpenGL/OpenGLVertexArray.h"


namespace Engine
{
	VertexArray* VertexArray::Create()
	{

		return new OpenGlVertexArray();
	}
}
