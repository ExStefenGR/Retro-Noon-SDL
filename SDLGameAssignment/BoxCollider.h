#pragma once

#include "Vector2D.h"
class BoxCollider
{
public:
	void SetPosition(int x, int y);
	void SetDimension(int width, int height);
	void Update();
	bool IsColliding(const BoxCollider& secondBox)const;
private:
	Vector2D m_min {0,0};
	Vector2D m_max{0,0};
	Vector2D m_dimension{0,0};
	Vector2D m_position{0,0};
};