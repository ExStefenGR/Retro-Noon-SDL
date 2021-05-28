#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Sound.h"
class EnemyBullet : public GameObject
{
public:
	EnemyBullet(Screen& screen);
	~EnemyBullet();

	const BoxCollider& GetCollider() const;

	int SetVelocity(int speed);
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