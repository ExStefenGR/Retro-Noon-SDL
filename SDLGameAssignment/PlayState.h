#pragma once
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
#include "GameState.h"
#include "Game.h"
class PlayState : public GameState
{
public:

	~PlayState() override {}

	bool OnEnter() override;
	GameState* Update() override;
	bool Render() override;
	void OnExit() override;

private:
	Screen m_screen; //Declaring Screen 	  
	Input m_input;
	Music m_music;
	BoxCollider m_cowBoyCollider = {};
	BoxCollider m_bulletCollider = {};
	Background m_background{m_screen};
	CowboyP2 m_cowboy{m_screen};
	Player m_player{m_screen};
	Bullet m_bullet{m_screen};
	bool m_isGameRunning = true;

	std::unique_ptr<Score>m_score;
	std::unique_ptr<Timer>m_timer;
};

