#pragma once
#include "ComponentsSystem/RenderingSystem/TextureComponent.h"


namespace Engine
{
	class OpenGLTexture2D: public Texture2D
	{
	public:
		OpenGLTexture2D(const std::string& name);
		virtual ~OpenGLTexture2D();

		 void Bind(uint32_t slot) const override;
		 uint32_t GetWidth() const override;
		 uint32_t GetHeight() const override;

	private:
		std::string _path_;
		uint32_t _width_, _height_;
		uint32_t _renderID_;
		
		
	};
}
