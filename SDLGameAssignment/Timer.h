#pragma once
#include "GameObject.h"
#include "Text.h"

class Timer : public GameObject
{
public:
	Timer();
	virtual ~Timer();
	void Update() final;
	void Render() final;
	void CountDown();
	void SetText(std::string const &text);
	void SetDimension(int width, int height);
	void SetPosition(int x, int y) final;
	void SetTime(int time);
	[[nodiscard]] int GetTime() const;

private:
	int m_timeSet{0};
	int m_result{0};
	double m_start{0.0f};
	double m_finish{0.0f};
	const double m_velocity{0.0035f};
	Text m_line{};
};