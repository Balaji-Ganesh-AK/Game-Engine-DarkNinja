#pragma once
#include "Logger.h"
#include "Utlis/Helper.h"


namespace Engine
{

	enum class ShaderDataType
	{
		None = 0,
		Vec, Vec2, Vec3, Vec4,
		Mat3, Mat4,
		Int,
		Bool

	};

	static uint32_t ShaderDataTypeSize(ShaderDataType Type)
	{
		switch (Type)
		{
			case ShaderDataType::Vec:   return 4;
			case ShaderDataType::Vec2:  return 4*2;
			case ShaderDataType::Vec3:  return 4*3;
			case ShaderDataType::Vec4:  return 4*4;
			case ShaderDataType::Int:   return 4; 
			case ShaderDataType::Bool:  return 1;
			case ShaderDataType::Mat3:  return 4*3*3;
			case ShaderDataType::Mat4:  return 4*4*4;
		}
#ifdef _LOGGER
		DNE_ENGINE_ASSERT(false, "Unknown Data type");
#endif
		return 0;

		
	}
	
	struct BufferElements
	{
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		uint32_t Offset;

		BufferElements(std::string name, ShaderDataType type): Name(name), Type(type),
		Size(ShaderDataTypeSize(type)), Offset(0)
		{
			
		};
	};
	
	class BufferLayout
	{
	public:
		BufferLayout(std::initializer_list<BufferElements>& bufferelements):_buffer_elements_(bufferelements)
		{
			
		}
		//inline const std::vector<BufferElements>& GetElements() const { return _buffer_elements_; }
	private:
		std::vector<BufferElements> _buffer_elements_;
	};
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
