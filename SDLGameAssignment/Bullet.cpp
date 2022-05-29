#include "Bullet.h"

Bullet::Bullet()
{
	m_images.Load("Assets/Images/Bullet.png");
	m_images.SetImageDimension(1, 1, 32, 32);
	m_images.SetSpriteDimension(32, 32);
	m_collider.SetDimension(32, 32);
	m_gunshot.Load("Assets/Sounds/gunshot.wav");
	m_gunshot.SetVolume(20);
	return;
}
Bullet::~Bullet()
{
	m_images.Unload();
	m_gunshot.Unload();
	return;
}
const BoxCollider& Bullet::GetCollider() const
{
	return m_collider;
}
int Bullet::SetVelocity(int speed)
{
	m_speed = speed;
	return m_speed;
}
void Bullet::ShootSound()
{
	m_gunshot.Play();
}
void Bullet::Update()
{	
	m_direction = Vector<int>(1, 0);
	m_direction = m_direction * m_speed;
	m_position = m_position + m_direction;
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}
void Bullet::Render()
{
	m_images.Render(m_position.x, m_position.y, m_angle);
}