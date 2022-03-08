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
#include "Game.h"
#include "PlayState.h"
#include <memory>


int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game = std::make_unique<Game>(new PlayState);
	if (game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}
	return 0;
}