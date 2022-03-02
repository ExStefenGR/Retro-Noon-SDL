#include "Game.h" 

Game::Game(){}
Game::~Game(){}

bool Game::Initialize()
{
	Screen screen; //Declaring Screen 	 
	Input input;
	Text::Initialise(); //Implemented in Menu 
	Music::Initialize();
	return true;
}

bool Game::Run()
{
	m_screen.Init(); //Initialising screen 
	Background background(m_screen);
	CowboyP2 cowboy(m_screen);
	Player player(m_screen);
	Bullet bullet(m_screen);
	//Setting variables for background 
	background.SetPosition(0, 0);
	background.SetAngle(0.0);
	background.SetSize(1280, 720);
	//Setting Variables for Player 
	player.SetPosition(50, 400);
	player.SetAngle(0.0);
	player.SetSize(128, 128);
	player.SetVelocity(2);
	//Setting variables for cowboy 
	cowboy.SetPosition(1150, 400);
	cowboy.SetSize(128, 128);
	cowboy.SetVelocity(1);
	//Setting variables for Player's bullet 
	bullet.SetSize(32, 32);
	bullet.SetPosition(player.GetPosition());
	//Initialising text objects 
	std::unique_ptr<Score>score(new Score);
	std::unique_ptr<Timer>timer(new Timer);
	score->SetScore(0);
	timer->SetTime(50);

	while (m_isGameRunning)
	{
		m_screen.Clear();
		m_input.Update();
		if (m_input.IsWindowClosed())
		{
			m_isGameRunning = false;
		}
		if (timer->GetTime() <= 0)
		{
			timer->SetText("Time up!");
			score->SetPosition(500, 500);
		}
		else if (timer->GetTime() >= 0)
		{
			timer->CountDown();
			//========Updating position and/or Input translation============ 
			player.Update(m_input);
			cowboy.Update(m_input);
			if (player.IsBulletShot() && !bullet.IsActive())
			{
				bullet.ShootSound();
				bullet.IsActive(true);
				bullet.IsVisible(true);
				bullet.SetPosition(player.GetPosition());
			}
			if (bullet.IsActive())
			{
				m_cowBoyCollider = cowboy.GetCollider();
				m_bulletCollider = bullet.GetCollider();
				bullet.Update(m_input);
				//=====Box Collision Detection========= 
				if (m_bulletCollider.IsColliding(m_cowBoyCollider))
				{
					score->AddScore(500);
					bullet.IsActive(false);
					bullet.IsVisible(false);
					bullet.SetPosition(player.GetPosition());
					player.IsBulletShot(false);
				}
			}
			if (bullet.GetPosition().x > 1280)
			{
				bullet.IsActive(false);
				bullet.IsVisible(false);
				bullet.SetPosition(player.GetPosition());
				player.IsBulletShot(false);
			}
		}
		//===================================== 
		//========rendering objects============ 
		background.Render(m_screen);
		player.Render(m_screen);
		cowboy.Render(m_screen);
		if (bullet.IsVisible())
		{
			bullet.Render(m_screen);
		}
		score->Render(m_screen);
		timer->Render(m_screen);
		m_screen.Present();
	}
	m_screen.Exit();
	return true;
}
