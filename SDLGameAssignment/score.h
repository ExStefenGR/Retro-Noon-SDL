#pragma once

#include "GameObject.h"
#include "Text.h"
class Score : public GameObject
{
public:
	Score();
	virtual ~Score();
	void SetScore(int score);
	void SetPosition(const Vector<int>& m_position) final;
	void AddScore(int add);
	void SetText(std::string const &text);
	int GetScore() const;
	void Update() final {}
	void Render() final;
private:
	int m_positionX{0};
	int m_positionY{0};
	int m_score{0};
	Text m_line{};
};