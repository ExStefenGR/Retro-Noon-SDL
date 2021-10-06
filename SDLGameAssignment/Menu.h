#pragma once

#include "Input.h"
#include "Vector2D.h"
#include "Text.h"
#include "GameObject.h"
class Menu : public GameObject
{
	enum GameMode
	{
		NOMODE,
		NORMAL,
		TIME_ATTACK,
		TWO_PLAYER,
		TOTAL_MODES
	};
public:
	Menu();
	~Menu();

	int GetGameMode();
	int SetGameMode(int mode);

	virtual void Render(Screen& screen);
	
	void Update(Input& input);
private:
	int m_gameMode[TOTAL_MODES];
	int m_currentMode;
	Text m_line;
};

