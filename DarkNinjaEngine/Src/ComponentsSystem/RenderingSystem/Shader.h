#pragma once


#include <string>


namespace Engine
{
	class Shader
	{
	public:
		Shader(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc);
		~Shader();


		void Bind() const;
		 void UnBind() const;

	private:
		uint32_t _render_ID_;
	};
}
