#include "Score.h"

Score::Score()
{
	m_line.Load("Assets/Fonts/p.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
}
Score::~Score()
{
	m_line.Unload();
}
void Score::SetScore(int score)
{
	m_score = score;
	m_line.SetText("Score: " + std::to_string(m_score));
}
void Score::SetPosition(int x, int y)
{
	m_positionX = x;
	m_positionY = y;
}
void Score::AddScore(int add)
{
	m_score += add;
	m_line.SetText("Score: " + std::to_string(m_score));
}
void Score::SetText(std::string text)
{
	m_line.SetText(text);
}
int Score::GetScore()
{
	return m_score;
}
void Score::Render()
{
	m_line.Render(m_positionX, m_positionY);
}