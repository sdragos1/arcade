/*
** EPITECH PROJECT, 2024
** SDL2Sound
** File description:
** Arcade
*/

#include "SDL2Sound.hpp"

SDL2Sound::SDL2Sound(const std::string &path)
{
    _loop = false;
    if (Mix_Init(MIX_INIT_MP3) < 0) {
        throw SDL2SoundException("SDL2 class", "Can't create SDL2Sound class");
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        throw SDL2SoundException("SDL2 class", "Can't create SDL2Sound class");
    }
    _sound = Mix_LoadMUS(path.c_str());
    if (!_sound) {
        std::cerr << "Erreur : Impossible de charger le son depuis le fichier: ";
        std::cerr << path << std::endl;
        throw SDL2SoundException("SDL2 class", "Can't create SDL2Sound class");
    }
    std::cout << "Constructor in SDL2Sound" << std::endl;
}

SDL2Sound::~SDL2Sound()
{
    Mix_FreeMusic(_sound);
    Mix_CloseAudio();
    Mix_Quit();
    std::cout << "Destructor in SDL2Sound" << std::endl;
}

void SDL2Sound::setState(shared::graphics::ISound::SoundState state)
{
    if (state == shared::graphics::ISound::SoundState::PLAY) {
        _state = shared::graphics::ISound::SoundState::PLAY;
        Mix_ResumeMusic();
    } else if (state == shared::graphics::ISound::SoundState::PAUSE) {
        _state = shared::graphics::ISound::SoundState::PAUSE;
        Mix_PauseMusic();
    } else if (state == shared::graphics::ISound::SoundState::STOP) {
        _state = shared::graphics::ISound::SoundState::STOP;
        Mix_HaltMusic();
    }
}

shared::graphics::ISound::SoundState SDL2Sound::getState() const
{
    return _state;
}

void SDL2Sound::setVolume(shared::graphics::ISound::SoundVolume volume)
{
    Mix_VolumeMusic(volume);
}

shared::graphics::ISound::SoundVolume SDL2Sound::getVolume() const
{
    shared::graphics::ISound::SoundVolume volume = Mix_VolumeMusic(-1);
    return volume;
}

void SDL2Sound::setLoopState(bool loop)
{
    Mix_PlayMusic(_sound, -1);
    _loop = true;
}

bool SDL2Sound::getLoopState(void) const
{
    return _loop;
}

