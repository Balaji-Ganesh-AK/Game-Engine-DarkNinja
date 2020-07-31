#include "pch.h"
#include "OpenGLBuffer.h"

#include <glad/glad.h>


namespace Engine
{
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* Vertices, uint32_t size)
	{
		glCreateBuffers(1, &_render_ID);
		glBindBuffer(GL_ARRAY_BUFFER, _render_ID);
		glBufferData(GL_ARRAY_BUFFER, size, Vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer()
	{
		glDeleteBuffers(1, &_render_ID);
	}

	void OpenGLVertexBuffer::Bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, _render_ID);
	}

	void OpenGLVertexBuffer::UnBind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(uint32_t* Indices, uint32_t count):
	_count_(count)
	{
		glCreateBuffers(1, &_render_ID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _render_ID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), Indices, GL_STATIC_DRAW);
	}
	OpenGLIndexBuffer::~OpenGLIndexBuffer()
	{
	}

	uint32_t OpenGLIndexBuffer::GetCount() const
	{
		return _count_;
	}

	void OpenGLIndexBuffer::Bind() const
	{
	}

	void OpenGLIndexBuffer::UnBind() const
	{
	}
}
