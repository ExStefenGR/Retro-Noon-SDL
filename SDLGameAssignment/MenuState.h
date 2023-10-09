#pragma once
#include "Game.h"
#include "PlayState.h"
class MenuState final : public GameState
{
public:
	~MenuState() override = default;

	bool OnEnter() override;
	GameState *Update() override;
	bool Render() override;
	void OnExit() override;

private:
	std::unique_ptr<Background> m_background;
	std::unique_ptr<MenuOptions> m_menu;
};