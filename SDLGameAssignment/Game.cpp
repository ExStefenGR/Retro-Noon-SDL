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
	screen.Init(); //Initialising screen 
	Background background(screen);
	CowboyP2 cowboy(screen);
	Player player(screen);
	Bullet bullet(screen);
	BoxCollider cowBoyCollider = cowboy.GetCollider();
	BoxCollider bulletCollider = bullet.GetCollider();
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
	screen.Exit();
	return true;
}
