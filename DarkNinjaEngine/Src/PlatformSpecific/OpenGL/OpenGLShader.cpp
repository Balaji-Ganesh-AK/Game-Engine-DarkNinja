#include "pch.h"
#include "OpenGLShader.h"

#include <GLAD/glad.h>
#include "glm/glm/gtc/type_ptr.hpp"
#include "Logger.h"


namespace Engine
{
	OpenGLShader::OpenGLShader(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc)
	{
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = vertexShaderSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(vertexShader);

			DNE_ENGINE_ERROR("{0}", infoLog.data());
			DNE_ENGINE_ASSERT(false, "Vertex Shader compilation failed!");
			return;
			return;
		}

		// Create an empty fragment shader handle
		const GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = fragmentShaderSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			// We don't need the shader anymore.
			glDeleteShader(fragmentShader);
			// Either of them. Don't leak shaders.
			glDeleteShader(vertexShader);

			DNE_ENGINE_ERROR("{0}", infoLog.data());
			DNE_ENGINE_ASSERT(false, "Fragment Shader compilation failed!");
			return;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.
		GLuint program = glCreateProgram();
		_render_ID_ = program;
		// Attach our shaders to our program
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, static_cast<int*>(&isLinked));
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			DNE_ENGINE_ERROR("{0}", infoLog.data());
			DNE_ENGINE_ASSERT(false, "Linking Shaders  failed!");
			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);
	}

	OpenGLShader::~OpenGLShader()
	{
	}




	void OpenGLShader::Bind() const
	{
		glUseProgram(_render_ID_);
	}

	void OpenGLShader::UnBind() const
	{
		glUseProgram(0);
	}

	void OpenGLShader::UniformMat4Upload(const std::string& name, const glm::mat4& matrix) 
	{
		GLint Location = glGetUniformLocation(_render_ID_, name.c_str());
		glUniformMatrix4fv(Location, 1, GL_FALSE, glm::value_ptr(matrix));

	}

	void OpenGLShader::UniformIntUpload(const std::string& name, const int value) 
	{
		GLint Location = glGetUniformLocation(_render_ID_, name.c_str());
		glUniform1i(Location, value);
	}

	void OpenGLShader::UniformFloat4Upload(const std::string& name, vec4 value) 
	{
		GLint Location = glGetUniformLocation(_render_ID_, name.c_str());
		glUniform4f(Location, value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::UniformFloat4Upload(const std::string& name, float x, float y, float z, float w)
	{
		GLint Location = glGetUniformLocation(_render_ID_, name.c_str());
		glUniform4f(Location, x, y,z, w);
	}
}
