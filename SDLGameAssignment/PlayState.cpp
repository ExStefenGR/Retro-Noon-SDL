#include "PlayState.h"
#include <assert.h>

bool PlayState::OnEnter()
{
	//Make Unique Pointers
	m_background = std::make_unique<Background>();
	m_cowboy = std::make_unique<CowboyP2>();
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
	//All main game mechanics are updated here
		if (Input::Instance()->GetKey() == SDLK_ESCAPE)
		{
			return nullptr;
		}
		if (m_timer->GetTime() <= 0)
		{
			m_timer->SetDimension(500,100);
			m_timer->SetPosition(650, 250);
			m_timer->SetText("Time up! Press ESC To Exit");
			m_score->SetPosition(800, 500);
		}
		else if (m_timer->GetTime() >= 0)
		{
			m_timer->CountDown();
			//========Updating position and/or Input translation============ 
			m_player->Update();
			m_cowboy->Update();
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
	//m_cowboy->Render();
	m_score->Render();
	m_timer->Render();
	return true;
}
void PlayState::OnExit()
{
	Screen::Instance()->Exit();
}