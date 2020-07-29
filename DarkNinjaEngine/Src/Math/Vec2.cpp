#include "pch.h"
#include "vec2.h"

namespace Engine
{
	vec2::vec2()
	{
			x = 0;
			y = 0;
	}
	vec2::vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}
 	vec2& vec2::Random(const float& other)
	{
		this->x = static_cast<float>(rand() % 100);
		this->y = static_cast<float>(rand() % 100);
		return *this;
		

	}
	vec2& vec2::addition(const vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}
	vec2& vec2::subtraction(const vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
	vec2& vec2::division(const vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}
	vec2& vec2::multiplication(const vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}
	//operator overloading
	vec2& vec2::operator+=(const vec2&other)
	{
		return addition(other);
	}
	vec2& vec2::operator+(const vec2&other)
	{
		return addition(other);
	}
	vec2& vec2::operator-=(const vec2&other)
	{
		return subtraction(other);
	}
	vec2& vec2::operator-(const vec2&other)
	{
		return subtraction(other);
	}
	//Negation
	vec2& vec2::operator-()
	{
		this->x = -1 * this->x;
		this->y = -1 * this->y;
		return *this;
	}
	vec2& vec2::operator/=(const vec2&other)
	{
		return division(other);
	}
	vec2 operator/(vec2 left, const vec2 &right)
	{
		return left.division(right);
	}
	bool vec2::operator==(const vec2 & other)
	{
		return x == other.x && y == other.y;
	}
	bool vec2::operator!=(const vec2 & other)
	{
		return !(*this == other);
	}
	vec2 operator*(vec2 left, const vec2 &right)
	{
		return left.multiplication(right);
	}
	vec2& vec2::operator*=(const vec2&other)
	{
		return multiplication(other);
	}
	vec2::~vec2()
	{
	}

	vec2 vec2::zero()
	{
		this->x = 0;
		this->y = 0;
		return *this;
	}

	//scaler
	vec2& vec2::operator+=(const float&other)
	{
		this->x = other + this->x;
		this->y = other + this->y;
		return *this;
	}
	vec2& vec2::operator+(const float&other)
	{
		this->x = other + this->x;
		this->y = other + this->y;
		return *this;
	}
	vec2& vec2::operator-=(const float&other)
	{
		this->x = other - this->x;
		this->y = other - this->y;
		return *this;
	}

	vec2& vec2::operator-(const float&other)
	{
		this->x = other - this->x;
		this->y = other - this->y;
		return *this;
	}
	vec2& vec2::operator*(const float&other)
	{
		this->x = other * this->x;
		this->y = other * this->y;
		return *this;
	}
	vec2& vec2::operator*=(const float&other)
	{
		this->x = other * this->x;
		this->y = other * this->y;
		return *this;
	}
	vec2& vec2::operator/=(const float&other)
	{
		this->x = other / this->x;
		this->y = other / this->y;
		return *this;
	}
	vec2& vec2::operator/(const float&other)
	{
		this->x = other / this->x;
		this->y = other / this->y;
		return *this;
	}

	// Printing overloading
	std::ostream & operator<<(std::ostream & stream, const vec2 & vector2D)
	{
		stream << "("<<vector2D.x <<","<< vector2D.y <<")";
		return stream;
	}
}
