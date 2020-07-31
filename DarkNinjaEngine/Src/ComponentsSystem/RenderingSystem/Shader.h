#pragma once


#include <string>
#include <glm/glm/fwd.hpp>
#include "Math/Vec4.h"


namespace Engine
{
	class Shader
	{
	public:
		virtual ~Shader()= default;


		virtual void Bind() const =0;
		virtual void UnBind() const =0;

		virtual void SetMat4(const std::string& name, const glm::mat4& matrix) =0;
		virtual void SetInt(const std::string& name, const int value) =0;
		virtual void SetFloat4(const std::string& name,  vec4 value) =0;
		virtual void SetFloat4(const std::string& name,  float x, float y, float z, float w) =0;
		


		static Shader* Create(const std::string& vertexShaderSrc, const std::string& fragmentShaderSrc);

	private:
		uint32_t _render_ID_;

		
	};
}
