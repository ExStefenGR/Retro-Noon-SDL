#pragma once
#include "Game.h"
#include "PlayState.h"
class MenuState : public GameState
{
public:
	~MenuState() override = default;

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
};