#pragma once
#include "Game.h"
class PlayState : public GameState
{
public:
	~PlayState() override {}

	bool OnEnter(Screen& screen) override;
	GameState* Update(Input& input) override;
	bool Render(Screen& screen) override;
	void OnExit(Screen& screen) override;
private:  
	BoxCollider m_cowBoyCollider = {};
	BoxCollider m_bulletCollider = {};
	std::unique_ptr<Background>m_background;
	std::unique_ptr<CowboyP2>m_cowboy;
	std::unique_ptr<Player>m_player;
	std::unique_ptr<Bullet>m_bullet;			
	std::unique_ptr<Score>m_score;
	std::unique_ptr<Timer>m_timer;
};