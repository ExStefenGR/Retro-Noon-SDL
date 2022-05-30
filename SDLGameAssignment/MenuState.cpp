#include "MenuState.h"

bool MenuState::OnEnter()
{
   m_background.reset(new Background);
   m_menu.reset(new MenuOptions);
   m_menu->SetDimension(500, 100);
   m_menu->SetPosition(650, 100);
   m_menu->SetText("WELCOME!! PRESS ENTER TO FIGHT");
   return true;
}
GameState* MenuState::Update()
{
    if (Input::IsKeyPressed(HM_KEY_ESCAPE))
    {
		return nullptr;
    }
    if (Input::IsKeyPressed(HM_KEY_RETURN))
    {
	    const auto newstate = new PlayState;
	    return newstate;
    }
    return this;
}
bool MenuState::Render()
{
    if (Screen::Instance()->getRenderer() == nullptr)
    {
        return false;
    }
    m_background->Render();
    m_menu->Render();
    return true;
}
void MenuState::OnExit()
{
	const GameState* newstate = Update();
    delete newstate;
}