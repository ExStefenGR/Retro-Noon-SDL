#pragma once

#include "Input.h"
#include "Vector2D.h"
#include "Text.h"
#include "GameObject.h"
class Menu : public GameObject
{
	enum class GameMode
	{
		NoMode,
		Normal,
		Time_Attack,
		Two_Player,
		Total_Modes
	};
public:
	Menu();
	~Menu();
	int GetGameMode();
	int SetGameMode(int mode);
	virtual void Render(Screen& screen);
	void Update(Input& input);
private:
	int m_gameMode[static_cast<int>(GameMode::Total_Modes)];
	int m_currentMode;
	Text m_line;
};