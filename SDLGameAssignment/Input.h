#pragma once
#include <SDL.h>

class Input
{
public:
	static Input* Instance();

	void Update();
	char getKeyUp();
	char getKeyDown();
	bool isKeyPressed();
	bool IsWindowClosed();
private:
	Input() {};
	Input(const Input&);
	Input& operator=(const Input&);

	char m_keyUp = NULL;
	char m_keyDown = NULL;
	bool m_isKeyPressed = false;
	bool m_isWindowClosed = false;
	const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
};