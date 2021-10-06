#pragma once

#include "GameObject.h"
#include "Text.h"

class Score : public GameObject
{
public:
	Score();
	~Score();
	void SetScore(int score);
	void SetPosition(int x, int y);
	void AddScore(int add);
	void SetText(std::string text);
	int GetScore();
	virtual void Update(Input& input) {}
	virtual void Render(Screen& screen);
private:
	int m_positionX;
	int m_positionY;
	int m_score;
	Text m_line;
};

