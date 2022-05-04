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
	virtual void Update() {}
	virtual void Render();
private:
	int m_positionX{0};
	int m_positionY{0};
	int m_score{0};
	Text m_line{};
};