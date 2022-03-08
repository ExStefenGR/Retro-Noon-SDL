#include "PlayState.h"
#include <assert.h>

bool PlayState::OnEnter()
{
	m_screen.Init(); //Initialising screen 
	//Music::Initialize();
	//Text::Initialise();
	//Load assets for player and enemy
	//Load all music for game
	//Load images and fonts
	m_background.SetPosition(0, 0);
	m_background.SetAngle(0.0);
	m_background.SetSize(1280, 720);
	//Setting Variables for Player 
	m_player.SetPosition(50, 400);
	m_player.SetAngle(0.0);
	m_player.SetSize(128, 128);
	m_player.SetVelocity(2);
	//Setting variables for cowboy 
	m_cowboy.SetPosition(1150, 400);
	m_cowboy.SetSize(128, 128);
	m_cowboy.SetVelocity(1);
	//Setting variables for Player's bullet 
	m_bullet.SetSize(32, 32);
	m_bullet.SetPosition(m_player.GetPosition());
	//Initialising text objects 
	m_score = std::make_unique<Score>();
	m_timer = std::make_unique<Timer>();

	m_score->SetScore(0);

	m_timer->SetTime(50);
	return true;
}

GameState* PlayState::Update()
{
	//Check keypress and mouse clicks
	//check if buttons are clicked on
	//All main game mechanics are updated here


		m_screen.Clear();
		m_input.Update();
		if (m_input.IsWindowClosed())
		{
			m_isGameRunning = false;
		}
		if (m_timer->GetTime() <= 0)
		{
			m_timer->SetText("Time up!");
			m_score->SetPosition(500, 500);
		}
		else if (m_timer->GetTime() >= 0)
		{
			m_timer->CountDown();
			//========Updating position and/or Input translation============ 
			m_player.Update(m_input);
			m_cowboy.Update(m_input);
			if (m_player.IsBulletShot() && !m_bullet.IsActive())
			{
				//m_bullet.ShootSound();
				m_bullet.IsActive(true);
				m_bullet.IsVisible(true);
				m_bullet.SetPosition(m_player.GetPosition());
			}
			if (m_bullet.IsActive())
			{
				m_cowBoyCollider = m_cowboy.GetCollider();
				m_bulletCollider = m_bullet.GetCollider();
				m_bullet.Update(m_input);
				//=====Box Collision Detection========= 
				if (m_bulletCollider.IsColliding(m_cowBoyCollider))
				{
					m_score->AddScore(500);
					m_bullet.IsActive(false);
					m_bullet.IsVisible(false);
					m_bullet.SetPosition(m_player.GetPosition());
					m_player.IsBulletShot(false);
				}
			}
			if (m_bullet.GetPosition().x > 1280)
			{
				m_bullet.IsActive(false);
				m_bullet.IsVisible(false);
				m_bullet.SetPosition(m_player.GetPosition());
				m_player.IsBulletShot(false);
			}
		}
		//===================================== 
		//========rendering objects============ 
		m_screen.Present();

	return this;
}

bool PlayState::Render()
{
	//Render player
	//render enemy
	//render ...
	m_background.Render(m_screen);
	m_player.Render(m_screen);
	m_cowboy.Render(m_screen);
	if (m_bullet.IsVisible())
	{
		m_bullet.Render(m_screen);
	}
	m_score->Render(m_screen);
	m_timer->Render(m_screen);

	return true;
}

void PlayState::OnExit()
{
	//unload all music, text, sprites for this state

}