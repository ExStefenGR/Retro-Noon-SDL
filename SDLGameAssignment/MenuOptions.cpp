#include "MenuOptions.h"

MenuOptions::MenuOptions()
{
	m_line.Load("Assets/Fonts/p.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
}
MenuOptions::~MenuOptions()
{
	m_line.Unload();
}
void MenuOptions::SetPosition(int x, int y)
{
	m_positionX = x;
	m_positionY = y;
}
void MenuOptions::SetText(std::string text)
{
	m_line.SetText(text);
}
void MenuOptions::SetDimension(const int width, const int height)
{
	m_line.SetDimension(width, height);
}
void MenuOptions::Render()
{
	m_line.Render(m_positionX, m_positionY);
}