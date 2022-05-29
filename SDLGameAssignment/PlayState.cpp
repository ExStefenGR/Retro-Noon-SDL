#include "PlayState.h"

bool PlayState::OnEnter()
{
	// Load Background
	m_background->PlayMusic();
	// Setting Variables for Player
	m_player->SetPosition(50, 800);
	m_player->SetSize(128, 128);
	m_player->SetVelocity(3);
	// Initialising text objects
	m_score->SetScore(0);
	m_timer->SetPosition(0, 80);
	m_timer->SetTime(5);
	return true;
}
GameState* PlayState::Update()
{
	m_timer->Update();
	if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) || Input::Instance()->IsWindowClosed())
	{
		return nullptr;
	}
	if (m_player->IsBulletColliding())
	{
		m_score->AddScore(500);
	}
	else if (m_timer->GetTime() >= 0)
	{
		//========Update Functions============
		m_timer->CountDown();
		m_player->Update();
		// For Future development: Add ability for the enemy to shoot bullets
	}
	if (m_timer->GetTime() <= 0)
	{
		auto newstate = new EndState;
		return newstate;
	}
	else
	{
		return this;
	}
}
bool PlayState::Render()
{
	if (Screen::Instance()->getRenderer() == nullptr)
	{
		return false;
	}
	else
	{
		m_background->Render();
		m_player->Render();
		m_score->Render();
		m_timer->Render();
		return true;
	}
}
void PlayState::OnExit()
{
	GameState* newstate = Update();
	delete newstate;
}