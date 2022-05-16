#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include <memory>

int main(int argc, char *argv[])
{
	if (auto game = std::make_unique<Game>(new MenuState); game->Initialize())
	{
		game->Run();
		game->Shutdown();
	}
	return 0;
}