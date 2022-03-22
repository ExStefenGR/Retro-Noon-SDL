#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter()
{
    //Make Unique Pointers
    m_background = std::make_unique<Background>();
    m_menu = std::make_unique<MenuOptions>();
    return true;
}
GameState* MenuState::Update()
{
    m_menu->SetDimension(500, 100);
    m_menu->SetPosition(360, 100);
    m_menu->SetText("WELCOME!!1!11 PRESS ENTER TO FIGHT");
    //Input
    Input::Instance()->Update();
    if (Input::Instance()->getKeyDown() == SDLK_ESCAPE)
    {
		return 0;
    }
    else if (Input::Instance()->getKeyDown() == SDLK_RETURN)
    {
        std::unique_ptr<Game> game = std::make_unique<Game>(new PlayState);

        if (game->Initialize())
        {
            game->Run();
            game->Shutdown();
        }
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
    Screen::Instance()->Exit();
}
