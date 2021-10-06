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
	int m_mouseButtonUp;
	int m_mouseButtonDown;
	char m_keyUp;
	char m_keyDown;
	bool m_isMouseClicked;
	bool m_isKeyPressed;
	bool m_isWindowClosed;
	MousePos m_mousePosition;
};