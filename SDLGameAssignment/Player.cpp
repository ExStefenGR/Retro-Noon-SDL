#include "Player.h"


Player::Player(Screen& screen) : m_screen(screen)
{
	m_state = IDLE;
	m_isBulletShot = false;
	m_image[IDLE].Load("Assets/Images/CboyIDLE.png", screen);
	m_image[UP].Load("Assets/Images/CboyUP.png", screen);
	m_image[DOWN].Load("Assets/Images/CboyDOWN.png", screen);
	for (int i = 0; i < TOTAL_STATES; i++)
	{
		m_image[i].SetImageDimension(3, 1, 384, 128);
		m_image[i].SetSpriteDimension(128, 128);
		m_image[i].SetAnimationVelocity(0.5f);
		m_image[i].IsAnimated(true);
		m_image[i].IsAnimationLooping(true);
	}
	m_velocity = 0;
	m_direction = 0;
}

Player::~Player()
{
	m_image[IDLE].Unload();
}

Vector2D Player::SetVelocity(int velocity)
{
	m_velocity = velocity;
	return m_velocity;
}

const BoxCollider& Player::GetCollider() const
{
	return m_collider;
}

void Player::Update(Input& input)
{
	input.Update();

	if (input.getKeyDown() == SDLK_w)
	{
		m_direction.y = -1;
		m_direction.x = 0;
		m_state = UP;
	}
	else if (input.getKeyDown() == SDLK_s)
	{
		m_direction.y = 1;
		m_direction.x = 0;
		m_state = DOWN;
	}
	else
	{
		m_direction.x = 0;
		m_direction.y = 0;
		m_state = IDLE;
	}
	m_direction = m_direction.Scale(m_velocity);
	m_position = m_position.Add(m_direction);
	//====================Bullet Update=======================
	if (input.getKeyDown() == SDLK_d)
	{
		m_isBulletShot = true;
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

void Player::Render(Screen& screen)
{
	m_image[m_state].Render(m_position.x, m_position.y, m_angle, screen);
}

bool Player::IsBulletShot()
{
	return m_isBulletShot;
}

void Player::IsBulletShot(bool flag)
{
	m_isBulletShot = flag;
}
