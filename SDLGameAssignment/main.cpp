#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include <memory>

int main([[maybe_unused]]int argc, [[maybe_unused]]char *argv[])
{
	if (auto game = std::make_unique<Game>(new MenuState); game->Initialize())
	{
		game->Run();
	}
	else
	{
		game->Shutdown();
	}
	return 0;
}