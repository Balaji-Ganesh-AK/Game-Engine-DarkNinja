#pragma once
#include <iostream>
namespace Engine
{

	class vec2
	{
	public:

		float x, y;
		vec2();
		~vec2();
		//int x, y;
		//operations
		//vec2(const float & x, const float & y);
		vec2 zero();
		vec2(const float& x, const float& y);
		vec2& Random(const float& other);
		vec2& addition(const vec2& other); // reference , just reads the values and doesnt not store them
		vec2 & subtraction(const vec2 & other);
		vec2 & division(const vec2 & other);
		vec2 & multiplication(const vec2 & other);
		vec2 & operator+=(const vec2 & other);
		vec2 & operator+(const vec2 & other);
		
		vec2 & operator-=(const vec2 & other);
		vec2 & operator-(const vec2 & other);
		vec2  &operator-();
		vec2 & operator/=(const vec2 & other);
		friend vec2 operator/(vec2 left, const vec2 & right);
		bool operator==(const vec2 & other);
		bool operator!=(const vec2 & other);
		vec2 & operator*=(const vec2 & other);

		vec2 & operator+=(const float & other);

		vec2 & operator+(const float & other);

		vec2 & operator-=(const float & other);
		vec2 & operator-(const float & other);

		vec2 & operator*(const float & other);

		vec2 & operator*=(const float & other);

		vec2 & operator/=(const float & other);

		vec2 & operator/(const float & other);

		
		

		//overloading

		

	

		//Printing the values
		friend std::ostream& operator<<(std::ostream& stream, const vec2& vector2D);

	};
}

