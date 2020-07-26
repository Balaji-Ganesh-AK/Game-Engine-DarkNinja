#include "pch.h"
#include "OpenGLTexture.h"

#include "Logger.h"
#include "GLAD/glad.h"
#include "stb_image.h"
#include "Utlis/Helper.h"


namespace Engine
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& name):_path_(name)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(_path_.c_str(), &width, &height , &channels, 0);

		if(!data)
		{
			_path_="Resources/Assets/Textures/Checkerboard.png";
			data = stbi_load(_path_.c_str(), &width, &height, &channels, 0);
		}
		DNE_SIMPLE_ASSERT(data);
		_width_ = width;
		_height_ = height;

		GLenum dataFormat = 0, internalFormat = 0;

		if(channels==4)
		{
			internalFormat = GL_RGBA8;
			dataFormat = GL_RGBA;
		}
		else if(channels==3)
		{
			internalFormat = GL_RGB8;
			dataFormat = GL_RGB;
		}
		DNE_ENGINE_ASSERT(internalFormat, "Format not supported");
		glCreateTextures(GL_TEXTURE_2D, 1, &_renderID_);
		glTextureStorage2D(_renderID_, 1, internalFormat, _width_, _height_);

		glTextureParameteri(_renderID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_renderID_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


		glTextureSubImage2D(_renderID_, 0, 0, 0, _width_, _height_, dataFormat, GL_UNSIGNED_BYTE, data);

		
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
