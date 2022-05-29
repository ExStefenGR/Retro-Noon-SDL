#include "Score.h"

Score::Score()
{
	m_line.Load("Assets/Fonts/Pixeled.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
	return;
}
Score::~Score()
{
	m_line.Unload();
	return;
}
void Score::SetScore(int score)
{
	m_score = score;
	m_line.SetText("Score: " + std::to_string(m_score));
}
void Score::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}
void Score::AddScore(int add)
{
	m_score = m_score + add;
	m_line.SetText("Score: " + std::to_string(m_score));
}
void Score::SetText(std::string const &text)
{
	m_line.SetText(text);
}
int Score::GetScore() const
{
	return m_score;
}
void Score::Render()
{
	m_line.Render(m_position.x, m_position.y);
}