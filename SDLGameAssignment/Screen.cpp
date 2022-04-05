#include "Screen.h"

Screen* Screen::Instance()
{
	static Screen* screenObject = new Screen();
	return screenObject;
}
bool Screen::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		return false;
	}
	m_window = SDL_CreateWindow("SDL Retro-Noon",
								SDL_WINDOWPOS_CENTERED,	//X or Horizontal
								SDL_WINDOWPOS_CENTERED, //Y or Vertical position
								1920,		//Width
								1080,		//height
								SDL_WINDOW_VULKAN + SDL_WINDOW_MAXIMIZED);		//flags (fullscreen,focus,etc)
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	return true;
}
void Screen::Present()
{
	//render the screen (swap buffer)
	SDL_RenderPresent(m_renderer);
}
void Screen::Clear()
{
	//clears the screen, (frame buffer)
	SDL_RenderClear(m_renderer);
}
void Screen::Exit()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}
SDL_Renderer* Screen::getRenderer()
{
	return m_renderer;
}