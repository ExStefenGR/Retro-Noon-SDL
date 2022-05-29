#pragma once
#include <SDL_ttf.h>
#include <string>
#include <assert.h>
#include "Screen.h"

class Text
{
public:
	static bool Initialise();
	Text() = default;
	~Text() = default;
	void SetText(const std::string_view& text);
	void SetColor(const SDL_Color& color);
	void SetColor(const Uint8 r, const Uint8 g, const Uint8 b, const Uint8 a);
	void SetDimension(const int width, const int height);
	bool Load(const std::string& filename, const int fontSize);
	void Render(const int xPos, const int yPos);
	void Unload();
private:
	SDL_Rect m_targetRect = { 0,0,0,0 };
	SDL_Color m_color{ 255,255,255,255 };
	SDL_Point m_dimension{ 100,20 };
	SDL_Texture* m_texture{ nullptr };
	SDL_Surface* m_textData{ nullptr };
	std::string m_line{};
	TTF_Font* m_font{ nullptr };
	bool m_isDirty{ true };
};