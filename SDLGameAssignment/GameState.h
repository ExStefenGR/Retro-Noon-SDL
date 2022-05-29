#pragma once
#include "Screen.h"
#include "Input.h"
class GameState
{
public:
	virtual ~GameState() = default;

	virtual bool OnEnter() = 0;       //Load assets in this function
	virtual GameState* Update() = 0;  //TODO: make sure to find a way to use unique pointers for return values here
	virtual bool Render() = 0;        //Here we draw all of our scene's game objects
	virtual void OnExit() = 0;        //Unload assets in this function
};