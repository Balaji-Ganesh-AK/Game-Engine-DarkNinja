#include "pch.h"
#include "Vec4.h"


namespace Engine
{

	vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
	{
		
	}

	vec4 vec4::Down()
	{
		vec4 temp;
		temp.x = 0.0;
		temp.y = -1.0;
		temp.z = 0.0;
		temp.w = 0.0;
		return temp;
	}

	vec4 vec4::Zero()
	{
		vec4 temp;
		temp.x = 0.0;
		temp.y = 0.0;
		temp.z = 0.0;
		temp.w = 0.0;
		return temp;
	}

	vec4 vec4::Up()
	{
		vec4 temp;
		temp.x = 0;
		temp.y = 1;
		temp.z = 0;
		temp.w = 0.0;
		return temp;
	}

	vec4 vec4::Right()
	{
		vec4 temp;
		temp.x = 1;
		temp.y = 0;
		temp.z = 0;
		temp.w = 0.0;
		return temp;
	}

	vec4 vec4::Left()
	{
		vec4 temp;
		temp.x = -1;
		temp.y = 0;
		temp.z = 0;
		temp.w = 0.0; 
		return temp;
	}

	vec4& vec4::Add(const vec4& other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	vec4& vec4::Subtract(const vec4& other)
	{
		y -= other.y;
		x -= other.x;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	vec4& vec4::Multiply(const vec4& other)
	{
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	vec4& vec4::Divide(const vec4& other)
	{
		x /= other.x;
		y /= other.y;
		y /= other.z;
		w /= other.w;
		return *this;
	}

	vec4& vec4::Add(float value)
	{
		x += value;
		y += value;
		z -= value;
		w -= value;
		return *this;
	}

	vec4& vec4::Subtract(float value)
	{
		x -= value;
		y -= value;
		z -= value;
		w -= value;
		return *this;
	}

	vec4& vec4::Multiply(float value)
	{
		x *= value;
		y *= value;
		z *= value;
		w *= value;
		return *this;
	}

	vec4& vec4::Divide(float value)
	{
		x /= value;
		y /= value;
		z /= value;
		w /= value;
		return *this;
	}

	bool vec4::operator==(const vec4& other) const
	{
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool vec4::operator!=(const vec4& other) const
	{
		return !(*this == other);
	}

	bool vec4::operator>(const vec4& other) const
	{
		return x > other.x && y > other.y && z > other.z && w > other.w;
	}

	bool vec4::operator<(const vec4& other) const
	{
		return x < other.x && y < other.y && z < other.z && w< other.w;
	}

	bool vec4::operator>=(const vec4& other) const
	{
		return x >= other.x && y >= other.y && z >= other.z && w >=other.w;
	}

	bool vec4::operator<=(const vec4& other) const
	{
		return x <= other.x && y <= other.y && z <= other.z && w<=other.w;
	}

	vec4 vec4::operator+=(const vec4& other)
	{
		return Add(other);
	}

	vec4 vec4::operator-=(const vec4& other)
	{
		return Subtract(other);
	}

	vec4 vec4::operator*=(const vec4& other)
	{
		return Multiply(other);
	}

	vec4 vec4::operator/=(const vec4& other)
	{
		return Divide(other);
	}

	vec4 vec4::operator+=(float value)
	{
		return Add(value);
	}

	vec4 vec4::operator-=(float value)
	{
		return Subtract(value);
	}

	vec4 vec4::operator*=(float value)
	{
		return Multiply(value);
	}

	vec4 vec4::operator/=(float value)
	{
		return Divide(value);
	}

	float vec4::Magnitude() const
	{
		return sqrt(x * x + y * y + z * z + w*w);
	}

	vec4 vec4::Normalize() const
	{
		float temp = Magnitude();
		return vec4(x / temp, y / temp, z / temp, w/temp);
	}

	float vec4::Dot(const vec4& other) const
	{
		return x * other.x + y * other.y + z * other.z + w*other.w;
	}

	vec4 operator+(vec4 left, const vec4& right)
	{
		return left.Add(right);
	}

	vec4 operator-(vec4 left, const vec4& right)
	{
		return left.Subtract(right);
	}

	vec4 operator*(vec4 left, const vec4& right)
	{
		return left.Multiply(right);
	}

	vec4 operator/(vec4 left, const vec4& right)
	{
		return left.Divide(right);
	}

	vec4 operator+(vec4 left, float value)
	{
		return  vec4(left.x + value, left.y + value, left.z + value, left.w+value);
	}

	vec4 operator-(vec4 left, float value)
	{
		return  vec4(left.x - value, left.y - value, left.z - value, left.w - value);
	}

	vec4 operator*(vec4 left, float value)
	{
		return  vec4(left.x * value, left.y * value, left.z * value , left.w* value);
	}

	vec4 operator/(vec4 left, float value)
	{
		return  vec4(left.x / value, left.y / value, left.z / value, left.z / value);
	}

	std::ostream& operator<<(std::ostream& stream, const vec4& other)
	{
		stream << "(" << other.x << "," << other.y << "," << other.z << ","<<other.w <<")";
		return stream;
	}
}
