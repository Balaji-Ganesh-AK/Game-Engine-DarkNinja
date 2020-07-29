#include "pch.h"
#include "Camera.h"
#include "glm/glm/gtc/matrix_transform.hpp"
#define GLM_FORCE_CTOR_INIT
namespace Engine
{
	OrthographicCamera::OrthographicCamera(float left, float right, float bottom, float top)
		:_projection_matrix_(glm::ortho(left,right,bottom,top, -1.0f,1.0f)),_view_matrix_(1.0f)
	{
		_view_projection_matrix_ = _projection_matrix_ * _view_matrix_;
		_camera_size_.x = left;
		_camera_size_.y = right;
		_camera_size_.z = bottom;
		_camera_size_.w = top;
		
	}

	void OrthographicCamera::SetProjection(float left, float right, float bottom, float top)
	{
		_projection_matrix_ = (glm::ortho(left, right, bottom, top, -1.0f, 1.0f));
		_view_matrix_ = glm::mat4(1.0f);
		_view_projection_matrix_ = _projection_matrix_ * _view_matrix_;
	}

	void OrthographicCamera::ReclibarateMatrix()
	{

		glm::vec3 _glm_position_;
		_glm_position_.x = _position_.x;
		_glm_position_.y = _position_.y;
		_glm_position_.z = _position_.z;
		glm::mat4 transform = glm::translate(glm::mat4(1.0f), _glm_position_) *
			glm::rotate(glm::mat4(1.0f), _rotation_, glm::vec3(0, 0, 1));

		_view_matrix_ = glm::inverse(transform);
		_view_projection_matrix_ =  _projection_matrix_* _view_matrix_;

		
	}
}
