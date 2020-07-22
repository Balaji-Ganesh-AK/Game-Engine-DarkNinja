#pragma once

#include "glm/glm/glm.hpp"
#include "Math/Vec3.h"

namespace Engine
{
	class OrthographicCamera
	{
	public:
		OrthographicCamera(float left, float right, float bottom, float top);

		void SetPosition(const vec3& Position) {
			_position_ = Position; ReclibarateMatrix();
		}
		void SetRotation(const float Rotation) {
			_rotation_ = Rotation; ReclibarateMatrix();
		}

		void CameraMove(float left, float right, float bottom, float top);
		
		const vec3& GetPosition() const  { return _position_; }
		 float GetRotation()const { return _rotation_; }

		
		const glm::mat4& GetViewMatrix() const { return _view_matrix_; }
		const glm::mat4& GetProjectionMatrix() const { return _projection_matrix_; }
		const glm::mat4& GetViewProjectionMatrix() const { return _view_projection_matrix_; }
		
		
	private:
		void ReclibarateMatrix();

		
		glm::mat4 _projection_matrix_;
		glm::mat4 _view_matrix_;
		glm::mat4 _view_projection_matrix_;


		vec3 _position_;
		float _rotation_ = 0.0f;
	};
}
