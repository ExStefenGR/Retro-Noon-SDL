#pragma once

#include <string>
#include <SDL_mixer.h>
class Music
{
public:
	static bool Initialize();
	Music();
	bool Load(const std::string& filename);
	void Unload();
	void SetVolume(int volume);
	void Play(int playLoop);
	void Pause();
	void Resume();
	void Stop();
private:
	Mix_Music* m_music = nullptr;
	int m_normalizedValue = 0;
};

