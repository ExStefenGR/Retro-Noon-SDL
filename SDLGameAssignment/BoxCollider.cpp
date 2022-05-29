#include "BoxCollider.h"

void BoxCollider::SetPosition(int const x, int const y)
{
	m_position.x = x;
	m_position.y = y;
}
void BoxCollider::SetDimension(int const width, int const height)
{
	m_dimension.x = width;
	m_dimension.y = height;
}
void BoxCollider::Update()
{
	m_min.x = m_position.x;
	m_min.y = m_position.y;

	m_max.x = m_position.x + m_dimension.x;
	m_max.y = m_position.y + m_dimension.y;
}
bool BoxCollider::IsColliding(const BoxCollider& secondBox) const
{
	return ((m_max.x > secondBox.m_min.x) && (secondBox.m_max.x > m_min.x) &&
			(m_max.y > secondBox.m_min.y) && (secondBox.m_max.y > m_min.y));
}