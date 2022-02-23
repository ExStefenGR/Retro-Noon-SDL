#include "Timer.h"

Timer::Timer()
{
	m_line.Load("Assets/Fonts/p.ttf", 400);
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
	auto secondsNeeded = (m_timeSet * CLOCKS_PER_SEC);	
	auto timeText = secondsNeeded - m_start;
	auto result = static_cast<int>((timeText) / 1000);
	m_line.SetText("Time " + std::to_string(result));
	m_timeGet = result;
}

void Timer::SetText(std::string text)
{
	m_line.SetText(text);
}

int Timer::GetTime()
{
	return m_timeGet;
}

int Timer::SetTime(int time)
{
	m_timeGet = time;
	m_timeSet = time;
	return m_timeSet;
}

void Timer::Render(Screen& screen)
{
	m_line.Render(500, 10, screen);
}