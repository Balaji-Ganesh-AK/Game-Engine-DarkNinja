#include "pch.h"

#include "OpenGLVertexArray.h"

#include <glad/glad.h>

#include "Logger.h"

namespace Engine
{

	static GLenum ShaderDataTypeToOpenGlType(ShaderDataType Type)
	{
		switch (Type)
		{

		case ShaderDataType::Float: return GL_FLOAT;
		case ShaderDataType::FVec2:return GL_FLOAT;
		case ShaderDataType::FVec3:return GL_FLOAT;
		case ShaderDataType::FVec4:return GL_FLOAT;
		case ShaderDataType::Mat3: return GL_FLOAT;
		case ShaderDataType::Mat4: return GL_FLOAT;
		case ShaderDataType::Int:  return GL_INT;
		case ShaderDataType::Bool: return GL_BOOL;
		}


#ifdef _LOGGER
		DNE_SIMPLE_ASSERT(false, "Unknown Data type");
#endif
		return 0;
	}

	
	OpenGlVertexArray::OpenGlVertexArray()
	{
		glGenVertexArrays(1, &_rendererID);
	}

	OpenGlVertexArray::~OpenGlVertexArray()
	{
	}

	void OpenGlVertexArray::Bind() const
	{
		glBindVertexArray(_rendererID);
	}

	void OpenGlVertexArray::Unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGlVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer)
	{

		DNE_ENGINE_ASSERT(vertexBuffer->GetLayout().GetElements().size(),"Missing Layout!");
		Bind();
		vertexBuffer->Bind();
		uint32_t index = 0;
		const auto& layout = vertexBuffer->GetLayout();
		for (auto const& element : layout)
		{
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index,
				element.GetComponentCount(),
				ShaderDataTypeToOpenGlType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				reinterpret_cast<const void*>(element.Offset));
			index++;
		}
		_vector_buffer_list_.push_back(vertexBuffer);

	}

	void OpenGlVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(_rendererID);
		indexBuffer->Bind();

		_index_buffer_ = indexBuffer;
	}
}
