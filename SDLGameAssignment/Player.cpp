#include "Player.h"
#include <assert.h>
#include <algorithm>

Player::Player()
{
	m_image[static_cast<int>(State::Idle)].Load("Assets/Images/CboyIDLE.png");
	m_image[static_cast<int>(State::Up)].Load("Assets/Images/CboyUP.png");
	m_image[static_cast<int>(State::Down)].Load("Assets/Images/CboyDOWN.png");
	for (int i = 0; i < static_cast<int>(State::Total_States); i++)
	{
		m_image[i].SetImageDimension(3, 1, 384, 128);
		m_image[i].SetSpriteDimension(128, 128);
		m_image[i].SetAnimationVelocity(0.5f);
		m_image[i].IsAnimated(true);
		m_image[i].IsAnimationLooping(true);
	}
}
Player::~Player()
{
	m_image[static_cast<int>(State::Up,State::Down)].Unload();
}
void Player::SetVelocity(float velocity)
{
	//assert(velocity > 0);
	velocity = std::clamp(velocity, 0.0f, 100.0f);
	m_velocity = velocity;
}
const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}
void Player::Update()
{
	if (Input::Instance()->IsKeyPressed(HM_KEY_W))
	{
		m_direction.y = -1;
		m_direction.x = 0;
		m_state = State::Up;
	}
	else if (Input::Instance()->IsKeyPressed(HM_KEY_S))
	{
		m_direction.y = 1;
		m_direction.x = 0;
		m_state = State::Down;
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = State::Idle;
	}
	//====================Bullet Update=======================
	if (Input::Instance()->IsKeyPressed(HM_KEY_D))
	{
		m_isBulletShot = true;
	}
	if (m_position.y < 420)
	{
		m_position.y = 420;
	}
	else if (m_position.y >= 952)
	{
		m_position.y = 952;
	}
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);
	m_image[static_cast<int>(m_state)].Update();
	m_collider.Update();
}
void Player::Render()
{
	m_image[static_cast<int>(m_state)].Render(m_position.x, m_position.y, m_angle);
}
bool Player::IsBulletShot()
{
	return m_isBulletShot;
}
void Player::IsBulletShot(bool flag)
{
	m_isBulletShot = flag;
}