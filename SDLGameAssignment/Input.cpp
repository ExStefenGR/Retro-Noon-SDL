#include "Input.h"

Input::Input(){}

void Input::Update()
{
	SDL_Event events;
	while (SDL_PollEvent(&events))
	{
		if (events.type == SDL_QUIT)
		{
			m_isWindowClosed = true;
		}
		else if (events.type == SDL_KEYDOWN)
		{
			m_isKeyPressed = true;
			m_keyUp = NULL;
			m_keyDown = events.key.keysym.sym;
		}
		else if (events.type == SDL_KEYUP)
		{
			m_isKeyPressed = false;
			m_keyDown = NULL;
			m_keyUp = events.key.keysym.sym;
		}
	}
}

char Input::getKeyUp()
{
	return m_keyUp;
}

char Input::getKeyDown()
{
	return m_keyDown;
}

bool Input::isKeyPressed()
{
	return m_isKeyPressed;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}