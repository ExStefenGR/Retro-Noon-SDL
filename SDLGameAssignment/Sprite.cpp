#include "Sprite.h"
#include <SDL_image.h>

void Sprite::IsAnimated(bool flag)
{
	m_isAnimated = flag;
}
void Sprite::IsAnimationLooping(bool flag)
{
	m_isAnimationLooping = flag;
}
void Sprite::SetImageCel(int column, int row)
{
	m_imageCel = ((row - 1) * m_imageDimension.x) + (column - 1);
}
void Sprite::SetAnimationVelocity(float velocity)
{
	m_animationVelocity = velocity;
}
//This is the resolution of the sprite image as it will appear on-screen
void Sprite::SetSpriteDimension(int width, int height)
{
	m_spriteDimension.x = width;
	m_spriteDimension.y = height;
}
//This is the resolution and col/row dimensions of the sprite image as it is stored in the Assets folder
void Sprite::SetImageDimension(int columns, int rows, int width, int height)
{
	m_imageDimension.x = columns;
	m_imageDimension.y = rows;
	m_celDimension.x = width / columns;
	m_celDimension.y = height / rows;
}
bool Sprite::Load(const std::string& filename)
{
	SDL_Surface* rawImageData = IMG_Load(filename.c_str());
	if (!rawImageData)
	{
		return false;
	}
	m_image = SDL_CreateTextureFromSurface(Screen::Instance()->getRenderer(), rawImageData);
	return true;
}
void Sprite::Unload()
{
	SDL_DestroyTexture(m_image);
}
void Sprite::Update()
{
	if (m_isAnimated)
	{
		static float total = 0.0f;
		total += 0.1f;
		m_imageCel = static_cast<int>(total * m_animationVelocity) % (m_imageDimension.x * m_imageDimension.y);
		if (!m_isAnimationLooping && m_imageCel == (m_imageDimension.x * m_imageDimension.y - 1))
		{
			m_isAnimationDead = true;
		}
	}
}

void Sprite::Render(int xPos, int yPos, double angle)
{
	if (!m_isAnimationDead)
	{
		SDL_Rect sourceRect{0};
		SDL_Rect targetRect{0};
		sourceRect.x = (m_imageCel % m_imageDimension.x) * m_celDimension.x;
		sourceRect.y = (m_imageCel / m_imageDimension.x) * m_celDimension.y;
		sourceRect.w = m_celDimension.x;
		sourceRect.h = m_celDimension.y;
		targetRect.x = xPos;
		targetRect.y = yPos;
		targetRect.w = m_spriteDimension.x;
		targetRect.h = m_spriteDimension.y;
		SDL_Point centre{ static_cast<int>((m_spriteDimension.x * 0.5f)) , static_cast<int>(m_spriteDimension.y * 0.5f) };
		SDL_RenderCopyEx(Screen::Instance()->getRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, static_cast<SDL_RendererFlip>(m_flip));
	}
}