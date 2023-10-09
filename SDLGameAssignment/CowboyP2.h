#pragma once

#include "BoxCollider.h"
#include "GameObject.h"
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
	CowboyP2();
	virtual ~CowboyP2();
	[[nodiscard]] const BoxCollider &GetCollider() const;
	Vector<int> SetVelocity(int velocity);
	[[nodiscard]] bool IsBulletShot() const;
	void IsBulletShot(bool flag);
	void Update() final;
	void Render() final;

private:
	bool m_isTopReached{false};
	bool m_isBotReached{false};
	bool m_isBulletShot{false};
	int m_velocity{0};
	Sprite m_image[static_cast<int>(State::Total_States)]; // image container
	State m_state{State::Up};
	BoxCollider m_collider{};
};