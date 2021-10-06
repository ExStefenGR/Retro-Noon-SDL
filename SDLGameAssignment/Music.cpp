#include "Music.h"

bool Music::Initialize()
{
    if (Mix_OpenAudio(44100, AUDIO_S16SYS, 2, 1024) == -1)
    {
        std::cout << "Error in Audio system" << std::endl;
        return false;
    }
    return true;
}

Music::Music()
{
    m_music = nullptr;
}

bool Music::Load(const std::string& filename)
{
    m_music = Mix_LoadMUS(filename.c_str());
    if (!m_music)
    {
        std::cout << "Error loading audio file " << filename << std::endl;
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
    int normalizedValue;
    normalizedValue = static_cast<int>(volume / 128);
    Mix_VolumeMusic(normalizedValue);
}

void Music::Play(PlayLoop playLoop)
{
}

void Music::Pause()
{
    if(!Mix_PausedMusic())
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
    if (Mix_PausedMusic())
    {
        Mix_HaltMusic();
    }
}
