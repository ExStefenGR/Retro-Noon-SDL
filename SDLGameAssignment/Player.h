#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Bullet.h"
#include "CowboyP2.h"

class Player : public GameObject
{
public:
	enum class State
	{
		Idle,
		Up,
		Down,
		Total_States
	};

	Player();
	~Player();

	void SetVelocity(float velocity);
	const BoxCollider& GetCollider() const;
	virtual void Update();
	virtual void Render();
	bool IsBulletShot();
	void IsBulletShot(bool flag);

	bool IsColliding(const CowboyP2& cowboy)
	{
		//check for collision with player/enemy collider
		//if they collide update score
		//reduce cowboy health
	}

private:

	State m_state = State::Idle;
	Sprite m_image[static_cast<int>(State::Total_States)];   //spritesheet container
	Vector2D m_direction {0,0};
	bool m_isBulletShot{ false };
	BoxCollider m_collider;
	float m_velocity{ 0.0f };
	Sound m_gunshot;
};