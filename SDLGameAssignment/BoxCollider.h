#pragma once
#include "Vector.h"
class BoxCollider
{
public:
	BoxCollider() = default;
	~BoxCollider() = default;
	void SetPosition(int x, int y);
	void SetDimension(int width, int height);
	void Update();
	[[nodiscard]] bool IsColliding(const BoxCollider &secondBox) const;

private:
	Vector<int> m_dimension{0, 0};
	Vector<int> m_position{0, 0};
	Vector<int> m_min{0, 0};
	Vector<int> m_max{0, 0};
};