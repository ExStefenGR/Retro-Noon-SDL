#include "CowboyP2.h"

CowboyP2::CowboyP2(Screen& screen)
{
	m_images.Load("Assets/Images/characters.png", screen);
	m_images.SetSpriteDimension(128, 128);
	m_images.SetImageDimension(2, 1, 256, 128); //Check
	m_images.SetImageCel(2, 1);

	isTopReached = false;
	isBotReached = false;
	m_velocity = 0;
	m_collider.SetDimension(128, 128);
}

CowboyP2::~CowboyP2()
{
	m_images.Unload();
}

const BoxCollider& CowboyP2::GetCollider() const
{
	return m_collider;
}

int CowboyP2::SetVelocity(int velocity)
{
	m_velocity = velocity;
	return m_velocity;
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

	if (m_position.y == 226)
	{
		isTopReached = true;
	}

	if (m_position.y == 720 - 128)
	{
		isTopReached = false;
	}

	if (!isTopReached)
	{
		m_position.y -= m_velocity;
	}
	if (isTopReached)
	{
		m_position.y += m_velocity;
	}

	if (m_position.y < 226)
	{
		m_position.y = 226;
	}

	else if (m_position.y >= 720 - 128)
	{
		m_position.y = 720 - 128;
	}

	m_collider.SetPosition(m_position.x, m_position.y);
	m_collider.Update();
}

void CowboyP2::Render(Screen& screen)
{
	m_images.Render(m_position.x, m_position.y, m_angle, screen);
}
