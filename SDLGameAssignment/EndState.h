#pragma once
#include "Game.h"
#include "PlayState.h"
#include <memory>
class EndState final : public GameState
{
public:
	~EndState() override = default;

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
private:
	std::unique_ptr<Background>m_background;
	std::unique_ptr<MenuOptions>m_replay;
	std::unique_ptr<Score>m_score;
};