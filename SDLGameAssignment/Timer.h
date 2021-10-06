#pragma once
#include <time.h>
#include "GameObject.h"
#include "Text.h"
class Timer : public GameObject
{
public:
	Timer();
	~Timer();
	void CountDown();
	void SetText(std::string text);
	int GetTime();
	int SetTime(int time);
	virtual void Update(Input& input) {}
	virtual void Render(Screen& screen);
private:
	int m_timeGet;
	int m_timeSet;
	clock_t m_start;
	Text m_line;
};