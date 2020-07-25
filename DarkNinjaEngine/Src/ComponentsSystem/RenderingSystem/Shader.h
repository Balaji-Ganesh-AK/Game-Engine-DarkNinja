#pragma once


#include <string>
#include <glm/glm/fwd.hpp>



namespace Engine
{
	class Shader
	{
	public:
		Shader(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc);
		~Shader();


		void Bind() const;
		 void UnBind() const;

		 void UniformMat4Upload(const std::string& name, const glm::mat4& matrix);
		 void UniformIntUpload(const std::string& name, const int value);

	private:
		uint32_t _render_ID_;
	};
}
