#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"

class CowboyP2 : public GameObject
{
	enum class State
	{
		Up,
		Down,
		Total_States
	};
public:
	CowboyP2(Screen& screen);
	~CowboyP2();
	const BoxCollider& GetCollider() const;
	Vector2D SetVelocity(int velocity);
	bool IsBulletShot();
	void IsBulletShot(bool flag);
	virtual void Update(Input& input);
	virtual void Render(Screen& screen);
protected:
	bool m_isTopReached = false;
	bool m_isBotReached = false;
	bool m_isBulletShot = false;
	int m_velocity = 0;
	Sprite m_image[static_cast<int>(State::Total_States)];     //image container
	State m_state = State::Up;
	BoxCollider m_collider;
};

