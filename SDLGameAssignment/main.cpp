#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <stdlib.h> //For Time Attack mode
#include <time.h>	//For Time Attack mode
#include "Background.h"
#include "Bullet.h"
#include "CowboyP2.h"
#include "Input.h"
#include "Player.h"
#include "score.h"
#include "Screen.h"
#include "Sound.h"
#include "Text.h"
#include "Timer.h"
#include "Music.h"
#include "Vector2D.h"

bool isGameRunning = true;

int main(int argc, char* argv[])
{
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

	while (isGameRunning)
	{
		screen.Clear();
		input.Update();
		if (input.IsWindowClosed())
		{
			isGameRunning = false;
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
					std::cout << "Collision!" << std::endl;
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
	return 0;
}