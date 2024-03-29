#include "GameObject.h"

double GameObject::GetAngle() const
{
	return m_angle;
}
const std::string &GameObject::GetTag() const
{
	return m_tag;
}
const Vector<int> &GameObject::GetSize() const
{
	return m_size;
}
const Vector<int> &GameObject::GetPosition() const
{
	return m_position;
}
void GameObject::SetTag(const std::string_view &tag)
{
	m_tag = tag;
}
void GameObject::SetAngle(double angle)
{
	m_angle = angle;
}
void GameObject::SetPosition(int x, int y)
{
	m_position = {x, y};
}
void GameObject::SetPosition(const Vector<int> &position)
{
	m_position = position;
}
void GameObject::SetSize(const Vector<int> &size)
{
	m_size = size;
}
void GameObject::SetSize(int width, int height)
{
	m_size = {width, height};
}
bool GameObject::IsAlive() const
{
	return m_isAlive;
}
bool GameObject::IsVisible() const
{
	return m_isVisible;
}
bool GameObject::IsActive() const
{
	return m_isActive;
}
void GameObject::IsAlive(bool flag)
{
	m_isAlive = flag;
}
void GameObject::IsVisible(bool flag)
{
	m_isVisible = flag;
}
void GameObject::IsActive(bool flag)
{
	m_isActive = flag;
}