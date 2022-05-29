#include "Game.h"

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
	return;
}
bool Game::Initialize() const
{
	Screen::Instance()->Init();
	Text::Initialise();
	Music::Initialize();
	return true;
}
bool Game::Run()
{
	m_gameState->OnEnter();
	while (m_gameState) // will break if m_gameState == nullptr
	{
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		auto const nextState = m_gameState->Update();
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);
			if (m_gameState.get())
			{
				m_gameState->OnEnter();
			}
		}
		else
		{
			m_gameState->Render();
			Screen::Instance()->Present();
		}
	}
	return true;
}
void Game::Shutdown() const
{
	Screen::Instance()->Exit();
}