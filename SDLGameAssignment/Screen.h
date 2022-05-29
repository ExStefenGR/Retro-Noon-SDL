#pragma once
#include <SDL.h>
#include <memory>
class Screen
{
public:
	static Screen* Instance();
	bool Init(); //Initialises the screen
	void Present(); //Renders the frame on the screen
	void Clear(); //Clears the buffer to make room for the next frame
	void Exit(); //Clears junk data from memory and then shuts down the screen module
	SDL_Renderer* getRenderer();
private:
	Screen() = default;
	Screen(const Screen&);
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
};