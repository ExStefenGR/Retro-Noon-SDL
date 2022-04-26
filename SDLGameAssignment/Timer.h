#pragma once
#include <chrono>
#include "GameObject.h"
#include "Text.h"
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
	int SetTime(int time);
	virtual void Update() {}
	virtual void Render();
private:
	int m_positionX = 0;
	int m_positionY = 0;
	int m_timeGet = 0;
	int m_timeSet = 0;
	float result = 0;
	clock_t m_start = 0;
	Text m_line;
};