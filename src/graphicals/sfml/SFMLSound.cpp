/*
** EPITECH PROJECT, 2024
** SFMLSound
** File description:
** Arcade
*/

#include "SFMLSound.hpp"

SFMLSound::SFMLSound(const std::string &path)
{
    if (!_bufferSound.loadFromFile(path)) {
        std::cerr << "Erreur : Impossible de charger le son depuis le fichier: ";
        std::cerr << path << std::endl;
        throw SFMLSoundException("SFML Sound", "Can't create SFML Sound Class");
    }
    _sound.setBuffer(_bufferSound);
    std::cout << "Constructor in SFMLSound" << std::endl;
}

SFMLSound::~SFMLSound()
{
    std::cout << "Destructor in SFMLSound" << std::endl;
}

void SFMLSound::setState(shared::graphics::ISound::SoundState state)
{
    if (state == shared::graphics::ISound::SoundState::PLAY) {
        _state = shared::graphics::ISound::SoundState::PLAY;
        _sound.play();
    } else if (state == shared::graphics::ISound::SoundState::PAUSE) {
        _state = shared::graphics::ISound::SoundState::PAUSE;
        _sound.pause();
    } else if (state == shared::graphics::ISound::SoundState::STOP) {
        _state = shared::graphics::ISound::SoundState::STOP;
        _sound.stop();
    }
}

shared::graphics::ISound::SoundState SFMLSound::getState() const
{
    return _state;
}

void SFMLSound::setVolume(shared::graphics::ISound::SoundVolume volume)
{
    _sound.setVolume(volume);
}

shared::graphics::ISound::SoundVolume SFMLSound::getVolume() const
{
    shared::graphics::ISound::SoundVolume volume = _sound.getVolume();
    return volume;
}

void SFMLSound::setLoopState(bool loop)
{
    _sound.setLoop(loop);
}

bool SFMLSound::getLoopState(void) const
{
    return _sound.getLoop();
}

