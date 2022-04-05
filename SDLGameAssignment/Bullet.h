#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Sound.h"
class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet();
	const BoxCollider& GetCollider() const;
	int SetVelocity(int velocity);
	void ShootSound();
	virtual void Update();
	virtual void Render();
private:
	int m_speed = 12; //Making velocity with Scalar speed and direction vectors
	Vector2D m_direction {0,0};
	Sound m_gunshot;
	Sprite m_images;	//Spritesheet
	BoxCollider m_collider;
};