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
	m_start = HRClk_t::now();
	m_checker = std::chrono::duration_cast<S_t>(m_start - m_stopwatch);
	m_line.SetText("Time " + m_checker.count());
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
	m_stopwatch = HRClk_t::now();
}
void Timer::Render()
{
	m_line.Render(m_positionX, m_positionY);
}