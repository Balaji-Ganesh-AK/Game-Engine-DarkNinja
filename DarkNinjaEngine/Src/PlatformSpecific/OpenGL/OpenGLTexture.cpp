#include "pch.h"
#include "OpenGLTexture.h"
#include "GLAD/glad.h"
#include "stb_image.h"
#include "Utlis/Helper.h"


namespace Engine
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& name):_path_(name)
	{
		int width, height, channels;
		stbi_uc* data = stbi_load(_path_.c_str(), &width, &height , &channels, 0);
		DNE_SIMPLE_ASSERT(data);
		_width_ = width;
		_height_ = height;

		glCreateTextures(GL_TEXTURE_2D, 1, &_renderID_);
		glTextureStorage2D(_renderID_, 1, GL_RGB8, _width_, _height_);

		glTextureParameteri(_renderID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_renderID_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		glTextureSubImage2D(_renderID_, 0, 0, 0, _width_, _height_, GL_RGB, GL_UNSIGNED_BYTE, data);

		
		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &_renderID_);
	}

	void OpenGLTexture2D::Bind(uint32_t slot) const
	{
		glBindTextureUnit(slot, _renderID_);
	}

	uint32_t OpenGLTexture2D::GetWidth() const
	{
		return _width_;
	}

	uint32_t OpenGLTexture2D::GetHeight() const
	{
		return _height_;
	}
}
