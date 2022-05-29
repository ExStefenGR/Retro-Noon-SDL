#pragma once

#include <string>
#include <SDL_mixer.h>
class Sound
{
public:
	Sound() = default;
	~Sound() = default;
	bool Load(const std::string& filename);
	void Unload();
	void SetVolume(int volume);
	void Play(int loop = 0);
private:
	Mix_Chunk* m_sound{nullptr};
};