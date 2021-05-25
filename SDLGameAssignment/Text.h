#pragma once
#include <string>
#include <iostream>
#include <SDL_ttf.h>
#include "Screen.h"

class Text
{



public:

	static bool Initialise();
	static void ShutDown();

	Text();
	~Text() {}
	
	void SetText(const std::string text);
	void SetColor(const SDL_Color& color);
	void SetColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void SetDimension(int width, int height);

	bool Load(const std::string& filename, int fontSize);
	void Render(int xPos, int yPos, Screen& screen);
	void Unload();


	
private:

	bool m_isDirty;
	std::string m_line;

	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Point m_dimension;
	SDL_Texture* m_texture;
};

