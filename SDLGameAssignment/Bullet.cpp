#include "Bullet.h"


Bullet::Bullet(Screen& screen)
{
	
	m_speed = 10;
	m_images.Load("Assets/Images/Bullet.png", screen);
	m_images.SetImageDimension(1, 1, 32, 32);
	m_images.SetSpriteDimension(32, 32);
	m_collider.SetDimension(32, 32);

}

Bullet::~Bullet()
{
	m_images.Unload();
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

void Bullet::ResetPos(Vector2D a, Vector2D b)
{
	a = b;
}


void Bullet::Update(Input& input)
{	

	m_direction = Vector2D(1, 0);
	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);
	

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Bullet::Render(Screen& screen)
{
	m_images.Render(m_position.x, m_position.y, m_angle, screen);
}
