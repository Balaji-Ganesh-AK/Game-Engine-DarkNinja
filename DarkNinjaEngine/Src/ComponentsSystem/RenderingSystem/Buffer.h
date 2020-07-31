#pragma once
#include "Utlis/Helper.h"


namespace Engine
{

	enum class ShaderDataType
	{
		None = 0,
		FVec, FVec2, FVec3, FVec4,
		Mat3, Mat4,
		Int,
		Bool

	};

	static uint32_t ShaderDataTypeSize(ShaderDataType Type)
	{
		switch (Type)
		{
			case ShaderDataType::FVec:   return 4;
			case ShaderDataType::FVec2:  return 4*2;
			case ShaderDataType::FVec3:  return 4*3;
			case ShaderDataType::FVec4:  return 4*4;
			case ShaderDataType::Int:   return 4; 
			case ShaderDataType::Bool:  return 1;
			case ShaderDataType::Mat3:  return 4*3*3;
			case ShaderDataType::Mat4:  return 4*4*4;
		}
#ifdef _LOGGER
		DNE_SIMPLE_ASSERT(false, "Unknown Data type");
#endif
		return 0;

		
	}


	/// <summary>
	/// "Offset" is the starting point of each attribute,
	/// which is basically the size of each previous attribute
	///
	/// </summary>
	struct BufferElements
	{
		std::string Name;
		ShaderDataType Type;
		uint32_t Size;
		uint32_t Offset;
		bool Normalized;

		BufferElements(ShaderDataType type, std::string name, bool normalized = false) : Name(name), Type(type),
		Size(ShaderDataTypeSize(type)), Offset(0),Normalized(normalized)
		{
			
		};


		uint32_t GetComponentCount()const
		{
			switch (Type)
			{
			case ShaderDataType::FVec:   return 1;
			case ShaderDataType::FVec2:  return 2;
			case ShaderDataType::FVec3:  return 3;
			case ShaderDataType::FVec4:  return 4;
			case ShaderDataType::Int:   return 1;
			case ShaderDataType::Bool:  return 1;
			case ShaderDataType::Mat3:  return 4 * 3;
			case ShaderDataType::Mat4:  return 4 * 4;
			}

#ifdef _LOGGER
			DNE_SIMPLE_ASSERT(false, "Unknown Data type");
#endif
			return 0;
		}
	};
	
	class BufferLayout
	{
	public:

		BufferLayout(){};
		BufferLayout(const std::initializer_list<BufferElements>& bufferelements):_buffer_elements_(bufferelements)
		{
			CalculateOffset();
		}
		inline const std::vector<BufferElements>& GetElements() const { return _buffer_elements_; }
		inline  uint32_t GetStride() const { return _stride_; };

		std::vector<BufferElements>::iterator begin() { return _buffer_elements_.begin(); }
		std::vector<BufferElements>::iterator end() { return _buffer_elements_.end(); }
		std::vector<BufferElements>::const_iterator begin() const { return _buffer_elements_.begin(); }
		std::vector<BufferElements>::const_iterator end() const { return _buffer_elements_.end(); }
		
	private:
		void CalculateOffset()
		{
			_stride_ = 0;
			uint32_t offset = 0;
			for (auto& elements : _buffer_elements_)
			{
				elements.Offset = offset;
				offset += elements.Size;
				_stride_  += elements.Size;
			}
		}
		
	private:
		std::vector<BufferElements> _buffer_elements_;
		uint32_t _stride_ = 0;

	};
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind()const = 0;
		virtual void UnBind()const = 0;
		
		virtual void SetLayout(BufferLayout& layout) = 0;
		const virtual BufferLayout& GetLayout()  = 0;
		
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
