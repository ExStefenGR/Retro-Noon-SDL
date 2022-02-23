#include "Text.h"
#include <assert.h>

bool Text::Initialise()
{
	if (TTF_Init() == -1) { return false; }
	return true;
}
Text::Text(){}
void Text::SetText(const std::string text)
{
	m_line = text;
	m_isDirty = true;
}
void Text::SetColor(const SDL_Color& color)
{
	m_color = color;
	m_isDirty = true;
}
void Text::SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
	m_isDirty = true;
}
void Text::SetDimension(int width, int height)
{
	m_dimension = { width, height };
}
bool Text::Load(const std::string& filename, int fontSize)
{
	m_font = TTF_OpenFont(filename.c_str(), fontSize);
	if (!m_font)
	{
		return false;
	}
	return true;
}
void Text::Render(int xPos, int yPos, Screen& screen)
{
	m_targetRect.x = xPos;
	m_targetRect.y = yPos;
	m_targetRect.w = m_dimension.x;
	m_targetRect.h = m_dimension.y;
	if (m_isDirty)
	{
		SDL_DestroyTexture(m_texture);
		m_textData = TTF_RenderText_Blended(m_font, m_line.c_str(), m_color);
		m_texture = SDL_CreateTextureFromSurface(screen.getRenderer(), m_textData);
		SDL_FreeSurface(m_textData);
		m_isDirty = false;
	}
	SDL_RenderCopy(screen.getRenderer(), m_texture, nullptr, &m_targetRect);
}
void Text::Unload()
{
	TTF_CloseFont(m_font);
}