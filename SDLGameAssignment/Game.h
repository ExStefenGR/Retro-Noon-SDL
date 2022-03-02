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
	Screen screen; //Declaring Screen 	  
	Input input;
	Music music;
	//Cannot initialise from here??
	//Background background;
	//Player player;
	//CowboyP2 cowboy;
	//Bullet bullet;
};