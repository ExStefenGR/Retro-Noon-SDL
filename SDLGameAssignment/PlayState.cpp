#include "PlayState.h"
#include "EndState.h"
#include <assert.h>

bool PlayState::OnEnter()
{
	//Make Unique Pointers
	m_background = std::make_unique<Background>();
	m_player = std::make_unique<Player>();
	m_score = std::make_unique<Score>();
	m_timer = std::make_unique<Timer>();
	//Load Background
	m_background->PlayMusic();
	//Setting Variables for Player 
	m_player->SetPosition(50, 800);
	m_player->SetSize(128, 128);
	m_player->SetVelocity(3);
	//Initialising text objects 
	m_score->SetScore(0);
	m_timer->SetPosition(0, 80);
	m_timer->SetTime(10);
	return true;
}
GameState* PlayState::Update()
{
		m_timer->Update();
		/*TODO:A solution I have thought of would be to manually add the milliseconds on-enter in a variable and then
		subtract the difference in order to for the countdown to work every time*/
		if (Input::Instance()->IsKeyPressed(HM_KEY_ESCAPE) || Input::Instance()->IsWindowClosed())
		{
			return nullptr;
		}
		if (m_timer->GetTime() <= 0)
		{
			return new EndState;
		}
		else if (m_timer->GetTime() >= 0)
		{
			//========Update Functions============
			m_timer->CountDown();
			m_player->Update();
			//TODO: Add ability for the enemy to shoot bullets
		}
		if (m_player->IsBulletColliding())
		{
			m_score->AddScore(500);
		}
	return this;
}
bool PlayState::Render()
{
	m_background->Render();
	m_player->Render();
	m_score->Render();
	m_timer->Render();
	return true;
}
void PlayState::OnExit()
{}