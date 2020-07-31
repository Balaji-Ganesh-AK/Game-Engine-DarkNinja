#pragma once
#include <glad/glad.h>

#include "ComponentsSystem/RenderingSystem/Texture.h"


namespace Engine
{
	class OpenGLTexture2D: public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& name);
		OpenGLTexture2D(uint32_t width, uint32_t height);
		virtual ~OpenGLTexture2D();

		 void Bind(uint32_t slot) const override;
		 uint32_t GetWidth() const override;
		 uint32_t GetHeight() const override;

		 void SetData(void* data, uint32_t size)const override;

	private:
		std::string _path_;
		uint32_t _width_, _height_;
		uint32_t _renderID_;

		GLenum _data_format_ = 0, _internal_format_ = 0;
		
		
	};
}
