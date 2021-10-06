#include "Menu.h"
Menu::Menu()
{
	m_currentMode = static_cast<int>(GameMode::NoMode);
	m_gameMode[static_cast<int>(GameMode::NoMode)] = {};
	m_line.Load("Assets/Fonts/p.ttf", 400);
	m_line.SetColor(49, 211, 243, 255);
	m_line.SetDimension(1000, 100);
}

Menu::~Menu()
{
}

int Menu::GetGameMode()
{
	return m_gameMode[m_currentMode];
}

int Menu::SetGameMode(int mode)
{
	m_currentMode = mode;
	return m_gameMode[m_currentMode];
}

void Menu::Render(Screen& screen)
{
	m_line.Render(140, 312, screen);
}

void Menu::Update(Input& input)
{
	input.Update();
	if (input.getKeyDown() == SDLK_1)
	{
		m_currentMode = static_cast<int>(GameMode::Normal);
		/*m_gameMode[m_currentMode];*/
	}
	if (input.getKeyDown() == SDLK_2)
	{
		m_currentMode = static_cast<int>(GameMode::Time_Attack);
		/*m_gameMode[m_currentMode];*/
	}
	if (input.getKeyDown() == SDLK_3)
	{
		m_currentMode = static_cast<int>(GameMode::Two_Player);
		/*m_gameMode[m_currentMode];*/
	}
	if (m_currentMode == static_cast<int>(GameMode::NoMode))
	{
		m_line.SetText("1.Normal Mode   2.Time Attack Mode   3.2P Mode");
	}
}