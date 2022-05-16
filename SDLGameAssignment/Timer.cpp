#include "Timer.h"

Timer::Timer()
{
	m_line.Load("Assets/Fonts/Pixeled.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(100, 100);
}
Timer::~Timer()
{
	m_line.Unload();
	m_finish = 0.0f;
	m_start = 0.0f;
	m_result = 0;
	m_timeSet = 0;

}
void Timer::CountDown()
{
	if (m_finish == 0.0f)
	{
		m_finish = m_timeSet;
	}
		m_result = static_cast<int>(m_finish - m_start);
		m_line.SetText(std::to_string(m_result));
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
	m_result = time;
}
void Timer::Update()
{
	m_start = m_start + m_velocity;
}
void Timer::Render()
{
	m_line.Render(m_positionX, m_positionY);
}