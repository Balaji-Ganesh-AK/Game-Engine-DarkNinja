#pragma once
#include "ComponentsSystem/RenderingSystem/Shader.h"


namespace Engine
{
	class OpenGLShader :public Shader
	{
	public:
		OpenGLShader(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc);
		~OpenGLShader();

		void Bind() const override;
		void UnBind() const override;

		void SetInt(const std::string& name, const int value) override { UniformIntUpload(name, value); }
		void SetIntArray(const std::string& name, int* value, uint32_t count) override { UniformIntArrayUpload(name, value, count); }
		void SetFloat4(const std::string& name,vec4 value) override { UniformFloat4Upload(name, value); }
		void SetMat4(const std::string& name, const glm::mat4& matrix) override { UniformMat4Upload(name, matrix); }
		void SetFloat4(const std::string& name, float x, float y, float z, float w) override { UniformFloat4Upload(name, x, y, z, w); }

		
	private:

		void UniformMat4Upload(const std::string& name, const glm::mat4& matrix);
		void UniformIntArrayUpload(const std::string& name, int* value, uint32_t count);
		void UniformIntUpload(const std::string& name, const int value);
		void UniformFloat4Upload(const std::string& name,  vec4 value);
		void UniformFloat4Upload(const std::string& name, float x, float y, float z, float w);
		uint32_t _render_ID_;
	};
}
