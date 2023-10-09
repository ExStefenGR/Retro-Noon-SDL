#pragma once

#include "GameObject.h"
#include "Text.h"
class Score : public GameObject
{
public:
	Score();
	virtual ~Score();
	void SetScore(int score);
	void SetPosition(const Vector<int> &position) override;
	void AddScore(int add);
	void SetText(std::string const &text);
	[[nodiscard]] int GetScore() const;
	void Update() final {}
	void Render() final;

private:
	int m_score{0};
	Text m_line{};
};