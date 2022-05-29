#pragma once
#include "EndState.h"
#include "Game.h"
class PlayState : public GameState
{
public:
	~PlayState() override = default;

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:
};
