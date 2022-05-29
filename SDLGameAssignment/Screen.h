#pragma once
#include <SDL.h>
#include <memory>
class Screen
{
public:
	static Screen* Instance();
	bool Init(); //Initialises the screen
	void Present() const; //Renders the frame on the screen
	void Clear() const; //Clears the buffer to make room for the next frame
	void Exit() const; //Clears junk data from memory and then shuts down the screen module
	SDL_Renderer* getRenderer() const;
private:
	Screen() = default;
	Screen(const Screen&);
	SDL_Window* m_window{ nullptr };
	SDL_Renderer* m_renderer{ nullptr };
};