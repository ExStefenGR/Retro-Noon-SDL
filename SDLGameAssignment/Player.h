#pragma once

#include "GameObject.h"
#include "Sprite.h"
#include "Sound.h"
#include "Input.h"
#include "BoxCollider.h"
#include "Bullet.h"
#include "CowboyP2.h"
#include <memory>

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
	~Player() override = default;

	void SetVelocity(int velocity);
	const BoxCollider& GetCollider() const;
	void Update() final;
	void Render() final;
	bool IsBulletShot() const;
	void IsBulletShot(bool flag);

	bool IsBulletColliding();
private:
	Sprite m_image[static_cast<int>(State::Total_States)];   //spritesheet container
	BoxCollider m_cowBoyCollider{};
	BoxCollider m_bulletCollider{};
	std::unique_ptr<CowboyP2>m_cowboy;
	std::unique_ptr<Bullet>m_bullet;
	State m_state{ State::Idle };
	BoxCollider m_collider;
	Sound m_gunshot;

	int m_velocity{ 0 };
	bool m_isBulletShot{ false };
	Vector<int> m_direction{ 0,0 };
};