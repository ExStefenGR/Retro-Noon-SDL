#include "CowboyP2.h"

CowboyP2::CowboyP2()
{
	m_image[static_cast<int>(State::Up)].Load("Assets/Images/Cboy2UP.png");
	m_image[static_cast<int>(State::Down)].Load("Assets/Images/Cboy2DOWN.png");
	for (int i = 0; i < static_cast<int>(State::Total_States); i++)
	{
		m_image[i].SetImageDimension(3, 1, 384, 128);
		m_image[i].SetSpriteDimension(128, 128);
		m_image[i].SetAnimationVelocity(0.5f);
		m_image[i].IsAnimated(true);
		m_image[i].IsAnimationLooping(true);
	}
	m_collider.SetDimension(128, 128);
	SetPosition(1690, 400);
	SetSize(128, 128);
	SetVelocity(2);
}
CowboyP2::~CowboyP2()
{
	m_image[static_cast<int>(State::Up)].Unload();
	m_image[static_cast<int>(State::Down)].Unload();
}
const BoxCollider& CowboyP2::GetCollider() const
{
	return m_collider;
}
Vector<int> CowboyP2::SetVelocity(int velocity)
{
	m_velocity = velocity;
	return m_velocity;
}
bool CowboyP2::IsBulletShot()
{
	return m_isBulletShot;
}
void CowboyP2::IsBulletShot(bool flag)
{
	m_isBulletShot = flag;
}
void CowboyP2::Update()
{
	if (Input::Instance()->IsKeyPressed(HM_KEY_A)) 
	{
		m_isBulletShot = true;
	}
	if (m_position.y == 420)
	{
		m_isTopReached = true;
	}
	if (m_position.y == 952)
	{
		m_isTopReached = false;
	}
	if (!m_isTopReached)
	{
		m_position.y -= m_velocity;
		m_state = State::Up;
	}
	if (m_isTopReached)
	{
		m_position.y += m_velocity;
		m_state = State::Down;
	}
	if (m_position.y < 420)
	{
		m_position.y = 420;
	}
	else if (m_position.y >= 952)
	{
		m_position.y = 952;
	}
	m_image[static_cast<int>(m_state)].Update();
	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}
void CowboyP2::Render()
{
	m_image[static_cast<int>(m_state)].Render(m_position.x, m_position.y, m_angle);
}