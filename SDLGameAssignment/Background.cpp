#include "Background.h"

Background::Background(Screen& screen)
{
	m_image.Load("Assets/Images/Background.png", screen);
	m_image.SetImageDimension(1, 1, 1280, 720);
	m_image.SetSpriteDimension(1280, 720);
	m_image.IsAnimated(false);
	m_image.IsAnimationLooping(false);
}

Background::~Background()
{
	m_image.Unload();
}

void Background::Update(Input& input)
{
}

void Background::Render(Screen& screen)
{
	m_image.Render(m_position.x, m_position.y, m_angle, screen);
}
