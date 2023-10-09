#pragma once

#include <string>
#include <SDL_mixer.h>
class Sound
{
public:
	Sound() = default;
	~Sound() = default;
	bool Load(const std::string &filename);
	void Unload() const;
	void SetVolume(int volume) const;
	void Play(int loop = 0) const;

private:
	Mix_Chunk *m_sound{nullptr};
};