#include "MenuOptions.h"

MenuOptions::MenuOptions()
{
	m_line.Load("Assets/Fonts/Pixeled.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(150, 100);
	return;
}
MenuOptions::~MenuOptions()
{
	m_line.Unload();
	return;
}
void MenuOptions::SetPosition(int x, int y)
{
	m_position.x = x;
	m_position.y = y;
}
void MenuOptions::SetText(std::string const& text)
{
	m_line.SetText(text);
}
void MenuOptions::SetDimension(const int width, const int height)
{
	m_line.SetDimension(width, height);
}
void MenuOptions::Render()
{
	m_line.Render(m_position.x, m_position.y);
}