#pragma once
#include "Game.h"
#include "EndState.h"
#include <cassert>

class PlayState final : public GameState
{
public:
	~PlayState() override = default;

	bool OnEnter() override;
	GameState *Update() override;
	bool Render() override;
	void OnExit() override;

private:
	std::unique_ptr<Background> m_background;
	std::unique_ptr<CowboyP2> m_cowboy;
	std::unique_ptr<Player> m_player;
	std::unique_ptr<Bullet> m_bullet;
	std::unique_ptr<Score> m_score;
	std::unique_ptr<Timer> m_timer;
};