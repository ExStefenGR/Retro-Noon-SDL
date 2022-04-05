#include "Game.h" 

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}
bool Game::Initialize()
{
	Screen::Instance()->Init();
	Text::Initialise(); 
	Music::Initialize();
	return true;
}
bool Game::Run()
{
	m_gameState->OnEnter();
	while (m_gameState)  //will break if m_gameState == nullptr
	{
		//clearing the screen
		Screen::Instance()->Clear();
		Input::Instance()->Update();
		//updating the current game state
		GameState* nextState = m_gameState->Update();
		m_gameState->Render();
		//This will only run if a switch is required
		if (nextState != m_gameState.get())
		{
			m_gameState->OnExit();
			m_gameState.reset(nextState);
			if (m_gameState)
			{
				m_gameState->OnEnter();
			}
		}
		//rendering the screen
		Screen::Instance()->Present();
	}
	return true;
}
void Game::Shutdown()
{
	Screen::Instance()->Exit();
}