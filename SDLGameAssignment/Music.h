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
	virtual void SetVolume(int volume);
	virtual void Play(int playLoop);
	virtual void Pause();
	virtual void Resume();
	virtual void Stop();
private:
	Mix_Music* m_music{ nullptr };
	int m_normalizedValue{ 0 };
};