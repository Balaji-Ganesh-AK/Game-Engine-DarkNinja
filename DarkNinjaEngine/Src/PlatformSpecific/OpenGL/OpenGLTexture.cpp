#include "pch.h"
#include "OpenGLTexture.h"

#include "Logger.h"

#include "stb/stb_image.h"
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

		if(channels==4)
		{
			_internal_format_ = GL_RGBA8;
			_data_format_ = GL_RGBA;
		}
		else if(channels==3)
		{
			_internal_format_ = GL_RGB8;
			_data_format_ = GL_RGB;
		}
		DNE_ENGINE_ASSERT(_internal_format_, "Format not supported");
		glCreateTextures(GL_TEXTURE_2D, 1, &_renderID_);
		glTextureStorage2D(_renderID_, 1, _internal_format_, _width_, _height_);

		glTextureParameteri(_renderID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_renderID_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//these settings are default, can make the parameters as variables and give the user the
		// ability to changes the parameter in run time.
		glTextureParameteri(_renderID_, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(_renderID_, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(_renderID_, 0, 0, 0, _width_, _height_, _data_format_, GL_UNSIGNED_BYTE, data);

		
		stbi_image_free(data);
	}

	OpenGLTexture2D::OpenGLTexture2D(uint32_t Width, uint32_t Height)
		:_width_(Width), _height_(Height)
	{
		_internal_format_ = GL_RGBA8;
		_data_format_ = GL_RGBA;


		glCreateTextures(GL_TEXTURE_2D, 1, &_renderID_);
		glTextureStorage2D(_renderID_, 1, _internal_format_, _width_, _height_);

		glTextureParameteri(_renderID_, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_renderID_, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		//these settings are default, can make the parameters as variables and give the user the
		// ability to changes the parameter in run time.
		glTextureParameteri(_renderID_, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(_renderID_, GL_TEXTURE_WRAP_T, GL_REPEAT);
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

	void OpenGLTexture2D::SetData(void* data, uint32_t size) const
	{
		const uint32_t bitsperpixel = _data_format_ == GL_RGBA ? 4 : 3;

		//The buffer has to be the entire size of the texture
		DNE_SIMPLE_ASSERT(size == _width_ * _height_ * bitsperpixel);


		glTextureSubImage2D(_renderID_, 0, 0, 0, _width_, _height_, _data_format_, GL_UNSIGNED_BYTE, data);
	}

	
}
