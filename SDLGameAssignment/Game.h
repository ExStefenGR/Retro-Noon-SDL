#pragma once
#include <memory>
#include "Text.h"
#include "Background.h"
#include "Bullet.h"
#include "CowboyP2.h"
#include "Player.h"
#include "score.h"
#include "Timer.h"
#include "Music.h"
#include "MenuOptions.h"
#include "Sound.h"
#include "GameState.h"
class Game
{
public:
	explicit Game(GameState *initialState);
	~Game() = default;
	static bool Initialize();
	bool Run();
	static void Shutdown();

private:
	std::unique_ptr<GameState> m_gameState;
};