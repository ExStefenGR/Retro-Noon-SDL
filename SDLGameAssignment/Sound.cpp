#include "Sound.h"

Sound::Sound()
{
	m_sound = nullptr;
}

bool Sound::Load(const std::string& filename)
{
    m_sound = Mix_LoadWAV(filename.c_str());

    if (!m_sound)
    {
        std::cout << "Error loading audio file " << filename << std::endl;
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
        int normalizedValue;
        normalizedValue = static_cast<int>(volume / 128);
        volume = normalizedValue;
    }
    Mix_VolumeChunk(m_sound, volume); //Flagging up as access violation reading location: 0x0000000C
}

void Sound::Play(int loop)
{
    if (Mix_PlayChannel(-1, m_sound, loop) == -1)
    {
        std::cout << "Error playing sound effect" << std::endl;
    }
}
