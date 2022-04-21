#include <math.h>
#include "Vector2D.h"

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D Vector2D::Add(const Vector2D& second)
{
	Vector2D result;

	result.x = x + second.x;
	result.y = y + second.y;

	return result;
}

Vector2D Vector2D::Subtract(const Vector2D& second)
{
	Vector2D result;

	result.x = x - second.x;
	result.y = y - second.y;

	return result;
}

Vector2D Vector2D::Scale(float second)
{
	Vector2D result;

	result.x = x * second;
	result.y = y * second;

	return result;
}

Vector2D Vector2D::Scale(const Vector2D& second)
{
	Vector2D result;

	result.x = x * second.x;
	result.y = y * second.y;

	return result;
}

Vector2D Vector2D::Divide(int second)
{
	Vector2D result;

	/*
	if (second != 0)
	{
		//auto automatically detect what type the variable is.
		auto tempX = static_cast<double>(x) / second;
		auto tempY = static_cast<double>(y) / second;
		result = Vector2D(tempX, tempY);
	}
	*/
	if (second != 0)
	{
		//auto automatically detect what type the variable is.
		result.x = x / second;
		result.y = y / second;
	}

	return result;
}

Vector2D Vector2D::Negate()
{
	Vector2D result;

	result.x = x * -1;
	result.y = y * -1;

	return result;
}

Vector2D Vector2D::Normalize()
{
	Vector2D result;

	if (Magnitude() != 0)
	{
		result = Divide(Magnitude());
	}

	return result;
}

double Vector2D::Magnitude()
{
	double x = static_cast<double>(this->x);
	double y = static_cast<double>(this->y);

	return (sqrt((x * x) + (y * y)));
}

int Vector2D::Distance(const Vector2D& second)
{
	Vector2D temp = Subtract(second);
	return static_cast<int>(temp.Magnitude());
}