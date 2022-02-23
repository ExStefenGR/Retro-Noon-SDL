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
	Player(Screen& screen);
	~Player();
	Vector2D SetVelocity(int velocity);
	const BoxCollider& GetCollider() const;
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);
	bool IsBulletShot();
	void IsBulletShot(bool flag);
protected:
	bool m_isBulletShot = false;
	BoxCollider m_collider;
	int m_velocity = 0;
	Screen& m_screen;
	Sound m_gunshot = {};
	Sprite m_image[static_cast<int>(State::Total_States)];   //spritesheet container
	State m_state = State::Idle;
	Vector2D m_direction = {0,0};
};