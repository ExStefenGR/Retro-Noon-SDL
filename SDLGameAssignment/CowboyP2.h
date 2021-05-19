#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "BoxCollider.h"

class CowboyP2 : public GameObject
{
public:

	CowboyP2(Screen& screen);
	~CowboyP2();


	const BoxCollider& GetCollider() const;

	int SetVelocity(int velocity);

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

protected:

	bool isTopReached;
	bool isBotReached;
	int m_velocity;
	Sprite m_images;     //image container

	BoxCollider m_collider;
};

