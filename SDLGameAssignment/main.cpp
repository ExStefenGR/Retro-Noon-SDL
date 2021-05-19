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



//TODO: Collision
//
//TODO: Music / SFX
//
//TODO: Sprites / animations


bool isGameRunning = true;
int gameMode;


int main(int argc, char* argv[])
{
	

	Screen screen; //Declaring Screen 	
	screen.Init(); //Initialising screen



									//Loading game objects (Background and Player) into memory via GameObject and image class

	Text::Initialise();
	Background background(screen);
	Player player(screen);
	CowboyP2 cowboy(screen);
	Bullet bullet(screen);

	Input input;

	//Vector2D endOfScreen = { 1280,720 }; <- Would teleport bullet away from the enemy object to avoid continuous score increase
	//Removed because of making the Y position of the bullet more inaccurate than it already is

	//Score and Score trigger (in the gameModes)
	Score* score = new Score;
	Timer* timer = new Timer;

	std::cout << "Select Game mode" << std::endl;
	std::cout << "1. Arcade Mode" << std::endl;
	std::cout << "2. Time Attack Mode" << std::endl;
	std::cout << "3. 2P Mode" << std::endl;

	std::cin >> gameMode;

	if(gameMode == 1)
	{
		//timer->CountDown();
		
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
		int scoreTrigger = 500;

		//On-Collider with Enemy player Var
		bool isBulletHit = false;


		while (isGameRunning)
		{
			screen.Clear();

			//========Updating position and/or Input translation============
			player.Update(input);
			bullet.Update(input);
			cowboy.Update(input);

			if (input.IsWindowClosed())
			{
				isGameRunning = false;
			}

			//=====Box Collision Detection=========

			BoxCollider CowBoyCollider = cowboy.GetCollider();
			BoxCollider bulletCollider = bullet.GetCollider();

			if (bulletCollider.IsColliding(CowBoyCollider) && isBulletHit == false)
			{
				std::cout << "Collision!" << std::endl;
				score->AddScore(500);
				isBulletHit = true;
				//repositions the bullet object to the end of the screen

				bullet.IsAlive(false);
				bullet.SetPosition(player.GetPosition());

			}
			else
			{
				isBulletHit = false;
				std::cout << "NO Collision!" << std::endl;
			}
			if (isBulletHit & !bullet.IsAlive())//Also checks if the Bullet can be reset back to the player's position
			{
				//bullet.SetPosition(player.GetYCords());

				bullet.SetPosition(player.GetPosition());
			}


			//=====================================
			//========rendering objects============

			background.Render(screen);
			player.Render(screen);
			cowboy.Render(screen);
			bullet.Render(screen);

			score->Render(screen);

			screen.Present();
		}
		
	}
	
	else if (gameMode == 2)
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
		int scoreTrigger = 500;

		//On-Collider with Enemy player Var
		bool isBulletHit = false;


		while (isGameRunning)
		{
			timer->CountDown(50);
			screen.Clear();

			//========Updating position and/or Input translation============
			player.Update(input);
			bullet.Update(input);
			cowboy.Update(input);

			if (input.IsWindowClosed())
			{
				isGameRunning = false;
			}

			//=====Box Collision Detection=========

			BoxCollider CowBoyCollider = cowboy.GetCollider();
			BoxCollider bulletCollider = bullet.GetCollider();

			if (bulletCollider.IsColliding(CowBoyCollider) && isBulletHit == false)
			{
				std::cout << "Collision!" << std::endl;
				score->AddScore(500);
				isBulletHit = true;
				//repositions the bullet object to the end of the screen

				bullet.IsAlive(false);
				bullet.SetPosition(player.GetPosition());

			}
			else
			{
				isBulletHit = false;
				std::cout << "NO Collision!" << std::endl;
			}
			if (isBulletHit & !bullet.IsAlive())//Also checks if the Bullet can be reset back to the player's position
			{
				//bullet.SetPosition(player.GetYCords());

				bullet.SetPosition(player.GetPosition());
			}


			//=====================================
			//========rendering objects============

			background.Render(screen);
			player.Render(screen);
			cowboy.Render(screen);
			bullet.Render(screen);

			score->Render(screen);
			timer->Render(screen);

			screen.Present();
		}
	}
	

	delete score;
	delete timer;
	Text::ShutDown();
	screen.Exit();
	return 0;
}