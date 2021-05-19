#pragma once
#include <time.h>
#include "GameObject.h"
#include "Text.h"
class Timer : public GameObject
{

public:

	Timer();
	~Timer();

	void CountDown(double seconds);

	virtual void Update(Input& input) {}
	virtual void Render(Screen& screen);

private:

	int m_time;
	double m_Difference;

	clock_t m_start;


	Text m_text;


};

