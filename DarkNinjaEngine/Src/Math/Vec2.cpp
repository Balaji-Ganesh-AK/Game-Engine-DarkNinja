#include "pch.h"
#include "Vec2.h"

namespace Engine
{
	Vec2::Vec2()
	{
			x = 0;
			y = 0;
	}
	Vec2::Vec2(const float& x, const float& y)
	{
		this->x = x;
		this->y = y;
	}
 	Vec2& Vec2::Random(const float& other)
	{
		this->x = static_cast<float>(rand() % 100);
		this->y = static_cast<float>(rand() % 100);
		return *this;
		

	}
	Vec2& Vec2::addition(const Vec2& other)
	{
		x += other.x;
		y += other.y;

		return *this;
	}
	Vec2& Vec2::subtraction(const Vec2& other)
	{
		x -= other.x;
		y -= other.y;

		return *this;
	}
	Vec2& Vec2::division(const Vec2& other)
	{
		x /= other.x;
		y /= other.y;
		return *this;
	}
	Vec2& Vec2::multiplication(const Vec2& other)
	{
		x *= other.x;
		y *= other.y;
		return *this;
	}
	//operator overloading
	Vec2& Vec2::operator+=(const Vec2&other)
	{
		return addition(other);
	}
	Vec2& Vec2::operator+(const Vec2&other)
	{
		return addition(other);
	}
	Vec2& Vec2::operator-=(const Vec2&other)
	{
		return subtraction(other);
	}
	Vec2& Vec2::operator-(const Vec2&other)
	{
		return subtraction(other);
	}
	//Negation
	Vec2& Vec2::operator-()
	{
		this->x = -1 * this->x;
		this->y = -1 * this->y;
		return *this;
	}
	Vec2& Vec2::operator/=(const Vec2&other)
	{
		return division(other);
	}
	Vec2 operator/(Vec2 left, const Vec2 &right)
	{
		return left.division(right);
	}
	bool Vec2::operator==(const Vec2 & other)
	{
		return x == other.x && y == other.y;
	}
	bool Vec2::operator!=(const Vec2 & other)
	{
		return !(*this == other);
	}
	Vec2 operator*(Vec2 left, const Vec2 &right)
	{
		return left.multiplication(right);
	}
	Vec2& Vec2::operator*=(const Vec2&other)
	{
		return multiplication(other);
	}
	Vec2::~Vec2()
	{
	}

	Vec2 Vec2::zero()
	{
		this->x = 0;
		this->y = 0;
		return *this;
	}

	//scaler
	Vec2& Vec2::operator+=(const float&other)
	{
		this->x = other + this->x;
		this->y = other + this->y;
		return *this;
	}
	Vec2& Vec2::operator+(const float&other)
	{
		this->x = other + this->x;
		this->y = other + this->y;
		return *this;
	}
	Vec2& Vec2::operator-=(const float&other)
	{
		this->x = other - this->x;
		this->y = other - this->y;
		return *this;
	}

	Vec2& Vec2::operator-(const float&other)
	{
		this->x = other - this->x;
		this->y = other - this->y;
		return *this;
	}
	Vec2& Vec2::operator*(const float&other)
	{
		this->x = other * this->x;
		this->y = other * this->y;
		return *this;
	}
	Vec2& Vec2::operator*=(const float&other)
	{
		this->x = other * this->x;
		this->y = other * this->y;
		return *this;
	}
	Vec2& Vec2::operator/=(const float&other)
	{
		this->x = other / this->x;
		this->y = other / this->y;
		return *this;
	}
	Vec2& Vec2::operator/(const float&other)
	{
		this->x = other / this->x;
		this->y = other / this->y;
		return *this;
	}

	// Printing overloading
	std::ostream & operator<<(std::ostream & stream, const Vec2 & vector2D)
	{
		stream << "("<<vector2D.x <<","<< vector2D.y <<")";
		return stream;
	}
}
