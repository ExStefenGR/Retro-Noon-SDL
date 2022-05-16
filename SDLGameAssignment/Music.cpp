#include "Music.h"
#include <assert.h>
bool Music::Initialize()
{
	if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
	{
		return false;
	}
	return true;
}
Music::Music(){}
bool Music::Load(const std::string& filename)
{
	m_music = Mix_LoadMUS(filename.c_str());
	assert(m_music != nullptr);
	if (!m_music)
	{
		return false;
	}
	return true;
}
void Music::Unload()
{
	Mix_FreeMusic(m_music);
}
void Music::SetVolume(int volume)
{
	if (volume > 128)
	{
		m_normalizedValue = static_cast<int>(volume / 128);
	}
	Mix_VolumeMusic(volume);
}
void Music::Play(int playLoop)
{
	assert(m_music != nullptr); //Music is NULL
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(m_music, -1);
	}
	if (Mix_PlayMusic(m_music, -1) == -1) 
	{
		printf("Mix_PlayMusic: %s\n", Mix_GetError());
		// well, there's no music, but most games don't break without music...
	}
}
void Music::Pause()
{
	if (!Mix_PausedMusic())
	{
		Mix_PauseMusic();
	}
}
void Music::Resume()
{
	if (Mix_PausedMusic())
	{
		Mix_ResumeMusic();
	}
}
void Music::Stop()
{
	if (Mix_PausedMusic() || Mix_PlayingMusic())
	{
		Mix_HaltMusic();
	}
}