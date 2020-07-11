#pragma once


namespace Engine
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind()const = 0;
		virtual void UnBind()const = 0;

		static  VertexBuffer* Create(float* Vertices, uint32_t size);
	};


	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind()const = 0;
		virtual void UnBind()const = 0;

		virtual uint32_t GetCount() const = 0;
		
		static  IndexBuffer* Create(uint32_t* Indices, uint32_t size);


		
	};
}
