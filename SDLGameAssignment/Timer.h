#pragma once
#include "GameObject.h"
#include "Text.h"

class Timer : public GameObject
{
public:
	Timer();
	~Timer() override;
	void Update() override;
	void Render() override;
	void CountDown();
	void SetText(std::string const& text);
	void SetDimension(const int width, const int height);
	void SetPosition(int x, int y) override;
	void SetTime(int time);
	int GetTime() const;
private:
	int m_timeSet{ 0 };
	int m_result{ 0 };
	double m_start{0.0f};
	double m_finish{0.0f};
	const double m_velocity{0.0035f};
	Text m_line{};
};