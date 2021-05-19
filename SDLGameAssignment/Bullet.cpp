#include "Bullet.h"
#include "Player.h"

Bullet::Bullet(Screen& screen)
{
	m_isBulletShot = false;
	m_speed = 0;
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



	if (input.getKeyDown() == SDLK_d) //Bullet begins movement from the trigger here
	{
		m_isBulletShot = true;
	}

	if (m_position.x > 1200) //If it does not collide but reaches the end of the screen !m_collider.IsColliding(m_collider)
	{
		m_isBulletShot = false;
		m_isAlive = false;
		
		m_position.x = 100;
	}

	if (m_isBulletShot) //If true, move the bullet at the velocity specified in main.cpp
	{
		m_fireDirection.x = 1;
		m_fireDirection.y = 0;
		if (m_isAlive)
		{
			m_fireDirection.x = 0;

		}
		m_fireDirection = m_fireDirection.Scale(m_speed);
		m_position = m_position.Add(m_fireDirection);
	}
	if (!m_isBulletShot)
	{

		if (input.getKeyDown() == SDLK_w)
		{
			m_direction.y = -1;
			m_fireDirection.y = -1;
		}
		else if (input.getKeyUp() == SDLK_w)
		{
			m_direction.y = 0;
			m_fireDirection.y = 0;
		}
		if (input.getKeyDown() == SDLK_s)
		{
			m_direction.y = +1;
			m_fireDirection.y = +1;
		}
		else if (input.getKeyUp() == SDLK_s)
		{
			m_direction.y = 0;
			m_fireDirection.y = 0;
		}

		m_direction = m_direction.Scale(m_speed);
		m_position = m_position.Add(m_direction);

	}

	if (m_position.y < 280)
	{
		m_position.y = 280;
		m_direction.y = -0;
		m_fireDirection.y = -0;
	}
	else if (m_position.y > 650)
	{
		m_position.y = 650;
		m_direction.y = -0;
		m_fireDirection.y = -0;
	}

	


	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void Bullet::Render(Screen& screen)
{
	//Hiding the bullet if it is not shot
	/*if (m_isBulletShot)
	{
		m_images.Render(m_position.x, m_position.y, m_angle, screen);
	}*/

	m_images.Render(m_position.x, m_position.y, m_angle, screen);
}
