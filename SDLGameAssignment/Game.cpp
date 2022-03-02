#include "Game.h" 

Game::Game(GameState* initialState)
{
	m_gameState.reset(initialState);
}
Game::~Game(){}

bool Game::Initialize()
{
	Text::Initialise(); //Implemented in Menu 
	//Music::Initialize();
	return true;
}

bool Game::Run()
{
	m_gameState->OnEnter();

	while (m_gameState)  //will break if m_gameState == nullptr
	{

		//clearing the screen

		//updating the input

		//checking delta time

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
	}
	return true;
}

void Game::Shutdown()
{}
