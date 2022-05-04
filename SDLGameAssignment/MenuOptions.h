#pragma once
#include "GameObject.h"
#include "Text.h"
class MenuOptions : public GameObject
{
public:
	MenuOptions();
	~MenuOptions();
	void SetPosition(int x, int y);
	void SetText(std::string text);
	void SetDimension(const int width, const int height);
	virtual void Update() {}
	virtual void Render();
private:
	int m_positionX{0};
	int m_positionY{0};
	Text m_line{};
};