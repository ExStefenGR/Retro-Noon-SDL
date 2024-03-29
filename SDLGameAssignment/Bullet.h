#pragma once
#include "GameObject.h"
#include "Sprite.h"
#include "BoxCollider.h"
#include "Sound.h"
class Bullet : public GameObject
{
public:
	Bullet();
	virtual ~Bullet();
	[[nodiscard]] const BoxCollider &GetCollider() const;
	int SetVelocity(int velocity);
	void ShootSound();
	void Update() final;
	void Render() final;

private:
	int m_speed{12}; // Making velocity with Scalar speed and direction vectors
	Vector<int> m_direction{0, 0};
	Sound m_gunshot;
	Sprite m_images; // Spritesheet
	BoxCollider m_collider;
};