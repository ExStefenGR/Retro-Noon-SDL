#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Sound.h"

class Bullet : public GameObject
{
public:
	Bullet(Screen& screen);
	~Bullet();

	const BoxCollider& GetCollider() const;

	int SetVelocity(int velocity);
	void ResetPos(Vector2D a, Vector2D b);
	void ShootSound();

	virtual void Update(Input& input);
	virtual void Render(Screen& screen);

private:
	int m_speed; //Making velocity with Scalar speed and direction vectors
	Vector2D m_direction;
	Vector2D m_fireDirection;
	Sound m_gunshot;
	Sprite m_images;	//Spritesheet
	BoxCollider m_collider;
};

