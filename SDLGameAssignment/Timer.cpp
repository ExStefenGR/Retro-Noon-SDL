#include "Timer.h"

Timer::Timer()
{
	m_start = 0;
	m_time = 0;
	m_Difference = 50;
	m_text.Load("Assets/Fonts/p.ttf", 400);
	m_text.SetColor(49, 211, 243, 255);
	m_text.SetDimension(150, 100);
}

Timer::~Timer()
{
	m_text.Unload();
}


void Timer::CountDown(double seconds)
{
	m_start = clock();

	int secondsNeeded = (seconds * CLOCKS_PER_SEC);
	
	int timeText = secondsNeeded - m_start;

	m_text.SetText("Time " + std::to_string((timeText) / 1000));
}

void Timer::Render(Screen& screen)
{
	m_text.Render(500, 10, screen);
}
