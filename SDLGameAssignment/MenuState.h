#pragma once
#include "Game.h"
class MenuState : public GameState
{
public:
	~MenuState() override {}

	bool OnEnter(Screen& screen) override;
	GameState* Update(Input& input) override;
	bool Render(Screen& screen) override;
	void OnExit(Screen& screen) override;
private:
	std::unique_ptr<Background>m_background;
	std::unique_ptr<MenuOptions>m_menu;
};