#pragma once
#include "Game.h"
#include "EndState.h"
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