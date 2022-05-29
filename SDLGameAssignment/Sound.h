#pragma once
#include <SDL_mixer.h>
#include <string>
class Sound
{
public:
	Sound() = default;
	~Sound() = default;
	bool Load(const std::string& filename);
	void Unload();
	void SetVolume(int volume);
	void Play(int loop = 0);

	Mix_Chunk* m_sound{ nullptr };
};
