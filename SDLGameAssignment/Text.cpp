#include "Text.h"

bool Text::Initialise()
{
	if (TTF_Init() == -1) { return false; }
	return true;
}
void Text::SetText(const std::string_view& text)
{
	m_line = text;
	m_isDirty = true;
}
void Text::SetColor(const SDL_Color& color)
{
	m_color = color;
	m_isDirty = true;
}
void Text::SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a)
{
	m_color.r = r;
	m_color.g = g;
	m_color.b = b;
	m_color.a = a;
	m_isDirty = true;
}
void Text::SetDimension(const int width, const int height)
{
	m_dimension = { width, height };
}
bool Text::Load(const std::string& filename, const int fontSize)
{
	m_font = TTF_OpenFont(filename.c_str(), fontSize);
	if (!m_font)
	{
		return false;
	}
	return true;
}
void Text::Render(const int xPos, const int yPos)
{
	m_targetRect.x = xPos;
	m_targetRect.y = yPos;
	m_targetRect.w = m_dimension.x;
	m_targetRect.h = m_dimension.y;
	if (m_isDirty)
	{
		SDL_DestroyTexture(m_texture);
		m_textData = TTF_RenderText_Blended(m_font, m_line.c_str(), m_color);
		m_texture = SDL_CreateTextureFromSurface(Screen::Instance()->getRenderer(), m_textData);
		SDL_FreeSurface(m_textData);
		m_isDirty = false;
	}
	SDL_RenderCopy(Screen::Instance()->getRenderer(), m_texture, nullptr, &m_targetRect);
}
void Text::Unload()
{
	TTF_CloseFont(m_font);
}