#include "EnemyBullet.h"

EnemyBullet::EnemyBullet(Screen& screen)
{
	m_speed = 10;
	m_images.Load("Assets/Images/BulletFlipped.png", screen);
	m_images.SetImageDimension(1, 1, 32, 32);
	m_images.SetSpriteDimension(32, 32);
	m_collider.SetDimension(32, 32);
	m_gunshot.Load("Assets/Sounds/gunshot.wav");
	m_gunshot.SetVolume(7);
}

EnemyBullet::~EnemyBullet()
{
	m_images.Unload();
}

const BoxCollider& EnemyBullet::GetCollider() const
{
	return m_collider;
}

int EnemyBullet::SetVelocity(int speed)
{
	m_speed = speed;
	return m_speed;
}

void EnemyBullet::ShootSound()
{
	m_gunshot.Play();
}

void EnemyBullet::Update(Input& input)
{
	m_direction = Vector2D(-1, 0);
	m_direction = m_direction.Scale(m_speed);
	m_position = m_position.Add(m_direction);

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void EnemyBullet::Render(Screen& screen)
{
	m_images.Render(m_position.x, m_position.y, m_angle, screen);
}
