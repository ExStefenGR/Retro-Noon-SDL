#include "EndState.h"
#include "PlayState.h"

bool EndState::OnEnter()
{
    m_background = std::make_unique<Background>();
    m_replay = std::make_unique<MenuOptions>();
    m_replay->SetDimension(500, 100);
    m_replay->SetPosition(360, 100);
    m_replay->SetText("Play Again? Press Enter or ESCAPE to Leave");
    return true;
}

GameState* EndState::Update()
{
    if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE))
    {
        return 0;
    }
    else if (Input::Instance()->IsKeyPressed(HM_KEY_RETURN))
    {
        return new PlayState;
    }
    return this;
}

bool EndState::Render()
{
    if (Screen::Instance()->getRenderer() == nullptr)
    {
        return false;
    }
    m_background->Render();
    m_replay->Render();
    return true;
}

void EndState::OnExit()
{
}