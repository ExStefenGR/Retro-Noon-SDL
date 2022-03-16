#pragma once
#include <SDL.h>

struct MousePos
{
	int x;
	int y;
};
class Input
{
public:
	Input();
	void Update();
	char getKeyUp();
	char getKeyDown();
	bool isKeyPressed();
	bool IsWindowClosed();
private:
	char m_keyUp = NULL;
	char m_keyDown = NULL;
	bool m_isKeyPressed = false;
	bool m_isWindowClosed = false;
};