#include "Sound.h"
#include <cassert>

bool Sound::Load(const std::string &filename)
{
	m_sound = Mix_LoadWAV(filename.c_str());
	// Possible missing sound file
	assert(m_sound != nullptr); // if false this will break here
	if (!m_sound)
	{
		return false;
	}
	return true;
}
void Sound::Unload() const
{
	Mix_FreeChunk(m_sound);
}
void Sound::SetVolume(int volume) const
{
	if (volume > 128)
	{
		volume = 128;
	}
	Mix_VolumeChunk(m_sound, volume);
}
void Sound::Play(const int loop) const
{
	Mix_PlayChannel(-1, m_sound, loop);
}
