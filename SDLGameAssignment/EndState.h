#pragma once
#include "Game.h"
class EndState : public GameState
{
public:
	~EndState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
private:
	std::unique_ptr<Background>m_background;
	std::unique_ptr<MenuOptions>m_replay;
};