#pragma once
#include <memory>
#include "Screen.h"
#include "Text.h"
#include "Background.h"
#include "Bullet.h"
#include "CowboyP2.h"
#include "Player.h"
#include "score.h"
#include "Timer.h"
#include "Music.h"
#include "Sound.h"
class Game
{
public:
	Game();
	~Game();
	bool Initialize();
	bool Run();
	void Shutdown();
private:
	bool m_isGameRunning = true;
	Screen m_screen; //Declaring Screen 	  
	Input m_input;
	Music m_music;
	BoxCollider m_cowBoyCollider = {};
	BoxCollider m_bulletCollider = {};

	//Cannot initialise from here??
	//Background background;
	//Player player;
	//CowboyP2 cowboy;
	//Bullet bullet;
};