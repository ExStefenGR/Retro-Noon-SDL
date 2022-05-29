#pragma once
#include <memory>

#include "Game.h"
#include "PlayState.h"
class EndState : public GameState
{
public:
	~EndState() override = default;

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;
};
