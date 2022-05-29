#pragma once

#include <SDL_mixer.h>
#include <assert.h>
#include <string>
class Music
{
public:
	Music() = default;
	virtual ~Music() = default;
	static bool Initialize();
	bool Load(const std::string& filename);
	void Unload();
	virtual void SetVolume(int volume);
	virtual void Play();
	virtual void Pause();
	virtual void Resume();
	virtual void Stop();

private:
	Mix_Music* m_music{ nullptr };
};
