#pragma once
#include <chrono>
#include "GameObject.h"
#include "Text.h"

typedef std::chrono::high_resolution_clock  HRClk_t;
typedef HRClk_t::time_point                 Time_t;
typedef std::chrono::seconds				S_t;
typedef std::chrono::milliseconds           MS_t;
typedef std::chrono::microseconds           US_t;
typedef std::chrono::nanoseconds            NS_t;
using namespace std::chrono_literals;

class Timer : public GameObject
{
public:
	Timer();
	~Timer();
	void CountDown();
	void SetText(std::string text);
	void SetDimension(const int width, const int height);
	void SetPosition(int x, int y);
	int GetTime();
	void SetTime(int time);
	virtual void Update();
	virtual void Render();
private:
	int m_positionX{ 0 };
	int m_positionY{ 0 };
	int m_timeSet{ 0 };
	int m_result{ 0 };
	int m_secondsNeeded{ 0 };
	US_t m_checker{};
	Time_t m_start{};
	Time_t m_stopwatch{};
	Text m_line{};
};