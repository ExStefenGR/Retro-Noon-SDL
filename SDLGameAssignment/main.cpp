#include <memory>

#include "Game.h"
#include "MenuState.h"

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
	if (auto const game = std::make_unique<Game>(new MenuState))
	{
		Game::Initialize();
		game->Run();
		Game::Shutdown();
	}
	return 0;
}
