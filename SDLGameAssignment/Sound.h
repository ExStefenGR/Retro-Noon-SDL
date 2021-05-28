#pragma once

#include <string>
#include <iostream>
#include <SDL_mixer.h>
class Sound
{
public:
	Sound();

	bool Load(const std::string& filename);
	void Unload();

	void SetVolume(int volume);

	void Play(int loop = 0);
private:
	Mix_Chunk* m_sound;
};