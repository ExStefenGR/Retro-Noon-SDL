#include "EndState.h"

bool EndState::OnEnter()
{
    m_background = std::make_unique_for_overwrite<Background>();
    m_replay = std::make_unique_for_overwrite<MenuOptions>();
    m_replay->SetDimension(500, 100);
    m_replay->SetPosition(360, 100);
    m_replay->SetText("Play Again? Press Enter or ESCAPE to Leave");
    return true;
}

GameState* EndState::Update()
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
    m_background.reset(nullptr);
    m_replay.reset(nullptr);
    const GameState* newstate = Update();
    delete newstate;
}
