#include "pch.h"
#include "Texture.h"

#include "PlatformSpecific/OpenGL/OpenGLTexture.h"

namespace Engine
{

    std::shared_ptr<Texture2D> Texture2D::Create(const std::string& path)
    {
        return std::make_shared<OpenGLTexture2D>(path);
    }
}
