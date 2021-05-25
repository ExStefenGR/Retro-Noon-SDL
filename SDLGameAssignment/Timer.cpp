#include "Timer.h"

Timer::Timer()
{
	m_start = 0;
	m_time = 0;
	m_Difference = 50;
	m_line.Load("Assets/Fonts/p.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
}

Timer::~Timer()
{
	m_line.Unload();
}

void Timer::CountDown(double seconds)
{
	m_start = clock();

	auto secondsNeeded = (seconds * CLOCKS_PER_SEC);	
	auto timeText = secondsNeeded - m_start;
	m_line.SetText("Time " + std::to_string((static_cast<int>(timeText)) / 1000));
}

void Timer::Render(Screen& screen)
{
	m_line.Render(500, 10, screen);
}
