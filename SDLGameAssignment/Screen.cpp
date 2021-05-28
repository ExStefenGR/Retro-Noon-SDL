#include "Screen.h"

bool Screen::Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
	{
		std::cout << "Error, SDL could not initialise" << std::endl;
		return false;
	}

	m_window = SDL_CreateWindow("Game that is fun a bit",
								SDL_WINDOWPOS_CENTERED,	//X or Horizontal
								SDL_WINDOWPOS_CENTERED, //Y or Vertical position
								1280,		//Width
								720,		//height
								0	);		//flags (fullscreen,focus,etc)

	std::cout << "Window created" << std::endl;

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	std::cout << "Render created" << std::endl;

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
	std::cout << "Exiting initialised.." << std::endl;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

SDL_Renderer* Screen::getRenderer()
{
	return m_renderer;
}
