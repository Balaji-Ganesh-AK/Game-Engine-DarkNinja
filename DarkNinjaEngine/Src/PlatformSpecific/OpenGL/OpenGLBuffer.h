#pragma once

#include "ComponentsSystem/RenderingSystem/Buffer.h"
namespace Engine
{
	class OpenGLVertexBuffer: public VertexBuffer
	{
	public:

		OpenGLVertexBuffer(float* Vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();
		
		void Bind() const override;
		void UnBind() const override;
	private:
		uint32_t _render_ID;
	};


	class OpenGLIndexBuffer: public IndexBuffer
	{
	public:

		OpenGLIndexBuffer(uint32_t* Indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		//returns the number of instances.
		virtual uint32_t GetCount() const override;
		
		void Bind() const override;
		void UnBind() const override;
	private:
		uint32_t _render_ID;
		uint32_t _count_;
		
	};
	
}

