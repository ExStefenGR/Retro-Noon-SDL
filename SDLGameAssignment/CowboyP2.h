#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
#include "Input.h"
#include "Sprite.h"

class CowboyP2 : public GameObject
{
	enum State
	{
		UP,
		DOWN,
		TOTAL_STATES
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
	bool m_isTopReached;
	bool m_isBotReached;
	bool m_isBulletShot;
	int m_velocity;

	Sprite m_image[TOTAL_STATES];     //image container
	State m_state;
	BoxCollider m_collider;
};

