#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
    //Make Unique Pointers
   
   m_background = std::make_unique_for_overwrite<Background>();
   m_menu = std::make_unique_for_overwrite<MenuOptions>();
   m_menu->SetDimension(500, 100);
   m_menu->SetPosition(360, 100);
   m_menu->SetText("WELCOME!! PRESS ENTER TO FIGHT");
   return true;
}
GameState* MenuState::Update()
{
    if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
    {
		return nullptr;
    }
    else if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN))
    {
        return new PlayState;  
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
    m_background.release();
    m_menu.release();
}