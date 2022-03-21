#include "MenuState.h"
#include "PlayState.h"

bool MenuState::OnEnter(Screen& screen)
{
    //Make Unique Pointers
    m_background = std::make_unique<Background>(screen);
    m_menu = std::make_unique<MenuOptions>();
    return true;
}

GameState* MenuState::Update(Input& input)
{
    m_menu->SetDimension(500, 100);
    m_menu->SetPosition(360, 100);
    m_menu->SetText("Testing MenuState 123");
    //Input
    input.Update();
    if (input.getKeyDown() == SDLK_ESCAPE)
    {
        return 0;
    }
    else if (input.getKeyDown() == SDLK_1)
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

bool MenuState::Render(Screen& screen)
{
    if (screen.getRenderer() == nullptr)
    {
        return false;
    }
    m_background->Render(screen);
    m_menu->Render(screen);
    return true;
}

void MenuState::OnExit(Screen& screen)
{
    screen.Exit();
}
