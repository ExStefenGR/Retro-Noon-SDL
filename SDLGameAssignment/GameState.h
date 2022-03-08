#pragma once
#include "Screen.h"
#include "Input.h"
class GameState
{
public:
	virtual ~GameState() = 0 {}

	virtual bool OnEnter(Screen& screen) = 0;       //Load assets in this function
	virtual GameState* Update(Input& input) = 0;  //Here we update all of our game mechanics
	virtual bool Render(Screen& screen) = 0;        //Here we draw all of our scene's game objects
	virtual void OnExit() = 0;        //Unload assets in this function
};