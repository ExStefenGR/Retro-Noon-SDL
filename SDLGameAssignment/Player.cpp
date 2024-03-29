#include "Player.h"
#include <cassert>
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
	m_bullet = std::make_unique<Bullet>();
	m_cowboy = std::make_unique<CowboyP2>();
	m_bullet->SetSize(32, 32);
	return;
}
void Player::SetVelocity(int velocity)
{
	velocity = std::clamp(velocity, 0, 100);
	m_velocity = velocity;
}
const BoxCollider &Player::GetCollider() const
{
	return m_collider;
}
void Player::Update()
{
	//====================Other Updates=======================
	m_collider.Update();
	m_cowboy->Update();
	//====================Animation/Direction Update=======================
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
	//====================Boundaries Update=======================
	if (m_position.y < 420)
	{
		m_position.y = 420;
	}
	else if (m_position.y > 952)
	{
		m_position.y = 952;
	}
	else
	{
		m_direction = m_direction * m_velocity;
		m_position = m_position + m_direction;
		m_image[static_cast<int>(m_state)].Update();
	}
	//====================Bullet Update=======================
	if (Input::Instance()->IsKeyPressed(HM_KEY_D))
	{
		m_isBulletShot = true;
	}
	if (IsBulletShot() && !m_bullet->IsActive())
	{
		m_bullet->ShootSound();
		m_bullet->IsActive(true);
		m_bullet->IsVisible(true);
		m_bullet->SetPosition(GetPosition());
	}
	else if (m_bullet->GetPosition().x > 1920)
	{
		m_bullet->IsActive(false);
		m_bullet->IsVisible(false);
		m_bullet->SetPosition(GetPosition());
		IsBulletShot(false);
	}
	else if (!m_isBulletShot && !m_bullet->IsActive())
	{
		m_bullet->SetPosition(GetPosition());
	}
	else
	{
		return;
	}
}
void Player::Render()
{
	if (m_isBulletShot)
	{
		m_bullet->Render();
	}
	m_cowboy->Render();
	m_image[static_cast<int>(m_state)].Render(m_position.x, m_position.y, m_angle);
}
bool Player::IsBulletShot() const
{
	return m_isBulletShot;
}
void Player::IsBulletShot(bool flag)
{
	m_isBulletShot = flag;
}

bool Player::IsBulletColliding()
{
	m_bullet->Update();
	m_cowBoyCollider = m_cowboy->GetCollider();
	m_bulletCollider = m_bullet->GetCollider();
	if (m_bulletCollider.IsColliding(m_cowBoyCollider))
	{
		m_bullet->IsActive(false);
		m_bullet->IsVisible(false);
		m_bullet->SetPosition(GetPosition());
		IsBulletShot(false);
		return true;
	}
	return false;
}
