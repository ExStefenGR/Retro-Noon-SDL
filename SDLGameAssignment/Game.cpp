#include "Game.h" 

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}

bool Game::Initialize()
{
	m_screen.Init();
	Text::Initialise(); 
	Music::Initialize();
	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter(m_screen);
	while (m_gameState)  //will break if m_gameState == nullptr
	{
		//clearing the screen
		m_screen.Clear();
		//updating the current game state
		GameState* nextState = m_gameState->Update(m_input);
		m_gameState->Render(m_screen);
		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit(m_screen);
			m_gameState.reset(nextState);
			if (m_gameState)
			{
				m_gameState->OnEnter(m_screen);
			}
		}
		//rendering the screen
		m_screen.Present();
	}
	return true;
}

void Game::Shutdown()
{
	m_screen.Exit();
}
