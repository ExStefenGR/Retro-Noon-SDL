#include "Sprite.h"

void Sprite::IsAnimated(const bool flag)
{
	m_isAnimated = flag;
}
void Sprite::IsAnimationLooping(const bool flag)
{
	m_isAnimationLooping = flag;
}
void Sprite::SetImageCel(const int column, int const row)
{
	m_imageCel = m_imageDimension.x * (row - 1) + (column - 1);
}
void Sprite::SetAnimationVelocity(const float velocity)
{
	m_animationVelocity = velocity;
}
//This is the resolution of the sprite image as it will appear on-screen
void Sprite::SetSpriteDimension(const int width, const int height)
{
	m_spriteDimension.x = width;
	m_spriteDimension.y = height;
}
//This is the resolution and col/row dimensions of the sprite image as it is stored in the Assets folder
void Sprite::SetImageDimension(int const columns, int const rows, int const width, int const height)
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
void Sprite::Unload() const
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
		if (!m_isAnimationLooping && m_imageCel == m_imageDimension.x * m_imageDimension.y - 1)
		{
			m_isAnimationDead = true;
		}
	}
}

void Sprite::Render(const int xPos, int const yPos, double const angle)
{
	if (!m_isAnimationDead)
	{
		SDL_Rect sourceRect{};
		SDL_Rect targetRect{};
		sourceRect.x = (m_imageCel % m_imageDimension.x) * m_celDimension.x;
		sourceRect.y = (m_imageCel / m_imageDimension.x) * m_celDimension.y;
		sourceRect.w = m_celDimension.x;
		sourceRect.h = m_celDimension.y;
		targetRect.x = xPos;
		targetRect.y = yPos;
		targetRect.w = m_spriteDimension.x;
		targetRect.h = m_spriteDimension.y;
		const SDL_Point centre{m_spriteDimension.x, m_spriteDimension.y};
		SDL_RenderCopyEx(Screen::Instance()->getRenderer(), m_image, &sourceRect, &targetRect, angle, &centre, static_cast<SDL_RendererFlip>(m_flip));
	}
}