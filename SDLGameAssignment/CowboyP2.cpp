#include "CowboyP2.h"

CowboyP2::CowboyP2(Screen& screen)
{
	m_state = UP;
	m_isBulletShot = false;
	m_image[UP].Load("Assets/Images/Cboy2UP.png", screen);
	m_image[DOWN].Load("Assets/Images/Cboy2DOWN.png", screen);

	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_image[i].SetImageDimension(3, 1, 384, 128);
		m_image[i].SetSpriteDimension(128, 128);
		m_image[i].SetAnimationVelocity(0.5f);
		m_image[i].IsAnimated(true);
		m_image[i].IsAnimationLooping(true);
	}
	m_isTopReached = false;
	m_isBotReached = false;
	m_velocity = 0;

	m_collider.SetDimension(128, 128);
}

CowboyP2::~CowboyP2()
{
	m_image[DOWN].Unload();
}

const BoxCollider& CowboyP2::GetCollider() const
{
	return m_collider;
}

Vector2D CowboyP2::SetVelocity(int velocity)
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

void CowboyP2::Update(Input& input)
{
	input.Update();
	//Below I could use the same function for the next assignment as a second player in a competitive setting
	//Could be used with a flag "isPlayer" but updating only works with one button at a time with current input class
	/*if (input.getKeyDown() == SDLK_i)
	{
		m_position.y -= m_velocity;
	}
	else if (input.getKeyDown() == SDLK_k)
	{
		m_position.y += m_velocity;
	}*/

	if (input.getKeyDown() == SDLK_a)
	{
		m_isBulletShot = true;
	}

	if (m_position.y == 226)
	{
		m_isTopReached = true;
	}
	if (m_position.y == 720 - 128)
	{
		m_isTopReached = false;
	}

	if (!m_isTopReached)
	{
		m_position.y -= m_velocity;

		m_state = UP;
	}
	if (m_isTopReached)
	{
		m_position.y += m_velocity;

		m_state = DOWN;
	}

	if (m_position.y < 226)
	{
		m_position.y = 226;
	}
	else if (m_position.y >= 720 - 128)
	{
		m_position.y = 720 - 128;
	}
	m_image[m_state].Update();

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void CowboyP2::Render(Screen& screen)
{
	m_image[m_state].Render(m_position.x, m_position.y, m_angle, screen);
}
