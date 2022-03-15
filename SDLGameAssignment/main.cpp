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