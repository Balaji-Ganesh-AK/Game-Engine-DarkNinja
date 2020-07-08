#pragma once
#include <iostream>
namespace Engine
{

	class Vec2
	{
	public:

		float x, y;
		Vec2();
		~Vec2();
		//int x, y;
		//operations
		//Vec2(const float & x, const float & y);
		Vec2 zero();
		Vec2(const int & x, const int & y);
		Vec2& Random(const int & other);
		Vec2& addition(const Vec2& other); // reference , just reads the values and doesnt not store them
		Vec2 & subtraction(const Vec2 & other);
		Vec2 & division(const Vec2 & other);
		Vec2 & multiplication(const Vec2 & other);
		Vec2 & operator+=(const Vec2 & other);
		Vec2 & operator+(const Vec2 & other);
		
		Vec2 & operator-=(const Vec2 & other);
		Vec2 & operator-(const Vec2 & other);
		Vec2  &operator-();
		Vec2 & operator/=(const Vec2 & other);
		friend Vec2 operator/(Vec2 left, const Vec2 & right);
		bool operator==(const Vec2 & other);
		bool operator!=(const Vec2 & other);
		Vec2 & operator*=(const Vec2 & other);

		Vec2 & operator+=(const float & other);

		Vec2 & operator+(const float & other);

		Vec2 & operator-=(const float & other);
		Vec2 & operator-(const float & other);

		Vec2 & operator*(const float & other);

		Vec2 & operator*=(const float & other);

		Vec2 & operator/=(const float & other);

		Vec2 & operator/(const float & other);

		
		

		//overloading

		

	

		//Printing the values
		friend std::ostream& operator<<(std::ostream& stream, const Vec2& vector2D);

	};
}

