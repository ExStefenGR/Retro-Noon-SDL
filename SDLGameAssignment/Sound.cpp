#include "Sound.h"
#include <assert.h>

bool Sound::Load(const std::string& filename)
{
	m_sound = Mix_LoadWAV(filename.c_str());
	//Possible missing sound file
	assert(m_sound != nullptr); //if false this will break here
	if (!m_sound)
	{
		return false;
	}
	return true;
}
void Sound::Unload()
{
	Mix_FreeChunk(m_sound);
}
void Sound::SetVolume(int volume)
{
	if (volume > 128)
	{
		m_normalizedValue = volume / 128;
		volume = m_normalizedValue;
	}
	Mix_VolumeChunk(m_sound, volume);
}
void Sound::Play(int loop)
{
	if (Mix_PlayChannel(-1, m_sound, loop) == -1){}
}