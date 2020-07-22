#include "pch.h"
#include "Vec3.h"


namespace Engine
{
	vec3::vec3() :x(0.0f), y(0.0f), z(0.0f)
	{
	}

	vec3::vec3(float x, float y, float z) : x(x), y(y),z(z)
	{
	}

	vec3 vec3::Down()
	{
		vec3 temp;
		temp.x = 0.0;
		temp.y = 1.0;
		temp.z = 0.0;
		return temp;
	}

	vec3 vec3::Zero()
	{
		vec3 temp;
		temp.x = 0.0;
		temp.y = 0.0;
		temp.z = 0.0;
		return temp;
	}

	vec3 vec3::Up()
	{
		vec3 temp;
		temp.x = 0;
		temp.y = -1;
		temp.z = 0;
		return temp;
	}

	vec3 vec3::Right()
	{
		vec3 temp;
		temp.x = 1;
		temp.y = 0;
		temp.z = 0;
		return temp;
	}

	vec3 vec3::Left()
	{
		vec3 temp;
		temp.x = -1;
		temp.y = 0;
		temp.z = 0;
		return temp;
	}

	vec3& vec3::Add(const vec3& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	vec3& vec3::Subtract(const vec3& other)
	{
		y -= other.y;
		x -= other.x;
		z -= other.z;
		return *this;
	}

	vec3& vec3::Multiply(const vec3& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	vec3& vec3::Divide(const vec3& other)
	{
		x /= other.x;
		y /= other.y;
		y /= other.z;
		return *this;
	}

	vec3& vec3::Add(float value)
	{
		x += value;
		y += value;
		z -= value;
		return *this;
	}

	vec3& vec3::Subtract(float value)
	{
		x -= value;
		y -= value;
		z -= value;
		return *this;
	}

	vec3& vec3::Multiply(float value)
	{
		x *= value;
		y *= value;
		z *= value;
		return *this;
	}

	vec3& vec3::Divide(float value)
	{
		x /= value;
		y /= value;
		z /= value;
		return *this;
	}

	bool vec3::operator==(const vec3& other) const
	{
		return x == other.x && y == other.y && z ==other.z;
	}

	bool vec3::operator!=(const vec3& other) const
	{
		return !(*this == other);
	}

	bool vec3::operator>(const vec3& other) const
	{
		return x > other.x && y > other.y && z > other.z;
	}

	bool vec3::operator<(const vec3& other) const
	{
		return x < other.x && y < other.y && z< other.z;
	}

	bool vec3::operator>=(const vec3& other) const
	{
		return x >= other.x && y >= other.y && z>= other.z;
	}

	bool vec3::operator<=(const vec3& other) const
	{
		return x <= other.x && y <= other.y && z<= other.z;
	}

	vec3 vec3::operator+=(const vec3& other)
	{
		return Add(other);
	}

	vec3 vec3::operator-=(const vec3& other)
	{
		return Subtract(other);
	}

	vec3 vec3::operator*=(const vec3& other)
	{
		return Multiply(other);
	}

	vec3 vec3::operator/=(const vec3& other)
	{
		return Divide(other);
	}

	vec3 vec3::operator+=(float value)
	{
		return Add(value);
	}

	vec3 vec3::operator-=(float value)
	{
		return Subtract(value);
	}

	vec3 vec3::operator*=(float value)
	{
		return Multiply(value);
	}

	vec3 vec3::operator/=(float value)
	{
		return Divide(value);
	}

	float vec3::Magnitude() const
	{
		return sqrt(x * x + y * y + z*z);
	}

	vec3 vec3::Normalize() const
	{
		float temp = Magnitude();
		return vec3(x / temp, y / temp , z/temp);
	}

	float vec3::Dot(const vec3& other) const
	{
		return x * other.x + y * other.y + z*other.z;
	}

	vec3 operator+(vec3 left, const vec3& right)
	{
		return left.Add(right);
	}

	vec3 operator-(vec3 left, const vec3& right)
	{
		return left.Subtract(right);
	}

	vec3 operator*(vec3 left, const vec3& right)
	{
		return left.Multiply(right);
	}

	vec3 operator/(vec3 left, const vec3& right)
	{
		return left.Divide(right);
	}

	vec3 operator+(vec3 left, float value)
	{
		return  vec3(left.x + value, left.y + value , left.z + value);
	}

	vec3 operator-(vec3 left, float value)
	{
		return  vec3(left.x - value, left.y - value ,left.z - value);
	}

	vec3 operator*(vec3 left, float value)
	{
		return  vec3(left.x * value, left.y * value, left.z *value);
	}

	vec3 operator/(vec3 left, float value)
	{
		return  vec3(left.x / value, left.y / value, left.z /value);
	}

	std::ostream& operator<<(std::ostream& stream, const vec3& other)
	{
		stream << "(" << other.x << "," << other.y << "," <<other.z <<")";
		return stream;
	}
}
