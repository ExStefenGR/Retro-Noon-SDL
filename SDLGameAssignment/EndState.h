#pragma once
#include "Game.h"
#include "PlayState.h"
#include <memory>
class EndState : public GameState
{
public:
	~EndState() override = default;

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
};