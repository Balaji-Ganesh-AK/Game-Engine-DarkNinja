#pragma once

#include "Math/vec2.h"
#include "ComponentsSystem/Components.h"
#include "glm/glm/glm.hpp"
#include "Math/Vec3.h"


namespace Engine
{
	class Transform:public Components
	{
	public:
		
		void Init() override;
		void Update() override;
		void End() override;


		void SetPosition(const vec3 Position);
		void SetPosition(const float x, const float y , const float z);
		
		void SetRotation(const float Rad);
		void SetScale(const vec2 size);


		vec3 GetPosition() const { return _position_; }
		vec2 GetSize() const { return _size_; }
		float GetRotation() const { return _rotation_; }
		bool IsRotated() const { return _is_rotation_; }

		glm::mat4 GetTransformMatrix() { return _transform_; }
		
	private:

		vec2 _size_ = vec2(1,1);
		vec3 _position_;
		float _rotation_=0.0f;
		bool _is_rotation_ = false;

		glm::mat4 _transform_ = glm::mat4(1.0f);
	
	};
}
