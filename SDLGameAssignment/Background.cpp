#include "Background.h"

Background::Background()
{
	m_images.Load("Assets/Images/Background.png");
	m_images.SetImageDimension(1, 1, 1280, 720);
	m_images.SetSpriteDimension(1920, 1080);
	m_images.IsAnimated(false);
	m_images.IsAnimationLooping(false);
	music.Load("Assets/Music/yes.wav");
	music.SetVolume(12);
	return;
}
Background::~Background()
{
	m_images.Unload();
	music.Unload();
	return;
}
void Background::PlayMusic()
{
	music.Play();
}
void Background::Render()
{
	m_images.Render(m_position.x, m_position.y, m_angle);
}