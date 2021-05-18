#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "Player.h"
#include "CowboyP2.h"
#include "Bullet.h"
#include "Input.h"
#include "Screen.h"
#include "Background.h"
#include "Vector2D.h"
#include "Text.h"
#include "score.h"


//- Collision
//
//-Music / SFX
//
//- Sprites / animations
//
//- Text rendering
//
//- Vector math
//
//-

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

	Vector2D vector;
	Vector2D vector2;
	Vector2D endOfScreen = { 1280,720 };

	//Score and Score trigger (in the gameModes)
	Score* score = new Score;

	std::cout << "Select Game mode" << std::endl;
	std::cout << "1. Arcade Mode" << std::endl;
	std::cout << "2. Time Attack Mode" << std::endl;
	std::cout << "3. 2P Mode" << std::endl;

	std::cin >> gameMode;

	switch (gameMode)
	{
	case 1:

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
			screen.Clear();

			//========Updating position and/or Input translation============
			player.Update(input);
			bullet.Update(input);
			cowboy.Update(input);



			if (input.IsWindowClosed())
			{
				isGameRunning = false;
			}


			//distance doesn't seem accurate enough

			vector = bullet.GetPosition();
			vector2 = cowboy.GetPosition();

			std::cout << vector.Distance(vector2) << std::endl;




			
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
			if(isBulletHit &! bullet.IsAlive())//Also checks if the Bullet can be reset back to the player's position
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
	}

	delete score;

	Text::ShutDown();
	screen.Exit();
	return 0;
}