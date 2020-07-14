#pragma once
#include "ComponentsSystem/RenderingSystem/VertexArray.h"


namespace Engine
{
	class OpenGlVertexArray: public VertexArray
	{
	public:
		OpenGlVertexArray();
		~OpenGlVertexArray();
		
		void Bind() const override;
		void Unbind() const override;

		void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
		void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

	private:
		std::vector<std::shared_ptr<VertexBuffer>> _vector_buffer_list_;
		std::shared_ptr<IndexBuffer> _index_buffer_;

		uint32_t _rendererID;
		
	};


}
