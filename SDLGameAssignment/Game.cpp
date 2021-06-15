#include "Game.h"

Game::Game()
{
	m_isGameRunning = true;
	Screen screen; //Declaring Screen 	
	screen.Init(); //Initialising screen
	Text::Initialise(); //Implemented in Menu
	Music::Initialize();

	Background background(screen);
	Bullet bullet(screen);
	CowboyP2 cowboy(screen);
	Player player(screen);
	Input input;
	//Score and Timer
	Score* score = new Score;
	Timer* timer = new Timer;
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
	score->SetScore(0);
	timer->SetTime(50);
	while (m_isGameRunning)
	{
		screen.Clear();
		input.Update();
		if (input.IsWindowClosed())
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
			player.Update(input);
			cowboy.Update(input);
			if (player.IsBulletShot() && !bullet.IsActive())
			{
				bullet.ShootSound();
				bullet.IsActive(true);
				bullet.IsVisible(true);
				bullet.SetPosition(player.GetPosition());
			}
			if (bullet.IsActive())
			{
				bullet.Update(input);
				//=====Box Collision Detection=========
				BoxCollider cowBoyCollider = cowboy.GetCollider();
				BoxCollider bulletCollider = bullet.GetCollider();
				if (bulletCollider.IsColliding(cowBoyCollider))
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
		background.Render(screen);
		player.Render(screen);
		cowboy.Render(screen);
		if (bullet.IsVisible())
		{
			bullet.Render(screen);
		}
		score->Render(screen);
		timer->Render(screen);

		screen.Present();
	}
	delete score;
	delete timer;
	Text::ShutDown();
	screen.Exit();
}