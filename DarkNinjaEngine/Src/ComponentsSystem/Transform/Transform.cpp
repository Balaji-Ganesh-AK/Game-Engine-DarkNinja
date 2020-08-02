#include "pch.h"
#include "Transform.h"
#include <glm/glm/ext/matrix_transform.inl>

namespace Engine
{
	void Transform::Init()
	{
	
		_transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
			* glm::scale(glm::mat4(1.0f), { _size_.x, _size_.y,1.0f });
	}

	void Transform::Update()
	{
		_transform_ = glm::translate(glm::mat4(1.0f), { _position_.x,_position_.y,_position_.z })
			* glm::scale(glm::mat4(1.0f), { _size_.x, _size_.y,1.0f });
		
		//TODO add a control statement to make rotation false when the rotation rad is 0;
	}

	void Transform::End()
	{
		
	}

	void Transform::SetPosition(const vec3 Position)
	{
		
		_position_ = Position;
		

	}

	void Transform::SetPosition(const float x, const float y, const float z)
	{
		_position_ = vec3(x, y, z);
	}

	void Transform::SetRotation(const float Rad)
	{
		_rotation_ = Rad;
		_is_rotation_ = true;
	}

	void Transform::SetScale(const vec2 size)
	{
		_size_ = size;
		
	}
}
