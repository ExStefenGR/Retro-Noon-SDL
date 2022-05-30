#include "GameStateMachine.h"

void GameStateMachine::pushState(GameState* state)
{
	m_gameStates.push_back(state);
	m_gameStates.back()->OnEnter();
}

void GameStateMachine::changeState(GameState* state)
{
	if (!m_gameStates.empty() && m_gameStates.back()->GetStateID() == state->GetStateID())
	{
			return;
	}

	m_gameStates.push_back(state);

	if (!m_gameStates.empty() && m_gameStates.back()->OnExit())
	{
		m_gameStates.erase(m_gameStates.end() - 2);
	}

	m_gameStates.back()->OnEnter();
}

void GameStateMachine::popState()
{
	if (!m_gameStates.empty() && m_gameStates.back()->OnExit())
	{

		m_gameStates.erase(m_gameStates.end() - 1);

	}
}

void GameStateMachine::update()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->Update();
	}
}

void GameStateMachine::render()
{
	if (!m_gameStates.empty())
	{
		m_gameStates.back()->Render();
	}
}

std::string GameStateMachine::GetStateID() const
{
	return std::string();
}
