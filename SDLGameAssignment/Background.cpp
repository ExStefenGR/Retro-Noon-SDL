#include "Background.h"

Background::Background(Screen& screen)
{
	m_images.Load("Assets/Images/Background.png", screen);
	m_images.SetImageDimension(1, 1, 1280, 720);
	m_images.SetSpriteDimension(1280, 720);
	m_images.IsAnimated(false);
	m_images.IsAnimationLooping(false);
	music.Load("Assets/Music/yes.wav");
	music.SetVolume(5);
}
Background::~Background()
{
	m_images.Unload();
}
void Background::PlayMusic()
{
	music.Play(1);
}
void Background::Update(Input& input) {}
void Background::Render(Screen& screen)
{
	m_images.Render(m_position.x, m_position.y, m_angle, screen);
}