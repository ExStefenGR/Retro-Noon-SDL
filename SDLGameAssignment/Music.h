#pragma once

#include <string>
#include <SDL_mixer.h>
class Music
{
public:
	enum class PlayLoop { PLAY = 1, PLAY_ENDLESS = -1 };
	static bool Initialize();
	Music();
	bool Load(const std::string& filename);
	void Unload();
	void SetVolume(int volume);
	void Play(PlayLoop playLoop);
	void Pause();
	void Resume();
	void Stop();
private:
	Mix_Music* m_music;
};

