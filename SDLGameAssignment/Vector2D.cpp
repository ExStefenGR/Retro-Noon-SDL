#include "Vector2D.h"

Vector2D::Vector2D(int x, int y)
{
	this->x = x;
	this->y = y;
}

Vector2D::~Vector2D()
{
}

Vector2D Vector2D::Add(const Vector2D& rhs)
{
	Vector2D result;

	result.x = x + rhs.x;
	result.y = y + rhs.y;

	return result;
}

Vector2D Vector2D::Subtract(const Vector2D& rhs)
{
	Vector2D result;

	result.x = x - rhs.x;
	result.y = y - rhs.y;
	return result;
}

Vector2D Vector2D::Scale(const Vector2D& rhs)
{
	Vector2D result;

	result.x = x * rhs.x;
	result.y = y * rhs.y;

	return result;
}
Vector2D Vector2D::Scale(int second)
{
	Vector2D result;

	result.x = x * second;
	result.y = y * second;

	return result;
}

int Vector2D::Distance(const Vector2D& rhs)
{
	Vector2D result = Subtract(rhs);

	return static_cast<int>(result.Magnitude());
}

int Vector2D::Magnitude()
{
	double x = static_cast<double>(this->x);
	double y = static_cast<double>(this->y);

	return static_cast<int>(sqrt((x * x) + (y * y)));
}

Vector2D Vector2D::Negate()
{
	Vector2D result;

	result.x = x * -1;
	result.y = y * -1;
	return result;
}
