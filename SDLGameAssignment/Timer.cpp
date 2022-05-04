#include "Timer.h"

Timer::Timer()
{
	m_line.Load("Assets/Fonts/Pixeled.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
}
Timer::~Timer()
{
	m_line.Unload();
}
void Timer::CountDown()
{
	m_start = clock();
	checker = (m_stopwatch - m_start / CLOCKS_PER_SEC);
	m_result = static_cast<int>((checker / CLOCKS_PER_SEC));
	m_line.SetText("Time " + std::to_string(m_result));
	if (m_secondsNeeded < m_result)
	{
		checker = 0;
	}
}
void Timer::SetText(std::string text)
{
	m_line.SetText(text);
}
void Timer::SetDimension(const int width, const int height)
{
	m_line.SetDimension(width, height);
}
void Timer::SetPosition(int x, int y)
{
	m_positionX = x;
	m_positionY = y;
}
int Timer::GetTime()
{
	return m_result;
}
void Timer::SetTime(int time)
{
	m_timeSet = time;
	m_secondsNeeded = time;
	m_result = 0;
}
void Timer::Update()
{
	m_stopwatch = clock();
}
void Timer::Render()
{
	m_line.Render(m_positionX, m_positionY);
	m_stopwatch = clock();
}