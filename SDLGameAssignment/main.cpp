#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <time.h>	//For Time Attack mode
#include <stdlib.h> //For Time Attack mode
#include "Player.h"
#include "CowboyP2.h"
#include "Bullet.h"
#include "Input.h"
#include "Screen.h"
#include "Background.h"
#include "Vector2D.h"
#include "Text.h"
#include "score.h"
#include "Timer.h"
#include "Menu.h"
//TODO: Enemy Animations via photoshop and Music/Sound

bool isGameRunning = true;

enum GameMode
{
	NOMODE,
	NORMAL,
	TIME_ATTACK,
	TWO_PLAYER,
	TOTAL_MODES
};

int main(int argc, char* argv[])
{
	Screen screen; //Declaring Screen 	
	screen.Init(); //Initialising screen

	//TODO: Check compatibility with the rest
	Text::Initialise(); //Implemented in Menu


	//TODO: Implement Later Properly in the game's mode Function
	Background background(screen);

	Player player(screen);
	CowboyP2 cowboy(screen);
	Bullet bullet(screen);
	Input input;
	//Input input; //Implemented in Menu

	//Score and Score trigger (in the gameModes)
	Score* score = new Score;
	Timer* timer = new Timer;
	Menu* menu = new Menu;

	while (isGameRunning)
	{

		screen.Clear();
		menu->Update(input);
		if (menu->GetGameMode() == NOMODE)
		{
			if (input.IsWindowClosed())
			{
				isGameRunning = false;
			}
			menu->Render(screen);
		}

		if (menu->GetGameMode() == NORMAL)
		{
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
			cowboy.SetVelocity(3);
			//Setting variables for Player's bullet
			bullet.SetSize(32, 32);
			bullet.SetVelocity(2);
			bullet.SetPosition(player.GetPosition());
			score->SetScore(0);


			screen.Clear();

			//========Updating position and/or Input translation============
			player.Update(input);
			if (player.IsBulletShot() && !bullet.IsActive())
			{
				bullet.IsActive(true);
				bullet.IsVisible(true);
				bullet.SetPosition(player.GetPosition());
			}
			if (bullet.IsActive())
			{
				bullet.Update(input);
				//=====Box Collision Detection=========

				BoxCollider CowBoyCollider = cowboy.GetCollider();
				BoxCollider bulletCollider = bullet.GetCollider();
				if (bulletCollider.IsColliding(CowBoyCollider))
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
			cowboy.Update(input);

			if (input.IsWindowClosed())
			{
				isGameRunning = false;
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

		}

		screen.Present(); //TODO: Render Menu and ask for input from player, remove virtual Update Input

	}

	if (menu->GetGameMode() == TIME_ATTACK)
	{
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
		//bullet.SetVelocity(2);
		bullet.SetPosition(player.GetPosition());
		//Initialising text objects
		score->SetScore(0);


		timer->CountDown(50);
		screen.Clear();

		//========Updating position and/or Input translation============
		player.Update(input);
		if (player.IsBulletShot() && !bullet.IsActive())
		{
			bullet.IsActive(true);
			bullet.IsVisible(true);
			bullet.SetPosition(player.GetPosition());
		}
		if (bullet.IsActive())
		{
			bullet.Update(input);
			//=====Box Collision Detection=========
			BoxCollider CowBoyCollider = cowboy.GetCollider();
			BoxCollider bulletCollider = bullet.GetCollider();
			if (bulletCollider.IsColliding(CowBoyCollider))
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
		cowboy.Update(input);

		if (input.IsWindowClosed())
		{
			isGameRunning = false;
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