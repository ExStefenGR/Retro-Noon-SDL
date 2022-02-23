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
	int	 getMouseButtonUp();
	int  getMouseButtonDown();
	const MousePos& getMousePosition();
	bool isMouseClicked();
	bool isKeyPressed();
	bool IsWindowClosed();
private:
	int m_mouseButtonUp = 0;
	int m_mouseButtonDown = 0;
	char m_keyUp = NULL;
	char m_keyDown = NULL;
	bool m_isMouseClicked = false;
	bool m_isKeyPressed = false;
	bool m_isWindowClosed = false;
	MousePos m_mousePosition = {};
};