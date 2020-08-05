#include "pch.h"
#include "Buffer.h"

#include "PlatformSpecific/OpenGL/OpenGLBuffer.h"


namespace Engine
{
	VertexBuffer* VertexBuffer::Create(float* Vertices, uint32_t size)
	{
		return new OpenGLVertexBuffer(Vertices,size);
	}

	VertexBuffer* VertexBuffer::Create(uint32_t size)
	{
		return new OpenGLVertexBuffer(size);
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* Indices, uint32_t size)
	{
		return new OpenGLIndexBuffer(Indices,size);
	}

}
