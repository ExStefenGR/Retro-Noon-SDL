#pragma once

#include "GameObject.h"
#include "Text.h"
class Score : public GameObject
{
public:
	Score();
	virtual ~Score();
	void SetScore(int score);
	void SetPosition(int x, int y) final;
	void AddScore(int add);
	void SetText(std::string const &text);
	int GetScore() const;
	void Update() final {}
	void Render() final;
private:
	int m_score{0};
	Text m_line{};
};