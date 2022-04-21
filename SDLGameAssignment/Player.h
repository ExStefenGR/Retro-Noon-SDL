#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Bullet.h"

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
	Vector2D SetVelocity(int velocity);
	const BoxCollider& GetCollider() const;
	virtual void Update();
	virtual void Render();
	bool IsBulletShot();
	void IsBulletShot(bool flag);
protected:
	State m_state = State::Idle;
	Sprite m_image[static_cast<int>(State::Total_States)];   //spritesheet container
	Vector2D m_direction = {0,0};
	bool m_isBulletShot = false;
	BoxCollider m_collider;
	float m_velocity = 0;
	Sound m_gunshot = {};
};