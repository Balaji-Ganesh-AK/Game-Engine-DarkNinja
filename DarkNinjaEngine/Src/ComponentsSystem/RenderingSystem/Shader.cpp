#include "pch.h"

#include "Shader.h"

#include <glad/glad.h>

#include "Logger.h"
#include "glm/glm/gtc/type_ptr.hpp"
#include "PlatformSpecific/OpenGL/OpenGLShader.h"

namespace Engine
{
	
	Shader* Shader::Create(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc)
	{
		return new OpenGLShader(vertexShaderSrc, fragmentShaderSrc);
	}
}
