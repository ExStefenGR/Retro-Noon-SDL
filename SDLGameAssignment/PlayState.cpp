#include "PlayState.h"
#include <assert.h>

bool PlayState::OnEnter(Screen& screen)
{
	//Make Unique Pointers
	m_background = std::make_unique<Background>(screen);
	m_cowboy = std::make_unique<CowboyP2>(screen);
	m_player = std::make_unique<Player>(screen);
	m_bullet = std::make_unique<Bullet>(screen);
	m_score = std::make_unique<Score>();
	m_timer = std::make_unique<Timer>();
	//Load Background
	m_background->PlayMusic();
	//Setting Variables for Player 
	m_player->SetPosition(50, 400);
	m_player->SetSize(128, 128);
	m_player->SetVelocity(2);
	//Setting variables for cowboy 
	m_cowboy->SetPosition(1150, 400);
	m_cowboy->SetSize(128, 128);
	m_cowboy->SetVelocity(1);
	//Setting variables for Player's bullet
	m_bullet->SetSize(32, 32);
	m_bullet->SetPosition(m_player->GetPosition());
	//Initialising text objects 
	m_score->SetScore(0);
	m_timer->SetPosition(0, 80);
	m_timer->SetTime(40);
	return true;
}

GameState* PlayState::Update(Input& input)
{
	//All main game mechanics are updated here
		input.Update();
		if (input.getKeyDown() == SDLK_ESCAPE)
		{
			return 0;
		}
		if (m_timer->GetTime() <= 0)
		{
			m_timer->SetDimension(500,100);
			m_timer->SetPosition(360, 100);
			m_timer->SetText("Time up! Press ESC To Exit");
			m_score->SetPosition(500, 500);
			m_background->Stop();
		}
		else if (m_timer->GetTime() >= 0)
		{
			m_timer->CountDown();
			//========Updating position and/or Input translation============ 
			m_player->Update(input);
			m_cowboy->Update(input);
			if (m_player->IsBulletShot() && !m_bullet->IsActive())
			{
				m_bullet->ShootSound();
				m_bullet->IsActive(true);
				m_bullet->IsVisible(true);
				m_bullet->SetPosition(m_player->GetPosition());
			}
			if (m_bullet->IsActive())
			{
				m_cowBoyCollider = m_cowboy->GetCollider();
				m_bulletCollider = m_bullet->GetCollider();
				m_bullet->Update(input);
				//=====Box Collision Detection========= 
				if (m_bulletCollider.IsColliding(m_cowBoyCollider))
				{
					m_score->AddScore(500);
					m_bullet->IsActive(false);
					m_bullet->IsVisible(false);
					m_bullet->SetPosition(m_player->GetPosition());
					m_player->IsBulletShot(false);
				}
			}
			if (m_bullet->GetPosition().x > 1280)
			{
				m_bullet->IsActive(false);
				m_bullet->IsVisible(false);
				m_bullet->SetPosition(m_player->GetPosition());
				m_player->IsBulletShot(false);
			}
		}
	return this;
}

bool PlayState::Render(Screen& screen)
{
	//Render player
	m_background->Render(screen);
	m_player->Render(screen);
	m_cowboy->Render(screen);
	if (m_bullet->IsVisible())
	{
		m_bullet->Render(screen);
	}
	m_score->Render(screen);
	m_timer->Render(screen);
	return true;
}

void PlayState::OnExit(Screen& screen)
{
}