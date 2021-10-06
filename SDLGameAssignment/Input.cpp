#include "Input.h"

Input::Input()
{
	m_mousePosition = { 0,0 };
	m_isMouseClicked = false;
	m_isKeyPressed = false;
	m_isWindowClosed = false;
	m_keyDown = {};
	m_keyUp = {};
	m_mouseButtonDown = 0;
	m_mouseButtonUp = 0;
}

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
			m_keyDown = events.key.keysym.sym;
		}
		else if (events.type == SDL_KEYUP)
		{
			m_isKeyPressed = false;
			m_keyUp = events.key.keysym.sym;
		}
		else if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			m_isMouseClicked = true;
			m_mouseButtonDown = events.button.button;
		}
		else if (events.type == SDL_MOUSEBUTTONUP)
		{
			m_isMouseClicked = false;
			m_mouseButtonUp = events.button.button;
		}
		else if (events.type == SDL_MOUSEMOTION)
		{
			m_mousePosition.x = events.motion.x;
			m_mousePosition.y = events.motion.y;
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

int Input::getMouseButtonUp()
{
	return m_mouseButtonUp;
}

int Input::getMouseButtonDown()
{
	return m_mouseButtonDown;
}

const MousePos& Input::getMousePosition()
{
	return m_mousePosition;
}

bool Input::isMouseClicked()
{
	return m_isMouseClicked;
}

bool Input::isKeyPressed()
{
	return m_isKeyPressed;
}

bool Input::IsWindowClosed()
{
	return m_isWindowClosed;
}

